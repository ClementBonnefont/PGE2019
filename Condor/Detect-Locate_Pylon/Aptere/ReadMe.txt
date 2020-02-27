Ce dossier contient notre intégration avec le système aptère, tous ces dossier ce situe normalement dans le home du système aptere défini par "~" : "/home/jetson/"

L'archive "catkin_ws_appro.zip" contient le répertoire ROS relatif à l'intégration entre les algorithmes développés et le système aptere.
On y retrouve essentiellement un package qui se nomme "appro_aptere" dans lequel se trouve le fichier appro_ros.cpp qui est l'agorithme qui gère les relation entre tiago, l'interface et commande donc la phase d'approche.
Il fait appel aux fichier python se trouvant dans le répertoire darkflow.

Le dossier "Photo_ZED" est l'emplacement d'enregistrement de toutes les photos qui seront prisent par la caméra ZED.

Dans le dossier darkflow on retrouve les élements essentiel permettant la prédiction avec Yolo, mais également les fichier "extract_pylonTop.py" et "getPosOr_pylPhy.py" qui permettent, dans l'ordre, de prédire le type de pylone et de déterminer la position et l'orientation du drone par rapport au pylone.
C'est également dans ce dossier que seront donc stocké les jsons que retournent les algos précédents.
On peut y retrouver aussi le fichier "zed_capture" qui est en fait un exécutable du code "capture.cpp" (trouvable dans le dossier "No_Aptere") qui permet au lancement de prendre une photo à l'aide de la caméra ZED.

Bien sur pour fonctionner correctement il faudrait un environnement utilisant ROS kinetic, le sdk de la caméra ZED installé et une architecture similaire à celle de la Jetson.

LANCEMENT:

Tous ceci se trouvant aussi déjà sur la Jetson je vous invite à directement le lancer depuis cette derniere.
Il suffit de tout dabord lancer un roscore dans un terminal, puis dans un second de vous placer dans le "catkin_ws_appro" de sourcer le fichier Devel/setup.bash, puis de lancer un rosrun du package appro_aptere et de l'exécutable appro_ros.

FONCTIONNEMENT:

Pour bien fonctionner il faut que la caméra ZED soit bien branché et reconnu, et qu'il existe des publisheurs sur les topics "tiago/approche/appro", "tiago/approche/recalage" et "/Envol". Les deux premiers topic peuvent renvoyer n'importe quel valeur pour que l'algorithme continue de se dérouler, cependant pour le topic "/Envol", des réponses spécifique sont attendu (mais toujours des strings):
	0 : cela signifie qu'il faut relancer l'identification du type de pylone
    1 : cela signifie que tiago doit se rapprocher du pylone
    2,B : cela signifie que l'utilisateur a décidé de changer le type détecter, ainsi on lit le texte apres ',', ici représenté par B, qui sera le type de pylone donné par l'opérateur.
    3 : Cela signifie que la détection s'est bien passé et donc nous pouvons passé au calcul de la position et l'angle du sytème aptère par rapport au pylone.

Autre chose à savoir, ici on retourne uniquement la matrice de translation de la caméra au pylone avec le quaternion de l'orientation de la caméra par rapport au pylone et tout ceci sous la forme d'un "geometry_msgs::PoseStamped".