import argparse
import cv2 as cv
import os 
from DetecteurRouille import DetecterRouille
from dtDefaultIso import runDtDefaultIso
import numpy as np
import json
import extract

# Pour faire fonctionner ce code, il faut qu'il soit à la racine du dossier contenant Images/ 
# Soit l'architecture : 
# - detection_dft.py
# - DetecteurRouille.py
# - extract.py (Yolo détection Nids)
# - dtDefaultIso.py
# - Images (qui contiendra Left, Right et Depth)
# - results (dossier qui sera créé par ce script)


def function():
	## Argument du dossier Images, Images contient les dossier Depth, Left et Right

	ap = argparse.ArgumentParser()
	ap.add_argument("-d", "--dir", required=True, help="Chemin/vers/votre/dossier/a/check")
	args = vars(ap.parse_args())
	directory = str(args["dir"])

	finish = False
	abs_path = os.path.abspath(directory+'/')

	## On récup l'intégralité des images gauches (on aurait pu utiliser les images de droite c'est pareil)
	images_left = os.listdir(directory+'/Images/Left')
	images_left = [x.split('/')[-1] for x in images_left if '.png' in x.split('/')[-1]]
	images_left.sort()

	## On récup les images de profondeur, en théorie il y a autant d'images Left et Depth car elles sont associées
	images_depth = os.listdir(directory+'/Images/Depth')
	images_depth = [x.split('/')[-1] for x in images_depth if '.png' in x.split('/')[-1]]
	images_depth.sort()
	
	## On récup les images de profondeur, en théorie il y a autant d'images Left et Depth car elles sont associées
	file_depth = os.listdir(directory+'/DepthMeasure')
	file_depth = [x.split('/')[-1] for x in file_depth if '.yml' in x.split('/')[-1]]
	file_depth.sort()
    
    

	## On crée le dossier results dans lequel on va remettre les images résultats ainsi que le json final results.json
	if not os.path.exists("resultat"):
		os.mkdir("resultat")
	if not os.path.exists("resultat\\images"):
		os.mkdir("resultat\\images")

	dico = {} #Dictionnaire utilisé pour créer le json final qui map "nom_image" : "label_defaut"

	#On utilise ces boxes afin de ne pas détecter la rouille dans ces régions car il s'agit d'isolateurs, j'ai fixé le nb à 4 car sur la maquette on a que 4 isolateurs

	for numFile in range(0,len(images_left)):

		lstBox = []  # Les bounding boxes des isolateurs initialisées

		dico[str(images_left[numFile])] = []

		## Lancement YOLO

		## DETECTION NIDS
        
        #On récup le label de défaut nest ou none et on le charge dans le dictionnaire général
		data_nest = extract.extract_nest(abs_path+'/Images/Left/'+images_left[numFile])
		
		## On récupère les défauts détectés par extract.py

		for cle in data_nest.keys():
			if cle == 'defaults':
				dict_nest = data_nest[cle]
				#si le type d'erreur est nouveau alors on le rajoute dans le dictionnaire
				
				for i in range(0,len(dict_nest)): #ici on veut s'assurer de traiter tous les isolateurs possibles

					if dict_nest[i]['label'] == 'Nest':

						if 'Nest' not in dico[str(images_left[numFile])]:
				 			dico[str(images_left[numFile])].append('Nest')

						xmin = dict_nest[i]['xmin']
						xmax = dict_nest[i]['xmax']
						ymin = dict_nest[i]['ymin']
						ymax = dict_nest[i]['ymax']
						lstBox.append([xmin,xmax,ymin,ymax]) #On met à jour les bounding boxes des isolateurs repérés pour appeler le code de détection rouille"""



		## Detection Isolateurs
		# A DECOMMENTER UNE FOIS LE DETECTEUR DISOLATEUR INTEGRE


		pathImg = abs_path+'/Images/Left/'+images_left[numFile]
		pathFileDepht = abs_path+'/DepthMeasure/'+file_depth[numFile]

		data_isolator = runDtDefaultIso(pathFileDepht, pathImg) #A modif

		## On récup les défauts d'isolateurs détectés ainsi que leur nombre
		for cle in data_isolator.keys():
			if cle == 'defaultIso':
				dict_iso = data_isolator[cle]
				for i in range(0,len(dict_iso)): #ici on veut s'assurer de traiter tous les isolateurs possibles

					if dict_iso[i]['label'] == 'isolateur':

						if 'isolateur' not in dico[str(images_left[numFile])]:
				 			dico[str(images_left[numFile])].append('isolateur')

						xmin = dict_iso[i]['xmin']
						xmax = dict_iso[i]['xmax']
						ymin = dict_iso[i]['ymin']
						ymax = dict_iso[i]['ymax']
						lstBox.append([xmin,xmax,ymin,ymax]) #On met à jour les bounding boxes des isolateurs repérés pour appeler le code de détection rouille



		## Lancement detection rouille
		left_test = cv.imread(abs_path+'/Images/Left/'+images_left[numFile], cv.IMREAD_COLOR)
		depth_test = cv.imread(abs_path+'/Images/Depth/'+images_depth[numFile], cv.IMREAD_COLOR)
		
		# Décommenter la ligne avec les box une fois le detecteur d'isolateurs intégré, et commenter l'autre
		x,y,etat =  DetecterRouille(depth_test,left_test, lstBox)

		#dessine les box et sauvegarde l'image
		for box in lstBox:
			numpyBox = np.array([[int(box[0]), int(box[2])],
								[int(box[0]), int(box[3])],
								[int(box[1]), int(box[3])],
								[int(box[1]), int(box[2])]])
			left_test = cv.drawContours(left_test, [numpyBox], 0, (0, 0, 255), 2)
		cv.imwrite("resultat\\images\\"+str(images_left[numFile]), left_test)

		if etat == 'Rouille':
			if etat not in dico[str(images_left[numFile])]:
				 dico[str(images_left[numFile])].append(etat)

	# Conversion en JSON et écriture du fichier results.json:
	with open("resultat\\results.json", 'w') as outfile:
		json.dump(dico, outfile)

	finish = True


if __name__ == '__main__':
	function()