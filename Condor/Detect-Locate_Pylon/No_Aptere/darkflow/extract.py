import cv2
from darkflow.net.build import TFNet
import matplotlib.pyplot as plt

# define the model options and run

options = {
    'metaLoad': 'built_graph/tiny-yolo.meta',
    'pbLoad': 'built_graph/tiny-yolo.pb',
    'threshold': 0.3,
}

tfnet = TFNet(options)

# read the color image and covert to RGB
imgPath = "path_to_your_test_img"


img = cv2.imread(imgPath2, cv2.IMREAD_COLOR)
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# use YOLO to predict the image
result = tfnet.return_predict(img)

# if result vide (tableau) alors aucune prédiction n'a été faite.

print("**************************************************************************************************************")
print(result)
print("**************************************************************************************************************")


# pull out some info from the results
tl = (result[0]['topleft']['x'], result[0]['topleft']['y'])
br = (result[0]['bottomright']['x'], result[0]['bottomright']['y'])
label = result[0]['label']

fig = plt.figure()
# add the box and label and display it
img = cv2.rectangle(img, tl, br, (0, 255, 0), 7)
img = cv2.putText(img, label, tl, cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)
plt.imshow(img)
plt.show()

img_extract=img[result[0]['topleft']['y']:result[0]['bottomright']['y'], result[0]['topleft']['x']:result[0]['bottomright']['x']]

plt.imshow(img_extract)
plt.show()
