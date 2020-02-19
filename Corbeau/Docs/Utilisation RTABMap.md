# Utilisation RTABMap
Ce readme est un résumé des étapes d'optimisation de RTABMap trouvées pour augmenter la performance de l'algorithme sur la Jetson Nano

# 1. Paramètres optimaux caméra ZED
Avec rtabmap (sans ROS), il est possible de visualiser les amers directement depuis le SDK ZED
Paramètres optimaux
Resolution : HD720 (optimal, changer la résolution fait peu varier le framerate)
Quality : ULTRA
Self-Calibration : coché
Sensing mode : STANDARD
Filtering value for the disparity map : 90

Il existe avec le wrapper ZED un fichier launch qui lance rtabmap avec ROS
https://kapernikov.com/visual-odometry-with-the-zed-stereo-camera/

http://wiki.ros.org/rtabmap_ros/Tutorials/HandHeldMapping

Pour lancer le launch (avec RVIZ) : 
roslaunch zed_rtabmap_example PGE_zed_rtabmap.launch

# 2. Fichiers de paramètres utilisés par RTABMap
**Le fichier launch** utilise les fichiers suivants : 
- PGE_zed_camera.launch (copié de zed_camera.launch) pour la caméra ZED
- PGE_rtabmap.launch (copié de rtabmap.launch) pour les paramètres de RTABMap
- PGE_rtabmap.ini (copié de rtabmap.ini) pour les paramètres SLAM de RTABMap
- PGE_rgbd.ini (copié de rgbd.ini) pour les paramètres de RVIZ
- PGE_common.yaml (copié de common.yaml) pour les paramètres de la caméra ZED

Commande pratique pour chercher récursivement
```sh
grep -rni “<terme>” *
```

Lien avec les autres capteurs
http://wiki.ros.org/rtabmap_ros/Tutorials/SetupOnYourRobot

Modifications fichier PGE_rtabmap.ini (à ne pas modifier)
- FAST\Gpu = true pour passer le traitement de FAST sur GPU
- DbSqlite3\InMemory = true pour passer la sauvegarde sur la RAM (plus rapide)

Pour extraire le point cloud et la pose
```sh
rtabmap-databaseViewer rtabmap.db
```

# 3. Obtention des nuages de points
RTABMap sauvegarde une base de données personnalisée (au format db) contenant toutes les informations du SLAM (amers, points, localisation et images caractéristiques)
Cette base est sauvegardée après le traitement ou si le traitement est mis en pause
Ouvrir le visualisateur RTABMap et mettre en pause au moment où extraire la pose et le nuage de points
