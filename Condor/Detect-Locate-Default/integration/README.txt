Architecture nécessaire au bon fonctionnement de detection.py :

> detection_dft.py 
> DetecteurRouille.py 
> extract.py
> dtDefaultIso.py

captures de la ZED
> DepthMeasure
> Images
   > Depth
   > Left
   > Right

Lancer python detection_dft.py --dir directory/of/picture

Le code "detection_dft.py" va utiliser les codes "DetecteurRouille.py", "extract.py" et "dtDefaultIso.py" pour vérifier la présence des défauts.
"DetecteurRouille.py" vérifie la présence de rouille.
"extract.py" vérifie la présence de nie
"dtDefaultIso.py" vérifie la présence de défaut sur les isolateurs.

ceci va créer un dossier results, déposer toutes les images avec les défauts identifiés dedans ainsi que générer un json contenant toutes les "nom_image" : ["label_défaut"]
