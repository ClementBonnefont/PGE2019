#include <ros/ros.h>
#include <ros/package.h>

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>

#include <fstream>
//#include <iostream>

nav_msgs::Path::Ptr path (new nav_msgs::Path);
std::string record_file_path;
const char* record_file_path_ptr;

void convert_odom(const nav_msgs::Odometry::ConstPtr& msg)
{
	std::ofstream record_file (record_file_path_ptr, std::ios_base::app);
	if(record_file.is_open())
	{
		record_file << ros::Time::now();
		record_file << " ";
		record_file << msg->pose.pose.position.x;
		record_file << " ";
		record_file << msg->pose.pose.position.y;
		record_file << " ";
		record_file << msg->pose.pose.position.z;
		record_file << " ";
		record_file << msg->pose.pose.orientation.x;
		record_file << " ";
		record_file << msg->pose.pose.orientation.y;
		record_file << " ";
		record_file << msg->pose.pose.orientation.z;
		record_file << " ";
		record_file << msg->pose.pose.orientation.w;
		record_file << "\n";
		record_file.close();
	}
	else std::cout << "Record file not opened";
}


int main (int argc, char** argv)
{
	ros::init(argc, argv, "odom_to_path_converter");

	if (argc < 3) {ROS_ERROR("Required input arg1: odom_topic, arg2: file_name"); return -1;};

	std::string odometry_topic_name = argv[1], file_name = argv[2];

	ros::NodeHandle node;
	

	std::string package_path = ros::package::getPath("path_printing");
	record_file_path = package_path + "/record/" + file_name;
	std::cout << record_file_path << std::endl;

	//strcpy(record_file_path_ptr, record_file_path.c_str());
	record_file_path_ptr = record_file_path.c_str();

	ros::Subscriber sub = node.subscribe(odometry_topic_name,10, &convert_odom);

	ros::spin();

	return 0;
}