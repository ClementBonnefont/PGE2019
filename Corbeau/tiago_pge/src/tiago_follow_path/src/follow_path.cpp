#include <tiago_follow_path/follow_path.h>

using namespace tiago_follow_path;

void Follow_path_demo::go_to_point_base_footprint(move_base_msgs::MoveBaseGoal base_goal_pose_pylon_frame, MoveBaseClient& ac) {

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  ROS_INFO("Sending goal");
  ac.sendGoal(base_goal_pose_pylon_frame);
}

geometry_msgs::PoseStamped Follow_path_demo::transform(geometry_msgs::PoseStamped source_frame, std::string target_frameid) {
  ros::NodeHandle nh;
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

void Follow_path_demo::show_markers(ros::Publisher marker_pub, int nb_pts_cercle, float rayon_cercle_base_footprint) {
	Generate_circular_poi gen_poi;
	
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
			return;
		}
		ROS_WARN_ONCE("Dans Rviz ajouter un marker pour visualiser les points");
		sleep(1);
	}
	marker_pub.publish(pointsPassage); //publication de la liste des points de passage
	
	// ---------------------- FIN AFFICHAGE ----------------------------- // 
}

geometry_msgs::PoseStamped Follow_path_demo::next_base_footprint(std::string num_next_plot, geometry_msgs::PoseStamped pt1) {
	ROS_INFO_STREAM("Demande de transformation frame");
	geometry_msgs::PoseStamped arm_goal_in_plot_frame = transform(pt1,"plot_"+num_next_plot);
	ROS_INFO_STREAM("Transformation effectuee");

	geometry_msgs::PoseStamped arm_goal_in_base_footprint_frame = arm_goal_in_plot_frame;
	arm_goal_in_base_footprint_frame.header.frame_id = "base_footprint";

	return arm_goal_in_base_footprint_frame;
}

void Follow_path_demo::moves_plot(int num_plot, MoveBaseClient& ac, move_base_msgs::MoveBaseGoal base_goal, Move_tiago_arm tiago_arm, geometry_msgs::PoseStamped pt1, geometry_msgs::PoseStamped pt2) {

	ROS_INFO_STREAM("Deplacement vers le plot "+std::to_string(num_plot));
	base_goal.target_pose.header.frame_id = "plot_"+std::to_string(num_plot);
	go_to_point_base_footprint(base_goal,ac);
	ac.waitForResult();

	//geometry_msgs::PoseStamped pt1_next_plot_frame = next_base_footprint(std::to_string(num_plot), pt1);
	//ROS_INFO_STREAM("Deplacement du bras vers le pt 1");
	//tiago_arm.go_to_point_arm_tool_link(pt1_next_plot_frame);
	//ac.waitForResult();
	
	tiago_arm.go_to_point_arm_tool_link(pt1);

	if(pt2.header.frame_id != "null") {
		ROS_INFO_STREAM("Deplacement du bras vers le pt 2");
		tiago_arm.go_to_point_arm_tool_link(pt2);
	}
}

void Follow_path_demo::follow_path() {
	Move_tiago_arm tiago_arm;
	MoveBaseClient ac("move_base", true);

	// read params from follow_path.launch
	ros::NodeHandle nh;
	int nb_pts_cercle = -1;
	nh.getParam("/nb_pts_base_footprint", nb_pts_cercle);
	float rayon_cercle_base_footprint = -1.0;
	nh.getParam("/rayon_base_footprint", rayon_cercle_base_footprint);

	ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 1); 

	show_markers(marker_pub, nb_pts_cercle, rayon_cercle_base_footprint);

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
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.973;
	pt1.pose.position.y = 0.512;
	pt1.pose.position.z = 1.182;
	pt1.pose.orientation.x = -0.165;
	pt1.pose.orientation.y = 0.702;
	pt1.pose.orientation.z = -0.685;
	pt1.pose.orientation.w = 0.105;

	// pt2
	pt2.pose.position.x = 1.127;
	pt2.pose.position.y = 0.441;
	pt2.pose.position.z = 1.196;
	pt2.pose.orientation.x = -0.070;
	pt2.pose.orientation.y = 0.701;
	pt2.pose.orientation.z = -0.696;
	pt2.pose.orientation.w = 0.137;
	moves_plot(0, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 1 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.424;
	pt1.pose.position.y = 1.150;
	pt1.pose.position.z = 1.031;
	pt1.pose.orientation.x = -0.514;
	pt1.pose.orientation.y = 0.549;
	pt1.pose.orientation.z = -0.490;
	pt1.pose.orientation.w = 0.440;

	// pt2
	pt2.pose.position.x = 0.388;
	pt2.pose.position.y = 1.192;
	pt2.pose.position.z = 1.029;
	pt2.pose.orientation.x = -0.467;
	pt2.pose.orientation.y = 0.573;
	pt2.pose.orientation.z = -0.539;
	pt2.pose.orientation.w = 0.404;

	moves_plot(1, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 2 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.387;
	pt1.pose.position.y = 0.658;
	pt1.pose.position.z = 0.951;
	pt1.pose.orientation.x = -0.712;
	pt1.pose.orientation.y = 0.291;
	pt1.pose.orientation.z = -0.107;
	pt1.pose.orientation.w = 0.630;

	// pt2
	pt2.pose.position.x = -0.536;
	pt2.pose.position.y = 0.910;
	pt2.pose.position.z = 0.928;
	pt2.pose.orientation.x = -0.641;
	pt2.pose.orientation.y = 0.334;
	pt2.pose.orientation.z = -0.303;
	pt2.pose.orientation.w = 0.622;

	moves_plot(2, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 3 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.995;
	pt1.pose.position.y = 0.338;
	pt1.pose.position.z = 0.890;
	pt1.pose.orientation.x = -0.718;
	pt1.pose.orientation.y = 0.155;
	pt1.pose.orientation.z = -0.003;
	pt1.pose.orientation.w = 0.678;

	// pt2
	pt2.pose.position.x = -0.988;
	pt2.pose.position.y = 0.346;
	pt2.pose.position.z = 1.039;
	pt2.pose.orientation.x = -0.718;
	pt2.pose.orientation.y = 0.155;
	pt2.pose.orientation.z = -0.003;
	pt2.pose.orientation.w = 0.678;

	moves_plot(3, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 4 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.612;
	pt1.pose.position.y = -0.434;
	pt1.pose.position.z = 1.230;
	pt1.pose.orientation.x = -0.675;
	pt1.pose.orientation.y = -0.208;
	pt1.pose.orientation.z = 0.273;
	pt1.pose.orientation.w = 0.653;

	// Pas de deuxieme point
	pt2.header.frame_id = "null";

	moves_plot(4, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 5 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = -0.145;
	pt1.pose.position.y = -0.730;
	pt1.pose.position.z = 1.220;
	pt1.pose.orientation.x = -0.617;
	pt1.pose.orientation.y = -0.307;
	pt1.pose.orientation.z = 0.445;
	pt1.pose.orientation.w = 0.572;

	// pt2
	pt2.header.frame_id = "pylon";
	pt2.pose.position.x = -0.153;
	pt2.pose.position.y = -0.741;
	pt2.pose.position.z = 1.044;
	pt2.pose.orientation.x = -0.617;
	pt2.pose.orientation.y = -0.307;
	pt2.pose.orientation.z = 0.445;
	pt2.pose.orientation.w = 0.572;

	moves_plot(5, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 6 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 0.687;
	pt1.pose.position.y = -0.691;
	pt1.pose.position.z = 0.812;
	pt1.pose.orientation.x = -0.421;
	pt1.pose.orientation.y = -0.569;
	pt1.pose.orientation.z = 0.614;
	pt1.pose.orientation.w = 0.348;

	// pt2
	pt2.pose.position.x = 0.670;
	pt2.pose.position.y = -0.713;
	pt2.pose.position.z = 0.662;
	pt2.pose.orientation.x = -0.414;
	pt2.pose.orientation.y = -0.572;
	pt2.pose.orientation.z = 0.591;
	pt2.pose.orientation.w = 0.390;

	moves_plot(6, ac, base_goal, tiago_arm, pt1, pt2);

	// ---------------------- PLOT 7 ----------------------------- //
	// Déclaration des pts pour le bras pour le plot courant
	// pt1
	pt1.pose.position.x = 1.103;
	pt1.pose.position.y = -0.269;
	pt1.pose.position.z = 0.431;
	pt1.pose.orientation.x = 0.168;
	pt1.pose.orientation.y = 0.712;
	pt1.pose.orientation.z = -0.648;
	pt1.pose.orientation.w = -0.213;

	// Pas de deuxieme point
	pt2.header.frame_id = "null";
	moves_plot(7, ac, base_goal, tiago_arm, pt1, pt2);

	//tiago_arm.remove_aptere();
}
