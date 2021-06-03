#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	char verbo[11], finalVerbo, inicioVerbo[11];
	int tamVerbo , i ,verboOk;
	
	strcpy(verbo, "NAO_FIM");
	while(strcmp(verbo, "FIM") != 0){
		verboOk = 0;

		while(!verboOk){
			
			tamVerbo = 0;
			i = 0;
		
			printf("Escolha um verbo ou digite \"FIM\" para sair: ");
			scanf("%s", verbo);

			while(verbo[i++] != '\0'){
				tamVerbo++;
			}

			finalVerbo = verbo[tamVerbo - 2];

			i = 0;
			while( i < tamVerbo - 2){
				inicioVerbo[i] = verbo[i];
				i++;
			}
			inicioVerbo[i] = '\0';

			if(((finalVerbo == 'a' || finalVerbo == 'e' || finalVerbo == 'i') && verbo[tamVerbo - 1] == 'r') || strcmp(verbo, "FIM") == 0){
				verboOk = 1;
			}
			else{
				printf("O verbo deve estar no infinitivo, ser regular e terminar por uma das opções a seguir: ar, er, ir\n\n");
			}
		}
		

		if(strcmp(verbo, "FIM") != 0){
			printf("__________________\nVERBO: %s\n__________________", verbo);
			
			printf("\n\nTEMPO: Presente\n");

			printf("Eu\t%so\n",inicioVerbo);
			(finalVerbo == 'i')? printf("Tu\t%ses\n",inicioVerbo):printf("Tu\t%s%cs\n",inicioVerbo, finalVerbo);
			(finalVerbo == 'i')? printf("Ele\t%se\n",inicioVerbo):printf("Ele\t%s%c\n",inicioVerbo, finalVerbo);
			printf("Nós\t%s%cmos\n",inicioVerbo, finalVerbo);
			(finalVerbo == 'i')? printf("Vós\t%sis\n",inicioVerbo):printf("Vós\t%s%cis\n",inicioVerbo, finalVerbo);
			(finalVerbo == 'i')? printf("Eles\t%sem\n",inicioVerbo):printf("Eles\t%s%cm\n",inicioVerbo, finalVerbo);

			printf("\n\nTEMPO: Preterito Perfeito\n");

			(finalVerbo == 'a')? printf("Eu\t%sei\n",inicioVerbo):printf("Eu\t%si\n",inicioVerbo);
			printf("Tu\t%s%cste\n",inicioVerbo, finalVerbo);
			(finalVerbo == 'a')? printf("Ele\t%sou\n",inicioVerbo):printf("Ele\t%s%cu\n",inicioVerbo, finalVerbo);
			printf("Nós\t%s%cmos\n",inicioVerbo, finalVerbo);
			printf("Vós\t%s%cstes\n",inicioVerbo, finalVerbo);
			printf("Eles\t%s%cram\n",inicioVerbo, finalVerbo);

			printf("\n\nTEMPO: Futuro do Presente\n");

			printf("Eu\t%s%crei\n",inicioVerbo, finalVerbo);
			printf("Tu\t%s%crás\n",inicioVerbo, finalVerbo);
			printf("Ele\t%s%crá\n",inicioVerbo, finalVerbo);
			printf("Nós\t%s%cremos\n",inicioVerbo, finalVerbo);
			printf("Vós\t%s%creis\n",inicioVerbo, finalVerbo);
			printf("Eles\t%s%crão\n",inicioVerbo, finalVerbo);

			printf("\n____________________________________\n\n");
		}

	}

	return 0;
}