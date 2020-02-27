import os
import json

import cv2
import numpy as np
import matplotlib.pyplot as plt
import math

import extract


''' getIsolateurByProf
Filtre l'image par profondeur et retourne une image binarisée de l'isolateur par profondeur.

Entrée : 
- nameFileDepth : nom du fichier contenant la profondeur de l'image (String)
- nameImageLeft : nom du fichier de l'image (String)
- xMin, yMin, xMax, yMax : coordonnée de la box issue de yolo contenant l'isolateur (int)

Sortie :
- image issue de la box de yolo et du filtrage par distance

PS : La méthode de segmentation par profondeur pourrait être utile à explorer dans un cas réel. Avec une simple maquette 
réduite, du fait des performances du capteur ZED il est presque impossible pour se dernier de correctement segmenter 
le pylone, car avec les "trous" il y a des difficulté d'appariements et des zones non reconnues "nan". 
De même la distance séparant le sol du pylone est tres réduit avec la maquette "1m20" ce qui nous laisse 
une marge malgré tout assez fine.'''

def getIsolateurByProf(nameFileDepth, nameImageLeft, xMin, yMin, xMax, yMax):

	# lit le fichier de profondeur
	f = cv2.FileStorage(nameFileDepth, cv2.FILE_STORAGE_READ)
	a = f.getNode("ocv_depth_measure").mat()
	f.release()

	depth_measure = np.array(a)
	depth_measure = depth_measure[yMin:yMax, xMin:xMax]

	#remplace les valeurs null par 0 
	depth_measure = np.where(np.logical_not(np.isnan(depth_measure)), depth_measure, 0)

	# isole les valeurs entre 0 et 4m
	filter_pylon = (depth_measure < 4).astype(np.int)
	filter_nan = (depth_measure > 0).astype(np.int)
	filter_complete = filter_nan * filter_pylon

	#lit l'image RGB
	image = cv2.imread(nameImageLeft)
	image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
	image = image[yMin:yMax, xMin:xMax]

	#crée l'image RBG en mettant à 0 tous les pixels à 0m ou > 4m
	img = np.zeros(image.shape).astype(np.uint8)
	img[:, :, 0] = (image[:, :, 0] * filter_complete[:, :])
	img[:, :, 1] = (image[:, :, 1] * filter_complete[:, :])
	img[:, :, 2] = (image[:, :, 2] * filter_complete[:, :])

	return img

''' detect : 
Détecte l'isolateur dans l'image donnée par la profondeur avec des méthodes 
de détection de couleur et de composante connexe.

Entrée : 
- image : image au format numpy
- angle : float représentant l'angle de rotation en degrée

Sortie :
- image au format numpy'''

def detect(input_image, r_mean, g_mean, b_mean):

	#la couleur n'est pas noir : on est dans la partie détéctée par la profondeur
	bin_1 = (input_image[:,:,0] != 0).astype(np.int)
	bin_2 = (input_image[:,:,1] != 0).astype(np.int)
	bin_3 = (input_image[:,:,2] != 0).astype(np.int)
	nonZero = bin_1*bin_2*bin_3

	#crée une image en fonction de la différence de couleur avec l'isolateur
	img1 = np.absolute(input_image[:,:,0]-r_mean)
	img2 = np.absolute(input_image[:,:,1]-g_mean)
	img3 = np.absolute(input_image[:,:,2]-b_mean)
	imgDiff = img1*img2*img3*nonZero

	#binarise l'image tel que l'isolateur est égal à toutes les valeurs < à la moyenne des couleurs de l'image
	bin_input_image = ((imgDiff<np.mean(imgDiff)).astype(np.int) * nonZero).astype(np.uint8)

	#lisse notre image binaire
	kernel = np.ones((3,3),np.uint8)
	bin_input_image = cv2.morphologyEx(bin_input_image, cv2.MORPH_OPEN, kernel)
	bin_input_image = cv2.morphologyEx(bin_input_image, cv2.MORPH_CLOSE, kernel)


	#garde la plus grande composante connexe
	## attention, méthode non intégrée à vérifier si vous voulez l'utiliser 
	## (utile que dans de rares cas précis)

	"""ret, labels = cv2.connectedComponents(bin_input_image[:,:])
	unique, counts = np.unique(labels, return_counts=True)
	counts = counts[1:]
	bigForm = np.argwhere(counts==max(counts))[0,0]+1
	binImg = (labels==bigForm).astype(np.uint8)"""

	
	#définit une box encadrant l'isolateur
	rect = cv2.minAreaRect(cv2.findNonZero(bin_input_image))
	box = cv2.boxPoints(rect)

	x1 = min(box[:, 0])
	y1 = min(box[:, 1])
	x2 = max(box[:, 0])
	y2 = max(box[:, 1])

	# By construction, the points in box are stored in clockwise order, 
	# with the lowest point first (in box[0])
	# Hence, box[1] is the leftmost point of the box
	# In case of equality between two leftmost, box[1] is the higher (min y)

	pylon_center = np.mean(box, axis=0)

	dist_x = box[0][0] - box[1][0]
	dist_y = box[0][1] - box[1][1]
	dist1 = math.sqrt(dist_x**2 + dist_y**2)
	dist_x = box[1][0] - box[2][0]
	dist_y = box[1][1] - box[2][1]
	dist2 = math.sqrt(dist_x**2 + dist_y**2)

	height = min(dist1, dist2)
	width = max(dist1, dist2)

	box = np.int0(box)

	# Compute
	
	if rect[1][0] > rect[1][1]: # if width > height
		angle = rect[2]
	else:
		angle = rect[2]+90
	
	return bin_input_image, angle



''' rotate_bound : 
Effectue une rotation sur l'image et renvoie l'image tournée

Entrée : 
- image : image au format numpy
- angle : float représentant l'angle de rotation en degrée

Sortie :
- image au format numpy'''

def rotate_bound(image, angle):
    # grab the dimensions of the image and then determine the
    # center
    (h, w) = image.shape[:2]
    (cX, cY) = (w // 2, h // 2)
    # grab the rotation matrix (applying the negative of the
    # angle to rotate clockwise), then grab the sine and cosine
    # (i.e., the rotation components of the matrix)
    M = cv2.getRotationMatrix2D((cX, cY), -angle, 1.0)
    cos = np.abs(M[0, 0])
    sin = np.abs(M[0, 1])
    # compute the new bounding dimensions of the image
    nW = int((h * sin) + (w * cos))
    nH = int((h * cos) + (w * sin))
    # adjust the rotation matrix to take into account translation
    M[0, 2] += (nW / 2) - cX
    M[1, 2] += (nH / 2) - cY
    # perform the actual rotation and return the image
    return cv2.warpAffine(image, M, (nW, nH))

''' cutImg : 
Coupe l'image binaire en entrée et seulement la partie de l'image représentée par des 1/True.

Entrée : 
- imgToCut : image binaire au format numpy, type = uint8 (composé de 0 et 1)

Sortie :
- coordonnées x_min, x_max, y_min et y_max encadrant la partie à 1 dans l'image'''

def cutImg(imgToCut):
	x_min = -1
	x_max = -1
	y_min = -1
	y_max = -1

	cpt = 0
	while max(imgToCut[:,cpt])==0:
		cpt += 1
	x_min = cpt

	cpt = imgToCut.shape[1]-1
	while max(imgToCut[:,cpt])==0:
		cpt -= 1
	x_max = cpt

	cpt = 0
	while max(imgToCut[cpt,:])==0:
		cpt += 1
	y_min = cpt

	cpt = imgToCut.shape[0]-1
	while max(imgToCut[cpt,:])==0:
		cpt -= 1
	y_max = cpt

	return x_min, x_max, y_min, y_max


''' dtDefault : 
Trouve la position des erreurs avant la rotation de l'image

Entrée : 
- lstError : liste de tableaux nympy représentant les erreurs
- angle : float représentant l'angle de rotation en degrée
- shapeImg : dimensions de l'image

Sortie :
- lstError : liste de tableaux nympy représentant les erreurs (tournées)'''

def dtDefault(img_input):

	#retail l'image pour juste avoir l'isolateur
	(x_min_cut, x_max_cut, y_min_cut, y_max_cut) = cutImg(img_input)
	img = img_input[y_min_cut:y_max_cut, x_min_cut:x_max_cut]
	
	#définit les seuils selon l'image
	nbrMoy = int(img.shape[0]/10)
	seuilError = img.shape[1]/15

	error = []
	debut = -1
	meanImg = int(img.shape[1]/2)

	#parcours toutes les lignes pour vérifier la présence d'erreurs
	#on enlève 3 pixels au début et à la fin pour enlever le bruit
	for y in range(3, img.shape[0] - nbrMoy - 3):

		#calcul de la différence moyenne entre les nbrMoy pixels suivants
		totDiff = 0
		for cptMoy in range(nbrMoy):

			cpt = 0
			while img[y+cptMoy,cpt]==0 and cpt<meanImg:
				cpt += 1
			value1 = cpt

			cpt = img.shape[1]-1
			while img[y+cptMoy,cpt]==0 and cpt>meanImg:
				cpt -= 1
			value2 = cpt

			totDiff += abs(abs(value1 - meanImg) - abs(value2 - meanImg))

		moyError = totDiff/nbrMoy

		#si l'erreur est supérieur au seuil et que l'on a encore rien détécté
		#c'est le debut d'une erreur
		if moyError > seuilError and debut==-1:
			debut = y

		#si l'erreur est inférieur au seuil et que l'on a une erreur détécté
		#c'est la fin d'une erreur
		if moyError < seuilError and debut!=-1:

			box = np.array([[0+x_min_cut, debut+y_min_cut],
							[0+x_min_cut, y+y_min_cut],
							[img.shape[1]+x_min_cut, y+y_min_cut],
							[img.shape[1]+x_min_cut, debut+y_min_cut]])

			#on vérifie que la taille de l'erreur est assez grande pour éviter les faux positifs
			if abs(debut-y) > img.shape[0]/10:
				error.append(box)
			debut = -1

	return error


''' rotateError : 
Trouve la position des erreurs avant la rotation de l'image

Entrée : 
- lstError : liste de tableaux nympy représentant les erreurs
- angle : float représentant l'angle de rotation en degrée
- shapeImg : dimensions de l'image

Sortie :
- lstError : liste de tableaux nympy représentant les erreurs (tournées)'''

def rotateError(lstError, angle, shapeImg):

	#angle = angle/360 * 2*math.pi
	#passage en radian
	angle = angle * math.pi / 180

	center = (shapeImg[1]/2, shapeImg[0]/2)

	#parcours toutes les box détéctées
	for cptBox in range(len(lstError)):
		boxError = lstError[cptBox]

		#pour chacun des 4 points de la box
		for i in range(4):

			#calcul des cosinus et sinus relatifs par rapport au centre de l'image
			dist1 = boxError[i][0]-center[0] #x
			dist2 = boxError[i][1]-center[1] #y
			distToCenter = math.sqrt(dist1**2 + dist2**2)

			valueCos = dist1/distToCenter
			valueSin = dist2/distToCenter
		
			#définie l'angle de l'erreur
			if valueCos!=0:
				#pour un angle calcule les 2 cosinus et sinus possible

				angleCos1 = round(math.acos(valueCos), 4)
				angleCos2 = round(- angleCos1, 4)
				angleSin1 = round(math.asin(valueSin), 4)
				
				if angleSin1 > 0 and angleSin1 < math.pi :
					angleSin2 = round(math.pi - angleSin1, 4)
				if angleSin1 <= 0 and angleSin1 > -math.pi/2 :
					angleSin2 = -round(math.pi + angleSin1, 4)

				#met les angles égaux à 0 à 2pi 
				lstAngle = [angleCos1, angleCos2, angleSin1, angleSin2]
				for j in range(4):
					if lstAngle[j]==0:
						lstAngle[j] = 2*math.pi

				#récupère l'angle qui se répète plus d'une fois
				if lstAngle.count(lstAngle[0]) > 1:
					currentAngle = lstAngle[0]
				elif lstAngle.count(lstAngle[1]) > 1:
					currentAngle = lstAngle[1]
				elif lstAngle.count(lstAngle[2]) > 1:
					currentAngle = lstAngle[2]
				else:
					currentAngle = lstAngle[3]

			else:
				if valueSin==-1:
					currentAngle = -90 * math.pi / 180
				else:
					currentAngle = 90 * math.pi / 180

			# définis les nouvelles valeurs de l'emplacement des erreurs
			newAngle = currentAngle+angle

			lstError[cptBox][i][0] = math.cos(newAngle)*distToCenter + center[0]
			lstError[cptBox][i][1] = math.sin(newAngle)*distToCenter + center[1]

	return lstError

''' seuilColor : 
Isole l'isolateur dans l'image et retourne la couleur moyenne de celui-ci.

Entrée : 
- name_file_depth : nom du fichier contenant la profondeur de l'image (String)
- name_file_img : nom du fichier de l'image (String)
- x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo : coordonnée de la box issue de yolo contenant l'isolateur (int)

Sortie :
- r_mean, g_mean, b_mean : couleur moyenne de l'isolateur en R, G et B'''

def seuilColor(name_file_depth, name_file_img, x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo):

	#filtre l'image par profondeur
	img_rgb = getIsolateurByProf(name_file_depth, name_file_img, x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo)
	img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_RGB2GRAY)

	#coupe l'image pour n'avoir que l'isolateur
	(x_min_cut, x_max_cut, y_min_cut, y_max_cut) = cutImg(img_gray)
	img = img_rgb[y_min_cut:y_max_cut, x_min_cut:x_max_cut]

	#on definit une box centrale dans l'image
	xminColor = int(img.shape[1]/2) - int(img.shape[1]/20)
	xmaxColor = int(img.shape[1]/2) + int(img.shape[1]/20)
	yminColor = int(img.shape[0]*0.2)
	ymaxColor = int(img.shape[0]*0.8)

	#récupère les couleurs moyennes dans la box définit
	r_mean = np.mean(img[yminColor:ymaxColor, xminColor:xmaxColor, 0]) 
	g_mean = np.mean(img[yminColor:ymaxColor, xminColor:xmaxColor, 1]) 
	b_mean = np.mean(img[yminColor:ymaxColor, xminColor:xmaxColor, 2]) 

	return r_mean, g_mean, b_mean

''' dtDefaultInBox : 
Détecte les défauts dans une box yolo.

Entrée : 
- name_file_depth : nom du fichier contenant la profonceur de l'image (String)
- name_file_img : nom du fichier de l'image (String)
- x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo : coordonnée de la box issue de yolo contenant l'isolateur (int)

Sortie :
- lstError : liste de tableaux nympy représentant les erreurs'''

def dtDefaultInBox(name_file_depth, name_file_img, x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo):

	#récupère la couleur moyenne de l'isolateur
	r_mean, g_mean, b_mean = seuilColor(name_file_depth, name_file_img, x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo)
	
	#filtre l'image par profondeur
	imgIso = getIsolateurByProf(name_file_depth, name_file_img, x_min_yolo, y_min_yolo, x_max_yolo, y_max_yolo)

	#filtre l'image par couleur et trouve l'angle de l'isolateur
	imgBinIso, angle = detect(imgIso, r_mean, g_mean, b_mean)

	#tourne l'image pour avoir l'isolateur droit
	imgBinIso = rotate_bound(imgBinIso, -angle)

	#detect les défault d'isolateur
	lstError = dtDefault(imgBinIso)

	#repositionne les défauts dans l'image originale
	lstError = rotateError(lstError, angle, imgIso.shape)

	return lstError

''' runDtDefaultIso : 
Détecte les default d'isolateur.

Entrée : 
- name_file_depth : nom du fichier contenant la profonceur de l'image (String)
- name_file_img : nom du fichier de l'image (String)

Sortie :
- dicRes : dictionnaire résultat contenant liste de tableaux nympy représentant les erreurs'''

def runDtDefaultIso(name_file_depth, name_file_img):

	dicRes = {}
	dicRes["defaultIso"] = []

	#détecter les isolateurs avec yolo
	allBox = extract.extract_iso(name_file_img)

	#traiter les box du yolo
	for boxYolo in allBox['defaults']:

		#detect les defauts d'une box
		lstError = dtDefaultInBox(name_file_depth, name_file_img, boxYolo["xmin"], boxYolo["ymin"], boxYolo["xmax"], boxYolo["ymax"])
		
		for box in lstError:
			xMin = min(box[:,0])+boxYolo["xmin"]
			xMax = max(box[:,0])+boxYolo["xmin"]
			yMin = min(box[:,1])+boxYolo["ymin"]
			yMax = max(box[:,1])+boxYolo["ymin"]

			dicRes["defaultIso"].append({
					"label" : "isolateur",
					"xmin" : str(xMin),
					"xmax" : str(xMax),
					"ymin" : str(yMin),
					"ymax" : str(yMax)})

	return dicRes


#if __name__ == '__main__':
#	runDtDefaultIso("isolateur\\isolateur_2") #chemin absolu ou relatif
