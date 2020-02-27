# -*- coding: utf-8 -*-
"""
Created on Tue Jul 30 20:36:56 2019

@author: hugod
"""

import win32api, win32con
import time

#attend le clic de la souris
def waitClic():
    # Left button down = 0 or 1. Button up = -127 or -128
    # info a verifier, j'ai l'impressions que c'est l'inverse
    
    while win32api.GetKeyState(0x01)>=0:
        time.sleep(0.01)
    while win32api.GetKeyState(0x01)<0:
        time.sleep(0.01)
       
#fait l'action alt-F4
def altF4():
    alt = 0x12
    f4 = 0x73
    win32api.keybd_event(alt, 0,0,0)
    win32api.keybd_event(f4, 0,0,0)
    time.sleep(.05)
    win32api.keybd_event(alt,0 ,win32con.KEYEVENTF_KEYUP ,0)
    win32api.keybd_event(f4,0 ,win32con.KEYEVENTF_KEYUP ,0)

##################################################
# coordonnées à ecrire dans un dossier "coord.txt"
##################################################

#12 plage horaire (clic puis fleche)
#11 intensite de fog (clic puis fleche)
#10 intentite de nuage (slide uniquement)
#11 ciel (clics au meme endroit)
#9 sol (clic)

#print("Mettre Armada sur la moitier gauche de l'ecran")
#print("Mettre le terminal a droite de l'ecran")
print("Ouvrir armada en fenêtré")
print("Mettre armada en plein ecran")
print("Supprimer le dossier image d'armada")
print("Commencer sans aucune caméra")
print("Plusieurs commandes vont vous etres données pour chaque onglets")
print("Apres les avoir faites, retourner sur le terminal pour voir les suivantes")
print("Quand vous etes pres, rentrer 'OK'")
mot = ""
while mot!="OK":
    mot = input("OK? : ")

print("\nAttention: votre fichier de coordonnées va être re-ecrit")
mot = ""
while mot!="y" and mot!="n":
    mot = input("Etes vous sur de vouloir faire ça ? (y/n): ")
    
if(mot=="y"):
    mon_fichier = open("coord.txt", "w")
    print("\nAttention : quand vous cliquer sur un onglet (ex : viewer), veillez a ce qu'ils soient tous fermés !!!\n")

    input("Appuyer sur entrer une fois les onglets fermés")
    print("1 - liquer sur l'onglet 'render'")
    print("2 - Appuyer sur 'C' pour pauser une camera")
    print("3 - Cliquer sur le bouton 'render'")
    print("4 - attendre que la fenetre se ferme")
    print("5 - remetre armada en plein ecran\n")

    print("1")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "Render : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)

    print("2-3")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "Render cam: "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)

    print("4")
    time.sleep(1)
    altF4()

    print("5")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "Full screen: "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("\n1 - Cliquer sur l'onglet 'Time of day'")
    print("2 - Cliquer au centre du rond des heures et le depacer sur 8h")
    print("3 - Cliquer au centre du rond des heures et le depacer sur 19h\n")
    input("Appuyer sur entrer une fois les onglets fermés")

    print("1")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "Time of day : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("2")    
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "hourMin : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("3")     
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "hourMax : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("\n1 - Cliquer sur l'onglet 'Weather'")
    print("2 - Cliquer au centre du rond des Fog et le depacer sur la gauche (minimum)")
    print("3 - Cliquer au centre du rond des Fog et le depacer sur la droite (maximum)")
    print("4 - Cliquer au centre du rond des Cloud et le depacer sur la gauche (minimum)")
    print("5 - Cliquer au centre du rond des Cloud et le depacer sur la droite (maximum)")
    print("6 - Cliquer le bouton Next de Sky\n")
    input("Appuyer sur entrer une fois les onglets fermés")
    
    print("1")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "Weather : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("2")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "fogMin : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("3")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "fogMax : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("4")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "cloudMin : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("5")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "cloudMax : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("6")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "nextSky : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    

    print("\n1 - Cliquer sur l'onglet 'Ground'")
    print("2 - Cliquer au centre de sol en haut a gauche")
    print("3 - Cliquer au centre de sol en haut a droite\n")
    input("Appuyer sur entrer une fois les onglets fermés")
    
    print("1")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "Ground : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("Cliquer au centre de sol en haut a gauche")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "ground1Center : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    print("Cliquer au centre de sol en haut a droite")
    waitClic()
    cursorPos = win32api.GetCursorPos()
    line = "ground2Center : "+str(cursorPos)+"\n"
    print(line)
    mon_fichier.write(line)
    
    mon_fichier.close()

print("finis")