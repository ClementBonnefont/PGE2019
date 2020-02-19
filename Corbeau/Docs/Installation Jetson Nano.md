# Documentation d'installation sur la Jetson Nano
## 1. Installation de la carte et des drivers

Installer JetPack 4.2.2 sur carte SD d’au moins 32 Go UHS-1
https://developer.nvidia.com/jetpack-422-archive

Carte wifi rtl8212au fonctionne sur la carte avec l’installation d’un driver
https://devtalk.nvidia.com/default/topic/1051503/jetson-nano/make-usb-wifi-dongle-rtl8812au-works-on-nano/

Swap augmenté à 4 Go
**Très important pour éviter des problèmes à la compilation**
/etc/systemd/nvzramconfig.sh changer la taille des emplacements swap

Attention à l’heure du système, il n’y a pas de RTC ni de pile donc il faut réinitialiser l’heure au lancement

**Commandes nvidia et utilitaires**
tegrastats : températures et utilisation GPU
https://github.com/jetsonhacks/jetsonUtilities
https://github.com/JetsonHacksNano/gpuGraph

**Version installée sur le système pour le PGE**
L4T 32.2.1
JetPack 4.2.2
Ubuntu 18.04.3 LTS
Kernel : 4.9.140-tegra
CUDA : 10.0.326

**Pas d’Ubuntu 16.04 sur la Nano**

ldd executable_file : trouve les dépendances à exécuter
Installer directement les librairies manquantes

# 2. Installation SDK ZED
Installation du ZED SDK sur /usr/local/zed
Fonctionne parfaitement, sans ralentissement

**Outils de visualisation sur /usr/local/zed/tools**
Explorer : visualisation des caméras
Calibration : outil de calibration
Depth Viewer : visualisation de profondeur
ZEDfu : outil de cartographie de l’environnement avec trajectoire

# 3. Installation ROS Melodic
Installer ROS Melodic sur la Jetson en suivant le tutoriel habituel
http://wiki.ros.org/melodic/Installation/Ubuntu

Créer **deux** catkin workspace dans home (catkin_ws et catkin_ws_zed_wrapper)
http://wiki.ros.org/catkin/Tutorials/create_a_workspace

**Ne pas oublier de les source dans le .bashrc**

# 4. Installation du wrapper ROS de la ZED
Installation wrapper ZED dans **catkin_ws_zed_wrapper** : 
**Attention prendre la dernière version pour le SDK 2.x disponible ci-joint**
https://github.com/stereolabs/zed-ros-wrapper/releases/tag/v2.x

Suivre ensuite le tutoriel ici
https://github.com/stereolabs/zed-ros-wrapper

Tester en lançant un launch ZED si la ZED s'allume correctement et émet des topics

# 5. Installation rtabmap en source
**Bien suivre les installations suivantes**
**L'installation par les sources est obligatoire pour optimiser RTABMap sur l'architecture CUDA de la Jetson**
En installant rtabmap en binaries, cela fonctionne mais cela n’utilise pas CUDA, seulement le CPU, ce qui fait que les performances sont très limitées
https://github.com/introlab/rtabmap_ros

Tutoriel
```sh
sudo apt-get update
sudo apt-get install ros-melodic-rtabmap ros-melodic-rtabmap-ros
sudo apt-get remove ros-melodic-rtabmap ros-melodic-rtabmap-ros
```

**Il faut installer OpenCV avec les modules SIFT et SURF en source**
OpenCV 3.4.9 et OpenCV_contrib 3.4.9
**Suivre le tutoriel suivant**
https://docs.opencv.org/3.4.9/d7/d9f/tutorial_linux_install.html
Commande : cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DOPENCV_EXTRA_MODULES_PATH=<opencv_contrib>/modules ..

Installation g2o
```sh
sudo apt-get install ros-melodic-libg2o
```

**Attention à boost lors de l'installation**

Installation de RTABMap
```sh
cd ~
git clone https://github.com/introlab/rtabmap.git rtabmap
cd rtabmap/build
cmake ..
make
sudo make install
```

Modifier /home/jetson/rtabmap/guilib/src/opencv/stereoRectifyFisheye.h commenter la fonction stereoRectifyFisheye à la fin du fichier
Modifier /home/jetson/rtabmap/guilib/src/CalibrationDialog.cpp commenter ligne 1010 appel de stereoRectifyFisheye

Tester RTABMap dans un terminal
```sh
rtabmap
```

Vérifier avec *tegrastats* que le GPU est bien utilisé

# 6. Installation catkin_ws
Copier les sources dans *src* puis construire les sources
```sh
cd ~/catkin_ws
catkin build -j1
```

Tutorial ZED : http://wiki.ros.org/rtabmap_ros/Tutorials/HandHeldMapping
Utiliser les launch de l’archive Altran sur armada/SLAM/rtabmap_ros/launch/demo
