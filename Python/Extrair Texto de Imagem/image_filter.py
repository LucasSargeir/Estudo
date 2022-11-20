import cv2
import numpy as np
from PIL import Image
from skimage.filters import threshold_local

def noise_reduction(image, channel = (1,0,1)):
	
	npimagem = np.asarray(image).astype(np.uint8)

	# diminuição dos ruidos antes da binarização
	if(channel[0] == 1):
		npimagem[:, :, 0] = 0 # zerando o canal R (RED)

	if(channel[1] == 1):
		npimagem[:, :, 1] = 0 # zerando o canal G (GREEN)

	if(channel[2] == 1):	
		npimagem[:, :, 2] = 0 # zerando o canal B (BLUE)

	height = len(npimagem)
	width = len(npimagem[0])

	# atribuição em escala de cinza
	im = cv2.cvtColor(npimagem, cv2.COLOR_RGB2GRAY) 
	T = threshold_local(im, 101, offset = 10, method = "mean")
	im = (im > T).astype("uint8") * 255

	# aplicação da truncagem binária para a intensidade
	# pixels de intensidade de cor abaixo de 127 serão convertidos para 0 (PRETO)
	# pixels de intensidade de cor acima de 127 serão convertidos para 255 (BRANCO)
	# A atrubição do THRESH_OTSU incrementa uma análise inteligente dos nivels de truncagem
	# reconvertendo o retorno do threshold em um objeto do tipo PIL.Image
	return Image.fromarray(im), width, height

if __name__ == "__main__":
	
	file = input('Entre com o nome do arquivo: ')
	
	img = Image.open(file).convert('RGB')
	
	img2, w, h = noise_reduction(img)
	img2.save('_'+file)
	print(f'{w} x {h}')
