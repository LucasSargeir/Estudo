#include<iostream>
#include"database_acess.h"
using namespace std;

// Função de callback, quando alguma função externa é executada
int DatabaseAcess::callback(void *data, int argc, char **argv, char **azColName){
	int i;

	// Define que a função extena foi executada com sucesso
	((DatabaseAcess*)data)->callback_used = 1;


	cout<<endl;

	// Mostra os dados retornados pelo banco, caso existam
	for(i = 0; i<argc; i++) {
		argv[i] ?
		cout<<"\t"<<azColName[i]<<": "<<argv[i]<<endl
		:
		cout<<"\t"<<azColName[i]<<": "<<"NULL"<<endl;
	}

	cout<<endl;

	return 0;
}


// Construtor da classe
DatabaseAcess:: DatabaseAcess(){

	// Coneceta ao banco se existir, se não, o cria
	this->rc = sqlite3_open("database.db", &(this->db));

	// Caso nao consiga realizar sua ação mostra a mensagem
	if(this->rc) {
		cout<<"\t"<<"Can't open database: "<<sqlite3_errmsg(this->db)<<endl;
	}

	// SQL para criar a tabela, caso ela nao exista 

	char *sql = "CREATE TABLE produtos("  \
	"id_produto INTEGER PRIMARY KEY AUTOINCREMENT," \
	"nome VARCHAR(50) NOT NULL," \
	"tamanho VARCHAR(10) NOT NULL," \
	"quantidade DOUBLE NOT NULL," \
	"categoria VARCHAR(50) NOT NULL," \
	"subcategoria VARCHAR(50) NOT NULL," \
	"fornecedor VARCHAR(50) NOT NULL);";

	// Executa o SQL acima
	this->rc = sqlite3_exec(this->db, sql, callback, this, &(this->errMsg));

	// Limpa a memória do rc
	if( this->rc != SQLITE_OK ){
		sqlite3_free(this->errMsg);
	}

	// fecha conexão com o banco
	sqlite3_close(db);
}

// Função de inserir item
void DatabaseAcess::insert_item(Produto p){

	// Se coneceta ao banco	
	this->rc = sqlite3_open("database.db", &(this->db));

	// Caso nao consiga realizar sua ação mostra a mensagem
	if(this->rc) {
		cout<<"\t"<<"Can't open database: "<<sqlite3_errmsg(this->db)<<endl;
	}

	// SQL para inserir um elemento, concatenando com os valores passados

	char sql[1000];

	snprintf(sql, 1000 , "INSERT INTO produtos (nome, tamanho, quantidade, categoria, subcategoria, fornecedor) "  \
		"VALUES ( '%s', '%s', %f, '%s', '%s', '%s' );"
		, p.nome, p.tamanho, p.quantidade, p.categoria, p.subcategoria, p.fornecedor);

	// Executa o SQL acima
	this->rc = sqlite3_exec(this->db, sql, callback, this, &(this->errMsg));

	// Mostra o sucesso ou falha da inserção e limpa a memória do rc
	if( this->rc != SQLITE_OK ){
		cout<<"\t"<<"SQL error: "<<this->errMsg<<endl;
		sqlite3_free(this->errMsg);
	} else {
		cout<<endl<<"\t"<<"Item cadastrado com sucesso!"<<endl;
	}

	cout<<endl;
	// fecha conexão com o banco
	sqlite3_close(db);
}

int DatabaseAcess::find_by_id(int id){

	// Zera o callback_used para saber se o callback foi executado
	this->callback_used = 0;


	// Se coneceta ao banco	
	this->rc = sqlite3_open("database.db", &(this->db));

	// Caso nao consiga realizar sua ação mostra a mensagem
	if(this->rc) {
		cout<<"\t"<<"Can't open database: "<<sqlite3_errmsg(this->db)<<endl;
	}

	// SQL para buscar um produdo especifico

	char sql[200];

	snprintf(sql, 200 , "SELECT * FROM produtos WHERE id_produto = %d;", id);

	// Executa o SQL acima
	this->rc = sqlite3_exec(this->db, sql, callback, this, &(this->errMsg));

	// Mostra o sucesso ou falha da busca e limpa a memória do rc
	if( this->rc != SQLITE_OK ){
		cout<<"\t"<<"SQL error: "<<this->errMsg<<endl;
		sqlite3_free(this->errMsg);
	} else {
		if(this->callback_used == 0){
			cout<<"\t"<<"Produto nao cadastrado!"<<endl;
		}
	}

	cout<<endl;
	// fecha conexão com o banco
	sqlite3_close(db);
	return this->callback_used;
}

void DatabaseAcess::find_all(){

	// Zera o callback_used para saber se o callback foi executado
	this->callback_used = 0;

	// Se coneceta ao banco	
	this->rc = sqlite3_open("database.db", &(this->db));

	// Caso nao consiga realizar sua ação mostra a mensagem
	if(this->rc) {
		cout<<"\t"<<"Can't open database: "<<sqlite3_errmsg(this->db)<<endl;
	}
	// SQL para buscar todos os produtos

	char *sql = "SELECT * FROM produtos;";
	// Executa o SQL acima
	this->rc = sqlite3_exec(this->db, sql, callback, this, &(this->errMsg));

	// Mostra o sucesso ou falha da busca e limpa a memória do rc
	if( this->rc != SQLITE_OK ){
		cout<<"\t"<<"SQL error: "<<this->errMsg<<endl;
		sqlite3_free(this->errMsg);
	} else {
		if(this->callback_used == 0){
			cout<<"\t"<<"Nao existe produtos cadastrados!"<<endl;
		}
	}

	cout<<endl;
	// fecha conexão com o banco
	sqlite3_close(db);
}

void DatabaseAcess::delete_item(int id){

	// Zera o callback_used para saber se o callback foi executado
	this->callback_used = 0;

	// Se coneceta ao banco	
	this->rc = sqlite3_open("database.db", &(this->db));

	// Caso nao consiga realizar sua ação mostra a mensagem
	if(this->rc) {
		cout<<"\t"<<"Can't open database: "<<sqlite3_errmsg(this->db)<<endl;
	}

	// SQL para deletar um produto

	char sql[200];
	snprintf(sql, 200 , "DELETE FROM produtos WHERE id_produto = %d;", id);

	// Executa o SQL acima
	this->rc = sqlite3_exec(this->db, sql, callback, this, &(this->errMsg));

	// Mostra o sucesso ou falha da exclusão e limpa a memória do rc
	if( this->rc != SQLITE_OK ){
		cout<<"\t"<<"SQL error: "<<this->errMsg<<endl;
		sqlite3_free(this->errMsg);
	} else {
		if(this->callback_used == 0){
			cout<<"\t"<<"Produto excluido com sucesso!"<<endl;
		}
	}

	cout<<endl;
	// fecha conexão com o banco
	sqlite3_close(db);
}

void DatabaseAcess::update_item(Produto p){

	// Zera o callback_used para saber se o callback foi executado
	this->callback_used = 0;

	// Se coneceta ao banco	
	this->rc = sqlite3_open("database.db", &(this->db));

	// Caso nao consiga realizar sua ação mostra a mensagem
	if(this->rc) {
		cout<<"\t"<<"Can't open database: "<<sqlite3_errmsg(this->db)<<endl;
	}

	// SQL para atualização de um produto
	char sql[1000];
	snprintf(sql, 200 , "UPDATE produtos SET "\
		"nome = '%s', "\
		"tamanho = '%s', "\
		"quantidade = %f, "\
		"categoria = '%s', "\
		"subcategoria = '%s', "\
		"fornecedor = '%s' "\
		"WHERE id_produto = %d;", 
		p.nome, p.tamanho, p.quantidade, p.categoria, p.subcategoria, p.fornecedor, p.id_produto);

	// Executa o SQL acima
	this->rc = sqlite3_exec(this->db, sql, callback, this, &(this->errMsg));

	// Mostra o sucesso ou falha da atualização e limpa a memória do rc
	if( this->rc != SQLITE_OK ){
		cout<<"\t"<<"SQL error: "<<this->errMsg<<endl;
		sqlite3_free(this->errMsg);
	} else {
		if(this->callback_used == 0){
			cout<<endl<<"\t"<<"Produto atualizado com sucesso!"<<endl;
		}
	}

	cout<<endl;
	// fecha conexão com o banco
	sqlite3_close(db);
}