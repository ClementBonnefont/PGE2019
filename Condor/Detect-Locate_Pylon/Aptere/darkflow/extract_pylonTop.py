# coding: utf-8
"""" Fin the label of a pylon in a image, get it's box and write an image ("extract_pyloneType.jpg")
     and json ('data.json') corresponding

To execute the file you need to give the path of the image like: python extract_pylonTop.py path_to_my_img.png
"""

import cv2
from darkflow.net.build import TFNet
import json
import argparse

def extract(imgPath, options):
    """" Use TinyYolo for extract the label and the box of a pylon in a image and write an image with those infos

    imgPath -- string : path to the image
    options -- dictionnary : key 'metaLoad' with path to the built_graph meta
                            key 'pbLoad' with path to the built_graph pb
                            key 'threshold' with 0.3 value by default

    return : label of the pylon (string), top-left point of the box ((int,int)),
             bottom-right point of the box ((int,int)). And an image is generate : "extract_pyloneType.jpg"
    """
    tfnet = TFNet(options)

    img = cv2.imread(imgPath, cv2.IMREAD_COLOR)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    # use YOLO to predict the image
    result = tfnet.return_predict(img)

    # if result empty then no prediction have been made
    if result:

        # pull out some info from the results
        tl = (result[0]['topleft']['x'], result[0]['topleft']['y'])
        br = (result[0]['bottomright']['x'], result[0]['bottomright']['y'])
        label = result[0]['label']

        # add the box and label and write it
        img = cv2.rectangle(img, tl, br, (0, 255, 0), 7)
        img = cv2.putText(img, label, tl, cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)

        # Write image for send it to the ENVOL interface
        cv2.imwrite("extract_pyloneType.jpg", img)

        print("Well done")

    else:
        label = 0
        tl = 0
        br = 0
        print("Fail")

    return label, tl, br

if __name__ == '__main__':

    # json dictionnary
    data = {}

    parser = argparse.ArgumentParser()
    parser.add_argument("path_img", help="Give the path of the image to predict")
    args = parser.parse_args()
    try:
        with open(args.path_img) as f:
            imgPath = args.path_img
    except IOError:
        print("file not accessible")
        imgPath = ""
        with open('data.json', 'w') as outfile:
            json.dump(data, outfile)

    # Path to post-training files of built_graph
    options = {
        'metaLoad': 'built_graph/tiny-yolo-voc-pylone_phy.meta',
        'pbLoad': 'built_graph/tiny-yolo-voc-pylone_phy.pb',
        'threshold': 0.3,
    }

    (label, tl, br) = extract(imgPath, options)

    # Writing the Json file
    if label != 0:
        data['pylon'] = []
        data['pylon'].append({
            'label': label,
            'top_left_x': tl[0],
            'top_left_y': tl[1],
            'bot_right_x': br[0],
            'bot_right_y': br[1]
        })

    with open('data.json', 'w') as outfile:
        json.dump(data, outfile)
