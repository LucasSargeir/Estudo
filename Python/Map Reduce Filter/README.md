# Map Reduce Filter

Esse repositório guarda algumas questões feitas utilizando `map`, `reduce` e `filter` do *python*. Essas são utilizadas no paradigma funcional para manter o código mais limpo e fácil de entender.



**Linguagem**

- Python (3.8).

**Módulos**

- *functools*



------

### Questão 1
Utilizando estratégias de map-reduce-filter implemente as seguintes operações:

**a)** Gerar a média das notas.
**b)** Gerar um array apenas com os alunos aprovados (media>6).
**c)** Gerar um array de strings com as mensagens 'APROVADO','REPROVADO', no lugar das notas.

**Dados:** 

```python
notas = [8.0,7.0,8.3,9.0,4.5,6.0,3.7,5.0,7.1,9.5,6.0]
```



### Questão 2

Utilizando estratégias de map-reduce-filter implemente as seguintes operações:

**a)** Gerar um array com os caracteres das palavras invertidos (Ex.*["neB","rafaJ",....*).
**b)** Determinar o nome com maior quantidade de caracteres.

**Dados:** 

```python
nomes = ["Ben", "Jafar", "Matthews", "Priya", "Brian"]
```



### Questão 3
Utilizando estratégias de map-reduce-filter implemente as seguintes operações:
**a)** Gerar um array com os nomes dos filmes com rating maior ou igual a 4.
**b)** Gerar um array com um objeto composto dos ids/nomes dos filmes com rating maior ou igual a 4.

**Dados:**

```python
filmes = [
    {
        "id": 70111470,
     	"title": "Die Hard",
     	"rating": [4.0]
     },
	 {
         "id": 654356453,
         "title": "Bad Boys",
         "rating": [5.0]
     },
	 {
         "id": 65432445,
         "title": "The Chamber",
         "rating": [3.0]
     }
]
```



### Questão 4
Utilizando estratégias de map-reduce-filter implemente as seguintes operações:
**a)** Gerar um objeto com com o label e a metragem em m<sup>2</sup> do maior comodo da casa.
**b)** Determinar a metragem quadrada total do apartamento.
**c)** Determinar a metragem quadrada total dos quartos.

**Dados:** 

```python
medidas = [ 
    {
        'label': "sala", 
   		'largura': 4.5, 
      	'comprimento':5
    },
	{ 
        'label': "quarto1" , 
        'largura': 3.5, 
        'comprimento':2 
    },
	{ 
        'label': "quarto2" , 
        'largura': 2.7, 
        'comprimento':2 
    },
	{ 
        'label': "banheiro" , 
        'largura': 1.5, 
        'comprimento':2 
    }
]
```

