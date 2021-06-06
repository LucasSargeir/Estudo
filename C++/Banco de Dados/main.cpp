#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"database_acess.cpp"
using namespace std;


int main (){

	char opcao;

	// Cria a instância para manipulação de dados
	DatabaseAcess da = DatabaseAcess();

	do{

		// Apresenta o menu
		system("cls || clear");
		cout<<"----------[MENU PRINCIPAL]----------"<<endl;
		cout<<"[1] - Inserir produto"<<endl;
		cout<<"[2] - Ver produtos cadastrados"<<endl;
		cout<<"[3] - Buscar produto"<<endl;
		cout<<"[4] - Atualizar produto"<<endl;
		cout<<"[5] - Excluir produto"<<endl;
		cout<<"[6] - Sair"<<endl;

		cout<<endl<<endl<<"OPCAO: ";
		cin>>opcao;

		switch(opcao){

			// Opção para inserir produto
			case '1':{
				Produto p;
				cout<<endl<<"\t----------[CADASTRO PRODUTO]----------"<<endl<<endl;;

				// Pede os dados do produto
				cout<<"\tNome: ";
				getchar();
				scanf("%[^\n]", p.nome);
				cout<<"\tTamanho: ";
				getchar();
				scanf("%[^\n]", p.tamanho);
				cout<<"\tQuantidade: ";
				cin>>p.quantidade;
				cout<<"\tCategoria: ";
				getchar();
				scanf("%[^\n]", p.categoria);
				cout<<"\tSubcategoria: ";
				getchar();
				scanf("%[^\n]", p.subcategoria);
				cout<<"\tFornecedor: ";
				getchar();
				scanf("%[^\n]", p.fornecedor);

				// Insere o produto
				da.insert_item(p);
				break;
			}
			// Opção para buscar os produtos
			case '2':{
				cout<<endl<<"\t----------[LISTA DE PRODUTOS]----------"<<endl<<endl;;

				// Busca os produtos
				da.find_all();
				break;
			}
			// Opção para buscar um produto
			case '3':{
				int id;
				cout<<endl<<"\t----------[BUSCA DE PRODUTO]----------"<<endl<<endl;;
				
				// Pede o identificador do produto
				cout<<"\tEntre com o id do produto: ";
				cin>>id;

				// Busca o item solicitado
				da.find_by_id(id);
				break;
			}
			// Opção para atualizar um produto
			case '4':{
				Produto p;
				char confirmacao;
				int id;
				cout<<endl<<"\t----------[ATUALIZACAO DE PRODUTO]----------"<<endl<<endl;;
				
				// Solicita o produto a ser atualizado
				cout<<"\tEntre com o id do produto que deseja atualizar: ";
				cin>>id;

				// Se o produto existir
				if(da.find_by_id(id)){

					p.id_produto = id;

					// Pede os dados do produto
					cout<<"\t----[NOVOS VALORES]----"<<endl<<endl;
					cout<<"\tNome: ";
					getchar();
					scanf("%[^\n]", p.nome);
					cout<<"\tTamanho: ";
					getchar();
					scanf("%[^\n]", p.tamanho);
					cout<<"\tQuantidade: ";
					cin>>p.quantidade;
					cout<<"\tCategoria: ";
					getchar();
					scanf("%[^\n]", p.categoria);
					cout<<"\tSubcategoria: ";
					getchar();
					scanf("%[^\n]", p.subcategoria);
					cout<<"\tFornecedor: ";
					getchar();
					scanf("%[^\n]", p.fornecedor);

					// Atualiza o produto
					da.update_item(p);
				}
				break;
			}
			// Opção para excluir um produto 
			case '5':{
				int id;
				cout<<endl<<"\t----------[EXCLUIR PRODUTO]----------"<<endl<<endl;;
				
				// Solicita o produto a ser excluido
				cout<<"\tEntre com o id do produto que deseja excluir: ";
				cin>>id;

				// Se o produto existir
				if(da.find_by_id(id)){

					// Exclui o produto
					da.delete_item(id);
				}
				break;
			}
			// Opção para sair do programa
			case '6':{
				cout<<"Saindo..."<<endl;
				break;
			}
			// Caso nao seja uma opção válida
			default:{
				cout<<"Opcao inválida, tente novamente!"<<endl;
				break;
			}
			
		}

		// Aguarda para voltar ao menu limpo
		cout<<endl<<endl<<endl<<endl<<endl<<"Pressione enter para continuar..."<<endl;
		getchar();
		getchar();
	}while(opcao != '6');

	return 0;
}