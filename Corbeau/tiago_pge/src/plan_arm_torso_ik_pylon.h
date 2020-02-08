// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <moveit/move_group_interface/move_group_interface.h>
#include <tf/transform_listener.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/AttachedCollisionObject.h>

// Std C++ headers
#include <string>
#include <vector>
#include <map>

#define M_PI 3.14159265358979323846

namespace tiago_move_arm_pylon
{
    class Move_tiago_arm
    {
    public:
        void go_to_point_arm_tool_link(geometry_msgs::PoseStamped goal_pose_pylon_frame);
        float degree_to_radian(float degree);
        void add_aptere(); 
    };

}