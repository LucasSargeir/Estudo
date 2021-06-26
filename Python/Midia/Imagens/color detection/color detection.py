from PIL import Image
import numpy as np
import os


def color_percent_detection(file, color):
	print(f'Analisando imagem {file}...')

	im = Image.open('imagens/'+file).convert('RGB')
	data = np.array(im)
	vermelho, verde, azul = data.T

	linhas = len(vermelho)
	colunas	= len(vermelho[0])

	total_pixels = linhas * colunas
	cont_area_vermelha = 0

	for i in range(linhas):
		for j in range(colunas):
			if vermelho[i][j] == color[0] and verde[i][j] == color[1] and azul[i][j] == color[2]:
				cont_area_vermelha += 1

	return total_pixels, cont_area_vermelha ,f'{((cont_area_vermelha/total_pixels)*100):.2f}%'


if __name__ == '__main__':

	result = []
	arquivos = os.listdir('imagens')
	color = (237, 27, 36)
	# file = 'marcada.png'

	print(arquivos)

	for a in arquivos:
		if os.path.isfile('imagens/'+a):
			total_pixels, cont_area_vermelha, percent = color_percent_detection(a, color)
			result.append({"arquivo": a, "porcentagem": percent, "total_pixels": total_pixels, "total_pintado": cont_area_vermelha}) 


	str_result = str(result).replace("}, ", "\n\n").replace(", ", "\n").replace("{", "").replace("}", "").replace("[", "").replace("]", "").replace("'", "")

	databse = open('registro.txt', 'w')
	databse.write(str_result)
	databse.close()