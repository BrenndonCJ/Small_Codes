#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	int cartas[9];
	
	int win=0;
	
	for(int i=0; i<9; i++){
		cartas[i] = 1+(rand()%13);
		printf(" %d", cartas[i]);
	}
	while(win < 3){
	int user, val=0;
	for(int i=1; i<9; i++){
		int aux = cartas[i];
		for(int a=i-1; a>=0; a--)
			if(aux < cartas[a]){
				cartas[a+1] = cartas[a];
				cartas[a] = aux;
			}
	}
	printf("\n");
	for(int i=0; i<9; i++)
		printf(" %d", cartas[i]);
	printf("\n");
	scanf(" %d",&user);
	
	for(int i=0; i<9; i++)
		if(user == cartas[i]){
			cartas[i] = 1+(rand()%13);
			val=1;
			break;
		}
	if(val == 0)
		printf("Carta nao encontrada");
	
	for(int i=0; i<9; i+=3){
		if((cartas[i] == cartas[i+1] && cartas[i] == cartas[i+2])){
			win++;
			printf(" %d\n",win);
		}
		if((cartas[i] == cartas[i+1]-1 && cartas[i] == cartas[i+2]-2)){
			win++;
			printf(" %d\n", win);
		}
	}
		
	}
	for(int i=0; i<9; i++)
		printf(" %d", cartas[i]);
	
	printf("\nvoce venceu");
	return 0;
}
