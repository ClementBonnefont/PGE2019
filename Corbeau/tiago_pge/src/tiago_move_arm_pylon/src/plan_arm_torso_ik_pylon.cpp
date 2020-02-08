#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>

using namespace tiago_move_arm_pylon;

float Move_tiago_arm::degree_to_radian(float degree) {
  return (degree*M_PI)/180.0;
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
  
  ros::AsyncSpinner spinner(1);
  spinner.start();

  //select group of joints
  moveit::planning_interface::MoveGroupInterface group_arm_torso("arm_torso");

  // Attach system aptere box to the TIAGo EE
  add_aptere();

  //choose your preferred planner
  group_arm_torso.setPlannerId("SBLkConfigDefault");
  group_arm_torso.setPoseReferenceFrame("base_footprint");
  group_arm_torso.setPoseTarget(goal_pose_base_footprint_frame);

  ROS_INFO_STREAM("Planning to move " << 
                  group_arm_torso.getEndEffectorLink() << " to a target pose expressed in " <<
                  group_arm_torso.getPlanningFrame());

  group_arm_torso.setStartStateToCurrentState();
  group_arm_torso.setMaxVelocityScalingFactor(1.0);

  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  //set maximum time to find a plan
  group_arm_torso.setPlanningTime(10.0);
  group_arm_torso.setStartState(*group_arm_torso.getCurrentState());

  bool success = bool(group_arm_torso.plan(my_plan));

  if ( !success )
    throw std::runtime_error("No plan found");

  ROS_INFO_STREAM("Plan found in " << my_plan.planning_time_ << " seconds");

  // Execute the plan
  ros::Time start = ros::Time::now();

  moveit::planning_interface::MoveItErrorCode e = group_arm_torso.move();
  if (!bool(e))
    throw std::runtime_error("Error executing plan");

  ROS_INFO_STREAM("Motion duration: " << (ros::Time::now() - start).toSec());

  spinner.stop();
}

void Move_tiago_arm::add_aptere(){
  moveit_msgs::AttachedCollisionObject attached_object;
  attached_object.link_name = "gripper_grasping_frame";
  /* The header must contain a valid TF frame*/
  attached_object.object.header.frame_id = "gripper_grasping_frame";
  /* The id of the object */
  attached_object.object.id = "sys_aptere_box";
  attached_object.object.header.stamp = ros::Time::now();

  /* A default pose */
  geometry_msgs::Pose pose;
  pose.orientation.w = 1.0;

  /* Define a box to be attached */
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.BOX;
  primitive.dimensions.resize(3);
  primitive.dimensions[0] = 0.19;
  primitive.dimensions[1] = 0.19;
  primitive.dimensions[2] = 0.19;

  attached_object.object.primitives.push_back(primitive);
  attached_object.object.primitive_poses.push_back(pose);
  attached_object.object.operation = attached_object.object.ADD;

  // Links touched by the system aptere box
  attached_object.touch_links = std::vector<std::string>{ "gripper_grasping_frame", "gripper_left_finger_link", "gripper_right_finger_link", "gripper_link", "gripper_tool_link" };

  ros::NodeHandle nh("~");
  ros::Publisher publisher = nh.advertise<moveit_msgs::AttachedCollisionObject>("/attached_collision_object", 1);
    while(publisher.getNumSubscribers() < 1)
    {
      ROS_INFO_STREAM("Waiting for /attached_collision_object topic");
      ros::WallDuration sleep_t(0.5);
      sleep_t.sleep();
    }
    publisher.publish(attached_object);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "plan_arm_torso_ik_pylon");

	if ( argc < 7 )
	{
		ROS_INFO(" ");
		ROS_INFO("\tUsage:");
		ROS_INFO(" ");
		ROS_INFO("\trosrun tiago_move_arm_pylon plan_arm_torso_ik_pylon x y z r p y");
		ROS_INFO(" ");
		ROS_INFO("\twhere the list of arguments specify the target pose of /arm_tool_link expressed in /base_footprint");
		ROS_INFO(" ");
		return EXIT_FAILURE;
	}

	Move_tiago_arm tiago_arm;

	geometry_msgs::PoseStamped goal_pose_pylon_frame;
	goal_pose_pylon_frame.header.frame_id = "base_footprint";
	goal_pose_pylon_frame.pose.position.x = atof(argv[1]);
	goal_pose_pylon_frame.pose.position.y = atof(argv[2]);
	goal_pose_pylon_frame.pose.position.z = atof(argv[3]);
	goal_pose_pylon_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(atof(argv[4])), tiago_arm.degree_to_radian(atof(argv[5])), tiago_arm.degree_to_radian(atof(argv[6])));

	tiago_arm.go_to_point_arm_tool_link(goal_pose_pylon_frame);

  return EXIT_SUCCESS;
}