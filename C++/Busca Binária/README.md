# Busca Binária vs Busca Sequencial

Implementação de busca binária e comparação com a busca sequencial em um arquivo com registros de CEPs.



### Dados

Os dados encontram-se no arquivo `cep_ordenado.dat`, e possui a seguinte estrutura:

```c++
struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};
```

>Obs: o `lixo` serve para armazenar a quebra de linha encontrada no final de cada registro.



## Compilação

Para compilar o programa utilize o comando abaixo:

```bash
g++ buscaBinaria.cpp -o busca
```



## Execução

Uma vez compilado, o programa pode ser executado de duas formas, interativa ou por parâmetro de linha.

- Interativa

```bash
./busca
```

- Parâmetro de Linha

```bash
./busca <CEP_DESEJADO>
```

  

