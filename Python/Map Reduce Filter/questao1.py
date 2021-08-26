from functools import *

def questao_1():
	notas = [8.0,7.0,8.3,9.0,4.5,6.0,3.7,5.0,7.1,9.5,6.0]
	print(f"\tNotas: {notas}\n")

	def letra_a(notas):
		somaElementos = lambda acc, curr: acc + curr
		result = reduce(somaElementos, notas)/len(notas)
		print(f"Média das Notas: {result}")

	def letra_b(notas):
		filtraAluno = lambda nota: nota >= 6
		result = list(filter(filtraAluno, notas))
		print(f"Notas Aprovados: {result}")

	def letra_c(notas):
		situacaoAlunos = lambda aluno: 'REPROVADO' if aluno < 6 else 'APROVADO'
		result = list(map(situacaoAlunos, notas))
		print(f"Relação dos Alunos: {result}")
	
	print("\ta) ", end='')
	letra_a(notas)
	print("\tb) ", end='')
	letra_b(notas)
	print("\tc) ", end='')
	letra_c(notas)

questao_1()
