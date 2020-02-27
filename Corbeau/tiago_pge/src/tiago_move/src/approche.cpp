// ROS headers
#include <ros/ros.h>
#include "std_msgs/String.h"


// MoveIt! headers
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>
#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <ros/topic.h>


// Std C++ headers
#include <string>
#include <vector>
#include <map>
#include <exception>

// Boost headers
#include <boost/shared_ptr.hpp>

// commande à lancé pour lancer "rosrun tf static_transform_publisher -3 -0.5 1 0 1.57 0 map pylon_fake 100"




using namespace tiago_move_arm_pylon;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> arm_control_client;
typedef boost::shared_ptr< arm_control_client>  arm_control_client_Ptr;

bool done = false;



void go_to_point_base_footprint(move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame, MoveBaseClient& ac) {

  while(!ac.waitForServer()){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  ROS_INFO("Sending goal");
  ac.sendGoalAndWait(base_goal_pose_pylon_frame);
}

geometry_msgs::PoseStamped transform(geometry_msgs::PoseStamped source_frame, std::string target_frameid) {
  ros::NodeHandle nh("~");
  double rate_hz;
  nh.param("rate", rate_hz, 1.0);
  ros::Rate rate(rate_hz);
  tf::TransformListener tf;
  geometry_msgs::PoseStamped goal_pose_frame;


  tf.waitForTransform(target_frameid, source_frame.header.frame_id, ros::Time(), ros::Duration(1.0));
   while(goal_pose_frame.header.frame_id != target_frameid)
  {
    try
    {
      //target_frame, stamped_in, stamped_out
      tf.transformPose(target_frameid, source_frame, goal_pose_frame);
    }
    catch(tf::TransformException& ex)
    {
      std::cout << "Failure at "<< ros::Time::now() << std::endl;
      std::cout << "Exception thrown:" << ex.what()<< std::endl;
    }
    rate.sleep();
  }
  return goal_pose_frame;
}

// Create a ROS action client to move TIAGo's arm
void createArmClient(arm_control_client_Ptr& actionClient)
{
  ROS_INFO("Creating action client to arm controller ...");

  actionClient.reset( new arm_control_client("/arm_controller/follow_joint_trajectory") );

  int iterations = 0, max_iterations = 3;
  // Wait for arm controller action server to come up
  while( !actionClient->waitForServer(ros::Duration(2.0)) && ros::ok() && iterations < max_iterations )
  {
    ROS_DEBUG("Waiting for the arm_controller_action server to come up");
    ++iterations;
  }

  if ( iterations == max_iterations )
    throw std::runtime_error("Error in createArmClient: arm controller action server not available");
}

// Generates a simple trajectory with one waypoints to move TIAGo's arm 
void waypoints_arm_goal(control_msgs::FollowJointTrajectoryGoal& goal)
{
  // The joint names, which apply to all waypoints
  goal.trajectory.joint_names.push_back("arm_1_joint");
  goal.trajectory.joint_names.push_back("arm_2_joint");
  goal.trajectory.joint_names.push_back("arm_3_joint");
  goal.trajectory.joint_names.push_back("arm_4_joint");
  goal.trajectory.joint_names.push_back("arm_5_joint");
  goal.trajectory.joint_names.push_back("arm_6_joint");
  goal.trajectory.joint_names.push_back("arm_7_joint");

  // one waypoints in this goal trajectory
  goal.trajectory.points.resize(1);

  // First trajectory point
  // Positions
  int index = 0;
  goal.trajectory.points[index].positions.resize(7);
  goal.trajectory.points[index].positions[0] = 0.2;
  goal.trajectory.points[index].positions[1] = 0.25;
  goal.trajectory.points[index].positions[2] = -1.75;
  goal.trajectory.points[index].positions[3] = 2.20;
  goal.trajectory.points[index].positions[4] = -1.25;
  goal.trajectory.points[index].positions[5] = -0.70;
  goal.trajectory.points[index].positions[6] = -1.60;
  // Velocities
  goal.trajectory.points[index].velocities.resize(7);
  for (int j = 0; j < 7; ++j)
  {
    goal.trajectory.points[index].velocities[j] = 0.4;
  }
  // To be reached 2 second after starting along the trajectory
  goal.trajectory.points[index].time_from_start = ros::Duration(5.0);
}


void ordreAptereApprocheBaseMobile_callback(const std_msgs::String ordre){
  double pas = 0.5; //A METTRE EN PARAM

  MoveBaseClient ac("move_base", true);
  ROS_INFO_STREAM("Reception d'un ordre du système aptère");
  
  //Récupération de la position actuelle de la base mobile
  move_base_msgs::MoveBaseGoal goal_basefootprint_frame;
  goal_basefootprint_frame.target_pose.header.frame_id = "base_footprint";
  goal_basefootprint_frame.target_pose.pose.position.x = pas; // la base mobile avance
  goal_basefootprint_frame.target_pose.pose.position.y = 0;
  goal_basefootprint_frame.target_pose.pose.position.z = 0;

  goal_basefootprint_frame.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0);

  go_to_point_base_footprint(goal_basefootprint_frame,ac);
}

void ordreAptereRecallage_callback(const geometry_msgs::PoseStamped position_haut_pylon){

  tiago_move_arm_pylon::Move_tiago_arm tiago_arm;
  geometry_msgs::PoseStamped goal_arm = position_haut_pylon;

  double distFromTopPylon = 0.20;

  goal_arm.pose.position.x = goal_arm.pose.position.x - distFromTopPylon;

  tiago_arm.go_to_point_arm_tool_link(position_haut_pylon); //TODO A MODIFIER

  ROS_INFO_STREAM("Fin du recalage");

}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "tiago_move");
  ros::NodeHandle n;

  MoveBaseClient ac("move_base", true);

  std::string frame_pylon = "pylon"; // A METTRE EN PARAM
  double distanceFromPylon = 2; // A METTRE EN PARAM

  ///// ---- Déplacement de la base mobile ---- /////

  geometry_msgs::PoseStamped pt_approche_pylon_frame;
  pt_approche_pylon_frame.header.frame_id = frame_pylon;
  pt_approche_pylon_frame.pose.position.x = 0;
  pt_approche_pylon_frame.pose.position.y = 0;
  pt_approche_pylon_frame.pose.position.z = distanceFromPylon;
  pt_approche_pylon_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

  geometry_msgs::PoseStamped pt_approche_basefootprint_frame = transform(pt_approche_pylon_frame, "map");

  pt_approche_basefootprint_frame.pose.position.z = 0; //Projection sur le sol

  //Récupération de la position de l'origine du pylone pour l'orientation
  geometry_msgs::PoseStamped origin_pylon_pylon_frame;
  origin_pylon_pylon_frame.header.frame_id = frame_pylon;
  origin_pylon_pylon_frame.pose.position.x = 0;
  origin_pylon_pylon_frame.pose.position.y = 0;
  origin_pylon_pylon_frame.pose.position.z = 0;
  origin_pylon_pylon_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

  geometry_msgs::PoseStamped origin_pylon_basefootprint_frame = transform(origin_pylon_pylon_frame,"map");

  double angleRotation = atan2(origin_pylon_basefootprint_frame.pose.position.y - pt_approche_basefootprint_frame.pose.position.y
                              ,origin_pylon_basefootprint_frame.pose.position.x - pt_approche_basefootprint_frame.pose.position.x); //Tangeante + demi-tour pour être trouver orienté vers le pylone

  move_base_msgs::MoveBaseGoal goal_map_frame;
  goal_map_frame.target_pose.header.frame_id = pt_approche_basefootprint_frame.header.frame_id;
  goal_map_frame.target_pose.pose.position.x = pt_approche_basefootprint_frame.pose.position.x;
  goal_map_frame.target_pose.pose.position.y = pt_approche_basefootprint_frame.pose.position.y;
  goal_map_frame.target_pose.pose.position.z = pt_approche_basefootprint_frame.pose.position.z;

  goal_map_frame.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,angleRotation);

  go_to_point_base_footprint(goal_map_frame,ac);

  ///// ---- Déplacement initial du bras ---- ///// ~ Utilisation de l'action interface

  // Create an arm controller action client to move the TIAGo's arm
  arm_control_client_Ptr ArmClient;
  createArmClient(ArmClient);

  // Generates the goal for the TIAGo's arm
  control_msgs::FollowJointTrajectoryGoal arm_goal;
  waypoints_arm_goal(arm_goal);

  // Sends the command to start the given trajectory 1s from now
  arm_goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);
  ArmClient->sendGoal(arm_goal);
  ROS_INFO_STREAM("Goal envoye");

  ///// ---- Lancement des boules d'écoute des topics ---- ////

  //Lancement de la boucle d'écoute pour l'approche de la base mobile
  ros::Subscriber subOrder = n.subscribe("/aptere/approche/ordreApproche", 100, ordreAptereApprocheBaseMobile_callback);

  //Récupération des points de passage 

  /// !!!
  
  //Lancement de la boucle d'écoute pour le recalage de l'OT

  //Pour le test, lancer 
  // rostopic pub /aptere/approche/ordreRecalage geometry_msgs/PoseStamped '{header: {stamp: now, frame_id: "arm_tool_link"}, pose: {position: {x: 0.3 , y: 0.0, z: 0.0}, orientation: {w: 1.0}}}'
  ros::Subscriber subRecalage = n.subscribe("/aptere/approche/ordreRecalage", 1000, ordreAptereRecallage_callback);


ros::Rate r(10); // 10 hz
while (ros::ok())
{
  ros::spinOnce();
  r.sleep();
}

 
	return 0;
}
