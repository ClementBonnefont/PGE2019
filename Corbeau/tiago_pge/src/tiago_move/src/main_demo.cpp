#include <tiago_approche/approche.h>

using namespace tiago_follow_path;
using namespace tiago_approche;

std::string value_msg = "";

void ihm_msgs_callback(const std_msgs::String::ConstPtr& msg) {
	value_msg = msg->data.c_str();
	ROS_INFO_STREAM(value_msg);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "tiago_move");
	ros::NodeHandle nh;	

	Follow_path_demo tiago_follow_path;
	Approche_demo tiago_approche;

	ros::Subscriber subOrder = nh.subscribe("/aptere/approche/ordreApproche", 100, Approche_demo::ordreAptereApprocheBaseMobile_callback);

	ros::Subscriber subRecalage = nh.subscribe("/aptere/approche/ordreRecalage", 1000, Approche_demo::ordreAptereRecallage_callback);

	//Subscribe to a topic from the IHM
	ros::Subscriber ihm_sub = nh.subscribe("/TiagoDemo", 100, ihm_msgs_callback);

	tiago_follow_path.follow_path();
	tiago_approche.approche();

	if(value_msg != "")
		tiago_follow_path.follow_path();

	ros::spin();

	return 0;
}
