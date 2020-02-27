# Désactiver les caméras de profondeurs de Tiago 

Un soucis récurrent lors de l'utilisation de TiaGo est la pollution de la carte de navigation par les informations reçues de sa paire stéréo Orbbec astra. 

Lorsque le bras de TiaGo passe devant ses capteurs, la carte  2D de Rviz est mise à jour, ajoutant dynamiquement des zones de collisions/ objets qui entachent la carte, et perturbent donc le mouvement actuel de la base mobile du robot. 

Si le bras reste proche de ses cameras, le robot va vouloir replannifier une trajectoire, re détectera de nouveaux obstacles, etc ... 


# Désactivation des la caméra

### Prérequis
  - Etre connecté au robot via Wifi
  - Avoir un ROSCORE ouvert sur le robot
 
> Dans tous les cas, il vaut mieux avoir Rviz d'ouvert connecté au robot avant de désactiver les caméras. 

### Désactivation

Les topics à désactiver dynamiquement sont ceux qui alimentent les costsmaps localement et globalement. 

L'outil le plus simple pour le faire est d'utiliser le plugin de reconfiguration de rqt 

```sh
$ rosrun rqt_reconfigure rqt_reconfigure
```

Les topics à désactiver sont sous : 

>Move_base/global_costmap/obstacle_rgbd_layer
>Move_base/global_costmap/obstacle_rgbd_layer_footprint

>Move_base/local_costmap/obstacle_rgbd_layer
>Move_base/local_costmap/obstacle_rgbd_layer_footprint

Il suffit de décocher la case enabled désactiver la prise en compte dans la costmap des images de profondeurs de la caméra.

