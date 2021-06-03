#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

// Variáveis de Bloqueio
pthread_mutex_t bonding_mutex;
pthread_mutex_t oxygen_mutex;
pthread_mutex_t hydrogen_mutex;

// Variáveis contadores
int total_bonds = 0;
int oxygen = 0;
int hydrogen = 0;
int bond_count = 0;

// Variável de fila
char bond_queue[3];

// Metodo de junção
void bond(char atom){

	// Bloqueia para que um atomo chame o método por vez
	pthread_mutex_lock(&bonding_mutex);

	// Incrementa o numero de junções para apresentar os resultados
	total_bonds++;

	// Insere o atomo na fila de junção
	bond_queue[bond_count++] = atom;

	// Quando o último átomo chegar
	if(bond_count ==  3){

		// Mostra a junção
		printf("Uma molecula de H2O foi formada. Fila de juncao -> %s\n", bond_queue);

		// Esvazia fila
		bond_queue[0] = ' ';
		bond_queue[1] = ' ';
		bond_queue[2] = ' ';

		// Zera os contadores
		oxygen = hydrogen = bond_count = 0;
	}

	// Libera para o proximo atomo se juntar
	pthread_mutex_unlock(&bonding_mutex);

}

// Barreira de junção
void barrier_wait(char atom){
	// Chama o metodo de junção
	bond(atom);

	// Aguarda até que os outros atomos cheguem para se juntar
	while(bond_count != 0 || bond_count == 3){
		// Esperando
	}
}
// Thread de Oxigenio
void *oxygen_thread(void *arg){

	// Bloqueia para que Oxigenios sejam criado um de cada vez
	pthread_mutex_lock(&oxygen_mutex);

	// Caso o numero de oxigenios tenha atingido o limite de junção, aguarda
	while(oxygen == 1){
		// Esperando
	}

	// Cria oxigenio
	oxygen++;

	// Libera para outros oxigenios
	pthread_mutex_unlock(&oxygen_mutex);
	
	//Entra na barreira
	barrier_wait('O');
}

// Thread de Hidrogênio
void *hydrogen_thread(void *arg){

	// Bloqueia para que Hidrogenios sejam criado um de cada vez
	pthread_mutex_lock(&hydrogen_mutex);

	// Caso o numero de hidrogenios tenha atingido o limite de junção, aguarda
	while(hydrogen == 2){
		// Esperando
	}

	// Cria um hidrogenio
	hydrogen++;

	// Libera para os outros hidrogenios
	pthread_mutex_unlock(&hydrogen_mutex);

	// Entra na barreira
	barrier_wait('H');
}

int main(int argc, char *argv[]){

	// Inicializa Variáveis
	int i, total_molecules;
	pthread_mutex_init(&bonding_mutex, NULL);
	pthread_mutex_init(&oxygen_mutex, NULL);
	pthread_mutex_init(&hydrogen_mutex, NULL);

	// Recebe os argumentos por parametro de linha, caso não receba nada ele solicita os valores
	if(argc == 2){
		// Quando o parâmetro é passado
		total_molecules = atoi(argv[1]);
	}
	else{
		// Parêmetros não são passados
		if(argc < 2){
			printf("O numero de moleculas ira determinar a quantidade de Threads criadas\n1 molecula gera 3 Threads (2 Hidrogenios e 1 Oxigenio)\n\n");
			printf("Entre com o numero total de moleculas que voce deseja formar: ");
			scanf("%d", &total_molecules);
		}
		else{
			// São passados mais parâmetros do que deveria
			printf("Argumentos demais foram passados, veja o manual:\n");
			printf("\tbuilding_h2o [total_of_molecules]\n");
			return 1;
		}
	}

	// Inicializa as Threads de acordo com os parâmetros
	int max_threads_o = total_molecules;
	int max_threads_h = 2*total_molecules;
	pthread_t oxygen_queue[max_threads_o];
	pthread_t hydrogen_queue[max_threads_h];


	// Cria Threads de Oxigenio e Hidrogenio
	for(i=0; i<max_threads_o; i++){
		pthread_create(&(oxygen_queue[i]), NULL, oxygen_thread, NULL);	
	}
	for(i=0; i<max_threads_h; i++){
		pthread_create(&(hydrogen_queue[i]), NULL, hydrogen_thread, NULL);
	}

	// Finaliza as Threads quando elas terminarem
	for(i=0; i<max_threads_o; i++){
		pthread_join(oxygen_queue[i], NULL);
	}
	for(i=0; i<max_threads_h; i++){
		pthread_join(hydrogen_queue[i], NULL);
	}

	// Mostra os resultados obtidos
	printf("\nRESULTADOS\n");
	printf("Ao todo %d juncoes foram feitas, totalizando %d moleculas de H2O geradas.\n", total_bonds, total_bonds/3);

	return 0;
}
