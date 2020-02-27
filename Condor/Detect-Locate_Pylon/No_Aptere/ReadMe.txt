Ce dossier contient tous les algorithmes utilisé pour l'intégration (de façon accessible), mais également d'autres qui ont pu, ou peuvent être utile.

Dans le dossier darkflow on retrouve les élements essentiel permettant la prédiction avec Yolo. Si vous voulez entrainez vous même votre propre réseaux, je vous invite à lire le readme présent dans le dossier. Essentiellement il vous faut d'installer tensorflow 1.5 et opencv, puis par la suite vous positioner dans le dossier darkflow et de lancer le setup à l'aide d'un terminal: "python setup.py". Si vous souhaitez entrainer sur votre GPU, une installation de CUDA avec Cudnn est indispensable. Je vous invite à vous documenter dessus si besoin.
Sinon pour plus de faciliter, dès lors que votre environnement yolo est configuré, vous pourrez utilisez les commandes du fichier "tuto_yolo.txt" (se trouve dans le dossier darkflow), il s'agit d'un récapitulatif "clair" des commandes.
Pour l'entrainement je vous conseil d'établir un dossier train et test. Dans le dossier test vous pourrez y stocker uniquement des images, cependant dans le train il vous fraudra deux autres dossier: "annot" et "img". "annots" contiendra les annotations (de même je vous conseil l'utilisation du logiciel labelimg, il vous générera les xml indispensable: https://github.com/tzutalin/labelImg), et "images" qui contiendra uniquement les images comme son nom l'indique.

Dans le dossier image_test se trouve les images que l'on peut utiliser pour tester les différents algorithmes de traitement d'images.

appro_ros.cpp: est le fichier utilisé lors de l'intégration. C'est celui qui guide tous le processus d'approche. Je vous invite à lire le ReadMe du dossier Aptere pour plus d'informations

calculateFocalLength.py: il s'agit du code utiliser pour calculer la taille de focal de la caméra ZED, utile dans le calcul de la distance entre la caméra et un objet dans une image (dont la dimension est connue). La valeur retourné est différente de celle théorique fourni par la documentation de la caméra. Cependant elle semble fonctionner mieux. 

capture.cpp: est le code source de l'exécutable "zed_capture" dans le dossier darkflow du système aptère. C'est le code permettant à la caméra zed de prendre une photo et de l'enregistrer avec son image de profondeur mais également sa matrice de profondeur.

detectPyloneProfondeur.py: code utilisant les valeurs de la matrice de profondeur pour segmenter un objet dans une image. Le seuil de la fonction serait à ajuster. Ici pour montrer l'intéret d'une telle méthode, on se sert des images prise de l'isolateur "fait maison". Mais dans un cas réel avec un appariement réussi de l'image top d'un pylone, on pourrait (avec le bon seuil) se servir de cet algorithme pour segment le pylone.

extract_pylonTop.py: le code d'identification de type de pylone utilisé dans l'intégration. Il utilise Yolo afin de détecter un pylon physique. Pour le lancer dans un terminal exécuter:
python extract_pylonTop.py path_vers_votre_image 
exemple: python extract_pylonTop.py image_test/IMG_1_2.jpg
Si l'image a été bien reconnu un message disant "Well done" apparaitra avec dans le dossier le fichier "data.json" correctement rempli, ainsi qu'une image "extract_pyloneType.jpg" est générée. 
Sinon si un message d'erreur : " cv2.error: OpenCV(4.1.2) C:\projects\opencv-python\opencv\modules\imgproc\src\color.cpp:182: error: (-215:Assertion failed) !_src.empty() in function 'cv::cvtColor' " apparait alors le chemin vers l'image qui a été entré est erroné.
Sinon si le message "fail" apparait dans le terminal, alors le réseau n'a pas reconnu de pylone, un fichier "data.json" est tout de même généré, mais est vide.

getPosOr_pylPhy.py: le code permettant de déterminer la position et l'orientation (en Z) du pylone par rapport à la caméra, utilisé dans l'intégration. Pour le lancer il faut dans un terminal exécuter :
python getPosOr_pylPhy.py path_vers_votre_image
exemple: python getPosOr_pylPhy.py image_test/IMG_1_2.jpg
Si le code a réussi à segmenter le pylone, aucun message n'est renvoyé, mais un fichier "posOr.json" est généré.
Sinon le code a échoué et on retrouve le message d'erreur: " ValueError: not enough values to unpack (expected 3, got 2) "
