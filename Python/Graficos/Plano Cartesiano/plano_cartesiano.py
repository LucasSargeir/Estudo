import matplotlib.pyplot as plt
import math

def the_function(x:int):
	return 704 - (404*math.exp(-0.5*x))



qtd = int(input("Entre com a quantidade de meses: "))

eixo_x = [ i for i in range(qtd + 1)]
eixo_y = [the_function(i) for i in eixo_x]

print("Pares Ordenados")
for i in range(len(eixo_x)):
	print(f"Com {eixo_x[i]} meses o funcionário produz {eixo_y[i]:.2f}.")

plt.plot(eixo_x, eixo_y,  marker='o')
plt.title('Curva de Aprendizagem Peças Produzidas/Tempo de Experiência')
plt.xlabel('Meses de Experiência')
plt.ylabel('Peças Produzidas')
plt.show()
