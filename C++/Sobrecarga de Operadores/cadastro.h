#include<iostream>
#include<string.h>
#include"arvore.h"
using namespace std;

#ifndef CADASTRO_H
#define CADASTRO_H

template <class P>
class Cadastro {

	public:
		Cadastro();
		Cadastro(P &p);
		Cadastro(const Cadastro &);
		void imprime();
		P* insere(P &p);
		P* busca(string s);	
	private:
		Arvore<P> *arvore_pacientes;
};

#endif