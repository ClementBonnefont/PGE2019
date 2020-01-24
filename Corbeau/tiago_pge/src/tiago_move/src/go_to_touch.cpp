// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>
#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Std C++ headers
#include <string>
#include <vector>
#include <map>

using namespace tiago_move_arm_pylon;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void go_to_point_base_footprint(move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame, MoveBaseClient& ac) {
  // ros::NodeHandle nh("~");
  // ros::Publisher base_pub = nh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);

  // while(base_pub.getNumSubscribers() == 0) {}
  // base_pub.publish(base_goal_pose_pylon_frame);


  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  ROS_INFO("Sending goal");
  ac.sendGoal(base_goal_pose_pylon_frame);
}

void pylonPoseCallback(const geometry_msgs::PoseStamped& msg)
{
  ROS_INFO("I heard something");
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "plan_arm_torso_ik_pylon");

  // if ( argc < 7 )
  // {
  //   ROS_INFO(" ");
  //   ROS_INFO("\tUsage:");
  //   ROS_INFO(" ");
  //   ROS_INFO("\trosrun tiago_move_arm_pylon plan_arm_torso_ik_pylon  x y z  r p y");
  //   ROS_INFO(" ");
  //   ROS_INFO("\twhere the list of arguments specify the target pose of /arm_tool_link expressed in /base_footprint");
  //   ROS_INFO(" ");
  //   return EXIT_FAILURE;
  // }

  Move_tiago_arm tiago_arm;
  MoveBaseClient ac("move_base", true);

  ros::NodeHandle nh("~");
  ros::Subscriber sub = nh.subscribe("/aruco_single/pose", 1000, pylonPoseCallback);

  move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame0;
  base_goal_pose_pylon_frame0.target_pose.header.frame_id = "pylon";
  base_goal_pose_pylon_frame0.target_pose.pose.position.x = 0;
  base_goal_pose_pylon_frame0.target_pose.pose.position.y = -1;
  base_goal_pose_pylon_frame0.target_pose.pose.position.z = 0;
  base_goal_pose_pylon_frame0.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                              tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(0));

  move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame1;
  base_goal_pose_pylon_frame1.target_pose.header.frame_id = "pylon";
  base_goal_pose_pylon_frame1.target_pose.pose.position.x = 1;
  base_goal_pose_pylon_frame1.target_pose.pose.position.y = 0;
  base_goal_pose_pylon_frame1.target_pose.pose.position.z = 0;
  base_goal_pose_pylon_frame1.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                              tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(90));

  move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame2;
  base_goal_pose_pylon_frame2.target_pose.header.frame_id = "pylon";
  base_goal_pose_pylon_frame2.target_pose.pose.position.x = 0;
  base_goal_pose_pylon_frame2.target_pose.pose.position.y = 1;
  base_goal_pose_pylon_frame2.target_pose.pose.position.z = 0;
  base_goal_pose_pylon_frame2.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                              tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(180));

  move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame3;
  base_goal_pose_pylon_frame3.target_pose.header.frame_id = "pylon";
  base_goal_pose_pylon_frame3.target_pose.pose.position.x = -1;
  base_goal_pose_pylon_frame3.target_pose.pose.position.y = 0;
  base_goal_pose_pylon_frame3.target_pose.pose.position.z = 0;
  base_goal_pose_pylon_frame3.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                              tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(270));


  geometry_msgs::PoseStamped arm_goal_pose0;
  arm_goal_pose0.header.frame_id = "base_footprint";
  arm_goal_pose0.pose.position.x = 0.3;
  arm_goal_pose0.pose.position.y = 0.7;
  arm_goal_pose0.pose.position.z = 1.3;
  arm_goal_pose0.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                            tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(90));

  geometry_msgs::PoseStamped arm_goal_pose1;
  arm_goal_pose1.header.frame_id = "base_footprint";
  arm_goal_pose1.pose.position.x = 0.3;
  arm_goal_pose1.pose.position.y = 0.7;
  arm_goal_pose1.pose.position.z = 1.0;
  arm_goal_pose1.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                            tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(90));

  geometry_msgs::PoseStamped arm_goal_pose2;
  arm_goal_pose2.header.frame_id = "base_footprint";
  arm_goal_pose2.pose.position.x = 0.3;
  arm_goal_pose2.pose.position.y = 0.7;
  arm_goal_pose2.pose.position.z = 0.8;
  arm_goal_pose2.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                            tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(90));

  geometry_msgs::PoseStamped arm_goal_pose3;
  arm_goal_pose3.header.frame_id = "base_footprint";
  arm_goal_pose3.pose.position.x = 0.3;
  arm_goal_pose3.pose.position.y = 0.7;
  arm_goal_pose3.pose.position.z = 0.5;
  arm_goal_pose3.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), 
                                            tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(90));
  
  go_to_point_base_footprint(base_goal_pose_pylon_frame0,ac);
  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose0);
  ac.waitForResult();
  go_to_point_base_footprint(base_goal_pose_pylon_frame1,ac);
  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose1);
  ac.waitForResult();
  go_to_point_base_footprint(base_goal_pose_pylon_frame2,ac);
  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose2);
  ac.waitForResult();
  go_to_point_base_footprint(base_goal_pose_pylon_frame3,ac);
  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose3);
  ac.waitForResult();
  go_to_point_base_footprint(base_goal_pose_pylon_frame0,ac);
  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose0);

  ros::spin();
}


