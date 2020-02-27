// ROS headers
#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <visualization_msgs/Marker.h>

#include <vector>
#include <string>
#include <math.h>

#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>

#include <zone_ground_pylon/generate_circular_poi.h>


#define __NB_POINTS_BASE_FOOTPRINT__ 8


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

int main(int argc, char **argv)
{
/*---------- INITIALISATION DU NOEUD ------------------------------*/
ros::init(argc, argv, "plot_broadcaster");
ros::NodeHandle node;

ros::Publisher marker_pub = node.advertise<visualization_msgs::Marker>("visualization_marker", 1); 

/*---------- LISTE DE POINTS D APPROCHE BASE_FOOTPRINT -----------*/

  zone_ground_pylon::Generate_circular_poi gen_poi;

  // definition de la forme du marker de passage 
  uint32_t formes = visualization_msgs::Marker::CUBE_LIST;

  visualization_msgs::Marker pointsApprocheBaseFootprint;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  pointsApprocheBaseFootprint.header.frame_id = "/pylon";
  pointsApprocheBaseFootprint.header.stamp = ros::Time::now();

  // Set du namespace et id du marker.  ID unique
  // Attention si le meme namespace et id sont utilise, il y a ecrasement du precedent
  pointsApprocheBaseFootprint.ns = "approche_to_follow_path";
  pointsApprocheBaseFootprint.id = 1;
  // set le type de marqueur a vec la forme 
  pointsApprocheBaseFootprint.type = formes; 

  // ajout du marqueur sous le format action 
  pointsApprocheBaseFootprint.action = visualization_msgs::Marker::ADD;

  //setup de la taille du marker sur chaque axe 
  pointsApprocheBaseFootprint.scale.x = 0.15;
  pointsApprocheBaseFootprint.scale.y = 0.15; 
  pointsApprocheBaseFootprint.scale.z = 0.025;
  // de la couleur (entre 0 et 1)
  pointsApprocheBaseFootprint.color.r = 0.0f;
  pointsApprocheBaseFootprint.color.g = 1.0f;
  pointsApprocheBaseFootprint.color.b = 0.0f; 
  pointsApprocheBaseFootprint.color.a = 1.0; // couche alpha, si a 0 --> 100% de transparence  

  // set de la duree du marker
  pointsApprocheBaseFootprint.lifetime = ros::Duration();

    //map_pose
  geometry_msgs::PoseStamped map_frame;
  map_frame.header.frame_id = "map";
  map_frame.pose.position.x = 0;
  map_frame.pose.position.y = 0;
  map_frame.pose.position.z = 0;
  map_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);


  geometry_msgs::PoseStamped pylon_in_map_frame = transform(map_frame, "pylon");
  
  //generation d'un cercle 
  ROS_INFO_STREAM("GENERATION DU CERCLE EN COURS ...");
  std::vector <std::vector<double> > cercle = gen_poi.generate_circle(__NB_POINTS_BASE_FOOTPRINT__, 1.70, 0.0, 0.0, 0.0, 0.0);
 

  // creation de la liste de cubes 
  //positionnement des markers dans le monde 
  for(uint32_t i = 0; i < __NB_POINTS_BASE_FOOTPRINT__; ++i){
    geometry_msgs::Point p;
    p.x = cercle[0][i];
    p.y = cercle[1][i];
    p.z = 0;
    pointsApprocheBaseFootprint.points.push_back(p);
  }
  ROS_INFO_STREAM("GENERATION DU CERCLE FAITE");

    // publication des markers 
  while (marker_pub.getNumSubscribers() < 1){
    if (!ros::ok()) {
      return 0;
    }
    ROS_WARN_ONCE("Dans Rviz ajouter un marker pour visualiser les points");
    sleep(1);
  }
  marker_pub.publish(pointsApprocheBaseFootprint); //publication de la liste des points de passage

  /*--------Publication des frames correspondants aux plots -----------*/

    tf::TransformBroadcaster br;
    std::array<tf::Transform, __NB_POINTS_BASE_FOOTPRINT__> ensembleFramePlot;

    int iPoint;

    ros::Rate rate(100); //100Hz
    while(node.ok()){

        for(iPoint = 0 ; iPoint < __NB_POINTS_BASE_FOOTPRINT__ ; iPoint++){
            ensembleFramePlot[iPoint].setOrigin(tf::Vector3(cercle[0][iPoint],cercle[1][iPoint],0));
            ensembleFramePlot[iPoint].setRotation(tf::Quaternion(0,0,atan2(cercle[1][iPoint],cercle[0][iPoint]) + (M_PI/2) + (M_PI/10))); //Fait déjà la conversion rawpitchyall
            br.sendTransform(tf::StampedTransform(ensembleFramePlot[iPoint],ros::Time::now(),"pylon","plot_" + std::to_string(iPoint)));
        }

        rate.sleep();
    }


    return 0;
}
