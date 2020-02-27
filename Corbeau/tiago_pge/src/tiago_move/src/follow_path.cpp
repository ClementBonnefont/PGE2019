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

void go_to_point_base_footprint(move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame, MoveBaseClient& ac) {

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
	ros::init(argc, argv, "move_learned_pts");

	Move_tiago_arm tiago_arm;
	Generate_circular_poi gen_poi;
	MoveBaseClient ac("move_base", true);

	// read params from follow_path.launch
	ros::NodeHandle nh;
	int nb_pts_cercle = -1;
	nh.getParam("/nb_pts_base_footprint", nb_pts_cercle);

	float rayon_cercle_base_footprint = -1.0;
	nh.getParam("/rayon_base_footprint", rayon_cercle_base_footprint);

	ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 1); 
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

	/* --------- MAINTENANT DANS PLOT_BROADCASTER --------------------*/

	/* ---------------------------------------------------------------*/

	ROS_INFO_STREAM("DEBUT DE FOLLOW PATH");

	//generation d'un cercle 
	ROS_INFO_STREAM("GENERATION DU CERCLE EN COURS ...");
	std::vector <std::vector<double> > cercle = gen_poi.generate_circle(nb_pts_cercle, rayon_cercle_base_footprint, 0, 0, 0, 0);

	ROS_INFO_STREAM("GENERATION DU CERCLE FAITE");

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
	// marker_pub.publish(pointsApprocheBaseFootprint); //publication de la liste des points de passage
	// ---------------------- FIN AFFICHAGE ----------------------------- // 


	// ---------------------- DEMO TIAGO ----------------------------- // 
	tiago_arm.add_aptere();

	// Déclaration de la variable pour la base mobile
	move_base_msgs::MoveBaseGoal base_goal;

	base_goal.target_pose.pose.position.x = 0; 
	base_goal.target_pose.pose.position.y = 0;
	base_goal.target_pose.pose.position.z = 0;
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);

	// Déclaration des variables pour les pts du bras
	geometry_msgs::PoseStamped pt1;
	pt1.header.frame_id = "pylon";

	geometry_msgs::PoseStamped pt2;
	pt2.header.frame_id = "pylon";

	// ---------------------- PLOT 0 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 0");
	base_goal.target_pose.header.frame_id = "plot_0";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.992;
	pt1.pose.position.y = 0.451;
	pt1.pose.position.z = 1.005;
	pt1.pose.orientation.x = -0.125;
	pt1.pose.orientation.y = 0.723;
	pt1.pose.orientation.z = -0.669;
	pt1.pose.orientation.w = 0.118;

	// pt2
	pt2.pose.position.x = 0.992;
	pt2.pose.position.y = 0.451;
	pt2.pose.position.z = 0.7;
	pt2.pose.orientation.x = -0.125;
	pt2.pose.orientation.y = 0.723;
	pt2.pose.orientation.z = -0.669;
	pt2.pose.orientation.w = 0.118;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);
	ROS_INFO_STREAM("Deplacement du bras vers le pt 2");
	tiago_arm.go_to_point_arm_tool_link(pt2);

	// ---------------------- PLOT 1 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 1");
	base_goal.target_pose.header.frame_id = "plot_1";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.214;
	pt1.pose.position.y = 0.920;
	pt1.pose.position.z = 0.810;
	pt1.pose.orientation.x = -0.448;
	pt1.pose.orientation.y = 0.579;
	pt1.pose.orientation.z = -0.531;
	pt1.pose.orientation.w = 0.427;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);

	// ---------------------- PLOT 2 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 2");
	base_goal.target_pose.header.frame_id = "plot_2";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.414;
	pt1.pose.position.y = 0.883;
	pt1.pose.position.z = 0.639;
	pt1.pose.orientation.x = -0.609;
	pt1.pose.orientation.y = 0.427;
	pt1.pose.orientation.z = -0.365;
	pt1.pose.orientation.w = 0.560;

	// pt2
	pt2.pose.position.x = -0.414;
	pt2.pose.position.y = 0.883;
	pt2.pose.position.z = 1.005;
	pt2.pose.orientation.x = -0.609;
	pt2.pose.orientation.y = 0.427;
	pt2.pose.orientation.z = -0.365;
	pt2.pose.orientation.w = 0.560;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);
	ROS_INFO_STREAM("Deplacement du bras vers le pt 2");
	tiago_arm.go_to_point_arm_tool_link(pt2);

	// ---------------------- PLOT 3 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 3");
	base_goal.target_pose.header.frame_id = "plot_3";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -1.086;
	pt1.pose.position.y = 0.260;
	pt1.pose.position.z = 0.906;
	pt1.pose.orientation.x = -0.724;
	pt1.pose.orientation.y = 0.150;
	pt1.pose.orientation.z = -0.119;
	pt1.pose.orientation.w = 0.663;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);

	// ---------------------- PLOT 4 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 4");
	base_goal.target_pose.header.frame_id = "plot_4";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.797;
	pt1.pose.position.y = -0.678;
	pt1.pose.position.z = 0.956;
	pt1.pose.orientation.x = -0.667;
	pt1.pose.orientation.y = -0.286;
	pt1.pose.orientation.z = 0.268;
	pt1.pose.orientation.w = 0.634;

	pt2.pose.position.x = -0.797;
	pt2.pose.position.y = -0.678;
	pt2.pose.position.z = 0.707;
	pt2.pose.orientation.x = -0.667;
	pt2.pose.orientation.y = -0.286;
	pt2.pose.orientation.z = 0.268;
	pt2.pose.orientation.w = 0.634;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);
	ROS_INFO_STREAM("Deplacement du bras vers le pt 2");
	tiago_arm.go_to_point_arm_tool_link(pt2);

	// ---------------------- PLOT 5 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 5");
	base_goal.target_pose.header.frame_id = "plot_5";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.109;
	pt1.pose.position.y = -1.005;
	pt1.pose.position.z = 0.431;
	pt1.pose.orientation.x = -0.553;
	pt1.pose.orientation.y = -0.487;
	pt1.pose.orientation.z = 0.432;
	pt1.pose.orientation.w = 0.519;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);

	// ---------------------- PLOT 6 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 6");
	base_goal.target_pose.header.frame_id = "plot_6";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.677;
	pt1.pose.position.y = -0.836;
	pt1.pose.position.z = 0.680;
	pt1.pose.orientation.x = 0.389;
	pt1.pose.orientation.y = 0.630;
	pt1.pose.orientation.z = -0.568;
	pt1.pose.orientation.w = -0.358;

	// pt2
	pt2.pose.position.x = 0.677;
	pt2.pose.position.y = -0.836;
	pt2.pose.position.z = 0.880;
	pt2.pose.orientation.x = 0.389;
	pt2.pose.orientation.y = 0.630;
	pt2.pose.orientation.z = -0.568;
	pt2.pose.orientation.w = -0.358;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);
	ROS_INFO_STREAM("Deplacement du bras vers le pt 2");
	tiago_arm.go_to_point_arm_tool_link(pt2);

	// ---------------------- PLOT 7 ----------------------------- //
	ROS_INFO_STREAM("Deplacement vers le plot 7");
	base_goal.target_pose.header.frame_id = "plot_7";
	base_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0,0,0.5236);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.897;
	pt1.pose.position.y = -0.157;
	pt1.pose.position.z = 1.131;
	pt1.pose.orientation.x = 0.085;
	pt1.pose.orientation.y = 0.724;
	pt1.pose.orientation.z = -0.677;
	pt1.pose.orientation.w = -0.101;

	ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	tiago_arm.go_to_point_arm_tool_link(pt1);


  return 0;

}
