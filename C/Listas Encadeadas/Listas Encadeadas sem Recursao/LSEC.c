#include <stdio.h>
#include <stdlib.h>

struct ptr{
    int valor;
    struct ptr *prox;
};
struct ptr *inicio;

void removeNoInicio(){
	if(inicio != NULL){
		struct ptr *aux = inicio;
		if(inicio->prox != inicio){
			inicio = inicio->prox;	
			struct ptr* aux2 = inicio;
			while(aux2->prox != aux){
				aux2 = aux2->prox;
			}
			aux2->prox = inicio;
		}
		else{
			inicio = NULL;
		}
		aux->prox = NULL;
		free(aux);
	}
}
void removeElemento(int num){
	if(inicio != NULL){
		if(inicio->valor == num){
			removeNoInicio();
		}
		else{			
			struct ptr *aux = inicio;
			while(aux->prox != inicio){
				if(aux->prox->valor == num){
					break;
				}
				aux = aux->prox;
			}
			if(num == aux->prox->valor){
				struct ptr *aux2 = aux->prox;
				aux->prox = aux2->prox;
				aux2->prox = NULL;
				free(aux2);
			}
		}
	}
}
void removerFinal(){
	if(inicio != NULL){
		struct ptr *aux = inicio;
		if(inicio->prox == inicio)
			inicio = NULL;
		else{
			struct ptr * aux2 = inicio;
			while(aux2->prox->prox != inicio){
				aux2 = aux2->prox;
			}			
			aux = aux2->prox;
			aux2->prox = aux->prox;
		}
		aux->prox = NULL;
		free(aux);
	}
}
void inserirNoFinal(int num){

	if(inicio == NULL){
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = num;
		inicio->prox = inicio;
	}
	else{
		struct ptr *aux = inicio; 
		while(aux->prox != inicio){
			aux = aux->prox;
		}
		aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
		aux->prox->valor = num;
		aux->prox->prox = inicio;
	}
}
void inserirNoInicio(int num){

	if(inicio == NULL){
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = num;
		inicio->prox = inicio;
	}
	else{
		struct ptr *aux = inicio;
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = num;
		inicio->prox = aux;

		struct ptr * aux2 = aux;
		while(aux2->prox != aux){
			aux2 = aux2->prox;
		}
		aux2->prox = inicio;
	}
}
void inserirNoMeio(int num){
	if(inicio != NULL){
		struct ptr * aux = inicio;
		while(aux->prox != inicio){
			if(aux->prox->valor > num ){
				break;
			}
			aux = aux->prox;
		}
		struct ptr *aux2 = aux->prox;
		aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
		aux->prox->valor = num;
		aux->prox->prox = aux2;
	}
	else{
		inserirNoInicio(num);
	}
}
void inserirCrescente(int num){

	if(inicio == NULL){
		inserirNoInicio(num);
	}
	else{
		if(inicio->valor >= num){
			inserirNoInicio(num);
		}
		else{
			inserirNoMeio(num);
		}
	}
}
void mostraLista(){
	if(inicio != NULL) {
		struct ptr * aux = inicio;
		printf("%d\t", aux->valor);
		aux = aux->prox;
		while(aux != inicio){
			printf("%d\t", aux->valor);
			aux = aux->prox;
		}
	}
	printf("\n");
}
void insereElementos(){

	int numero;

	inicio = NULL;

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
	if(inicio != NULL){
		removeNoInicio();
		printf("\n");
	}
}
void removerElementos(){
	
	while(inicio != NULL){
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
		
		mostraLista(inicio);
	}
}
int contaElementos(){
	if(inicio == NULL){
		return 0;
	}
	else{
		if(inicio == inicio->prox)
			return 1;
		else{
			struct ptr* aux = inicio->prox;
			int count = 1;
			while(aux != inicio){
				aux = aux->prox;
				count ++;
			}
			return count;
		}
	}
}
int maiorElemento(){
	if(inicio == NULL){
		return -1;
	}
	else{
		struct ptr * aux = inicio->prox;
		int maior = inicio->valor;
		while(aux != inicio){
			if(aux->valor > maior)
				maior = aux->valor;
			aux = aux->prox;
		}
		return maior;
	}
}
int menorElemento(){
	if(inicio == NULL){
		return -1;
	}
	else{
		struct ptr * aux = inicio->prox;
		int menor = inicio->valor;
		while(aux != inicio){
			if(aux->valor < menor)
				menor = aux->valor;
			aux = aux->prox;
		}
		return menor;
	}
}
int somaElementos(){
	if(inicio == NULL){
		return 0;
	}
	else{
		int soma = inicio->valor;
		struct ptr * aux = inicio->prox;
		while(aux != inicio){
			soma += aux->valor;
			aux = aux->prox;
		}
		return soma;
	}
}
float mediaDosElementos(){
	return somaElementos()*1.0 /contaElementos();
}

int main(){

	printf("LISTA SIMPLESMENTE ENCADEADA CIRCULAR\n\n");

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
