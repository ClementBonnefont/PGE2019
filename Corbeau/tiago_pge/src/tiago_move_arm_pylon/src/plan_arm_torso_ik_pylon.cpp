#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>

using namespace tiago_move_arm_pylon;

float Move_tiago_arm::degree_to_radian(float degree) {
  return (degree*M_PI)/180.0;
}

void Move_tiago_arm::add_collision() {
  //Add obstacle
  moveit_msgs::CollisionObject collision_object;
  collision_object.header.frame_id = "pylon";

  /* The id of the object is used to identify it. */
  collision_object.id = "box1";

  /* Define a box to add to the world. */
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.CYLINDER;
  primitive.dimensions.resize(2);
  primitive.dimensions[primitive.CYLINDER_HEIGHT] = 5;
  primitive.dimensions[primitive.CYLINDER_RADIUS] = 0.1;

  /* A pose for the box (specified relative to frame_id) */
  geometry_msgs::Pose box_pose;
  box_pose.orientation.w = 1.0;
  box_pose.position.x =  1;
  box_pose.position.y = 1;
  box_pose.position.z =  0;

  collision_object.primitives.push_back(primitive);
  collision_object.primitive_poses.push_back(box_pose);
  collision_object.operation = collision_object.ADD;

  std::vector<moveit_msgs::CollisionObject> collision_objects;
  collision_objects.push_back(collision_object);

  ROS_INFO("Add an object into the world");
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  planning_scene_interface.addCollisionObjects(collision_objects);

  /* Sleep so we have time to see the object in RViz */
  sleep(2.0);
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
