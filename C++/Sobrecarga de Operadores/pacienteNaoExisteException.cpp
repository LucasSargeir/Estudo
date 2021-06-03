#include <exception>
using namespace std;

class pacienteNaoExisteException: public exception{

	virtual const char* what() const throw(){
		return "\n\t[ERRO]\n\tPaciente nao existe!";
	}

}pacienteNaoExisteException;