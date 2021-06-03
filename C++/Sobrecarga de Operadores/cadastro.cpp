#include "cadastro.h"
#include "arvore.cpp"
#include "pacienteExisteException.cpp"
#include "pacienteNaoExisteException.cpp"
#include "listaVaziaException.cpp"
using namespace std;

template <class P>
Cadastro<P>::Cadastro(){
	this->arvore_pacientes = NULL;
}

template <class P>
Cadastro<P>::Cadastro(const Cadastro &a) {
	this->arvore_pacientes = a.arvore_pacientes;
}

template <class P>
Cadastro<P>::Cadastro(P &p){
	this->arvore_pacientes = new Arvore<P>(p);
}

template <class P>
void Cadastro<P>::imprime(){
	if(this->arvore_pacientes == NULL){
		cout<<"Lista de Pacientes vazia."<<endl;
	}
	else{
		cout<<*(this->arvore_pacientes);
	}
}

template <class P>
P* Cadastro<P>::insere(P &p){
	if(this->arvore_pacientes == NULL){
		this->arvore_pacientes = new Arvore<P>(p);
		return &p;
	}
	else{
		P *result = *(this->arvore_pacientes) += p;
		if(result != NULL){
			return result;
		}
		else{
			throw pacienteExisteException;
		}
	}
}

template <class P>
P* Cadastro<P>::busca(string s){
	if(this->arvore_pacientes == NULL){
		throw listaVaziaException;
	}
	else{
		P *result = (*(this->arvore_pacientes))(s);
		if(result != NULL){
			return result;
		}
		else{
			throw pacienteNaoExisteException;
		}
	}
}

