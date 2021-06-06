#include<iostream>
#include<stdlib.h>
using namespace std;

#ifndef PRODUTO_H
#define PRODUTO_H

// Modelo de Dados do produto

class Produto{
	public:
		int id_produto;
		char nome[51];
		char tamanho[10];
		double quantidade;
		char categoria[51];
		char subcategoria[51];
		char fornecedor[51];
};


#endif