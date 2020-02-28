import cv2
import numpy as np
import matplotlib.pyplot as plt

''' La méthode de segmentation par profondeur pourrait être utile à explorer dans un cas réel. Avec une simple maquette 
réduite, du fait des performances du capteur ZED il est presque impossible pour se dernier de correctement segmenter 
le pylone, car avec les "trous" il y a des difficulté d'appariements et des zones non reconnues "nan". 
De même la distance séparant le sol du pylone est tres réduit avec la maquette "1m20" ce qui nous laisse 
une marge malgré tout assez fine.'''

depth_measure_path = 'image_test\photo_isolateur\DepthMeasure\Depth_measure_2.yml'
image_left_path = 'image_test\photo_isolateur\Images\Left\Image_left_2.png'

f = cv2.FileStorage(depth_measure_path, cv2.FILE_STORAGE_READ)
a = f.getNode("ocv_depth_measure").mat()
#print("read matrix\n", a)
f.release()

depth_measure = np.array(a)
#print(depth_measure)
#print(depth_measure.shape)

depth_measure = np.where(np.logical_not(np.isnan(depth_measure)), depth_measure, 0)
print(np.max(depth_measure))

filter_pylon = (depth_measure < 4).astype(np.int)
filter_nan = (depth_measure > 0).astype(np.int)
print(filter_pylon)

filter_complete = filter_nan * filter_pylon

image = cv2.imread(image_left_path)
image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
img = np.zeros(image.shape).astype(np.uint8)
img[:, :, 0] = (image[:, :, 0] * filter_complete[:, :])
img[:, :, 1] = (image[:, :, 1] * filter_complete[:, :])
img[:, :, 2] = (image[:, :, 2] * filter_complete[:, :])

plt.imshow(img)
plt.show()
