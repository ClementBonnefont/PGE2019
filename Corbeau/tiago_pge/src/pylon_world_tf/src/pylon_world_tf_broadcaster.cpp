#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <moveit_msgs/ApplyPlanningScene.h>
#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_operations.h"
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <geometric_shapes/shape_operations.h>

tf::Transform transform;
int cpt_passage = 10;

void add_pylon_world() {
	ros::NodeHandle nh("~");
	ros::Publisher planning_scene_diff_publisher = nh.advertise<moveit_msgs::PlanningScene>("/planning_scene", 1);
	while(planning_scene_diff_publisher.getNumSubscribers() < 1)
	{
	ROS_INFO_STREAM("Waiting for /planning_scene topic");
	ros::WallDuration sleep_t(0.5);
	sleep_t.sleep();
	}

	//Vector to scale 3D file
	Eigen::Vector3d vectorScale(1, 1, 1);
	// Define a collision object ROS message.
	moveit_msgs::CollisionObject attached_object;
	// The id of the object is used to identify it.
	attached_object.id = "pylon_cao";
	attached_object.header.frame_id = "/map";

	//Path where the .dae or .stl object is located
	shapes::Mesh* m = shapes::createMeshFromResource("file:////home/pge/tiago_pge/src/pylon_world_tf/config/pylon.dae", vectorScale); 
	ROS_INFO("Your mesh was loaded");

	shape_msgs::Mesh mesh;
	shapes::ShapeMsg mesh_msg;  
	shapes::constructMsgFromShape(m, mesh_msg);
	mesh = boost::get<shape_msgs::Mesh>(mesh_msg);

	//Define a pose for your mesh (specified relative to frame_id)
	geometry_msgs::Pose obj_pose;
	obj_pose.position.x = transform.getOrigin().x();
	obj_pose.position.y = transform.getOrigin().y();
	obj_pose.position.z = transform.getOrigin().z();
	obj_pose.orientation.x = transform.getRotation().x();
	obj_pose.orientation.y = transform.getRotation().y();
	obj_pose.orientation.z = transform.getRotation().z();
	obj_pose.orientation.w = transform.getRotation().w();

	// Add the mesh to the Collision object message 
	attached_object.meshes.push_back(mesh);
	attached_object.mesh_poses.push_back(obj_pose);

	attached_object.operation = attached_object.ADD;

	ROS_INFO("Adding the object into the world.");
	moveit_msgs::PlanningScene planning_scene;
	planning_scene.world.collision_objects.push_back(attached_object);
	planning_scene.is_diff = true;
	planning_scene_diff_publisher.publish(planning_scene);
	/* Sleep so we have time to see the object in RViz */
	sleep(2.0);

	ros::ServiceClient planning_scene_diff_client = nh.serviceClient<moveit_msgs::ApplyPlanningScene>("/apply_planning_scene");
	planning_scene_diff_client.waitForExistence();
	moveit_msgs::ApplyPlanningScene srv;
	srv.request.scene = planning_scene;
	planning_scene_diff_client.call(srv);
}

void pylonPoseCallback(const geometry_msgs::PoseStamped& msg)
{
	if(cpt_passage < 10) {
		transform.setOrigin(tf::Vector3(msg.pose.position.x, msg.pose.position.y, msg.pose.position.z));
		transform.setRotation(tf::Quaternion(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w));
		cpt_passage++;
	}
	else
		add_pylon_world();
}

int main(int argc, char** argv){
	ros::init(argc, argv, "pylon_world_tf_broadcaster");
	ros::NodeHandle nh("~");
	tf::TransformBroadcaster br;
	ros::Subscriber sub = nh.subscribe("/aruco_single/pose", 100, pylonPoseCallback);
	// transform.setOrigin(tf::Vector3(-1, -1, -1));
	// transform.setRotation(tf::Quaternion(-1, -1, -1, -1));
	transform.setOrigin(tf::Vector3(0, 0, 0));
	transform.setRotation(tf::Quaternion(0, 0, 0, 1));
	add_pylon_world();
  
	ros::Rate rate(10.0); //Hertz
	while (nh.ok()){
	if(cpt_passage > 9)
		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "pylon"));
	ros::spinOnce();
	rate.sleep();
	}
	return 0;
};
