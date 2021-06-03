#include <stdio.h>
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
			if(lista->prim->prox != lista->prim){
				lista->prim = lista->prim->prox;	
				struct ptr* aux2 = lista->prim;
				while(aux2->prox != aux){
					aux2 = aux2->prox;
				}
				aux2->prox = lista->prim;
			}
			else{
				lista->prim = NULL;
				lista->ult = NULL;
			}
			aux->prox = NULL;
			free(aux);
		}
		lista->quant--;
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
				while(aux->prox != lista->prim){
					if(aux->prox->valor == num){
						break;
					}
					aux = aux->prox;
				}
				if(num == aux->prox->valor){
					struct ptr *aux2 = aux->prox;
					aux->prox = aux2->prox;
					aux2->prox = NULL;
					if(aux2 == lista->ult){
						lista->ult = aux;
					}
					free(aux2);
					lista->quant--;
				}
			}
		}
	}
}
void removerFinal(){
	if(lista != NULL){
		if(lista->prim != NULL){
			struct ptr *aux = lista->prim;
			if(lista->prim->prox == lista->prim){
				lista->prim = NULL;
				lista->ult = NULL;
			}
			else{
				struct ptr * aux2 = lista->prim;
				while(aux2->prox->prox != lista->prim){
					aux2 = aux2->prox;
				}			
				aux = aux2->prox;
				aux2->prox = aux->prox;
				lista->ult = aux2;
			}

			aux->prox = NULL;
			free(aux);

			lista->quant--;
		}
	}
}
void inserirNoFinal(int num){

	if(lista != NULL){
		if(lista->prim == NULL){
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = lista->prim;
			lista->ult = lista->prim;
		}
		else{
			struct ptr *aux = lista->prim; 
			while(aux->prox != lista->prim){
				aux = aux->prox;
			}
			aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
			aux->prox->valor = num;
			aux->prox->prox = lista->prim;
			lista->ult = aux->prox;
		}
		lista->quant++;
	}
}
void inserirNoInicio(int num){

	if(lista != NULL){
		if(lista->prim == NULL){
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = lista->prim;
			lista->ult = lista->prim;
		}
		else{
			struct ptr *aux = lista->prim;
			lista->prim = (struct ptr *)malloc(sizeof(struct ptr));
			lista->prim->valor = num;
			lista->prim->prox = aux;
			lista->ult->prox = lista->prim;
		}
		lista->quant++;
	}
}
void inserirNoMeio(int num){
	if(lista!= NULL){
		if(lista->prim != NULL){
			struct ptr * aux = lista->prim;
			while(aux->prox != lista->prim){
				if(aux->prox->valor > num ){
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
	if(lista!= NULL){
		if(lista->prim != NULL) {
			struct ptr * aux = lista->prim;
			printf("%d\t", aux->valor);
			aux = aux->prox;
			while(aux != lista->prim){
				printf("%d\t", aux->valor);
				aux = aux->prox;
			}
		}
	}
	printf("\n");
}
void insereElementos(){

	int numero;

	lista = (struct descritor *) malloc(sizeof(struct descritor));
	lista->quant = 0;
	lista->prim = NULL;
	lista->ult = NULL;

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
			while(aux != lista->prim){
				if(aux->valor > maior)
					maior = aux->valor;
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
			while(aux != lista->prim){
				if(aux->valor < menor)
					menor = aux->valor;
				aux = aux->prox;
			}
			return menor;
		}
	}
}
int somaElementos(){
	if(lista != NULL){
		if(lista->prim == NULL){
			return 0;
		}
		else{
			int soma = lista->prim->valor;
			struct ptr * aux = lista->prim->prox;
			while(aux != lista->prim){
				soma += aux->valor;
				aux = aux->prox;
			}
			return soma;
		}
	}
}
float mediaDosElementos(){
	return somaElementos()*1.0 /contaElementos();
}

int main(){
	
	printf("LISTA SIMPLESMENTE ENCADEADA CIRCULAS COM DESCRITOR\n\n");
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
