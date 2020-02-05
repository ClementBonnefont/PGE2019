#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <moveit_msgs/CollisionObject.h>
#include <geometric_shapes/shapes.h>
#include <geometric_shapes/mesh_operations.h>
#include <geometric_shapes/shape_operations.h>
#include <move_base_msgs/MoveBaseActionResult.h>

tf::Transform transform;
int cpt_passage = 10;
moveit_msgs::CollisionObject co;

moveit_msgs::CollisionObject add_pylon_world() {
	//Vector to scale 3D file
	Eigen::Vector3d vectorScale(1.2, 1.2, 1.2);
	// Define a collision object ROS message.
	moveit_msgs::CollisionObject pylon_object;
	// The id of the object is used to identify it.
	pylon_object.id = "pylon_cao";

	//Path where the .dae or .stl object is located
	shapes::Mesh* m = shapes::createMeshFromResource("file:////home/pge/tiago_pge/src/pylon_world_tf/config/pylon.dae", vectorScale); 
	ROS_INFO("Your mesh was loaded");

	shape_msgs::Mesh mesh;
	shapes::ShapeMsg mesh_msg;  
	shapes::constructMsgFromShape(m, mesh_msg);
	mesh = boost::get<shape_msgs::Mesh>(mesh_msg);

	//Define a pose for your mesh (specified relative to frame_id)
	pylon_object.header.frame_id = "/map";
	geometry_msgs::Pose obj_pose;
	obj_pose.position.x = transform.getOrigin().x();
	obj_pose.position.y = transform.getOrigin().y();
	obj_pose.position.z = transform.getOrigin().z();
	obj_pose.orientation.x = transform.getRotation().x();
	obj_pose.orientation.y = transform.getRotation().y();
	obj_pose.orientation.z = transform.getRotation().z();
	obj_pose.orientation.w = transform.getRotation().w();

	// Add the mesh to the Collision object message 
	pylon_object.meshes.push_back(mesh);
	pylon_object.mesh_poses.push_back(obj_pose);
	pylon_object.operation = pylon_object.ADD;

	// Return the CollisionObject to be published periodically in RVIZ
	return pylon_object;
}

void pylonPoseCallback(const geometry_msgs::PoseStamped& msg)
{
	if(cpt_passage < 10) {
		transform.setOrigin(tf::Vector3(msg.pose.position.x, msg.pose.position.y, msg.pose.position.z));
		transform.setRotation(tf::Quaternion(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w));
		cpt_passage++;
	}
}

void baseGoalReached(const move_base_msgs::MoveBaseActionResult& msg) {
	ROS_INFO_STREAM(msg.status.text);

	if(msg.status.text == "Goal reached.") {
		ros::NodeHandle nh("~");
		ros::Publisher collision_object_publisher = nh.advertise<moveit_msgs::CollisionObject>("/collision_object", 1);
		while(collision_object_publisher.getNumSubscribers() < 1)
		{
			ROS_INFO_STREAM("Waiting for /collision_object topic");
			ros::WallDuration sleep_t(0.5);
			sleep_t.sleep();
		}
		collision_object_publisher.publish(co); // Re-pose of the pylon CAO in RVIZ
	}
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

	ros::Subscriber sub_goal_reached = nh.subscribe("/move_base/result", 1000, baseGoalReached);
	
	co = add_pylon_world();
	ros::Publisher collision_object_publisher = nh.advertise<moveit_msgs::CollisionObject>("/collision_object", 1);
	while(collision_object_publisher.getNumSubscribers() < 1)
	{
		ROS_INFO_STREAM("Waiting for /collision_object topic");
		ros::WallDuration sleep_t(0.5);
		sleep_t.sleep();
	}
	collision_object_publisher.publish(co); // Initial publish of the pylon CAO in RVIZ
	co.meshes.clear();
	co.operation = co.MOVE;

	ros::Rate rate(10.0); //Hertz
	while (nh.ok()){
	if(cpt_passage > 9) {
		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/map", "/pylon"));
	}
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
};
