#include <ros/ros.h>

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>


nav_msgs::Path::Ptr path (new nav_msgs::Path);

void convert_odom(const nav_msgs::Odometry::ConstPtr& msg)
{
	geometry_msgs::PoseStamped new_pose;

	//Construction of the new pose
	new_pose.header = msg->header;
	new_pose.pose = msg->pose.pose;

	//Build of the path
	path->header = msg->header;
	path->poses.push_back(new_pose);
}


int main (int argc, char** argv)
{
	ros::init(argc, argv, "odom_to_path_converter");

	if (argc < 3) {ROS_ERROR("Required input arg1: odom_topic, arg2: path_topic"); return -1;};

	std::string odometry_topic_name = argv[1], path_topic_name = argv[2];

	ros::NodeHandle node;
	ros::Subscriber sub = node.subscribe(odometry_topic_name,10, &convert_odom);

	ros::Publisher pub = node.advertise<nav_msgs::Path>(path_topic_name,1);

	while(ros::ok())
	{
		pub.publish(path);

		ros::spinOnce();
	}

	return 0;
}