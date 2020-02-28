# coding: utf-8
""" Find the position and orientation of a pylon in a image and write it into a json name : "posOr.json"

To execute the file you need to give the path of the image like: python getPosOr_pylPhy.py path_to_my_img.png
"""

import numpy as np
import cv2
import math
import argparse
import json


def filterSeuilMax(img, seuil):
    img0 = (img[:, :, 0] < seuil).astype(np.uint8)
    img1 = (img[:, :, 1] < seuil).astype(np.uint8)
    img2 = (img[:, :, 2] < seuil).astype(np.uint8)

    mask = img0 * img1 * img2
    nimg = img.copy()

    nimg[:, :, 0] = img[:, :, 0] * mask
    nimg[:, :, 1] = img[:, :, 1] * mask
    nimg[:, :, 2] = img[:, :, 2] * mask

    return nimg


def detecteurPylone(filename, demo=False):
    """" Find the box of the pylon top

    filename -- string : the complete path to access the image where is the pylon
    demo -- boolean : if true it will use the filter (default False)

    return : the rect (cv2.minAreaRect), the box(np.int0(cv2.boxPoints)) and shape of the image ((int,int))
    """

    # Read the image
    img = cv2.imread(filename, cv2.IMREAD_COLOR)

    # Get resolution
    resolution = img.shape

    # Convert BGR to RGB
    img = cv2.cvtColor(img.copy(), cv2.COLOR_BGR2RGB)

    # Filter for the pylon on the support
    if demo:
        img_filt = filterSeuilMax(img, 50)
        # Convert to gray
        gray = cv2.cvtColor(img_filt.copy(), cv2.COLOR_RGB2GRAY)
    else:
        # Convert to gray
        gray = cv2.cvtColor(img.copy(), cv2.COLOR_RGB2GRAY)

    # Use canny to extract edges
    edges = cv2.Canny(gray.copy(), 100, 200)

    # Dilate image for edges become more visible
    kernel = np.ones((5, 5), np.uint8)
    img_dilation = cv2.dilate(edges.copy(), kernel, iterations=3)

    # Extracting contours and get the pylone rect and box
    _, cnts, _ = cv2.findContours(img_dilation.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    c = max(cnts, key=cv2.contourArea)
    rect = cv2.minAreaRect(c)
    box = cv2.boxPoints(rect)
    box = np.int0(box)

    return rect, box, resolution


def posOrPylon(filename, knowWidth, focal, demo=False):
    """" Find the position and orientation of the pylon in a image

    rect -- cv2.minAreaRect : the rect of the box of the pylon
    box -- np.int0(cv2.boxPoints) : the box of the pylon
    resolution -- (int,int) : shape of the image (pixels)
    knowWidth -- int/float : dimension of the pylon in the image but in real life (in cm)
    focal -- float : the value of the focal

    return : coordinate of pylon_center ((int,int)), height of the pylon in pixel (int),
             width of the pylon in pixel (int),  angle in radians (float),
             position of pylon compared to camera (left for zed) in cm posCompePylone [float, float, float]
    """

    rect, box, resolution = detecteurPylone(filename, demo)

    # center point of the pylon
    pylon_center = np.mean(box, axis=0)

    # In order of the box we will have points : A B C D
    # width = AB or width = CD
    # height = BC or height = AD
    # AB=sqrt( (x_B - x_A)^2 + (y_B-y_A)^2 )
    A = box[0]
    B = box[1]
    C = box[2]
    D = box[3]

    # calculate the width which is the mean between AB and CD
    dist_x = B[0] - A[0]
    dist_y = B[1] - A[1]
    dist1_1 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist_x = D[0] - C[0]
    dist_y = D[1] - C[1]
    dist1_2 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist1 = np.mean([dist1_1, dist1_2])

    # calculate the height which is the mean between BC and AD
    dist_x = C[0] - B[0]
    dist_y = C[1] - B[1]
    dist2_1 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist_x = D[0] - A[0]
    dist_y = D[1] - A[1]
    dist2_2 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist2 = np.mean([dist2_1, dist2_2])

    # height in pixel
    # width in pixel
    height = min(dist1, dist2)
    width = max(dist1, dist2)

    # Calculate the rotation of the box
    if rect[1][0] > rect[1][1]:  # if width > height
        angle = rect[2]
    else:
        angle = rect[2] + 90
    # Transform the angle in radians
    angle = math.radians(angle)

    tailleByPixel = knowWidth / width  # in cm by pixel
    diffCenterX = resolution[0] / 2 - pylon_center[0]
    diffCenterY = resolution[1] / 2 - pylon_center[1]
    hauteurDrone = distance_to_camera(knowWidth, focal, width)

    # posCompPylone = [X, Y, Height] compare to pylon in cm
    posCompePylone = [diffCenterX * tailleByPixel, diffCenterY * tailleByPixel, hauteurDrone]

    return pylon_center, height, width, angle, posCompePylone


def distance_to_camera(knownWidth, focalLength, perWidth):
    # compute and return the distance to the camera
    return (knownWidth * focalLength) / perWidth


if __name__ == '__main__':

    parser = argparse.ArgumentParser()
    parser.add_argument("path_img", help="Give the path of the image to get position and orientation")
    args = parser.parse_args()

    focal = 2104.7619047619046  # Focal of the ZED cam, calculate with python code : "calculateFocalLength.py"
    pylon_phy_width = 44  # cm

    pylon_center, height, width, angle, posPylon = posOrPylon(args.path_img, pylon_phy_width, focal, True)

    # We write the json in a file name "posOr.json"
    data = {}

    data['pos'] = []
    data['pos'].append({
        'x': posPylon[0],
        'y': posPylon[1],
        'z': posPylon[2]
    })

    data['rot'] = []
    data['rot'].append({
        'angle': angle
    })

    with open('posOr.json', 'w') as outfile:
        json.dump(data, outfile)
