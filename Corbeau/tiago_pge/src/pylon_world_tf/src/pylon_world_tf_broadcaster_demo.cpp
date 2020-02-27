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
//moveit_msgs::CollisionObject co_pylon_appro;
ros::Publisher collision_object_publisher;

void add_pylon_world() {
	//Vector to scale 3D file
	Eigen::Vector3d vectorScale(2.0, 2.0, 1.2);

	// The id of the object is used to identify it.
	co_pylon.id = "pylon_cao";
	//co_pylon_appro.id = "pylon_cao_appro";

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

	//APPROCHE
	/*co_pylon_appro.header.frame_id = "/pylon_appro";
	geometry_msgs::Pose obj_pose_appro;
	obj_pose_appro.position.x = 0;
	obj_pose_appro.position.y = 0;
	obj_pose_appro.position.z = 0;
	obj_pose_appro.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 1.571);*/

	// Add the mesh to the Collision object message 
	co_pylon.meshes.push_back(mesh);
	co_pylon.mesh_poses.push_back(obj_pose);
	
	co_pylon.operation = co_pylon.ADD;

	// Add the mesh to the Collision object message APPROCHE
	//co_pylon_appro.meshes.push_back(mesh);
	//co_pylon_appro.mesh_poses.push_back(obj_pose_appro);
	
	//co_pylon_appro.operation = co_pylon_appro.ADD;
	
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

	//APPROCHE	
	//collision_object_publisher.publish(co_pylon_appro); // Initial publish of the pylon CAO in RVIZ
	// To move the CAO after the move of the mobile base
	//co_pylon_appro.operation = co_pylon_appro.MOVE;
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
		//collision_object_publisher.publish(co_pylon_appro); // Re-pose of the pylon CAO in RVIZ
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
	// ARUCO not used during the demo
	//ros::Subscriber sub_aruco = nh.subscribe("/aruco_single/pose", 1000, pylonPoseCallback);

	ros::Subscriber sub_goal_reached = nh.subscribe("/move_base/result", 1000, baseGoalReached);
	cpt_passage = 10;
	add_pylon_world();
	
	moveit_msgs::CollisionObject co_ground = add_ground_world();

	// Add a second broadcaster for the Demo approche
	/*tf::Transform transform_appro;
	transform_appro.setOrigin(tf::Vector3(-1.23, 1.41, 0.96));
	const tf::Quaternion rpy_appro = tf::createQuaternionFromRPY(0.85, 1.571, 0.0);
	transform_appro.setRotation(rpy_appro);	*/

	ros::Rate rate(100.0); //Hertz
	while (nh.ok()){
		if(cpt_passage > 9) {
			br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/map", "/pylon"));
			//br.sendTransform(tf::StampedTransform(transform_appro, ros::Time::now(), "/map", "/pylon_appro"));
		}
		ros::spinOnce();
		rate.sleep();
	}

	// Remove the ground and the pylon COs on RVIZ
	/*	
	co_ground.operation = co_ground.REMOVE;
	co_pylon.operation = co_pylon.REMOVE;
	while(collision_object_publisher.getNumSubscribers() < 1) {
		ROS_INFO_STREAM("Waiting for /collision_object topic");
		ros::WallDuration sleep_t(0.5);
		sleep_t.sleep();
	}
	collision_object_publisher.publish(co_ground);
	collision_object_publisher.publish(co_pylon);*/

	return 0;
};
