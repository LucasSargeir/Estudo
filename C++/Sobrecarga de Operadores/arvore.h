#include<iostream>
using namespace std;

#ifndef ARVORE_H
#define ARVORE_H

template <class P>
class Arvore{
	
	public:
		Arvore(P &p);
		P* operator +=(P &p);
		P* operator ()(string s);
		friend ostream& operator <<(ostream &out, const Arvore<P> &a){
			if(a.dir != NULL){
				out<<*(a.dir);
			}
			out<<*(a.valor)<<endl;
			if(a.esq != NULL){
				out<<*(a.esq);
			}
			return out;
		}
	private:
		P *valor;
		Arvore<P> *esq, *dir;
};

#endif