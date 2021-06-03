#include<iostream>
#include"arvore.h"
using namespace std;

template <class P>
Arvore<P>::Arvore(P &p){
	this->valor = &p;
	this->esq = NULL;
	this->dir = NULL;
}

template<class P>
P* Arvore<P>::operator +=(P &p){
	if(this->valor->getNome() < p.getNome()){
		if(this->esq == NULL){
			this->esq = new Arvore<P>(p);
			return this->esq->valor;
		}
		else{
			return *(this->esq) += p;
		}
	}
	else{
		if(this->valor->getNome() == p.getNome()){
			return NULL;
		}
		if(this->dir == NULL){
			this->dir = new Arvore<P>(p);
			return this->dir->valor;
		}
		else{
			return *(this->dir) += p;
		}
	}
}

template<class P>
P* Arvore<P>::operator ()(string s){
	if(this->valor->getNome() == s){
		return this->valor;
	}
	else{
		if(this->valor->getNome() < s){
			if(this->esq == NULL){
				return NULL;
			}
			else{
				return (*(this->esq))(s);
			}
		}
		else{
			if(this->dir == NULL){
				return NULL;
			}
			else{
				return (*(this->dir))(s);
			}
		}
	}
}