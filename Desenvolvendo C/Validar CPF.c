#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char cpf[300]={0,0,0,0,0,0,0,0,0,0,0};
	int cpfInt[]={0,0,0,0,0,0,0,0,0,0,0};
	
	scanf(" %[^\n]s", cpf);
	
	if(cpf[0]>=48 && cpf[0]<=57){
		for(int i=0; i<11; i++){
				cpfInt[i]= cpf[i];
				cpfInt[i] -=48;
		}
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
		
		if((total == cpfInt[9]) && (total2 == cpfInt[10]))
			printf(" CPF valido");
		else printf(" CPF Invalido\n Tente novamente");
		
		//printf(" %s", cpf);
	}
	else printf(" ERRO ");
}
