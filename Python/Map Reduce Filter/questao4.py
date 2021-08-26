from functools import *

def questao_4():
	medidas = [ { 'label': "sala", 'largura': 4.5, 'comprimento':5 },
	{ 'label': "quarto1" , 'largura': 3.5, 'comprimento':2 },
	{ 'label': "quarto2" , 'largura': 2.7, 'comprimento':2 },
	{ 'label': "banheiro" , 'largura': 1.5, 'comprimento':2 }]
	
	print(f"\tMedidas do apartamento:")

	for m in medidas:
		print(f"\t\tLabel: {m['label']}\n\t\tLargura:{m['largura']}\n\t\tComprimento: {m['comprimento']}\n")
	
	def letra_a(medidas):
		converteMetragem = lambda comodo: {'label': comodo['label'],'metragem':comodo['largura'] * comodo['comprimento']}
		maiorMetragem = lambda acc, curr: acc if acc['metragem'] >curr['metragem'] else curr
		result = reduce(maiorMetragem, map(converteMetragem, medidas))
		print(f"Comodo de maior metragem {result}")
	


	def letra_b(medidas):
		converteMetragem = lambda comodo: comodo['largura'] * comodo['comprimento']
		calculaMetragem = lambda acc, curr: acc + curr
		result = reduce(calculaMetragem, map(converteMetragem, medidas))
		print(f"Metragem total {result}")
	


	def letra_c(medidas):
		filtraQuartos = lambda comodo: "quarto" in comodo['label']
		converteMetragem = lambda comodo: comodo['largura'] * comodo['comprimento']
		calculaMetragem = lambda acc, curr: acc + curr
		result = reduce(calculaMetragem, map(converteMetragem,
		filter(filtraQuartos, medidas)))
		print(f"Metragem total quartos {result}")

	print("\ta) ", end='')
	letra_a(medidas)
	print("\tb) ", end='')
	letra_b(medidas)
	print("\tc) ", end='')
	letra_c(medidas)

questao_4()