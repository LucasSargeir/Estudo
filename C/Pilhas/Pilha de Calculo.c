#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ptr{
    char valor[11];
    struct ptr *prox;
};
struct ptr *inicio, *numeros, *sinais, *desempilha_i;

void inserirNoFinal(struct ptr **aux, char *val){

	if(*aux == NULL){
		*aux = (struct ptr *)malloc(sizeof(struct ptr));
		strcpy((*aux)->valor, val);
		(*aux)->prox = NULL;
	}
	else{
		if((*aux)->prox == NULL){
			(*aux)->prox = (struct ptr *)malloc(sizeof(struct ptr));
			strcpy((*aux)->prox->valor, val);
			(*aux)->prox->prox = NULL;
		}
		else{
			inserirNoFinal(&(*aux)->prox, val);
		}
	}
}

void removeNoInicio(struct ptr **lista){
	if(*lista != NULL){
		struct ptr *aux = *lista;
		*lista = (*lista)->prox;
		aux->prox = NULL;
		free(aux);
	}
}

void inserirNoInicio(struct ptr **lista, char *val){
	if(*lista == NULL){
		*lista = (struct ptr *)malloc(sizeof(struct ptr));
		strcpy((*lista)->valor, val);
		(*lista)->prox = NULL;
	}
	else{
		struct ptr *aux = *lista;
		*lista = (struct ptr *)malloc(sizeof(struct ptr));
		strcpy((*lista)->valor, val);
		(*lista)->prox = aux;
	}
}

void mostraLista(struct ptr *aux){
	if(aux != NULL){
		printf("\t\t%s\n", aux->valor);
		mostraLista(aux->prox);
	}
	else{
		printf("\t\tNULL\n");
	}
}

void calcula(struct ptr **aux_sinais, struct ptr ** aux_numeros){
	if(*aux_sinais != NULL){
		char valor1[11], valor2[11],sinal[11], result[11];
		strcpy(valor1, (*aux_numeros)->valor);
		removeNoInicio(aux_numeros);
		strcpy(valor2, (*aux_numeros)->valor);
		removeNoInicio(aux_numeros);
		strcpy(sinal, (*aux_sinais)->valor);
		removeNoInicio(aux_sinais);
		int valor3, valor4;
		valor3 = atoi(valor1);
		valor4 = atoi(valor2);
		if(strcmp(sinal, "+") == 0){
			sprintf(result, "%d", valor3 + valor4);
			inserirNoInicio(aux_numeros, result);
		}
		if(strcmp(sinal, "*") == 0){
			sprintf(result, "%d", valor3 * valor4);
			inserirNoInicio(aux_numeros, result);
		}
		calcula(aux_sinais, aux_numeros);
	}
}

void inserirDados(){
	
	char val, valor[11];
	int i = 0;
	val = getchar();

	while(val != '\n'){
		if(val == ' '){
			valor[i] = '\0';
			i = 0;
			inserirNoFinal(&inicio, valor);
		}
		else{
			valor[i++] = val;
		}
		val = getchar();		
	}

	valor[i] = '\0';
	inserirNoFinal(&inicio, valor);

}

void desempilha(struct ptr **origem, struct ptr **destino){	
	inserirNoInicio(&(*destino), (*origem)->valor);
	removeNoInicio(&(*origem));
	
}


void reempilha(struct ptr **origem, struct ptr **destino){
	if(*origem != NULL){
		inserirNoInicio(&(*destino), (*origem)->valor);
		removeNoInicio(&(*origem));
		reempilha(origem, destino);
	}
}

void dividirLista(struct ptr **aux, int countabre, int countfecha){
	if( *aux != NULL){
		if (strcmp((*aux)->valor, "(") == 0){
			countabre ++;
			desempilha(aux, &desempilha_i);
			dividirLista(aux, countabre, countfecha);
		}
		else{
			if (strcmp((*aux)->valor, ")") == 0){
				countfecha ++;
				desempilha(aux, &desempilha_i);
				dividirLista(aux, countabre, countfecha);
			}
			else{
				if(countabre != countfecha && countabre != 0){
					if(strcmp((*aux)->valor, "+") == 0 || strcmp((*aux)->valor, "*") == 0){
						inserirNoInicio(&sinais, (*aux)->valor);
					}
					else{
						inserirNoInicio(&numeros, (*aux)->valor);
					}
					desempilha(aux, &desempilha_i);
					dividirLista(aux, countabre, countfecha);	
				}
			}
		}
	}
	else{
		reempilha(&desempilha_i, aux);
	}
}



int main(){

	inicio = NULL;
	inserirDados();

	printf("\nPilha principal: \n");
	mostraLista(inicio);
	
	dividirLista(&inicio, 0,0);
	
	printf("\nPilha de numeros: \n");
	mostraLista(numeros);

	printf("\nPilha de sinais: \n");
	mostraLista(sinais);

	calcula(&sinais, &numeros);
	printf("\nResultado: %s\n",numeros->valor);

	return 0;
}
