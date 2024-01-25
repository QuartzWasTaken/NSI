from PIL import Image
from PIL import ImageChops

im = Image.open("image1.bmp")
im2 = Image.open("image2.bmp")

diff = ImageChops.difference(im, im2)

if(diff.getbbox()):
    diff.show()