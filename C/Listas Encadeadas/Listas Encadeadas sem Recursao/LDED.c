#include <stdio.h>
#include <stdlib.h>

struct ptr{
    int valor;
    struct ptr *ant, *prox;
};
struct descritor{
	int quant;
	struct ptr *prim, * ult;
};
struct descritor * lista;

void removeNoInicio(){
	if(lista != NULL){
		if(lista->prim != NULL){
			struct ptr *aux = lista->prim;
			if(lista->prim->prox != NULL){
				lista->prim = lista->prim->prox;
				lista->prim->ant = NULL;
			}
			else{
				lista->prim = NULL;
				lista->ult = NULL;
			}
			aux->ant = NULL;
			aux->prox = NULL;
			free(aux);
			lista->quant --;
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
				struct ptr *aux = lista->prim;
				while(aux != NULL){
					if(aux->valor == num){
						break;
					}
					aux = aux->prox;
				}
				if(aux != NULL){
					if(aux == lista->ult){
						lista->ult = aux->ant;
					}
					aux->ant->prox = aux->prox;
					if(aux->prox != NULL){
						aux->prox->ant = aux->ant;
					}
					aux->prox = NULL;
					aux->ant = NULL;
					free(aux);
					lista->quant --;
				}
			}
		}
	}
}
void removerFinal(){
	if(lista != NULL){
		if(lista->prim != NULL){
			struct ptr *aux = lista->ult;
			if(lista->ult == lista->prim){
				lista->prim = NULL;
				lista->ult = NULL;
			}
			else{
				aux->ant->prox = NULL;
				lista->ult = aux->ant;
			}
			aux->prox = NULL;
			aux->ant = NULL;
			free(aux);
			lista->quant --;
		}
	}
}


void inserirNoInicio(int num){
	if(lista != NULL){
		if(lista->prim == NULL){
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->ant = NULL;
			lista->prim->prox = NULL;
			lista->ult = lista->prim;
		}
		else{
			struct ptr *aux = lista->prim;
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = aux;
			lista->prim->ant = NULL;
			aux->ant = lista->prim;
		}
		lista->quant ++;
	}
}
void inserirNoFinal(int num){
	if(lista != NULL){
		if(lista->prim == NULL){
			inserirNoInicio(num);
		}
		else{
			struct ptr *aux = lista->prim; 
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
			aux->prox->valor = num;
			aux->prox->prox = NULL;
			aux->prox->ant = aux;
			lista->ult = aux->prox;
		}
		lista->quant ++;
	}
}
void inserirNoMeio(int num){
	if(lista != NULL){
		if(lista->prim != NULL){
			struct ptr * aux = lista->prim;
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
			aux->prox->ant = aux;
			if(aux2 != NULL){
				aux2->ant = aux->prox;
			}
			if(aux == lista->ult){
				lista->ult = aux->prox;
			}
		}
		lista->quant ++;
	}
}
void inserirCrescente(int num){
	if(lista != NULL){
		if(lista->prim == NULL){
			inserirNoInicio(num);
		}
		else{
			if(lista->prim->valor > num){
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
		if(lista->prim != NULL) {
			struct ptr * aux = lista->prim;
			while(aux != NULL){
				printf("%d\t", aux->valor);
				aux = aux->prox;
			}
		}
	}
	else{
		printf("Lista vazia");
	}
	printf("\n");
}
void insereElementos(){
	int numero;

	lista = (struct descritor *)malloc(sizeof(struct descritor));
	lista->prim = NULL;
	lista->ult = NULL;
	lista->quant = 0;
	
	printf("Entre com um numero: ");
	scanf("%d", &numero);

	while (numero >= 0){
		inserirCrescente(numero);
		mostraLista();
		printf("Entre com um numero: ");
		scanf("%d", &numero);
	}
}

void removerTodosOsElementos(){
	if(lista != NULL){
		if(lista->prim != NULL){
			removeNoInicio();
			printf("\n");
		}
	}
}

void removerElementos(){
	if(lista != NULL){
		while(lista->prim != NULL){
			int o;
			printf("\n\n[1] Remover Inicio\n[2] Remover Final\n[3] Remover Elemento\n");
			scanf("%d", &o);
			printf("\n");
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
				printf("\n");
				removeElemento(n);
			}
			
			mostraLista(lista->prim);
		}
	}
}

int contaElementos(){
	if(lista != NULL){
		return lista->quant;
	}
	else{
		return -1;
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
	else{
		return -1;
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
	else{
		return -1;
	}
}

int somaElementos(){
	if(lista != NULL){
		if(lista->prim == NULL){
			return 0;
		}
		else{
			int soma = 0;
			struct ptr * aux = lista->prim;
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
	
	lista = NULL;
	insereElementos();
	printf("Lista: ");
	mostraLista();
	printf("\n\n");
  	printf("Numero de Elementos: %d\n", contaElementos()); 
	printf("Maior Elemento: %d\n", maiorElemento());
	printf("Menor Elemento: %d\n", menorElemento());
	printf("Soma dos Elementos: %d\n", somaElementos());
	printf("Media dos Elementos: %f\n", mediaDosElementos());
	printf("\n\n");
	removerElementos(); 
	

	return 0;
}
