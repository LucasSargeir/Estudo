#include <exception>
using namespace std;

class pacienteExisteException: public exception{

	virtual const char* what() const throw(){
		return "\n\t[ERRO]\n\tPaciente ja cadastrado!";
	}

}pacienteExisteException;