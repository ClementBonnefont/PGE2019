# -*- coding: utf-8 -*-
"""
Created on Tue Jul 30 20:36:56 2019

@author: hugod
"""
import winsound
import win32api, win32con
import time
import re
import sys
import os

pathBuildFile = ""

class myLittleBot():
               
    def __init__(self, listCoord, nbrHour, nbrFog, nbrCould, nbrSky, nbrGround, nameDir):
        self.listCoord = listCoord
        self.maxHour = nbrHour
        self.maxFog = nbrFog
        self.maxCould = nbrCould
        self.maxSky = nbrSky
        self.maxGround = nbrGround
        self.nameDir = nameDir
        
    #effectue un clic sur le pixel donné
    def clic(self, coord):
        x = coord[0]
        y = coord[1]
        win32api.SetCursorPos((x,y))
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,x,y,0,0)
        time.sleep(0.1);
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,x,y,0,0)
        time.sleep(0.2);
        

    # appuie, déplace puis lache le bouton gauche de la souris
    # a pour but de déplacer un élément
    def clicMove(self, coord1, coord2):
        x1 = coord1[0]
        y1 = coord1[1]
        x2 = coord2[0]
        y2 = coord2[1]
        
        win32api.SetCursorPos((x1,y1))
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,x1,y1,0,0)
        time.sleep(0.3);
        win32api.SetCursorPos((x2,y2))
        time.sleep(0.3);
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,x2,y2,0,0)
        time.sleep(0.2);

    def run(self):
        self.clic((100,10)) #clic sur le haut de la fenetre
        time.sleep(1)

        #debut Ground
        currentSky = 0
        while(currentSky < self.maxSky):

            #debut Sky
            currentGround = 0
            while(currentGround < self.maxGround):
                
                #debut Cloud
                currentCould = 0
                while(currentCould < self.maxCould):
                    
                    #debut Fog
                    currentFog = 0
                    while(currentFog < self.maxFog):
                        
                        #debut Hour
                        currentHour = 0
                        while(currentHour < self.maxHour):

                            self.echapIsPress()

                            self.setRender(currentHour,currentFog,currentCould,currentSky,currentGround)
                            
                            self.setTime(currentHour, (currentHour+1)%self.maxHour)
                            currentHour = currentHour+1
                        #fin Hour
                        
                        self.setFog(currentFog, (currentFog+1)%self.maxFog)
                        currentFog = currentFog+1
                    #fin Jour
                    
                    self.setCould(currentCould, (currentCould+1)%self.maxCould)
                    currentCould = currentCould+1
                #fin Could
            
                self.setGround((currentGround+1)%self.maxGround)
                currentGround = currentGround+1
            #fin Ground
            
            self.setSky()
            currentSky = currentSky+1
        #fin Sky
        
    # quitte le bot si la touche echape est préssé
    def echapIsPress(self):
        if win32api.GetAsyncKeyState(win32con.VK_ESCAPE)<0 :
            sys.exit()

    # effectue l'action alt-F4
    def altF4(self):
        alt = 0x12
        f4 = 0x73
        win32api.keybd_event(alt, 0,0,0)
        win32api.keybd_event(f4, 0,0,0)
        time.sleep(.05)
        win32api.keybd_event(alt,0 ,win32con.KEYEVENTF_KEYUP ,0)
        win32api.keybd_event(f4,0 ,win32con.KEYEVENTF_KEYUP ,0)
        time.sleep(.2)

    #crée le fichier de rendu des caméra
    def setRender(self, currentHour, currentFog, currentCould, currentSky, currentGround):
        
        # crée le nom du futur dossier
        completDir = self.nameDir
        if currentHour==0:
            completDir = completDir+"_0"
        else:
            completDir = completDir+"_"+str(round(currentHour/(self.maxHour-1),2))
        
        if currentFog==0:
            completDir = completDir+"_0"
        else:
            completDir = completDir+"_"+str(round(currentFog/(self.maxFog-1),2))
        
        if currentCould==0:
            completDir = completDir+"_0"
        else:
            completDir = completDir+"_"+str(round(currentCould/(self.maxCould-1),2))
        
        completDir = completDir+"_"+str(currentSky)
        completDir = completDir+"_"+str(currentGround)

        print(completDir)
        print("H:"+str(currentHour)+", F:"+str(currentFog)+", C:"+str(currentCould)+", S:"+str(currentSky)+", G:"+str(currentGround))
        
        #si le dossier n'a pas déjà été créé
        if not os.path.exists(completDir):
            coordRender = self.listCoord[12]
            coordRenderCam = self.listCoord[13]
            coordFullScreen = self.listCoord[14]

            #lance les captures
            self.clic(coordRender)
            self.clic(coordRenderCam)

            #attend que les captures soient finis
            time.sleep(2)
            nbrFiles = len(os.listdir("Build\\Armada_Data\\Images"))
            saveEnCours = True
            while saveEnCours:
                time.sleep(0.75)
                nbrFiles2 = len(os.listdir("Build\\Armada_Data\\Images"))
                if nbrFiles==nbrFiles2:
                    saveEnCours = False
                else:
                    nbrFiles = nbrFiles2
            
            time.sleep(3)
            self.altF4()
            time.sleep(0.5)
            self.clic(coordFullScreen)
            self.clic(coordRender)

            os.rename("Build\\Armada_Data\\Images", completDir)
        
    #modifie l'heure de loc1 à loc2
    def setTime(self, loc1, loc2):
        
        if self.maxHour>1:
            coordTimeOfDay = self.listCoord[0]
            coordHourMin = self.listCoord[1]
            coordHourMax = self.listCoord[2]
            
            margeByHour = (coordHourMax[0]-coordHourMin[0])/(self.maxHour-1)
            self.clic(coordTimeOfDay)
            actualCoord = (int(coordHourMin[0]+loc1*margeByHour), coordHourMin[1])
            futurCoord = (int(coordHourMin[0]+loc2*margeByHour), coordHourMin[1])
            self.clicMove(actualCoord, futurCoord)
            self.clic(coordTimeOfDay)
            
    #modifie le brouillare de loc1 à loc2
    def setFog(self, loc1, loc2):
    
        if self.maxFog>1:
            coordWeather = self.listCoord[3]
            coordFogMin = self.listCoord[4]
            coordFogMax = self.listCoord[5]
            
            margeByFog = (coordFogMax[0]-coordFogMin[0])/(self.maxFog-1)
            self.clic(coordWeather)
            actualCoord = (int(coordFogMin[0]+loc1*margeByFog), coordFogMin[1])
            futurCoord = (int(coordFogMin[0]+loc2*margeByFog), coordFogMin[1])
            self.clicMove(actualCoord, futurCoord)
            self.clic(coordWeather)
        
    #modifie les nuages de loc1 à loc2
    def setCould(self, loc1, loc2):
    
        if self.maxCould>1:
            coordWeather = self.listCoord[3]
            coordCouldMin = self.listCoord[6]
            coordCouldMax = self.listCoord[7]
            
            margeByCould = (coordCouldMax[0]-coordCouldMin[0])/(self.maxCould-1)
            self.clic(coordWeather)
            actualCoord = (int(coordCouldMin[0]+loc1*margeByCould), coordCouldMin[1])
            futurCoord = (int(coordCouldMin[0]+loc2*margeByCould), coordCouldMin[1])
            self.clicMove(actualCoord, futurCoord)
            self.clic(coordWeather)
        
    #passe au ciel suivant
    def setSky(self):
    
        if self.maxSky>1:
            coordWeather = self.listCoord[3]
            coordNextSky = self.listCoord[8]
            
            self.clic(coordWeather)
            self.clic(coordNextSky)
            self.clic(coordWeather)

    #modifie le sol
    def setGround(self, newGround):
    
        if self.maxGround>1:
            newGround = newGround+1
            
            coordGround = self.listCoord[9]
            coordGround1 = self.listCoord[10]
            coordGround2 = self.listCoord[11]
            
            margeByGround = coordGround2[0]-coordGround1[0]
            self.clic(coordGround)
            time.sleep(1)
            x = (newGround%2)*margeByGround + coordGround1[0]
            y = (int(newGround/2))*margeByGround + coordGround1[1]
            self.clic((x,y))
            time.sleep(0.5)
            self.clic(coordGround)
            time.sleep(1)
    
    
#lit les coordonées des boutons dans le fichier coord.txt
def getCoord():
        fichier = open("coord.txt", "r")
        textSplit = fichier.read().split("\n")
        fichier.close()

        for line in textSplit:
            var = re.findall("\((.*), (.*)\)", line)
            if len(var)!=0:
                var[0] = (int(var[0][0]),int(var[0][1]))
                
                if "Time of day" in line:
                    coordTimeOfDay = var[0]
                if "hourMin" in line:
                    coordHourMin = var[0]
                if "hourMax" in line:
                    coordHourMax = var[0]
                if "Weather" in line:
                    coordWeather= var[0]
                if "fogMin" in line:
                    coordFogMin = var[0]
                if "fogMax" in line:
                    coordFogMax = var[0] 
                if "cloudMin" in line:
                    coordCouldMin = var[0]
                if "cloudMax" in line:
                    coordCouldMax = var[0]
                if "nextSky" in line:
                    coordNextSky = var[0]
                if "Ground" in line:
                    coordGround = var[0]
                if "ground1Center" in line:
                    coordGround1Center = var[0]
                if "ground2Center" in line:
                    coordGround2Center = var[0]
                if "Render :" in line:
                    coordRender = var[0]
                if "Render cam" in line:
                    coordRenderCam = var[0]
                if "Full screen" in line:
                    coordFullScreen = var[0]
                    
        return (coordTimeOfDay,
                coordHourMin,
                coordHourMax,
                coordWeather,
                coordFogMin,
                coordFogMax,
                coordCouldMin,
                coordCouldMax,
                coordNextSky,
                coordGround,
                coordGround1Center,
                coordGround2Center,
                coordRender,
                coordRenderCam,
                coordFullScreen)
                
##################################################
# coordonnées à ecrire dans un dossier "coord.txt"
##################################################

#12 plage horaire (clic puis fleche)
#11 intensite de fog (clic puis fleche)
#10 intentite de nuage (slide uniquement)
#11 ciel (clics au meme endroit)
#9 sol (clic)

##################################################
path = ""

print("Condition du lancement du bot :")
print("- armada doit être ouvert en mode plein écran")
print("- les caméras doivent etres placés")
print("- la résolution doit être vérifier")
print("- heure, fog et cloud au minimum, 1e sol selectionne")
#print("- les annotation doivent être selectionne")
print("- tous les onglet de droites doivent etres fermes\n")

print("Si les clic ne sont pas bien localiser, les refaires avec setCoord.py")
input("Cliquer sur entrer quand c'est bon !")

numPylon = input("Quel est le numero du pylone ? (1 à 8)")
nameDir = numPylon

typeDt = input("Detection de Pylone ou de Default ? (p/d)")

if typeDt=="p":

    #valeur utilisés pour les BDD de pylones
    nbrHour = 5
    nbrFog = 4
    nbrCould = 1
    nbrSky = 1
    nbrGround = 5

    nameDir = nameDir+"_dtPylone"
    
else:

    #valeur utilisés pour les BDD de defauts
    nbrHour = 5
    nbrFog = 4
    nbrCould = 3
    nbrSky = 2 #11 max
    nbrGround = 2 #8 max

    nameDir = nameDir+"_dtDefault"
    var = input("Les defauts sont-ils visibles ? (y/n)")
    if(var=="y"):
        nameDir = nameDir+"_1"
    else:
        nameDir = nameDir+"_0"

    print("Num de defaut :")
    print("0 : rien")
    print("1 : isolateur")
    print("2 : nid")
    print("3 : rouille")

    var = input("Quel est le numero du type de default ? Si vous n'avez pas de default, auquel va-t-il etre comparé ?")
    nameDir = nameDir+"_"+var

"""verifDir = True
cpt = 0
while verifDir:
    path = "Build"+id+"\\Armada_Data\\"+str(cpt)+"_"+nameDir
    if():
        cpt = cpt+1
    else:
        verifDir = False"""
#path = "Build\\Armada_Data\\000_test"
path = pathBuildFile+"Build\\Armada_Data\\"+nameDir
#path = "Build1\\Armada_Data\\0_test"

listCoord = getCoord()
bot = myLittleBot(listCoord, nbrHour, nbrFog, nbrCould, nbrSky, nbrGround, path)
bot.run()

winsound.Beep(2500, 1000)