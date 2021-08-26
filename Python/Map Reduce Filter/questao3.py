from functools import *

def questao_3():
	filmes = [
	{"id": 70111470,"title": "Die Hard","rating": [4.0]},
	{"id": 654356453,"title": "Bad Boys","rating": [5.0]},
	{"id": 65432445,"title": "The Chamber","rating": [3.0]}]
	
	print(f"\tAvaliações de Filmes:")
	
	for f in filmes:
		print(f"\t\tID: {f['id']}\n\t\tTitle: {f['title']}\n\t\tRating:{f['rating'][0]}\n")
	
	

	def letra_a(filmes):
		filtraFilme = lambda filme: filme['rating'][0] >= 4.0
		pegaNomeFilme = lambda filme: filme['title']
		
		result = list(map(pegaNomeFilme,filter(filtraFilme, filmes)))
		
		print(f"Filmes com Rating Superior a 4: {result}")
	
	

	def letra_b(filmes):
		filtraFilme = lambda filme: filme['rating'][0] >= 4.0
		pegaNomeFilme = lambda filme: {'id':filme['id'],'title':filme['title']}
		
		result = list(map(pegaNomeFilme,filter(filtraFilme, filmes)))
	
		print(f"Objetos dos filmes acima: {result}")
	
	print("\ta) ", end='')
	letra_a(filmes)
	print("\tb) ", end='')
	letra_b(filmes)

questao_3()