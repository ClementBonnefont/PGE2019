from imutils import paths
import numpy as np
import cv2
import matplotlib.pyplot as plt
import math


# Find marker yellow on image and return its rect, box, height and width in the image
def find_marker(path, show=1):
    image = cv2.imread(path)
    # convert to rgb
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    #print(image.shape)
    if show:
        plt.imshow(image)
        plt.show()

    # convert the image to grayscale, blur it, and detect edges
    #gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    yellow = np.absolute(image[:,:,0] - image[:,:,2])
    maskYinf = (yellow > 20).astype(np.int)
    maskYsup = (yellow < 100).astype(np.int)
    maskY = maskYinf * maskYsup
    #maskY = maskYinf
    #print(maskY.shape)

    img = np.zeros(image.shape).astype(np.uint8)
    img[:, :, 0] = (image[:, :, 0] * maskY[:, :])
    img[:, :, 1] = (image[:, :, 1] * maskY[:, :])
    img[:, :, 2] = (image[:, :, 2] * maskY[:, :])

    #print(img)
    if show:
        plt.imshow(img)
        plt.show()

    # find the contours in the edged image and keep the largest one;
    # we'll assume that this is our piece of paper in the image
    gray = cv2.cvtColor(img.copy(), cv2.COLOR_RGB2GRAY)
    _, cnts, _ = cv2.findContours(gray.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    img_cont = cv2.drawContours(image.copy(), cnts, -1, (0, 0, 0), 3)
    if show:
        plt.imshow(img_cont)
        plt.show()

    # compute the bounding box of the of the paper region and return it
    c = max(cnts, key=cv2.contourArea)
    rect = cv2.minAreaRect(c)

    # box a 2 dimension tel que : box[0] -> point en bas à droite ->box[0][0]=x et box[0][1]=y
    #                             box[1] -> point en bas à gauche
    #                             box[2] -> point en haut à gauche
    #                             box[3] -> point en haut à droite
    box = cv2.boxPoints(rect)
    box = np.int0(box)
    img_box = cv2.drawContours(image.copy(), [box], 0, (0, 0, 255), 3)
    if show:
        print(box.shape)
        plt.imshow(img_box)
        plt.show()

    '''dist_x = box[0][0] - box[1][0]
    dist_y = box[0][1] - box[1][1]
    dist1 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist_x = box[1][0] - box[2][0]
    dist_y = box[1][1] - box[2][1]
    dist2 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    
    height = min(dist1, dist2)
    width = max(dist1, dist2)'''

    # In order of the box we will have points : A B C D
    # width = AB or width = CD
    # height = BC or height = AD
    # AB=sqrt( (x_B - x_A)^2 + (y_B-y_A)^2 )
    A = box[0]
    B = box[1]
    C = box[2]
    D = box[3]

    # calculate the width which is the mean between AB and CD
    dist_x = B[0]-A[0]
    dist_y = B[1]-A[1]
    dist1_1 = math.sqrt(dist_x**2 + dist_y**2)
    dist_x = D[0] - C[0]
    dist_y = D[1] - C[1]
    dist1_2 = math.sqrt(dist_x**2 + dist_y**2)
    dist1 = np.mean([dist1_1, dist1_2])

    # calculate the height which is the mean between BC and AD
    dist_x = C[0] - B[0]
    dist_y = C[1] - B[1]
    dist2_1 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist_x = D[0] - A[0]
    dist_y = D[1] - A[1]
    dist2_2 = math.sqrt(dist_x ** 2 + dist_y ** 2)
    dist2 = np.mean([dist2_1, dist2_2])

    height = min(dist1, dist2)
    width = max(dist1, dist2)

    return rect, box, height, width


# D = (W x F) / P
def distance_to_camera(knownWidth, focalLength, perWidth):
    # compute and return the distance from the maker to the camera
    return (knownWidth * focalLength) / perWidth


if __name__ == '__main__':

    # initialize the known distance from the camera to the object, which
    # in this case is 100cm and 120cm
    KNOWN_DISTANCE1 = 100
    KNOWN_DISTANCE2 = 120

    # initialize the known object width, which in this case, the piece of
    # paper is 21cm wide
    KNOWN_WIDTH = 21

    rect, box, height, width = find_marker("image_test/Paper/Left/Image_left_1_1m.png")  # Image de 1m de distance
    # F = (P x  D) / W
    # F: perceived focal length
    # P: the apparent width in pixels
    # D: distance
    # W: known width
    focalLength = (width * KNOWN_DISTANCE1) / KNOWN_WIDTH
    print("previous focal Length")
    print(focalLength)

    # calculate perfect box with the first point of ex box and size calculate previously:
    perfect_box = box.copy()
    perfect_box[1][0] = box[0][0] - height  # calculate x_B = x_A - width
    perfect_box[1][1] = box[0][1]  # calculate y_B = y_A
    perfect_box[2][0] = perfect_box[1][0]  # calculate x_C = x_B
    perfect_box[2][1] = perfect_box[1][1] - width  # calculate y_C = y_B - height
    perfect_box[3][0] = perfect_box[0][0]  # calculate x_D = x_A
    perfect_box[3][1] = perfect_box[2][1]  # calculate y_D = y_C

    # Recalculate width and height with the perfect box:
    A = perfect_box[0]
    B = perfect_box[1]
    C = perfect_box[2]
    D = perfect_box[3]

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

    perfect_height = min(dist1, dist2)
    perfect_width = max(dist1, dist2)

    # F = (P x  D) / W
    # F: perceived focal length
    # P: the apparent width in pixels
    # D: distance
    # W: known width
    perfect_focalLength = (perfect_width * KNOWN_DISTANCE1) / KNOWN_WIDTH
    print("new focal Length")
    print(perfect_focalLength)

    # Show new perfect box:
    image = cv2.imread("image_test/Paper/Left/Image_left_1_1m.png")
    nimage = cv2.drawContours(image, [perfect_box], -1, (255, 0, 0), 2)
    plt.imshow(nimage)
    plt.show()



    # loop over the images
    for imagePath in sorted(paths.list_images("image_test/Paper/Left")):
        # load the image, find the marker in the image, then compute the
        # distance to the marker from the camera
        rect, box, height, width = find_marker(imagePath, show=0)
        d = distance_to_camera(KNOWN_WIDTH, perfect_focalLength, width)

        # draw a bounding box around the image and display it
        image = cv2.imread(imagePath)
        cv2.drawContours(image, [box], -1, (0, 255, 0), 2)
        cv2.putText(image, "%.2fcm" % d,
                    (image.shape[1] - 300, image.shape[0] - 30), cv2.FONT_HERSHEY_SIMPLEX,
                    2.0, (0, 255, 0), 3)
        cv2.imshow("image", image)
        cv2.waitKey(0)
