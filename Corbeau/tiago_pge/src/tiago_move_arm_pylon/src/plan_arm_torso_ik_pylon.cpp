// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <moveit/move_group_interface/move_group_interface.h>
#include <tf/transform_listener.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

// Std C++ headers
#include <string>
#include <vector>
#include <map>

#define M_PI 3.14159265358979323846

float degree_to_radian(float degree) {
  return (degree*M_PI)/180.0;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "plan_arm_torso_ik");

  if ( argc < 7 )
  {
    ROS_INFO(" ");
    ROS_INFO("\tUsage:");
    ROS_INFO(" ");
    ROS_INFO("\trosrun tiago_moveit_tutorial plan_arm_torso_ik  x y z  r p y");
    ROS_INFO(" ");
    ROS_INFO("\twhere the list of arguments specify the target pose of /arm_tool_link expressed in /base_footprint");
    ROS_INFO(" ");
    return EXIT_FAILURE;
  }

  ros::NodeHandle nh("~");
  double rate_hz;
  nh.param("rate", rate_hz, 1.0);
  ros::Rate rate(rate_hz);
  tf::TransformListener tf;
  std::string source_frameid = "pylon";
  std::string target_frameid = "base_footprint"; 
  geometry_msgs::PoseStamped goal_pose;
  geometry_msgs::PoseStamped goal_pose_pylon_frame;
  goal_pose_pylon_frame.header.frame_id = source_frameid;
  goal_pose_pylon_frame.pose.position.x = atof(argv[1]);
  goal_pose_pylon_frame.pose.position.y = atof(argv[2]);
  goal_pose_pylon_frame.pose.position.z = atof(argv[3]);
  goal_pose_pylon_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(degree_to_radian(atof(argv[4])), degree_to_radian(atof(argv[5])), degree_to_radian(atof(argv[6])));

  
  tf.waitForTransform(target_frameid, source_frameid, ros::Time(), ros::Duration(1.0));
   while(goal_pose.header.frame_id != target_frameid)
  {
    try
    {
      tf.transformPose(target_frameid, goal_pose_pylon_frame, goal_pose);
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

  std::vector<std::string> torso_arm_joint_names;
  //select group of joints
  moveit::planning_interface::MoveGroupInterface group_arm_torso("arm_torso");
  //choose your preferred planner
  group_arm_torso.setPlannerId("SBLkConfigDefault");
  group_arm_torso.setPoseReferenceFrame("base_footprint");
  group_arm_torso.setPoseTarget(goal_pose);

  ROS_INFO_STREAM("Planning to move " <<
                  group_arm_torso.getEndEffectorLink() << " to a target pose expressed in " <<
                  group_arm_torso.getPlanningFrame());

  group_arm_torso.setStartStateToCurrentState();
  group_arm_torso.setMaxVelocityScalingFactor(1.0);

  //Add obstacle
  //define the pylon cylinder
  moveit_msgs::CollisionObject pylon_cylinder;
  pylon_cylinder.header.frame_id = "pylon";

  /* The id of the object is used to identify it. */
  pylon_cylinder.id = "pylon_cylinder";

  /* Define the cylinder to add to the world. */
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.CYLINDER;
  primitive.dimensions.resize(2);
  primitive.dimensions[0] = 110;
  primitive.dimensions[1] = 30;

  /* A pose for the box (specified relative to frame_id) */
  geometry_msgs::Pose box_pose;
  box_pose.orientation.w = 0;
  box_pose.position.x = 0;
  box_pose.position.y = 0;
  box_pose.position.z = 0;

  pylon_cylinder.primitives.push_back(primitive);
  pylon_cylinder.primitive_poses.push_back(box_pose);
  pylon_cylinder.operation = pylon_cylinder.ADD;

  std::vector<moveit_msgs::CollisionObject> pylon_cylinders;
  pylon_cylinders.push_back(pylon_cylinder);
  
  //Now, let’s add the collision object into the world
  ROS_INFO("Add an object into the world");
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  planning_scene_interface.addCollisionObjects(pylon_cylinders);

  /* Sleep so we have time to see the object in RViz */
  sleep(2.0);

  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  //set maximum time to find a plan
  group_arm_torso.setPlanningTime(10.0);
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

  return EXIT_SUCCESS;

}