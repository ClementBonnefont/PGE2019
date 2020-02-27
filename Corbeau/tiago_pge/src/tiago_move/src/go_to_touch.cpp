// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>
#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>

// Std C++ headers
#include <string>
#include <vector>
#include <map>

using namespace tiago_move_arm_pylon;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void go_to_point_base_footprint(move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame, MoveBaseClient& ac) {
  while(!ac.waitForServer()){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  ROS_INFO("Sending goal");
  ac.sendGoalAndWait(base_goal_pose_pylon_frame);
}

void pylonPoseCallback(const geometry_msgs::PoseStamped& msg)
{
  ROS_INFO("I heard something");
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "tiago_move");

	Move_tiago_arm tiago_arm;

	MoveBaseClient ac("move_base", true);
	//tiago_arm.add_aptere();
	geometry_msgs::PoseStamped arm_goal_pose;
	arm_goal_pose.header.frame_id = "pylon";
	arm_goal_pose.pose.position.x = -0.1;
	arm_goal_pose.pose.position.y = 0.3;
	arm_goal_pose.pose.position.z = 0.832;
	arm_goal_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0.0), tiago_arm.degree_to_radian(0.0), tiago_arm.degree_to_radian(0));

	move_base_msgs::MoveBaseGoal base_goal_close;
	base_goal_close.target_pose.header.frame_id = "pylon";
	base_goal_close.target_pose.pose.position.x = -0.72;
	base_goal_close.target_pose.pose.position.y = 0;
	base_goal_close.target_pose.pose.position.z = 0;
	base_goal_close.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(0));

	move_base_msgs::MoveBaseGoal base_goal_far;
	base_goal_far.target_pose.header.frame_id = "pylon";
	base_goal_far.target_pose.pose.position.x = -1.5;
	base_goal_far.target_pose.pose.position.y = 0;
	base_goal_far.target_pose.pose.position.z = 0;
	base_goal_far.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(0));

	//ROS_INFO_STREAM("GO FAR");
	//go_to_point_base_footprint(base_goal_far,ac);
	ROS_INFO_STREAM("GO CLOSE");
	go_to_point_base_footprint(base_goal_close,ac);
	
	ROS_INFO_STREAM("MOVE ARM");
	tiago_arm.go_to_point_arm_tool_link(arm_goal_pose);
	arm_goal_pose.pose.position.y = -0.3;
	tiago_arm.go_to_point_arm_tool_link(arm_goal_pose);
	
	ros::shutdown();
	return 0;
}


