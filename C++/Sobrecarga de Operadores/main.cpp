#include<iostream>
#include<string.h>
#include"cadastro.cpp"
using namespace std;

class Paciente{
private:
	string nome;
public:
	Paciente(string nome){
		this->nome = nome;
	}
	string getNome(){
		return this->nome;
	}
	void setNome(string s){
		this->nome = s;
	}
	friend ostream& operator <<(ostream &out, Paciente &p){
		out<<p.getNome();
		return out;
	}
};

class Paciente_Comum: public Paciente{
	private:
		int idade;
		float peso;
	public:
		Paciente_Comum(string nome): Paciente(nome){
			this->idade = 0;
			this->peso = 0;
		}
		Paciente_Comum(string nome, int idade, float peso): Paciente(nome){
			this->idade = idade;
			this->peso = peso;
		}
		friend ostream& operator <<(ostream &out, Paciente_Comum &p){
			out<<"\n\tNome: "<<p.getNome()<<endl;
			out<<"\tIdade: "<<p.idade<<endl;;
			out<<"\tPeso: "<<p.peso<<endl;;
			return out;
		}
};

void getch(void){

	cout<<endl<<endl<<endl<<endl<<"pressione enter para continuar..."<<endl;
	system("read b");
}

int main(int argc, char **argv){

	int opcao, count_argc = 1;
	Cadastro<Paciente_Comum> *cadastro = NULL;


	do{
		if(argc == 1){
			system("cls || clear");
			cout<<"CADASTRO DOS PACIENTES"<<endl<<endl;
			cout<<"[1] - Cadastrar Paciente"<<endl;
			cout<<"[2] - Ver Pacientes Cadastrados"<<endl;
			cout<<"[3] - Buscar Paciente"<<endl;
			cout<<"[4] - Sair"<<endl<<endl;
		

			cout<<endl<<"Opcao: ";
			cin>>opcao;
		}
		if(argc > 1){
			if(count_argc == argc){
				opcao = 4;
			}
			else{
				opcao = atoi(argv[count_argc++]);
			}
		}
		switch(opcao){
			case 1:
			{
				string nome;

				if(argc == 1){
					cout<<"\tEntre com o nome do paciente: ";
					cin>>nome;
				}
				else{
					nome = argv[count_argc++];
				}

				Paciente_Comum *p = new Paciente_Comum(nome);

				if(cadastro == NULL){
					cadastro = new Cadastro<Paciente_Comum>(*p);
					cout<<"\n\t[OK]\n\tPaciente inserido com sucesso!"<<endl;
				}
				else{
					try{
						cadastro->insere(*p);
						cout<<"\n\t[OK]\n\tPaciente inserido com sucesso!"<<endl;
					}
					catch(exception & e){
						cout<<e.what()<<endl;
					}
				}

				break;
			}
			case 2:
			{
				if(cadastro == NULL){
					cout<<"\tLista Vazia!"<<endl;
				}
				else{
					cout<<endl<<"[PACIENTES]"<<endl;
					cadastro->imprime();
				}
				break;
			}
			case 3:
			{
				string nome;
				Paciente_Comum *buscar;

				if(cadastro == NULL){
					cout<<"\tLista Vazia!"<<endl;
				}
				else{

					if(argc == 1){
						cout<<"\tProcurar: ";
						cin>>nome;
					}
					else{
						nome = argv[count_argc++];
					}
			
					try{
						buscar = cadastro->busca(nome);
						cout<<"\tUsuario encontrado:"<<endl;
						cout<<"\n\t-> "<<*buscar<<endl;
					}
					catch(exception & e){
						cout<<e.what()<<endl;
					}
				}

				break;
			}
			case 4:
			{
				cout<<"Saindo..."<<endl;
				break;
			}
			default:{
				cout<<"Opcao invalida!"<<endl;
				break;
			}

		}

		if(argc == 1){
			getch();
		}

	}while(opcao != 4 || (count_argc < argc && argc != 1));

	return 0;
}