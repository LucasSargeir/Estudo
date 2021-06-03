#include<stdio.h>
#include <stdlib.h>

struct ptr{
    int valor;
    struct ptr *prox;
};
struct ptr *inicio;

void removeElemento(struct ptr *aux, int num){
	if(inicio != NULL){
		if(inicio->valor == num){
			inicio = aux->prox;
			aux->prox = NULL;
			free(aux);
		}
		else{			
			if(aux->prox != NULL){
				if(aux->prox->valor == num){
					struct ptr *aux2 = aux->prox;
					aux->prox = aux->prox->prox;
					aux2->prox = NULL;
					free(aux2);
				}
				else{
					removeElemento(aux->prox, num);
				}
			}
		}
	}
}

void removeNoInicio(){
	if(inicio != NULL){
		struct ptr *aux = inicio;
		inicio = inicio->prox;
		aux->prox = NULL;
		free(aux);
	}
}

void removerFinal(struct ptr *aux){
	if(aux != NULL){
		if(aux->prox != NULL){
			if(aux->prox->prox != NULL){
				removerFinal(aux->prox);
			}
			else{
				struct ptr * aux2 = aux->prox;
				aux->prox = NULL;
				free(aux2);
			}
		}
		else{
			inicio = NULL;
			aux->prox = NULL;
			free(aux);
		}
	}
}

void inserirNoFinal(struct ptr *aux, int num){

	if(inicio == NULL){
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = num;
		inicio->prox = NULL;
	}
	else{
		if(aux->prox == NULL){
			aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
			aux->prox->valor = num;
			aux->prox->prox = NULL;
		}
		else{
			inserirNoFinal(aux->prox, num);
		}
	}
}

void inserirNoInicio(int num){

	if(inicio == NULL){
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = num;
		inicio->prox = NULL;
	}
	else{
		struct ptr *aux = inicio;
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = num;
		inicio->prox = aux;
	}
}

void inserirNoMeio(struct ptr *aux, int num){
	if(aux != NULL){
		if(aux->valor < num){
			if(aux->prox == NULL){
				inserirNoFinal(inicio, num);
			}
			else{
				if(aux->prox->valor < num){
					inserirNoMeio(aux->prox, num);
				}
				else{
					struct ptr *aux2 = aux->prox;
					aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
					aux->prox->valor = num;
					aux->prox->prox = aux2;
				}
			}
		}
	}
}

void inserirCrescente(struct ptr *aux, int num){

	if(inicio == NULL){
		inserirNoInicio(num);
	}
	else{
		if(inicio->valor > num){
			inserirNoInicio(num);
		}
		else{
			inserirNoMeio(inicio, num);
		}
	}
}

void insereElementos(){

	int numero;

	printf("Entre com um numero: ");
	scanf("%d", &numero);

	if(numero >= 0){
		inserirCrescente(inicio, numero);
		insereElementos();
	}
}

void mostraLista(struct ptr *aux){
	if(aux != NULL){
		printf("%d\t", aux->valor);
		mostraLista(aux->prox);
	}
}

void removerTodosOsElementos(){
	if(inicio != NULL){
		removeNoInicio();
		printf("\n");
	}
}

void removerElementos(){
	
	if(inicio != NULL){
		int o;
		printf("[1] Remover Inicio\n[2] Remover Final\n[3] Remover Elemento\n");
		scanf("%d", &o);
		if(o == 1){
			removeNoInicio();
		}
		if(o == 2){
			removerFinal(inicio);
		}
		if(o == 3){
			int n;
			printf("Entre com o valor:");
			scanf("%d", &n);
			removeElemento(inicio, n);
		}
		
		mostraLista(inicio);
		removerElementos();
	}
}

int contaElementos(struct ptr *aux){
	if(aux !=  NULL){
		return contaElementos(aux->prox) + 1;
	}
	else{
		return 0;
	}
}

int maiorElemento(struct ptr *aux, int anterior){
	if(aux == NULL){
		return anterior;
	}
	else{
		int maiorAnterior = maiorElemento(aux->prox, aux->valor);
		if( maiorAnterior > anterior){
			return maiorAnterior;
		}
		else{
			return anterior;
		}
	}
}

int menorElemento(struct ptr *aux, int anterior){
	if(aux == NULL){
		return anterior;
	}
	else{
		int menorAnterior = menorElemento(aux->prox, aux->valor);
		if( menorAnterior < anterior){
			return menorAnterior;
		}
		else{
			return anterior;
		}
	}
}

int somaElementos(struct ptr *aux){
	if(aux == NULL){
		return 0;
	}
	else{
		return somaElementos(aux->prox) + aux->valor;
	}
}

float mediaDosElementos(struct ptr *aux){
	return somaElementos(aux)*1.0 /contaElementos(aux);
}

int main(){

	inicio = NULL;

	insereElementos();
	printf("Lista: ");
	mostraLista(inicio);
	printf("\n");
	printf("Numero de Elementos: %d\n", contaElementos(inicio));
	printf("Maior Elemento: %d\n", maiorElemento(inicio, inicio->valor));
	printf("Menor Elemento: %d\n", menorElemento(inicio, inicio->valor));
	printf("Soma dos Elementos: %d\n", somaElementos(inicio));
	printf("Media dos Elementos: %f\n", mediaDosElementos(inicio));

	removerElementos();

	return 0;
}
