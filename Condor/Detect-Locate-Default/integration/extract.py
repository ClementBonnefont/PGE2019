import cv2
from darkflow.net.build import TFNet
import matplotlib.pyplot as plt
import argparse
import json

''' extract_nest
Lance le réseau de neurone yolo sur l'image dont le path est en paramètre.
Retourne toutes les erreurs détéctées.

Entrée : 
- path : chemin de l'image a traiter

Sortie :
- data : dictionnaire contenant la liste des nies détéctées'''

def extract_nest(path):

    #chargement de l'entrainement des nies
    options = {
        'metaLoad': '../darkflow/built_graph/tiny-yolo-voc-nest.meta',
        'pbLoad': '../darkflow/built_graph/tiny-yolo-voc-nest.pb',
        'threshold': 0.4,
    }

    tfnet = TFNet(options)


    #lecture de l'image
    img = cv2.imread(path, cv2.IMREAD_COLOR)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    data={}

    data['defaults']=[]


    try:
        # use YOLO to predict the image
        result = tfnet.return_predict(img)

        print(result)

        img.shape
        
        fig = plt.figure()
        
        # pull out some info from the resultss
        for i in range(len(result)):
            tl = (result[i]['topleft']['x'], result[i]['topleft']['y'])
            br = (result[i]['bottomright']['x'], result[i]['bottomright']['y'])
            label = result[i]['label']    
            data['defaults'].append({
            'label':label,
            'xmin':result[i]['topleft']['x'],
            'ymin': result[i]['topleft']['y'],
            'xmax':result[i]['bottomright']['x'],
            'ymax': result[i]['bottomright']['y'],
            })
            print(data)
            # add the box and label and display it
            img = cv2.rectangle(img, tl, br, (0, 255, 0), 7)
            img = cv2.putText(img, label, tl, cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)
            
        cv2.imwrite('results/image_nest.png', img)
        
        """img_extract=img[result[0]['topleft']['y']:result[0]['bottomright']['y'], result[0]['topleft']['x']:result[0]['bottomright']['x']]
        #save the resulted image into a result folder
        cv2.imwrite('results/image_nest.png', img)
        with open('results/defaults_nest.txt', 'w') as outfile:
            json.dump(data, outfile)"""
        
        
    except:
        print("pb avec la detection")

    return data


''' extract_iso
Lance le réseau de neurone yolo sur l'image dont le path est en paramètre.
Retourne touts les isolateurs détéctés.

Entrée : 
- path : chemin de l'image a traiter

Sortie :
- data : dictionnaire contenant la liste des isolateurs détéctées'''

def extract_iso(path):

    #chargement de l'entrainement des isolateur
    options = {
        'metaLoad': '../darkflow/built_graph/tiny-yolo-voc-iso.meta',
        'pbLoad': '../darkflow/built_graph/tiny-yolo-voc-iso.pb',
        'threshold': 0.4,
    }

    tfnet = TFNet(options)


    #lecture des résultats
    img = cv2.imread(path, cv2.IMREAD_COLOR)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    data={}

    data['defaults']=[]


    try:
        # use YOLO to predict the image
        result = tfnet.return_predict(img)

        print(result)

        img.shape
        
        fig = plt.figure()
        
        # pull out some info from the resultss
        for i in range(len(result)):
            tl = (result[i]['topleft']['x'], result[i]['topleft']['y'])
            br = (result[i]['bottomright']['x'], result[i]['bottomright']['y'])
            label = result[i]['label']    
            data['defaults'].append({
            'label':label,
            'xmin':result[i]['topleft']['x'],
            'ymin': result[i]['topleft']['y'],
            'xmax':result[i]['bottomright']['x'],
            'ymax': result[i]['bottomright']['y'],
            })
            print(data)
            # add the box and label and display it
            img = cv2.rectangle(img, tl, br, (0, 255, 0), 7)
            img = cv2.putText(img, label, tl, cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)
            
        """img_extract=img[result[0]['topleft']['y']:result[0]['bottomright']['y'], result[0]['topleft']['x']:result[0]['bottomright']['x']]
        #save the resulted image into a result folder
        cv2.imwrite('results/image_nest.png', img)
        with open('results/defaults_nest.txt', 'w') as outfile:
            json.dump(data, outfile)"""
        
        
    except:
        print("pb avec la detection")

    return data