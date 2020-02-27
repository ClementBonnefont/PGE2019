Ce dossier contient notre intégration avec le système aptère, tous ces dossier ce situe normalement dans le home du système aptere défini par "~" : "/home/jetson/"

L'archive 

Dans le dossier darkflow on retrouve les élements essentiel permettant la prédiction avec Yolo, mais également les fichier "extract_pylonTop.py" et "getPosOr_pylPhy.py" qui permettent, dans l'ordre, de prédire le type de pylone et de déterminer la position et l'orientation du drone par rapport au pylone.
C'est également dans ce dossier que seront donc stocké les jsons que retournent les algos précédents.
On peut y retrouver aussi le fichier "zed_capture" qui est en fait un exécutable du code "capture.cpp" (trouvable dans le dossier "No_Aptere") qui permet au lancement de prendre une photo à l'aide de la caméra ZED.