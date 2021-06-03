#include <exception>
using namespace std;

class listaVaziaException: public exception{

	virtual const char* what() const throw(){
		return "\n\t[ERRO]\n\tA lista de pacientes esta vazia!";
	}

}listaVaziaException;