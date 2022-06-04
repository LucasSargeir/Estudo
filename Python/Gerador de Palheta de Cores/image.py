from PIL import Image

def geraImagem(colors, filename):
	size = 100

	width = size * len(colors)
	height = size

	pillow_obj = Image.new("RGB", (width, height))
	pixel_set = pillow_obj.load()


	indice = 0

	for color in colors:
		for row in range(size):
			for col in range(size):
				pixel_set[col + indice, row] = color

		indice += size

	pillow_obj.save(filename + ".png")


geraImagem([(0,0,0),(150,150,150),(255,255,255)], 'cores')		