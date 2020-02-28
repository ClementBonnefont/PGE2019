import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt



'''Detecteur de rouille, prend en entree l'image de profondeur (frame1) et l'image normale RGB correspondante (frame2). 
La fonction retourne l'etat de l'image c'est a dire s'il y a de la rouille ou non ainsi que les valeurs x et y de l'endroit ou se trouve la rouille.

Entrée : 
- frame1 : image de profondeur au format numpy
- frame2 : image RGB au format numpy
- lstBox : liste des box d'isolateur détéctés [minX,maxX,minY,maxY]

Sortie :
- x :
- y :
- etat : présence de rouille ou non'''

def DetecterRouille(frame1, frame2, lstBox):

	etat = "Sans_rouille"

	SommeI = 0
	SommeJ = 0
	Taille = 0

	for i in range(0,frame1.shape[0]):
		for j in range(0,frame1.shape[1]):

			if frame1[i,j,0] > 220 :
				if frame2[i,j,2] > 1.7*frame2[i,j,1] and frame2[i,j,2] > 1.7*frame2[i,j,0] :
					valueOK = True

					for box in range(lstBox):
						#(j<box1[0] or j>box1[2] or i<box1[1] or i>box1[3])
						valueOK = valueOK and not (j>box[0] and j<box[1] and i>box[2] and i<box[3])			

					if valueOK:
						SommeI = SommeI + i
						SommeJ = SommeJ + j
						Taille = Taille + 1

						frame2[i,j] = (0,255,0)

			if(Taille > 10):
				etat = "Rouille" 

	if(Taille>0):

		x = SommeI/Taille
		y = SommeJ/Taille

	else:
		x=0
		y=0

	return x,y,etat