// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <visualization_msgs/Marker.h>

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

namespace tiago_follow_path
{
    class Follow_path_demo
    {
    public:
        void go_to_point_base_footprint(move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame, MoveBaseClient& ac);
        geometry_msgs::PoseStamped transform(geometry_msgs::PoseStamped source_frame, std::string target_frameid);
	void show_markers(ros::Publisher marker_pub, int nb_pts_cercle, float rayon_cercle_base_footprint);
	geometry_msgs::PoseStamped next_base_footprint(std::string num_next_plot, geometry_msgs::PoseStamped pt1);
	void moves_plot(int num_plot, MoveBaseClient& ac, move_base_msgs::MoveBaseGoal base_goal, Move_tiago_arm tiago_arm, geometry_msgs::PoseStamped pt1, geometry_msgs::PoseStamped pt2);
	void follow_path();
    };

}
