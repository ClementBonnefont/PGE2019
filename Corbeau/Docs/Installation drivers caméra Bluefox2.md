# Installation Bluefox2
Pour faire fonctionner la caméra Bluefox2 sur la Jetson, il faut installer le driver spécifique ARM

```sh
cd ~/catkin_ws/src/bluefox2/install
chmod 777 install_mvBlueFOX.sh
./install_mvBlueFOX.sh
```

Bien suivre l'installation en installant dans /opt
Pour lancer l'utilitaire de visualisation de la caméra du driver
```sh
/opt/mvIMPACT_Acquire/apps/mvPropView/arm64/wxPropView
```

Lancer la caméra sur ROS
```sh
source ~/catkin_ws/devel/setup.bash
roscore
roslaunch bluefox2 single_node.launch device:=25001581
rviz
```
