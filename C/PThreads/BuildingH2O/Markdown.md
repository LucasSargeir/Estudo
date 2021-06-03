# Building H20 Problem

Existem 2 tipos de threads, Hidrogenio e Oxigenio. Afim de montar moléculas de água, nós temos que criar uma barreira que faça com que cada thread espere até que uma molécula completa esteja pronta para continuar.

A medida que cada thread passe pela barreira, é necessário que chamem o método juntar. Você deve garantir que todas as threads de cada molécula chamaram o método juntar antes  de qualquer thread da molécula seguinte.

Em outras palavras:

- Se uma thread oxigenio chegar na barreira quando nenhuma thread  de hidrogenio estiver lá, ela deve esperar por 2 threads de hidrogenio.
- Se uma thread de hidrogenio chegar na barreira quando nenhuma outra thread estiver lá, ela deve esperar por 1 thread de oxigenio e uma outra thread de hidrogenio.

Nós não precisamos nos importar em combinar as threads explicitamente, ou seja, as threads não precisam conhecer as threads que estão combinadas. A chave do problema é que as threads devem passar pela barreira em grupos de 2 hidrogenios e 1 oxigenio (H2O). Logo, se examinarmos a sequencia de threads que chamaram o método juntar e dividi-los em grupos de 3, cada grupo deve conter um H2O. 

Desafio: escreva um código sincronizado para moléculas de oxigenio e hidrogenio que respeitem essas condições.



### Regras

- É obrigatório a utilização da biblioteca `pthreads`;
- Não é permitido a utilização de semáforos;
- O código deve vir acompanhado de um makefile;
- O código deve ser comentado explicando cada etapa;
- O código deve ser parametrizável utilizando parâmetros de linha (sem ser obrigatório);



## Compilação

A compilação pode ser feita atravez do `makefile` disponibilizado, execute o comando:

```bash
make all
```

Observe que o binário `building_h2o` foi gerado pelo make.



## Execução

Após a compilação, a execução do programa pode ser feita de duas maneiras, de forma interativa ou por parêmetro de linha.



<u>**Forma interativa**</u>

Para executar o programa de forma interativa utilize o comando abaixo:

```bash
./building_h2o
```



<u>**Parâmetro de Linha**</u>

Para pular o menu em que é pedido a quantidade de moléculas geradas, esse valor pode ser passado por parametro de linha. Por exemplo, para criar 500 moléculas podemos executar:

```bash
./building_h2o 500
```

> Obs: repare que o número de threads geradas será 3 vezes o número de moléculas escolhidas, pois para cada molécula são necessárias 2 threads de Hidrogênio e 1 thread de Oxigênio.



## Material de Apoio

- Praticando com PThreads (Problema do H2O): [link](https://courses.cs.vt.edu/cs3214/fall2014/exercises/water/water.pdf)
- Programação com Threads em C: [link](https://homepages.dcc.ufmg.br/~coutinho/pthreads/ProgramandoComThreads.pdf)
- Livro com problema proposto (capítulo 5.6): [link](https://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf)

