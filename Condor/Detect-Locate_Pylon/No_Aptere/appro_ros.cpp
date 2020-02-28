#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include <string>
#include <algorithm>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/PoseStamped.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <tf/transform_broadcaster.h>

bool getInterfaceCB = false;
bool getApproCB = false;
bool getRecalageCB = false;
std::string result = "";

std::string* readDataJson(std::string path){

    std::ifstream infile(path);
    bool ok = false;
    std::string line;
    std::string label, b, c ,d , e, lx, ly ,bx, by;

    std::getline(infile, line);
    std::istringstream iss(line);

    if (!(iss >> label >> b)) { 
        std::cout << "error" << std::endl;
    } // error

    else{
        iss >> label >> b >> lx >> c >> ly >> d >> bx >> e >> by;

        label.erase(std::remove(label.begin(), label.end(), '"'), label.end());
        label.erase(std::remove(label.begin(), label.end(), ','), label.end());

        lx.erase(std::remove(lx.begin(), lx.end(), ','), lx.end());
        ly.erase(std::remove(ly.begin(), ly.end(), ','), ly.end());
        bx.erase(std::remove(bx.begin(), bx.end(), ','), bx.end());

        by.erase(std::remove(by.begin(), by.end(), '}'), by.end());
        by.erase(std::remove(by.begin(), by.end(), ']'), by.end());
        ok = true;
        std::cout << "well read" << std::endl;
    }
        
    std::string* data = new std::string[5];

    if(ok){
        data[0] = label; 
        data[1] = lx;
        data[2] = ly;
        data[3] = bx;
        data[4] = by;
    }
    else{
        data[0] = "";
    }
    
    
    return data;
}

std::string* readPosOrJson(std::string path){

    std::ifstream infile(path);
    std::string a, b, c ,d, w, x ,y, z;
    bool ok = false;
    std::string line;

    std::getline(infile, line);
    std::istringstream iss(line);

    if (!(iss >> a >> b)) { 
        std::cout << "error" << std::endl;
    } // error

    else {
        iss >> x >> a >> y >> b >> z >> c >> d >> w;

        x.erase(std::remove(x.begin(), x.end(), ','), x.end());
        y.erase(std::remove(y.begin(), y.end(), ','), y.end());
        z.erase(std::remove(z.begin(), z.end(), ','), z.end());
        z.erase(std::remove(z.begin(), z.end(), '}'), z.end());
        z.erase(std::remove(z.begin(), z.end(), ']'), z.end());
        w.erase(std::remove(w.begin(), w.end(), '}'), w.end());
        w.erase(std::remove(w.begin(), w.end(), ']'), w.end());
        ok = true;
        std::cout << "well read" << std::endl;
    }

    std::string* posOr = new std::string[4];
    if (ok){
        posOr[0] = x;
        posOr[1] = y;
        posOr[2] = z;
        posOr[3] = w;
    }
    else{
        posOr[0] = "";
    }
      
    return posOr;
}


void interfaceCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  getInterfaceCB = true;
  result = msg->data.c_str();
}

void approCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  getApproCB = true;
}

void recalageCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  getRecalageCB = true;
}

int main(int argc, char **argv){

    ros::init(argc, argv, "appro");
    ros::NodeHandle n;

    //Tiago publisher
    ros::Publisher ordreApproche = n.advertise<std_msgs::String>("aptere/approche/ordreApproche", 100);
    ros::Publisher ordreRecalage = n.advertise<geometry_msgs::PoseStamped>("aptere/approche/ordreRecalage", 100);

    //Unity publisher
    ros::Publisher typePylone = n.advertise<std_msgs::String>("aptere/approche/tp", 100);
    image_transport::ImageTransport imt(n);
    image_transport::Publisher imagePylone = imt.advertise("aptere/approche/image", 1);

    //Subscribe to Tiago return
    ros::Subscriber sub_appro = n.subscribe("tiago/approche/appro", 100, approCallback);
    ros::Subscriber sub_recal = n.subscribe("tiago/approche/recalage", 100, recalageCallback);

    //Subscribe to unity return
    ros::Subscriber sub_inter = n.subscribe("/Envol", 100, interfaceCallback);

    ros::Rate loop_rate(10);

    while (ros::ok()) {
        //TODO: HAVE A SUBSCRIBE TO SOMETHING WHICH TELL IF WE CAN DEPLACE TIAGO AGAIN OR NOT (if we are too "proche" of the pylon)

        bool approche = false; // boolean which tell if we finish the appro case
        std::string label; //pylon type
        int top_left_x; //box point 
        int top_left_y; //box point
        int bot_right_x; //box point
        int bot_right_y; //box point

        // Counter for the images in appro case
        int counter = 1;

        //numero for check the type of message send by unity
        int num;

        //*********************************** PHASE D'APPROCHE ***********************************

        // While the approche case is not finish we do what we can for 
        while (!approche) {

            std::stringstream gstream; 
            gstream << counter;

			std::string capture_path = "cd ~/darkflow;./zed_capture " + gstream.str();
			system(capture_path.c_str());
            counter++;

            //Launch extract_pylonTop of YOLO
            //system("cd ~/darkflow;python3 extract_pylonTop.py " + imgLeft_path.c_str());
            system("cd ~/darkflow;python3 extract_pylonTop.py /home/jetson/darkflow/Image_left_9.png"); //Test a partir d'une image sure !

            //Read the Json generate with jsoncpp
            /*Json::Value data;
            std::ifstream data_json("~/darkflow/data.json", std::ifstream::binary);
            data_json >> data;
            std::cout << data << std::endl; //Prints the value for "pylon"

            // Check if yolo detect a pylon
            if (data.empty()) {*/

            // Read data.json and get all the value inside
            std::string* data = new std::string[5];
            data = readDataJson("/home/jetson/darkflow/data.json");
            std::string label;
            int lx, ly, bx, by;
            label = data[0];

            if (label == ""){
                std::cout <<"Nothing in Json" << std::endl;

                // Publish message pour dire à Charlie de faire avancer le robot
                std_msgs::String msg;
                std::stringstream ss;
                ss << "go";
                msg.data = ss.str();
                ordreApproche.publish(msg);

                //attente fin mouvement de charlie
                while(!getApproCB){
                    ros::spinOnce();
					loop_rate.sleep();

                }
                getApproCB = false;
            }

            //On a réussi a déterminer le type de pylone
            else{

                // Convert to int data value
                std::istringstream(data[1]) >> top_left_x;
                std::istringstream(data[2]) >> top_left_y;
                std::istringstream(data[3]) >> bot_right_x;
                std::istringstream(data[4]) >> bot_right_y;
                std::cout << "label=" << label << " tlx=" << top_left_x << "  tly=" << top_left_y << " brx=" << bot_right_x << "  bry=" << bot_right_y << std::endl;

                //Get all the element in the Json with jsoncpp
                /*label = data["pylon"][0].get("label","").asString();
                top_left_x = data["pylon"][0].get("top_left_x",0).asInt();
                top_left_y = data["pylon"][0].get("top_left_y",0).asInt();
                bot_right_x = data["pylon"][0].get("bot_right_x",0).asInt();
                bot_right_y = data["pylon"][0].get("bot_right_y",0).asInt();*/

                //TODO: Si la box est suffisament grande on continue sinon on retourne au début du while

                //publish message à Clement du type de pylon et publish un autre pour donner l'image extraite
                //Publish du type
                std_msgs::String msg;
                std::stringstream ss;
                ss << label;
                msg.data = label;
                typePylone.publish(msg);

                //Publis de l'image
                /*cv::Mat image = cv::imread("~/darkflow/extract_pyloneType.jpg", CV_LOAD_IMAGE_COLOR);
                sensor_msgs::ImagePtr msg_img = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
                imagePylone.publish(msg_img);*/

                //Attendre réponse de Clément ???? dans la fonction de callback mettre un booleen
                while(!getInterfaceCB){
                    ros::spinOnce();
					loop_rate.sleep();
                }
                getInterfaceCB = false;

                //std::string result = "0"; //Simulation of clement result

                /*
                0 : relaunch identification
                1 : appro to the pylon
                2 : change pylon type ident so -> 2,B with B type of pylone
                3 : OK
                */
                char res = result.at(0);
                num = (int)res - 48; //get first element of the string
                switch (num) {
                    case 0:{ //Si relaunch alors on relance une photo et une analyse donc on retourne au début du while
                        break;}

                    case 1:{ //Si Avancer alors on publish un message a tiago pour lui dire de se rapprocher
                        // Publish message pour dire à Charlie de faire avancer le robot
                        std_msgs::String msg;
                        std::stringstream ss;
                        ss << "go";
                        msg.data = ss.str();
                        ordreApproche.publish(msg);

                        //attente fin mouvement de charlie
                        while(!getApproCB){
                            ros::spinOnce();
							loop_rate.sleep();
                        }
                        getApproCB = false;
                        break;}

                    case 2:{ //Si mauvais type
                        label = result.substr(2, result.length()); // On sait que le type commence après la ","
                        approche = true;
                        break;}

                    case 3:{ //Si bon alors on passe en phase de recallage
                        approche = true;
                        //TODO: RECUPERER LES DONNEES RELATIF AU PYLONE IDENTIFIE
                        break;}
                }
            }
            
        }

        //************************************** PHASE DE RECALAGE **********************************
        //Launch getPosOr_pylPhy.py 
        //system("cd ~/darkflow;python3 getPosOr_pylPhy.py " + imgLeft_path);
        system("cd ~/darkflow;python3 getPosOr_pylPhy.py /home/jetson/darkflow/Image_left_8.png"); //Test a partir d'une image sure !

        //Read the Json generate with jsoncpp
        /*Json::Value data_posOr;
        std::ifstream data_json("~/darkflow/posOr.json", std::ifstream::binary);
        data_json >> data_posOr;
        std::cout << data_posOr << std::endl; //Prints the value for "pylon"
        //Get all the element in the Json with jsoncpp
        double pos_x = data_posOr["pos"][0].get("x",0).asDouble();
        double pos_y = data_posOr["pos"][0].get("y",0).asDouble();
        double pos_z = data_posOr["pos"][0].get("z",0).asDouble();
        double angle = data_posOr["rot"][0].get("angle",0).asDouble();*/

        double pos_x, pos_y, pos_z, angle;
        // Read posOr.json and get all the value inside
        std::string* posOr = new std::string[4];
        posOr = readPosOrJson("/home/jetson/darkflow/posOr.json");

        if(posOr[0] == ""){
            std::cout <<"Fail to segmented the pylon" << std::endl;
            // TODO: Faire en sorte de faire un retour d'urgence du drone !!!!!!
            return 0; 
        }
        else{
            // Convert to double posOr value
            pos_x = std::stod(posOr[0]);
            pos_y = std::stod(posOr[1]);
            pos_z = std::stod(posOr[2]);
            angle = std::stod(posOr[3]);
            std::cout << "px=" << pos_x << "  py=" << pos_y << " pz=" << pos_z << "  angle=" << angle << std::endl;
            
            //Envoi d'un message à Charlie avec l'histoire de quaternion qui est QuaternionFromRPY(0,0,angle) car on a une rotation en Z uniquement. Apres a voir si c'est + ou -
            geometry_msgs::PoseStamped poseStamped;
            poseStamped.header.frame_id="/frame_id_1";
            poseStamped.header.stamp = ros::Time::now();
            poseStamped.pose.position.x = pos_x;
            poseStamped.pose.position.y = pos_y;
            poseStamped.pose.position.z = pos_z;
            poseStamped.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, angle);

            ordreRecalage.publish(poseStamped);

            //Attente d'une réponse de charlie pour signaler la fin du mouvement
            while(!getRecalageCB){
                ros::spinOnce();
                loop_rate.sleep();
            }
            getRecalageCB = false;
        }

        
        //L'exécution de l'approche et du recalage est terminé ici
        return 0; //Des que l'opération est fini le code se termine et le node meurt.
    }

    return 0;
    
}
