from functools import *

def questao_2():
	nomes = ["Ben", "Jafar", "Matthews", "Priya", "Brian"]
	limpaLista = lambda l: str(l).replace("'", '').replace("[","").replace("]", "")

	print(f"\tNomes: {limpaLista(nomes)}\n")



	def letra_a(nomes):
		inverterNome = lambda nome: nome[::-1]
		result = list(map(inverterNome, nomes))
		print(f"Nomes Invertidos {result}")



	def letra_b(nomes):
		defineMaior = lambda acc, curr: acc if len(acc) > len(curr) else curr
		result = reduce(defineMaior, nomes)
		print(f"Maior nome: {result}")


	print("\ta) ", end='')
	letra_a(nomes)
	print("\tb) ", end='')
	letra_b(nomes)

questao_2()