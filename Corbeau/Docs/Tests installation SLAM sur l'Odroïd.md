# Installation ROVIO et SLAM sur Odroïd
Installation SLAM
Installer Ubuntu 16.04.6 avec min 4 Go de RAM et 4 Go de swap
Installer ROS Kinetic
Exécuter fichier script

Pour le fichier d’installation du SLAM, erreurs à l’intérieur, le convertir en sh et utiliser le fichier installation sur le Drive
Le nouveau fichier d’installation à exécuter est “installation_SLAM_qui_marche_vraiment.sh”

Lancer ROVIO : 
```sh
roscore
roslaunch rovio rovio_node.launch
rosbag play --clock MH_02_easy.bag
```

Lancer RTAB : 
```sh
roscore
roslaunch rtabmap_ros demo_robot_mapping.launch
rosbag play --clock demo_mapping.bag
```

Sur Odroïd, impossible de lancer le SLAM (rovio, erreur sur l’ouverture d’un fichier info)

SLAM sur micro SD
Transfert de “bluefox2”, “camera_base” et “mpu6050_serial_to_imu” de l’eMMC à la micro SD
Build réussi en installant “ros-kinetic-serial” avec apt
La caméra ne marche pas sur la carte SD, résolu en faisant
sudo chmod 777 /dev/bus/usb/xxx/xxx, en faisant lsusb

Règle ajoutée à /etc/udev/rules.d, voir https://github.com/KumarRobotics/bluefox2

Tutorial ROVIO ROS : https://riccardogiubilato.github.io/visual/odometry/2017/12/12/Visual-Inertial-Odometry-On-A-Budget.html

Démarrer caméra avec IMU sur Odroïd avec SLAM : 
```sh
roscore
roslaunch bluefox2 single_node.launch
rosrun image_view image_view image:=/cam0/image_raw _image_transport:=compressed
source catkin_ws/devel/setup.bash
roslaunch rovio PGE_rovio_test_node.launch
```

Problème : l’IMU ne marche pas sur la micro SD
Solution : Arduino n’était pas installée sur la micro SD, donc le driver n’était pas présent pour le Serial to IMU converter
Après installation Arduino 32 bit, la carte émet des trames sur le Serial plotter, mais rien sur le ROS
Changement de la configuration de la console ROS pour ajouter les debug : /opt/ros/kinetic/share/ros/config/rosconsole.config

90-extraacl.rules
“KERNEL=”ttyUSB[0-9]*”, TAG+=”udev-acl”, TAG+=”uaccess”, OWNER=”odroid”
“KERNEL=”ttyACM[0-9]*”, TAG+=”udev-acl”, TAG+=”uaccess”, OWNER=”odroid”

Contact avec Jorge : les performances sur eMMC sont meilleures que sur micro SD, donc il vaut mieux installer rovio sur l’eMMC
Cela évite le problème de l’installation du programme de synchronisation IMU caméra sur la micro SD

Backup de l’eMMC et installation de rovio dessus
Test de rovio : problème avec OpenGL, peut-être problème d’installation
Problème avec libGL
Trouvé problème rovio, clock skew detected, rebuild et fonctionne avec bag par défaut

Fonctionnement de rovio avec le fichier de calibration
