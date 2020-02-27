// ROS headers
#include <ros/ros.h>
#include "std_msgs/String.h"


// MoveIt! headers
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>
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

// Own pkg
#include <tiago_follow_path/follow_path.h>


using namespace tiago_move_arm_pylon;
using namespace tiago_follow_path;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> arm_control_client;
typedef boost::shared_ptr< arm_control_client>  arm_control_client_Ptr;

namespace tiago_approche
{
    class Approche_demo
    {
    public:
        void createArmClient(arm_control_client_Ptr& actionClient);
	void waypoints_arm_goal(control_msgs::FollowJointTrajectoryGoal& goal);
	static void ordreAptereApprocheBaseMobile_callback(const std_msgs::String ordre);
	static void ordreAptereRecallage_callback(const geometry_msgs::PoseStamped position_haut_pylon);
	void approche();
    };

}
