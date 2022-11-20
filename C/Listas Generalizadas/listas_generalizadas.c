/*
 * Lista generalizadas
 */

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

enum elem_t {tipo_int, tipo_sublista};

union info_lista {
    int i;
    struct No* sublista;
};

typedef struct No {
    enum elem_t tipo;
    union info_lista info;
    struct No* prox;
} No;


No* sublista(No* sublista);
No* atomo(int i);
No* concat(No* ap_elem, No* ap_lista);


/*
 *	QUESTÃO - 1
 *
 *	Inicializa uma lista como uma lista vazia
 *
 */

No* cria_lista_padrao () {
    return NULL;
}


/*
 *	QUESTÃO - 2
 *
 *	Soma os valores de uma lista
 *
 */

int soma_valores(No* l) {
	int soma = 0;
	
    while(l!=NULL) {
        switch(l->tipo){
        case tipo_int:
            soma += l->info.i;
            break;
        case tipo_sublista:
            soma += soma_valores(l->info.sublista);
            break;
        }
        l = l->prox;
    }

	return soma;
}


/*
 *	QUESTÃO - 3
 *
 *	Determina se duas listas sao iguais
 *
 */

int iguais (No* l1, No* l2) {
	
    while(l1!=NULL) {
        switch(l1->tipo){
        case tipo_int:
            if(l2->tipo != tipo_int){
				return FALSE;
			}
			if(l1->info.i != l2->info.i){
				return FALSE;
			}
            break;
        case tipo_sublista:
            if(l2->tipo != tipo_sublista){
				return FALSE;
			}
			if(!iguais(l1->info.sublista, l2->info.sublista)){
				return FALSE;
			};
            break;
        }
        l1 = l1->prox;
		l2 = l2->prox;
    }

	return TRUE;
}


/*
 *	QUESTÃO - 4
 *
 *	Exibe o conteúdo de uma lista com parentesis e virgula
 *
 */

void imprime(No* l) {
    printf("(");
    while(l!=NULL) {
        switch(l->tipo){
        case tipo_int:
            printf("%d", l->info.i);
            break;
        case tipo_sublista:
            imprime(l->info.sublista);
            break;
        }
        l = l->prox;
        if (l != NULL)
            printf(", ");
    }
    printf(")");
}


/*
 *	QUESTÃO - 5
 *
 *	Determinar se uma lista está vazia
 *
 */

int lista_vazia(No* l){
	if(l == NULL){
		return TRUE;
	}
	return FALSE;
}

/*
 *	QUESTÃO - 6
 *
 *	Dizer se é atomo ou lista
 *
 */

enum elem_t determina_tipo(No* l){
	if(l->tipo == tipo_int){
		return  tipo_int;
	}
	else if(l->tipo == tipo_sublista){
		return tipo_sublista;
	}
}


/*
 *	QUESTÃO - 7
 *
 *	Inserir um atomo no inicio de uma lista
 *
 */

No* insere_no_inicio(No* l, int elem){
	No* nova_lista = concat(atomo(elem), l);
	return nova_lista;
}


/*
 *	QUESTÃO - 8
 *
 *	Remover a cabeça da lista
 *
 */

No* remove_cabeca_da_lista(No* l){
	No* aux = l;
	l = l->prox;
	free(aux);	
	return l;
}

/*
 *	FUNÇÕES AUXILIARES
 *
 *	Funções auxiliares para criação das listas e prints
 *
 */

No* concat(No* ap_elem, No* ap_lista) {
    ap_elem->prox = ap_lista;
    return ap_elem;
}

No* atomo(int i) {
    No* n = (No*) malloc (sizeof(No));
    n->info.i = i;
    n->tipo = tipo_int;
    return n;
}

No* sublista(No* sublista) {
    No* n = (No*) malloc (sizeof(No));
    n->info.sublista = sublista;
    n->tipo = tipo_sublista;
    return n;
}

void imprime_lista(No* l){
	if(l == NULL){
		printf("Null");
	}
	else{
		imprime(l);
	}
	printf("\n");
}

void imprime_resultado_iguais(No* l1, No* l2){
	int resultado = iguais(l1, l2);
	if(resultado){
		printf("iguais");
	}
	else{
		printf("diferentes");
	}
}

void imprime_resultado_lista_vazia(No* l){
	int resultado = lista_vazia(l);
	if(resultado){
		printf("vazia");
	}
	else{
		printf("não vazia");
	}
}

void imprime_tipo_no(No* l){
	if(l == NULL){
		printf("Nó nulo, não é possível definir o tipo.");
	}
	else{
		enum elem_t resultado = determina_tipo(l);
		if(resultado == tipo_int){
			printf("átomo");
		}
		else if(resultado == tipo_sublista){
			printf("sublista");
		}
	}
}

/*
 *	MAIN
 *
 *	Testes das funções criadas
 *
 */

int main() {

	/*	QUESTAO 1 
	 *
	 * Monta uma lista vazia
	 *
	 */
	No* lista_vazia = cria_lista_padrao();
	printf("Q1 - Lista Vazia\n");
	printf("Lista -> ");
	imprime_lista(lista_vazia);
	printf("\n\n");

	
	// Criação de listas de exemplo para testes
	printf("Criando lista ((2, 3), 1) para testes...\n");
    No* lista_exemplo1 = concat(concat(sublista(concat(atomo(2), concat(atomo(3), NULL))), lista_vazia), atomo(1));
	printf("Criando lista (4, (5, 6)) para testes...\n\n\n");
	No* lista_exemplo2 = concat(atomo(4), concat(sublista(concat(atomo(5), concat(atomo(6), NULL))), lista_vazia));
	
	/*	QUESTAO 2
	 *
	 * Soma dos Valores
	 *
	 */
    printf("Q2 - Soma valores da lista\n");
	printf("Lista -> ");
	imprime_lista(lista_exemplo1);
	printf("Soma -> %d\n", soma_valores(lista_exemplo1));
	printf("\n\n");

	
	/*	QUESTAO 3
	 *
	 * Determinar Listas Iguais
	 *
	 */
    printf("Q3 - Listas Iguais\n");
	printf("Lista Ex1 -> ");
	imprime_lista(lista_exemplo1);
	printf("Lista Ex2 -> ");
	imprime_lista(lista_exemplo2);
	printf("Comparação Ex1 == Ex2 -> ");
	imprime_resultado_iguais(lista_exemplo1, lista_exemplo2);
	printf("\n");
	printf("Comparação Ex1 == Ex1 -> ");
	imprime_resultado_iguais(lista_exemplo1, lista_exemplo1);
	printf("\n\n\n");

	
	/*	QUESTAO 4
	 *
	 * Exibir conteúdo com () e ,
	 *
	 */
    printf("Q4 - Exibe conteúdo\n");
	printf("Lista Ex1 -> ");
	imprime_lista(lista_exemplo1);
	printf("\n\n");

	
	/*	QUESTAO 5
	 *
	 * Determinar se lista está vazia
	 *
	 */
    printf("Q5 - Determinar lista vazia\n");
	printf("Lista Ex1 -> ");
	imprime_lista(lista_vazia);
	printf("Lista Ex2 -> ");
	imprime_lista(lista_exemplo1);
	printf("A lista Ex1 está ");
	imprime_resultado_lista_vazia(lista_vazia);
	printf("\n");
	printf("A lista Ex2 está ");
	imprime_resultado_lista_vazia(lista_exemplo1);
	printf("\n\n\n");


	/*	QUESTAO 6
	 *
	 * Determinar se é átomo ou lista
	 *
	 */
    printf("Q6 - Determinar se é átomo ou lista\n");
    printf("Lista Ex1 -> ");
	imprime_lista(lista_exemplo1);
	printf("Avaliando primeiro elmento da lista -> ");
	imprime_tipo_no(lista_exemplo1);
	printf("\n");
	printf("Avaliando segundo elmento da lista  -> ");
	imprime_tipo_no(lista_exemplo1->prox);
	printf("\n\n\n");


	/*	QUESTAO 7
	 *
	 * Inserir átomo no inicio da lista
	 *
	 */
	
	printf("Q7 - Inserir no incio\n");
	printf("Lista -> ");
	imprime_lista(lista_exemplo1);
	printf("Inserindo elemento 0 no inicio da lista...\n");
	lista_exemplo1 = insere_no_inicio(lista_exemplo1, 0);
	printf("Nova Lista -> ");
	imprime_lista(lista_exemplo1);
	printf("\n\n");

	
	/*	QUESTAO 8
	 *
	 * Remover átomo da cabeça da lista
	 *
	 */

	printf("Q8 - Remover Cabeça da Lista\n");
	printf("Lista -> ");
	imprime_lista(lista_exemplo1);
	printf("Removendo cabeça da lista...\n");
	lista_exemplo1 = remove_cabeca_da_lista(lista_exemplo1);
	printf("Nova Lista -> ");
	imprime_lista(lista_exemplo1);
	printf("\n\n");
	
    return 0;
    
}