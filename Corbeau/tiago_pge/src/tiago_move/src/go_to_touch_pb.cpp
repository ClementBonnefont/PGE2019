// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Std C++ headers
#include <string>
#include <vector>
#include <map>
#include <math.h> 

// Own pkgs
#include <tiago_move_arm_pylon/plan_arm_torso_ik_pylon.h>
#include <zone_ground_pylon/generate_circular_poi.h>

using namespace tiago_move_arm_pylon;
using namespace zone_ground_pylon;

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

geometry_msgs::PoseStamped transform(std::string source_frameid, std::string target_frameid, 
                                      geometry_msgs::PoseStamped source_frame) {
  ros::NodeHandle nh("~");
  double rate_hz;
  nh.param("rate", rate_hz, 1.0);
  ros::Rate rate(rate_hz);
  tf::TransformListener tf;
  geometry_msgs::PoseStamped goal_pose_frame;

  tf.waitForTransform(target_frameid, source_frameid, ros::Time(), ros::Duration(1.0));
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


int main(int argc, char** argv)
{
  ros::init(argc, argv, "plan_arm_torso_ik_pylon");

  Move_tiago_arm tiago_arm;
  Generate_circular_poi gen_poi;
  MoveBaseClient ac("move_base", true);

  //map_pose
  geometry_msgs::PoseStamped map_frame;
  map_frame.header.frame_id = "map";
  map_frame.pose.position.x = 0;
  map_frame.pose.position.y = 0;
  map_frame.pose.position.z = 0;
  map_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);


  geometry_msgs::PoseStamped pylon_in_map_frame = transform("pylon", "map", map_frame);
  
  //generation d'un cercle 
  std::vector <std::vector<double> > cercle = gen_poi.generate_circle(60, 2, 0, 0, 0);
  ROS_INFO_STREAM("GENERATION DU CERCLE FAITES");
  geometry_msgs::PoseStamped arm_goal_pose;
  arm_goal_pose.header.frame_id = "pylon";
  arm_goal_pose.pose.position.x = 0.3;
  arm_goal_pose.pose.position.y = 0.7;
  arm_goal_pose.pose.position.z = 0.5;
  arm_goal_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);
  ROS_INFO_STREAM("Merdouille");
  //base_footprint
  geometry_msgs::PoseStamped base_footprint_frame;
  base_footprint_frame.header.frame_id = "base_footprint";
  base_footprint_frame.pose.position.x = 0;
  base_footprint_frame.pose.position.y = 0;
  base_footprint_frame.pose.position.z = 0;
  base_footprint_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);


  // genere les pts de passage
  geometry_msgs::PoseStamped base_footprint_pylon_frame = transform("base_footprint", "pylon", base_footprint_frame);

  //position courante base_footprint
  std::array<double,3> pointOrigine = { { base_footprint_pylon_frame.pose.position.x,
                                          base_footprint_pylon_frame.pose.position.y,
                                          base_footprint_pylon_frame.pose.position.z} };

  // position voulue par le bras
  std::array<double,3> pointGoal    = { { arm_goal_pose.pose.position.x,
                                          arm_goal_pose.pose.position.y,
                                          arm_goal_pose.pose.position.z} };

  ROS_INFO_STREAM("/* Avant génération cercle */");
  
  std::vector <std::vector<double> > chemin = gen_poi.generate_traj_2pt_from_circle(cercle,pointOrigine,pointGoal);

   ROS_INFO_STREAM("/* Après génération cercle */");

  move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame;
  base_goal_pose_pylon_frame.target_pose.header.frame_id = "pylon";

  for(int i = 0; i < chemin[0].size(); i++) {
    base_goal_pose_pylon_frame.target_pose.pose.position.x = chemin[0][i];
    base_goal_pose_pylon_frame.target_pose.pose.position.y = chemin[1][i];
    base_goal_pose_pylon_frame.target_pose.pose.position.z = chemin[2][i];

    // all / pylon_frame
    float y_robot = base_goal_pose_pylon_frame.target_pose.pose.position.y;
    float x_robot = base_goal_pose_pylon_frame.target_pose.pose.position.x;
    float theta_deg = atan(y_robot/x_robot); 
    
    base_goal_pose_pylon_frame.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(
        tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(0), tiago_arm.degree_to_radian(theta_deg));
    go_to_point_base_footprint(base_goal_pose_pylon_frame,ac);
    ac.waitForResult();
  }
  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose);
}
