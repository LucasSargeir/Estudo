from PIL import Image
import numpy as np

def change_one_color(src:str, dest:str,last_color: tuple, new_color: tuple):
	im = Image.open(src).convert('RGB')
	# Pega a imagem como um numpy.array com formato altura x largura x num_canais
	data = np.array(im)
	# Pego cada canal como um array separado para facilitar reconhecer o branco
	vermelho, verde, azul = data.T
	# Defino a condição (ser branco)
	condicao = (vermelho == last_color[0]) & (verde == last_color[1]) & (azul == last_color[2])
	# Substitui a cor branca pela cor desejada
	data[condicao.T] = new_color
	# Volto o array para uma imagem do PIL
	im2 = Image.fromarray(data)
	im2.save(dest)

def set_transparent_background(src:str, dest:str,color: tuple):
	im = Image.open(src).convert('RGBA')
	data = np.array(im)
	print(data)
	vermelho, verde, azul, alpha = data.T
	condicao = (vermelho == color[0]) & (verde == color[1]) & (azul == color[2])
	data[condicao.T] = (0, 0, 0, 0)
	im2 = Image.fromarray(data)
	im2.save(dest)


new_color = (200, 200, 0)
last_color = (55,56,55)
set_transparent_background('001.png','001.png',last_color)
#change_one_color('386.png','./new.png',last_color, new_color)