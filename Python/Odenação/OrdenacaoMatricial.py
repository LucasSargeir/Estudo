#Ordenar a matriz de forma que as linhas fiquem em ordem crescente e
#as colunas em ordem decrescente.

matriz = [
	[ 5,  30, 4,  8,100],
	[ 2,  8,  9, 18,20],
	[21, 17,  3,  5,44],
	[ 6, 10, 28, 10,0],
	[ 6, 13, 7, 3,11]
]

def ordenaMatrizLCCD(matriz, n):

	#Ordena toda a matriz
	for i in range(1,n*n):
		pos_i = i//n
		pos_j = i%n

		chave = matriz[pos_i][pos_j]
		k = i
		pos_i2 = (k-1)//n
		pos_j2 = (k-1)%n
		while k > 0 and chave < matriz[pos_i2][pos_j2]:
			matriz[pos_i][pos_j] = matriz[pos_i2][pos_j2]
			k -= 1
			pos_i = k//n
			pos_j = k%n

			pos_i2 = (k-1)//n
			pos_j2 = (k-1)%n
		matriz[pos_i][pos_j] = chave

	#Inverte os elementos das colunas
	for i in range(n//2):
		for j in range(n):
			aux = matriz[i][j]
			matriz[i][j] = matriz[n-1-i][j]
			matriz[n-1-i][j] = aux 

	return matriz

print("Matriz: "+str(ordenaMatrizLCCD(matriz, 5)).replace('],', '\n').replace('[[', '\n [').replace(' ', '\t').replace(']]', '').replace('[', ''))