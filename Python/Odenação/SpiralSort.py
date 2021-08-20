#Ordenar um vetor de forma espiral, ou seja, o primeiro elemento é o
#meno, o ultimo elemento e o segundo menor, o segundo elemento o 
#terceiro menor, o penultimo elemento o quarto menor, e assim por 
#diante.

vetor = [50,30,16,40,8,0,10]

#Interativo
def SpiralSortIterativo(vetor, n):
	inicio = 0
	fim = n-1

	sentido = 0

	while inicio != fim:
		if sentido == 0:
			menor = inicio
		else:
			menor = fim

		for i in range(inicio, fim+1):
			if vetor[menor] > vetor[i]:
				menor = i

		if sentido == 0:
			aux = vetor[menor]
			vetor[menor] = vetor[inicio]
			vetor[inicio] = aux

			inicio += 1
			sentido = 1
		else:
			aux = vetor[menor]
			vetor[menor] = vetor[fim]
			vetor[fim] = aux

			fim -= 1
			sentido = 0
	

	return vetor

#Recursivo
def SpiralSortRecursivo(vetor,inicio, fim, sentido):
	if(inicio == fim):
		return vetor
	else:
		if sentido == 0:
			SpiralSortRecursivo(vetor, inicio + 1, fim, 1)
			if vetor[inicio] > vetor[fim]:
				aux = vetor[inicio]
				vetor[inicio] = vetor[fim]
				vetor[fim] = aux
		else:
			SpiralSortRecursivo(vetor, inicio, fim - 1, 0)
			if vetor[fim] > vetor[inicio]:
				aux = vetor[inicio]
				vetor[inicio] = vetor[fim]
				vetor[fim] = aux

		return vetor

print("Interativo: \n\t" + str(SpiralSortIterativo(vetor,len(vetor))).replace('[','').replace(']','').replace(', ','\t'))
print("Recursivo: \n\t" + str(SpiralSortRecursivo(vetor,0, len(vetor)-1,0)).replace('[','').replace(']','').replace(', ','\t'))
