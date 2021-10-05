#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int main(){
	
	srand(time(NULL));
	char cpf[300]={0,0,0,0,0,0,0,0,0,0,0};
	int cpfInt[]={0,0,0,0,0,0,0,0,0,0,0};
	int valido = 0;
	
	while(valido != 5){
	
		for(int i=0; i<11; i++)
			cpfInt[i] = rand() % 10;
		
		int mult=0, mult2=0, total=0, total2=0;
		for(int i=1; i<10; i++){
			mult = cpfInt[i-1] * i;
			total += mult;
			mult2 = cpfInt[i] * i;
			total2 += mult2;
		}
		
		if(total % 11 == 0 || total % 11 == 10)
			total = 0;
		else total = total % 11;
		
		if(total2 % 11 == 0 || total2 % 11 == 10)
			total2 = 0;
		else total2 = total2 % 11;
		
		if((total == cpfInt[9]) && (total2 == cpfInt[10])){
			valido++;
			for(int i=0; i<11; i++){
				printf("%d", cpfInt[i]);
				if(i == 2 || i == 5)
					printf(".");
				else if(i == 8)
					printf("-");
			}
			printf("\n");
		}
		else {
			for(int i=0; i<11; i++)
				cpfInt[i] = 0;
		}
	}
	getch();
}
