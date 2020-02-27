#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <moveit_msgs/CollisionObject.h>
#include <geometric_shapes/shapes.h>
#include <geometric_shapes/mesh_operations.h>
#include <geometric_shapes/shape_operations.h>
#include <move_base_msgs/MoveBaseActionResult.h>

tf::Transform transform;
int cpt_passage = 0;
// Need to be global to the replace after the base moved
moveit_msgs::CollisionObject co_pylon;
ros::Publisher collision_object_publisher;

void add_pylon_world() {
	//Vector to scale 3D file
	Eigen::Vector3d vectorScale(2.0, 2.0, 1.2);

	// The id of the object is used to identify it.
	co_pylon.id = "pylon_cao";

	//Path where the .dae or .stl object is located
	shapes::Mesh* m = shapes::createMeshFromResource("package://pylon_world_tf/config/pylone_echelle_low_res.dae", vectorScale);
	ROS_INFO("Your mesh was loaded");

	shape_msgs::Mesh mesh;
	shapes::ShapeMsg mesh_msg;  
	shapes::constructMsgFromShape(m, mesh_msg);
	mesh = boost::get<shape_msgs::Mesh>(mesh_msg);

	//Define a pose for your mesh (specified relative to frame_id)
	co_pylon.header.frame_id = "/pylon";
	geometry_msgs::Pose obj_pose;
	obj_pose.position.x = 0;
	obj_pose.position.y = 0;
	obj_pose.position.z = 0;
	obj_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

	// Add the mesh to the Collision object message 
	co_pylon.meshes.push_back(mesh);
	co_pylon.mesh_poses.push_back(obj_pose);
	
	co_pylon.operation = co_pylon.ADD;

	// Publish the CAO to RVIZ
	while(collision_object_publisher.getNumSubscribers() < 1)
	{
		ROS_INFO_STREAM("Waiting for /collision_object topic");
		ros::WallDuration sleep_t(0.5);
		sleep_t.sleep();
	}
	collision_object_publisher.publish(co_pylon); // Initial publish of the pylon CAO in RVIZ
	// To move the CAO after the move of the mobile base
	co_pylon.operation = co_pylon.MOVE;
}

moveit_msgs::CollisionObject add_ground_world() {	
	moveit_msgs::CollisionObject co_ground;
	
	// The id of the object is used to identify it.
	co_ground.id = "ground";

	shape_msgs::SolidPrimitive primitive_ground;
	primitive_ground.type = primitive_ground.BOX;
	primitive_ground.dimensions.resize(3);
	primitive_ground.dimensions[0] = 10;
	primitive_ground.dimensions[1] = 10;
	primitive_ground.dimensions[2] = 0.4;


	//Define a pose for your mesh (specified relative to frame_id)
	co_ground.header.frame_id = "base_footprint";
	geometry_msgs::Pose obj_pose;
	obj_pose.position.x = 0;
	obj_pose.position.y = 0;
	obj_pose.position.z = 0;
	obj_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

	// Add the primitive to the Collision object message 
	co_ground.primitives.push_back(primitive_ground);
	co_ground.primitive_poses.push_back(obj_pose);
	
	co_ground.operation = co_ground.ADD;
	
	// Publish the CAO to RVIZ
	while(collision_object_publisher.getNumSubscribers() < 1)
	{
		ROS_INFO_STREAM("Waiting for /collision_object topic");
		ros::WallDuration sleep_t(0.5);
		sleep_t.sleep();
	}
	collision_object_publisher.publish(co_ground);

	return co_ground;
}

void pylonPoseCallback(const geometry_msgs::PoseStamped& msg)
{
	if(cpt_passage < 10) {
		transform.setOrigin(tf::Vector3(msg.pose.position.x, msg.pose.position.y, msg.pose.position.z));
		transform.setRotation(tf::Quaternion(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w));
		cpt_passage++;
	}
	else if(cpt_passage == 10) { //To add one time
		add_pylon_world();
		cpt_passage++;
	}
}

void baseGoalReached(const move_base_msgs::MoveBaseActionResult& msg) {
	ROS_INFO_STREAM(msg.status.text);

	if(msg.status.text == "Goal reached.") {
		while(collision_object_publisher.getNumSubscribers() < 1)
		{
			ROS_INFO_STREAM("Waiting for /collision_object topic");
			ros::WallDuration sleep_t(0.5);
			sleep_t.sleep();
		}
		collision_object_publisher.publish(co_pylon); // Re-pose of the pylon CAO in RVIZ
	}
}

int main(int argc, char** argv){
	ros::init(argc, argv, "pylon_world_tf_broadcaster");
	ros::NodeHandle nh("~");
	collision_object_publisher = nh.advertise<moveit_msgs::CollisionObject>("/collision_object", 1000);
	
	tf::TransformBroadcaster br;
	transform.setOrigin(tf::Vector3(1.18, 0.611, 0));
	const tf::Quaternion rpy= tf::createQuaternionFromYaw(0.69);
	transform.setRotation(rpy);
	ros::Subscriber sub_aruco = nh.subscribe("/aruco_single/pose", 1000, pylonPoseCallback);

	ros::Subscriber sub_goal_reached = nh.subscribe("/move_base/result", 1000, baseGoalReached);
	cpt_passage = 10;
	add_pylon_world();
	
	moveit_msgs::CollisionObject co_ground = add_ground_world();

	ros::Rate rate(100.0); //Hertz
	while (nh.ok()){
		if(cpt_passage > 9) {
			br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/map", "/pylon"));
		}
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
};
