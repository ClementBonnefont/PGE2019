#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "pylon_world_tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  

  ros::Rate rate(10.0); //Hertz
  while (node.ok()){
    transform.setOrigin( tf::Vector3(0.754517, 5.833130, 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "pylon"));
    rate.sleep();
  }
  return 0;
};
