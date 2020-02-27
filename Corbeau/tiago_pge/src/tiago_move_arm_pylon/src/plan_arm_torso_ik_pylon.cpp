#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>

using namespace tiago_move_arm_pylon;

float Move_tiago_arm::degree_to_radian(float degree) {
  return (degree*M_PI)/180.0;
}

void Move_tiago_arm::add_aptere(){
  moveit_msgs::AttachedCollisionObject attached_object;
  attached_object.link_name = "gripper_grasping_frame";
  /* The header must contain a valid TF frame*/
  attached_object.object.header.frame_id = "gripper_link";
  /* The id of the object */
  attached_object.object.id = "sys_aptere_box";
  attached_object.object.header.stamp = ros::Time::now();

	/* Box pose */
	geometry_msgs::Pose pose;
	pose.position.x = 0.1;
	pose.position.y = 0.06;
	pose.position.z = -0.275;
	pose.orientation.w = 1.0;

  /* Define a box to be attached */
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.BOX;
  primitive.dimensions.resize(3);
  primitive.dimensions[0] = 0.16;
  primitive.dimensions[1] = 0.19;
  primitive.dimensions[2] = 0.21;

  attached_object.object.primitives.push_back(primitive);
  attached_object.object.primitive_poses.push_back(pose);
  attached_object.object.operation = attached_object.object.ADD;

  // Links touched by the system aptere box
  attached_object.touch_links = std::vector<std::string>{ "gripper_grasping_frame", "gripper_left_finger_link", "gripper_right_finger_link", "gripper_link", "gripper_tool_link" };

  ros::NodeHandle nh("~");
  ros::Publisher publisher = nh.advertise<moveit_msgs::AttachedCollisionObject>("/attached_collision_object", 1000);
    while(publisher.getNumSubscribers() < 1)
    {
      ROS_INFO_STREAM("Waiting for /attached_collision_object topic");
      ros::WallDuration sleep_t(0.5);
      sleep_t.sleep();
    }
    publisher.publish(attached_object);
}

void Move_tiago_arm::remove_aptere() {
	moveit_msgs::AttachedCollisionObject attached_object;
	attached_object.object.id = "sys_aptere_box";
	attached_object.object.operation = attached_object.object.REMOVE;

	ros::NodeHandle nh;
	ros::Publisher publisher = nh.advertise<moveit_msgs::AttachedCollisionObject>("/attached_collision_object", 1000);
	while(publisher.getNumSubscribers() < 1) {
		ROS_INFO_STREAM("Waiting for /attached_collision_object topic");
		ros::WallDuration sleep_t(0.5);
		sleep_t.sleep();
	}
	publisher.publish(attached_object);
}

/*
void Move_tiago_arm::add_constraint(moveit::planning_interface::MoveGroupInterface& group_arm_torso) {
	moveit_msgs::OrientationConstraint ocm;
	ocm.link_name = "arm_tool_link";
	ocm.header.frame_id = "base_footprint";
	ocm.orientation.x = -0.5;
	ocm.orientation.y = -0.5;
	ocm.orientation.z = 0.5;
	ocm.orientation.w = 0.5;
	ocm.absolute_x_axis_tolerance = 0.2;
	ocm.absolute_y_axis_tolerance = 0.2;
	ocm.absolute_z_axis_tolerance = 0.2;
	ocm.weight = 0.8;
	ROS_INFO_STREAM(ocm.weight);
	moveit_msgs::Constraints constraint;
	constraint.orientation_constraints.push_back(ocm);
	group_arm_torso.setPathConstraints(constraint);
}*/

void Move_tiago_arm::add_constraint(moveit::planning_interface::MoveGroupInterface& group_arm_torso) {
	moveit_msgs::JointConstraint jc;
	jc.joint_name = "arm_5_link";
	jc.position = 1.6;
	jc.tolerance_above = 0.3;
	jc.tolerance_below = 0.3;
	jc.weight = 1.0;
	ROS_INFO_STREAM("Add a constraint to avoid flip");
	moveit_msgs::Constraints path_constraints;
	path_constraints.joint_constraints.push_back(jc);
	group_arm_torso.setPathConstraints(path_constraints);
}

void Move_tiago_arm::go_to_point_arm_tool_link(geometry_msgs::PoseStamped goal_pose_pylon_frame) {
	ros::NodeHandle nh("~");
	double rate_hz;
	nh.param("rate", rate_hz, 1.0);
	ros::Rate rate(rate_hz);
	tf::TransformListener tf;
	std::string source_frameid = goal_pose_pylon_frame.header.frame_id;
	std::string target_frameid = "base_footprint"; 
	geometry_msgs::PoseStamped goal_pose_base_footprint_frame;

	tf.waitForTransform(target_frameid, source_frameid, ros::Time(), ros::Duration(1.0));
	while(goal_pose_base_footprint_frame.header.frame_id != target_frameid)
	{
		try
		{
			//target_frame, stamped_in, stamped_out
			tf.transformPose(target_frameid, goal_pose_pylon_frame, goal_pose_base_footprint_frame);
		}
		catch(tf::TransformException& ex)
		{
			std::cout << "Failure at "<< ros::Time::now() << std::endl;
			std::cout << "Exception thrown:" << ex.what()<< std::endl;
		}
		rate.sleep();
	}

	ros::AsyncSpinner spinner(2); //Spinner 1
	spinner.start();

	//select group of joints
	moveit::planning_interface::MoveGroupInterface group_arm_torso("arm_torso");
 
	//choose your preferred planner
 	std::string planner;
	if(nh.getParam("/planner_id", planner))
		group_arm_torso.setPlannerId(planner);
	else
		group_arm_torso.setPlannerId("SBLkConfigDefault");

	group_arm_torso.setPoseReferenceFrame("base_footprint");
	group_arm_torso.setPoseTarget(goal_pose_base_footprint_frame);
	group_arm_torso.setEndEffectorLink("arm_tool_link");

	ROS_INFO_STREAM("Planning to move " << 
		  group_arm_torso.getEndEffectorLink() << " to a target pose expressed in " <<
		  group_arm_torso.getPlanningFrame());

	group_arm_torso.setMaxVelocityScalingFactor(0.45);

	//set constraint to the joint 5 to avoid flip
	moveit_msgs::JointConstraint jc5;
	jc5.joint_name = "arm_5_joint";
	jc5.position = 2.07;
	jc5.tolerance_above = 0.4;
	jc5.tolerance_below = 0.4;
	jc5.weight = 1.0;
	ROS_INFO_STREAM("Add a constraint to avoid flip");
	
	//set constraint to the joint 2 to avoid head collision
	moveit_msgs::JointConstraint jc2;
	jc2.joint_name = "arm_2_joint";
	jc2.position = 0.25;
	jc2.tolerance_above = 0.35;
	jc2.tolerance_below = 1.25;
	jc2.weight = 0.4;
	ROS_INFO_STREAM("Add a constraint to avoid head collision");
	
	moveit_msgs::Constraints path_constraints;
	path_constraints.joint_constraints.push_back(jc5);
	path_constraints.joint_constraints.push_back(jc2);
	group_arm_torso.setPathConstraints(path_constraints);

	moveit::planning_interface::MoveGroupInterface::Plan my_plan;
	//set maximum time to find a plan
	group_arm_torso.setPlanningTime(8.0);

	//add_constraint(group_arm_torso);
	group_arm_torso.setStartState(*group_arm_torso.getCurrentState());

	bool success = bool(group_arm_torso.plan(my_plan));

	if ( !success )
	  throw std::runtime_error("No plan found");

	ROS_INFO_STREAM("Plan found in " << my_plan.planning_time_ << " seconds");

	// Execute the plan
	ros::Time start = ros::Time::now();

	moveit::planning_interface::MoveItErrorCode e = group_arm_torso.move();
	e = group_arm_torso.move();
	if (!bool(e))
	  throw std::runtime_error("Error executing plan");

	ROS_INFO_STREAM("Motion duration: " << (ros::Time::now() - start).toSec());

	spinner.stop();
}
