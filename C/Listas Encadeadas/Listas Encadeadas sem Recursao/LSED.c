#include<stdio.h>
#include <stdlib.h>

struct ptr{
    int valor;
    struct ptr *prox;
};
struct descritor{
    int quant;
    struct ptr *prim, *ult;
};
struct descritor *lista;

void removeNoInicio(){
	if(lista != NULL){
		if(lista->prim != NULL){
			struct ptr *aux = lista->prim;
			if(lista->prim == lista->ult){
				lista->ult = NULL;
			}
			lista->prim = lista->prim->prox;
			aux->prox = NULL;
			free(aux);
			lista->quant--;
		}
	}
}
void removeElemento(int num){
	if(lista != NULL){
		if(lista->prim != NULL){
			if(lista->prim->valor == num){
				removeNoInicio();
			}
			else{
				struct ptr * aux = lista->prim;
				while(aux->prox != NULL){
					if(aux->prox->valor == num){
						break;
					}
					aux = aux->prox;		
				}
				struct ptr *aux2 = aux->prox;
				aux->prox = aux2->prox;
				aux2->prox = NULL;
				free(aux2);
				lista->quant--;
			}

		}
	}
}

void removerFinal(){
	if(lista != NULL){	
		if(lista->prim != NULL){
			if(lista->prim == lista->ult){
				lista->prim = NULL;
				lista->ult = NULL;
			}
			else{
				struct ptr * aux = lista->prim;
				while(aux->prox->prox != NULL){
					aux = aux->prox;
				}
				lista->ult = aux;
				aux = aux->prox;
				lista->ult->prox = NULL;
				free(aux);
				lista->quant--;
			}
		}
	}
}

void inserirNoFinal(int num){

	if(lista != NULL){
		if(lista->prim == NULL){
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = NULL;
			lista->ult = lista->prim;
		}
		else{
			lista->ult->prox = (struct ptr *)malloc(sizeof(struct ptr));
			lista->ult = lista->ult->prox;
			lista->ult->valor = num;
			lista->ult->prox = NULL;
		}
		lista->quant++;
	}
}

void inserirNoInicio(int num){

	if(lista != NULL){
		if(lista->prim == NULL){
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = NULL;
			lista->ult = lista->prim;
		}
		else{
			struct ptr *aux = lista->prim;
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = aux;
		}
		lista->quant++;
	}
}

void inserirNoMeio(int num){
	
	if(lista != NULL){
		if(lista->prim != NULL){
			struct ptr *aux = lista->prim;

			if(aux != NULL){
				while(aux->prox != NULL){
					if(aux->prox->valor > num){
						break;
					}
					aux = aux->prox;
				}
				struct ptr *aux2 = aux->prox;
				aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
				aux->prox->valor = num;
				aux->prox->prox = aux2;
				if(aux == lista->ult){
					lista->ult = aux->prox;
				}
			}
			lista->quant++;
		}
		else{
			inserirNoInicio(num);
		}
	}
}

void inserirCrescente(int num){

	if(lista != NULL){	
		if(lista->prim == NULL){
			inserirNoInicio(num);
		}
		else{
			if(lista->prim->valor >= num){
				inserirNoInicio(num);
			}
			else{
				inserirNoMeio(num);
			}
		}
	}
}

void mostraLista(){
	if(lista != NULL){
		struct ptr * aux = lista->prim;
		while(aux != NULL){
			printf("%d\t", aux->valor);
			aux = aux->prox;
		}
	}
	else{
		printf("Lista inexistente");
	}
	printf("\n");
}

void insereElementos(){

	int numero;

	lista = (struct descritor *) malloc(sizeof(struct descritor));
	lista->prim = NULL;
	lista->ult = NULL;

	printf("Entre com um numero: ");
	scanf("%d", &numero);

	while(numero >= 0){
		
		inserirCrescente(numero);
		mostraLista();

		printf("Entre com um numero: ");
		scanf("%d", &numero);
	}
}

void removerTodosOsElementos(){
	if(lista->prim != NULL){
		removeNoInicio();
		printf("\n");
	}
}

void removerElementos(){
	
	if(lista->prim != NULL){
		int o;
		printf("[1] Remover Inicio\n[2] Remover Final\n[3] Remover Elemento\n");
		scanf("%d", &o);
		if(o == 1){
			removeNoInicio();
		}
		if(o == 2){
			removerFinal();
		}
		if(o == 3){
			int n;
			printf("Entre com o valor:");
			scanf("%d", &n);
			removeElemento(n);
		}
		
		mostraLista();
		removerElementos();
	}
}

int contaElementos(){
	if(lista !=  NULL){
		return lista->quant;
	}
	else{
		return 0;
	}
}

int maiorElemento(){
	if(lista != NULL){
		if(lista->prim == NULL){
			return -1;
		}
		else{
			struct ptr * aux = lista->prim->prox;
			int maior = lista->prim->valor;
			while(aux != NULL){
				if(aux->valor > maior){
					maior = aux->valor;
				}
				aux = aux->prox;
			}
			return maior;
		}
	}	
}

int menorElemento(){
	if(lista != NULL){
		if(lista->prim == NULL){
			return -1;
		}
		else{
			struct ptr * aux = lista->prim->prox;
			int menor = lista->prim->valor;
			while(aux != NULL){
				if(aux->valor < menor){
					menor = aux->valor;
				}
				aux = aux->prox;
			}
			return menor;
		}
	}	
}

int somaElementos(){
	if(lista != NULL){
		if(lista->prim == NULL){
			return -1;
		}
		else{
			struct ptr * aux = lista->prim;
			int soma = 0;
			while(aux != NULL){
				soma += aux->valor;
				aux = aux->prox;
			}
			return soma;
		}
	}
	else{
		return -1;
	}	
}

float mediaDosElementos(){
	return somaElementos()*1.0 /contaElementos();
}

int main(){

	printf("LISTA SIMPLESMENTE ENCADEADA COM DESCRITOR\n\n");

	insereElementos();
	printf("Lista: ");
	mostraLista();
	printf("\n");
	printf("Numero de Elementos: %d\n", contaElementos());
	printf("Maior Elemento: %d\n", maiorElemento());
	printf("Menor Elemento: %d\n", menorElemento());
	printf("Soma dos Elementos: %d\n", somaElementos());
	printf("Media dos Elementos: %f\n", mediaDosElementos());

	removerElementos();

	return 0;
}
