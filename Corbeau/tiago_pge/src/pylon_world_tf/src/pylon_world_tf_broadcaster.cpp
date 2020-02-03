#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

tf::Transform transform;
int cpt_passage = 0;

void pylonPoseCallback(const geometry_msgs::PoseStamped& msg)
{
	if(cpt_passage < 10) {
		transform.setOrigin(tf::Vector3(msg.pose.position.x, msg.pose.position.y, msg.pose.position.z));
		transform.setRotation(tf::Quaternion(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w));
		cpt_passage++;
	}
}

int main(int argc, char** argv){
  ros::init(argc, argv, "pylon_world_tf_broadcaster");
  ros::NodeHandle nh("~");
  tf::TransformBroadcaster br;
	ros::Subscriber sub = nh.subscribe("/aruco_single/pose", 100, pylonPoseCallback);
	transform.setOrigin(tf::Vector3(-1, -1, -1));
	transform.setRotation(tf::Quaternion(-1, -1, -1, -1));
  
  ros::Rate rate(10.0); //Hertz
  while (nh.ok()){
  	if(cpt_passage > 9)
    	br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "pylon"));
    ros::spinOnce();
    rate.sleep();
  }
  return 0;
};
