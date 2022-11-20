def cria_identidade(tamanho):
	matriz = [] 
	for i in range(tamanho):
		linha = [0.0] * tamanho
		linha[i] = 1.0
		matriz.append(linha)

	return matriz

def mostra_matriz(matriz):
	for linha in matriz:
		for coluna in linha:
			print(coluna, end = '\t')
		print()
	print()

def matriz_inversa(matriz, matriz_identidade):

	tamanho = len(matriz)

	for coluna in range(tamanho):
		
		pivo = matriz[coluna][coluna]

		for k in range(tamanho):
			matriz[coluna][k] = matriz[coluna][k]/pivo
			matriz_identidade[coluna][k] = matriz_identidade[coluna][k]/pivo

		for linha in range(tamanho):
			if linha != coluna:
				m = matriz[linhaera][coluna]

				for k in range(tamanho):
					matriz[linha][k] = matriz[linha][k] - (m * matriz[coluna][k])
					matriz_identidade[linha][k] = matriz_identidade[linha][k] - (m * matriz_identidade[coluna][k])

	return matriz_identidade


print("---------[3x3]---------")

matriz = [
	[ 1, 1, 1],
	[ 3, 5, 4],
	[ 3, 6, 5],
]

print("Matriz")
mostra_matriz(matriz)

matriz_identidade = cria_identidade(3)
inversa = matriz_inversa(matriz, matriz_identidade)

print("Inversa")
mostra_matriz(inversa)


print("\n\n---------[4x4]---------")

matriz = [
	[ 1, 2, 0, 1],
	[-1,-3, 0, 1],
	[ 3, 6, 1, 3],
	[ 2, 4, 0, 3]
]

print("Matriz")
mostra_matriz(matriz)

matriz_identidade = cria_identidade(4)
inversa = matriz_inversa(matriz, matriz_identidade)

print("Inversa")
mostra_matriz(inversa)
