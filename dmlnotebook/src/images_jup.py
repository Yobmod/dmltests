#***************Method 1: Using PILLOW (PIL)****************

# importing PIL Module
from PIL import Image

# Read image
img = Image.open('./earth-globe.jpg')

# Display image
img.show()


# #***************Method 2: Using matplotlib****************
#
# # importing matplotlib modules
# import matplotlib.pyplot as plt
# import matplotlib.image as mpimg
#
# # Read image
# img = mpimg.imread('./earth-globe.jpg')
#
# # Display image
# plt.imshow(img)
# plt.show()
#
# #***************Method 3: Using imageio and matplotlib****************
#
# # importing imageio module
# import imageio
# # importing matplotlib module
# import matplotlib.pyplot as plt
#
# # Read image
# img = imageio.imread('./earth-globe.jpg')
#
# # Display image with matplotlib module
# plt.imshow(img)
# plt.show()
#
#
# #***************Method 4: Using OpenCV-Python****************
#
# # importing cv2 module
# import cv2 as cv
#
# # Read image
# img = cv.imread('./earth-globe.jpg',-1)
#
# # Display image
# cv.imshow('image',img)
# # to display image until you press any key
# cv.waitKey(0)
# # to destroy all windows
# cv.destroyAllWindows()
#
# #***************Method 5: Using OpenCV-matpotlib****************
#
# # importing opencv-python (cv2) Module
# import cv2 as cv
# # importing matplotlib Module
# import matplotlib.pyplot as plt
#
# # Read image with opencv-python (cv2)
# img = cv.imread('./earth-globe.jpg',1)
#
# # opencv retun BGR Color mode,
# # but matplotlib needs RGB Color mode
# # So we will convert BGR to RGB
# RGBimg = cv.cvtColor(img, cv.COLOR_BGR2RGB)
#
# # Display image with matplotlib module
# plt.imshow(RGBimg)
# plt.show()











