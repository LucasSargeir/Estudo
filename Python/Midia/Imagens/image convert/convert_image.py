#from PIL import Image
#im = Image.open("./001.gif")
#bg = Image.new("RGB", im.size)
#bg.paste(im,im)
#bg.save("./001.png")

from PIL import Image

def convert_transparancy(src:str, dest:str):
	im = Image.open(src)
	transparency = im.info['transparency'] 
	im .save(dest, transparency=transparency)

def convert_creating_background(src:str, dest:str):
	im = Image.open(src)
	im = im.convert('RGB').convert('P', palette=Image.ADAPTIVE)
	im.save(dest)

convert_creating_background('001.gif', '001.png')