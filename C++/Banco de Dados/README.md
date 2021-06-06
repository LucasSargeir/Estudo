# Controle de Estoque

O projeto tem o objetivo criar um programa, em C++, que funcione como um CRUD de Produtos. Cada produto têm nome, tamanho, quantidade, categoria, subcategoria e fornecedor. O sistema deve oferecer as seguintes operações:

- Inserir produto;
- Exibir produtos cadastrados;
- Buscar produto;
- Atualizar produto;
- Excluir produto.

Os dados registrados pelo programa deve ser armazenado em uma base de dados, dessa forma quando o programa encerrar os dados permanecerão salvos.

Além disso, o programa deve conter um `makefile` para a compilação.



**Tecnologias**

- C++;
- SQLite3.

> **Obs:** O SQLite foi escolhido no lugar do SQL Server para que não seja necessário a instação de um SGBD para utilização do programa.



## Compilação

A comliação do programa pode ser feita através do makefile, utilize o comando abaixo:

```bash
make all
```

> **Obs.:** Note que o binário `main` foi gerado.



## Execução 

Após compilado, o programa pode ser executado com o comando abaixo:

```bash
./main
```

