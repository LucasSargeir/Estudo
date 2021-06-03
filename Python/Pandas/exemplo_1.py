import pandas as pd

def corrigi_provas(notas, gabarito):
	lista_nota = []
	for resp in range(len(notas)):
		acertos = 0
		for q in range(len(notas[resp])):
			if notas[resp][q] == gabarito[q]:
				acertos = acertos + 1
		lista_nota.append(acertos)
	return lista_nota


status = {1: 'Fraco', 2:'Regular', 3:'Bom', 4:'Distinção'}
graus = [(1, 2, 3, 4), (5,6), (7,8), (9,10)]

def encontra_situacao(nota):
	situacao = -1
	for i in range(len(graus)):
		if nota in graus[i]:
			situacao = status[i+1]
			break
	return situacao


alunos = ["ALEX HOMBURGER","ALEXANDRE CARDOSO","ANA BRANDÃO","ANA NOBRE", "ANDRÉ NOÉ","ANDRE SALLES","ARTHUR MARTINS","BRENNO ALENCASTRO", "BRUNO VICENTE","CAIO PICANÇO","CARLOS GUIMARÃES","DANIEL ABDALLA", "DANIEL ANTUNES","DANIEL BRAUNE","DELANO QUEIROZ", "EDUARDO SAUER", "EDUARDO ADAMI", "ERIK BRAGA","EVELYN SOUZA","FERNANDA SALAZAR"]
respostas = [(1,2,1,3,4,2,1,5,5,4), (1,2,4,3,4,3,1,2,5,3), (1,2,4,3,4,3,1,5,5,3), (2,2,4,3,4,3,1,5,5,3), (1,2,4,3,4,3,2,5,5,3), (1,2,5,3,4,3,3,5,5,3), (3,1,4,3,3,3,2,5,5,4), (1,2,3,3,2,2,1,5,5,4), (1,2,4,2,3,3,2,2,5,4), (2,2,3,2,4,3,1,5,4,4), (1,1,5,2,4,3,2,5,5,5), (2,2,4,2,4,2,3,5,3),  (1,3,1,3,4,2,2,4,2,3), (1,4,4,3,4,2,1,5,5,3), (1,5,2,3,3,3,1,3,5,3), (1,4,3,3,3,4,1,5,5,3), (4,5,2,2,3,2,1,2,1,3), (1,1,4,5,4,3,1,3,5,3), (2,2,3,5,4,3,1,5,5,3), (1,2,4,3,4,3,1,5,5,3)]
gabarito = [1,2,4,3,4,3,1,5,5,3]

notas = corrigi_provas(respostas, gabarito)
status_alunos = []

for i in notas:
	status_alunos.append(encontra_situacao(i))



nota_e_status = (list(zip(notas, status_alunos)))
dados = pd.DataFrame(nota_e_status, columns=['Nota', 'Status'], index=alunos) 
dados = dados.sort_values(by="Nota", ascending=False, axis=0, kind='quicksort')

indexes = dados.index

for i in range(4):
	status, nota = dados.iloc[i].values
	print("Nome: "+str(indexes[i])+"\tNota:"+str(nota)+"\tSatus:"+str(status))


print(f"Média das notas: {dados['Nota'].mean():.2f}")