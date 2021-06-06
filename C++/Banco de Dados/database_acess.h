#include<sqlite3.h> 
#include"produto.h" 

#ifndef DATABASEACESS_H
#define DATABASEACESS_H

// Classe criada para mediar a comunicação com o banco

class DatabaseAcess{
	private:
		sqlite3 *db;
		char *errMsg = NULL;
		int rc;
		int callback_used;

		static int callback(void *data, int argc, char **argv, char **azColName);

	public:
		DatabaseAcess();
		void insert_item(Produto p);
		int find_by_id(int id);
		void find_all();
		void update_item(Produto p);
		void delete_item(int id);
};


#endif