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
#include <tiago_move_arm_visu/CollisionBox.h>

using namespace tiago_move_arm_pylon;
using namespace zone_ground_pylon;

// define exemple des points pour une trajectoire 
#define __NB_POINTS_BASE_FOOTPRINT__ 8
#define __NB_POINTS_PATH__ 16


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


int main(int argc, char** argv)
{
  ros::init(argc, argv, "plan_arm_torso_ik_pylon");

  Move_tiago_arm tiago_arm;
  Generate_circular_poi gen_poi;
  MoveBaseClient ac("move_base", true);


  ros::NodeHandle n; // node hadler et publisher pour l'affichage des points de passage du bras 
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1); 
  // CHANGER LE NOM DU PUBLISHER POUR FAIRE UN AFFICHAGE PAR COUCHE DES POINTS 


  /*---------- LISTE DE POINTS DE PASSAGE -----------*/

  // definition de la forme du marker de passage 
  uint32_t formes = visualization_msgs::Marker::SPHERE_LIST;

  visualization_msgs::Marker pointsPassage;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  pointsPassage.header.frame_id = "/pylon";
  pointsPassage.header.stamp = ros::Time::now();

  // Set du namespace et id du marker.  ID unique
  // Attention si le meme namespace et id sont utilise, il y a ecrasement du precedent
  pointsPassage.ns = "follow_path";
  pointsPassage.id = 0;
  // set le type de marqueur a vec la forme 
  pointsPassage.type = formes; 

  // ajout du marqueur sous le format action 
  pointsPassage.action = visualization_msgs::Marker::ADD;

  //setup de la taille du marker sur chaque axe 
  pointsPassage.scale.x = 0.05;
  pointsPassage.scale.y = 0.05; 
  pointsPassage.scale.z = 0.05;
  // de la couleur (entre 0 et 1)
  pointsPassage.color.r = 0.0f;
  pointsPassage.color.g = 0.0f;
  pointsPassage.color.b = 1.0f; 
  pointsPassage.color.a = 1.0; // couche alpha, si a 0 --> 100% de transparence  

  // set de la duree du marker
  pointsPassage.lifetime = ros::Duration();

  /*---------- LISTE DE POINTS D APPROCHE BASE_FOOTPRINT -----------*/

  // definition de la forme du marker de passage 
  formes = visualization_msgs::Marker::CUBE_LIST;

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


  ROS_INFO_STREAM("DEBUT DE FOLLOW PATH");


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
  std::vector <std::vector<double> > cercle = gen_poi.generate_circle(__NB_POINTS_BASE_FOOTPRINT__, 1.25, 0, 0, 0);
 

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


  //generation d'une trajectoire plus petite que 
  ROS_INFO_STREAM("GENERATION DU PATH EN COURS ...");
  std::vector <std::vector<double> > pathToFollow = gen_poi.generate_circle(__NB_POINTS_PATH__, 0.85, 0, 0, 0);

  // creation de la liste de spheres 
  //positionnement des markers dans le monde 
  for(uint32_t i = 0; i < __NB_POINTS_PATH__; ++i){
    geometry_msgs::Point p;
    p.x = pathToFollow[0][i];
    p.y = pathToFollow[1][i];
    p.z = pathToFollow[2][i];
    pointsPassage.points.push_back(p);
  }
  ROS_INFO_STREAM("GENERATION DU PATH FAITE");


  geometry_msgs::PoseStamped arm_goal_pose;
  arm_goal_pose.header.frame_id = "pylon";
  arm_goal_pose.pose.position.x = 0.3;
  arm_goal_pose.pose.position.y = 0.7;
  arm_goal_pose.pose.position.z = 0.5;
  arm_goal_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);


  //base_footprint
  geometry_msgs::PoseStamped base_footprint_frame;
  base_footprint_frame.header.frame_id = "base_footprint";
  base_footprint_frame.pose.position.x = 0;
  base_footprint_frame.pose.position.y = 0;
  base_footprint_frame.pose.position.z = 0;
  base_footprint_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);


  // genere les pts de passage
  geometry_msgs::PoseStamped base_footprint_pylon_frame = transform(base_footprint_frame, "pylon");

  //position courante base_footprint
  std::array<double,3> pointOrigine = { { base_footprint_pylon_frame.pose.position.x,
                                          base_footprint_pylon_frame.pose.position.y,
                                          base_footprint_pylon_frame.pose.position.z} };

  // position voulue par le bras
  std::array<double,3> pointGoal    = { { arm_goal_pose.pose.position.x,
                                          arm_goal_pose.pose.position.y,
                                          arm_goal_pose.pose.position.z} };

  ROS_INFO_STREAM("/* affichage de valeurs pointOrigine, pointGoal  */");
  for (int i = 0; i < 3; i++) {
      std::cout << i << " Ori : " << pointOrigine[i] << std::endl << std::endl << i << " Goal : "<< pointGoal[i];
  }
  ROS_INFO_STREAM("/* Avant génération des chemins */");
  
  std::vector <std::vector<double> > chemin = gen_poi.generate_traj_2pt_from_circle(cercle,pointOrigine,pointGoal);

  ROS_INFO_STREAM("/* Après génération des chemins  */");

  // -----------------------AFFICHAGE ---------------------------------- //
  // publication des markers 
  while (marker_pub.getNumSubscribers() < 1){
    if (!ros::ok()) {
      return 0;
    }
    ROS_WARN_ONCE("Dans Rviz ajouter un marker pour visualiser les points");
    sleep(1);
  }
  marker_pub.publish(pointsPassage); //publication de la liste des points de passage
  marker_pub.publish(pointsApprocheBaseFootprint); //publication de la liste des points de passage
  // ---------------------- FIN AFFICHAGE ----------------------------- // 

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
  //tiago_arm.go_to_point_arm_tool_link(arm_goal_pose);

  /*
  arm_goal_pose.pose.position.x = 0.2;
  arm_goal_pose.pose.position.y = 0.6;
  arm_goal_pose.pose.position.z = 0.4;
  arm_goal_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

  tiago_arm.go_to_point_arm_tool_link(arm_goal_pose);
  */
 
  
    // lecture de la position de l'OT 
    geometry_msgs::PoseStamped gripper_grasping_frame;
    gripper_grasping_frame.header.frame_id = "gripper_grasping_frame";
    gripper_grasping_frame.pose.position.x = 0;
    gripper_grasping_frame.pose.position.y = 0;
    gripper_grasping_frame.pose.position.z = 0;
    gripper_grasping_frame.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

    // tranforme de la position de l'OT dans le repere du base_footprint 
    geometry_msgs::PoseStamped gripper_grasping_frame_base_footprint_frame = transform(gripper_grasping_frame, "base_footprint");

    //position courante base_footprint
    std::array<double,3> pointOT = { { gripper_grasping_frame_base_footprint_frame.pose.position.x,
                                       gripper_grasping_frame_base_footprint_frame.pose.position.y,
                                       gripper_grasping_frame_base_footprint_frame.pose.position.z} };



  /*---------- Visualisation de la boite englobante -----------*/

  ROS_INFO_STREAM("GENERATION DE LA BOX DE COLLISION ... EN COURS");

  geometry_msgs::PoseStamped box_reachable;
  box_reachable.header.frame_id = "pylon";
  box_reachable.pose.position.x = 0.0;
  box_reachable.pose.position.y = 0.0;
  box_reachable.pose.position.z = 0.9;
  box_reachable.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);
  
  CollisionBox boiteTest(box_reachable.pose.position.x,box_reachable.pose.position.y,box_reachable.pose.position.z,1.7f,1.7f,1.9f); // equivalent de la sphere en marker 

  geometry_msgs::PoseStamped point_to_test;
  point_to_test.header.frame_id = "pylon";
  point_to_test.pose.position.x = 2.25;
  point_to_test.pose.position.y = 0.0;
  point_to_test.pose.position.z = 0.0;
  point_to_test.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, 0);

  geometry_msgs::PoseStamped point_arm_1_link = transform(point_to_test,"arm_1_link");

  if(boiteTest.isCollision(point_to_test.pose.position.x,point_to_test.pose.position.y,point_to_test.pose.position.z) == true)
    std::cout <<  "Une collision existe" << std::endl;
  else
    std::cout << "Aucune collision" << std::endl;
  
  

  while(ros::ok()){
  // definition de la forme du marker de passage 
  formes = visualization_msgs::Marker::SPHERE;

  visualization_msgs::Marker markerCollisionBox;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  markerCollisionBox.header.frame_id = "/base_footprint";
  markerCollisionBox.header.stamp = ros::Time::now();

  // Set du namespace et id du marker.  ID unique
  // Attention si le meme namespace et id sont utilise, il y a ecrasement du precedent
  markerCollisionBox.ns = "collision_box";
  markerCollisionBox.id = 2;
  // set le type de marqueur a vec la forme 
  markerCollisionBox.type = formes; 

  // ajout du marqueur sous le format action 
  markerCollisionBox.action = visualization_msgs::Marker::ADD;

  //setup de la taille du marker sur chaque axe 
  markerCollisionBox.scale.x = 1.70; //1.0;
  markerCollisionBox.scale.y = 1.70; //0.70; 
  markerCollisionBox.scale.z = 1.90;
  // de la couleur (entre 0 et 1)
  markerCollisionBox.color.r = 0.5f;
  markerCollisionBox.color.g = 0.0f;
  markerCollisionBox.color.b = 0.0f; 
  markerCollisionBox.color.a = 0.65; // couche alpha, si a 0 --> 100% de transparence  

  // set de la duree du marker
  markerCollisionBox.lifetime = ros::Duration();

  // creation de la liste de cubes 
  //positionnement du marker dans le reêre de la base mobile 
  
  markerCollisionBox.pose.position.x = 0.0;
  markerCollisionBox.pose.position.y = 0.0;
  markerCollisionBox.pose.position.z = 0.9;

  marker_pub.publish(markerCollisionBox); //publication de la liste des points de passage
  
 
  ROS_INFO_STREAM("GENERATION DE LA BOX DE COLLISION FAITE");
  

  
 // DEBUG DE .LA POSITION DE l'OT
    ros::Rate r(1); // 1 hz
    std::cout << "position de l'OT: " 
              << std::endl << "x : " << pointOT[0] 
              << std::endl << "y : " << pointOT[1] 
              << std::endl << "z : " << pointOT[2]  
              << std::endl; 
    r.sleep();
  
  }
  std::cout << "fin du programme bonne nuit" << std::endl;
  return 0;

}