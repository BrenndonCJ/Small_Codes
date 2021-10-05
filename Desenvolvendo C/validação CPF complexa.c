#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(){
	
	char cpf[300];
	int cpfInt[300], n=11;
	
	scanf(" %[^\n]s", cpf);
	
	if(cpf[0]>=48 && cpf[0]<=57){
		int a2=0;
		for(int i=0; i<n; i++){
			if(cpf[i]>=48 && cpf[i]<=57){
				cpfInt[i]= cpf[i];
				cpfInt[i] -=48;
			}
			else {n++; cpfInt[i] = cpf[i];}
		}
		/*for(int i=0; i<n; i++){
			if(cpfInt[i]>=0 && cpfInt[i]<=9)
				printf("%d", cpfInt[i]);
			else printf("%c",cpfInt[i]);
		}*/
		
		int mult=0, mult2=0, total=0, total2=0, a=1, b=1;
		
		//printf("%d\n", n);
		for(int i=1; i<n-1; i++){
			if(cpfInt[i-1]>=0 && cpfInt[i-1]<=9){
				mult = cpfInt[i-1] * a;
				total += mult;
				a++;
			}
			if(cpfInt[i]>=0 && cpfInt[i]<=9){
				mult2 = cpfInt[i] * b;
				total2 += mult2;
				b++;
			//	printf(" %d \t",mult2);
			//	printf(" %d \t",total2);
			}
		}
		int resto1, resto2;
	//	printf("\n\n %d %d\n\n", total, total2);
		if(total % 11 == 0 || total % 11 == 10)
			resto1 = 0;
		else resto1 = total % 11;
		
		if(total2 % 11 == 0 || total2 % 11 == 10)
			resto2 = 0;
		else resto2 = total2 % 11;
	
		if((resto1 == cpfInt[n-2]) && (resto2
		 == cpfInt[n-1]))
			printf(" CPF valido");
		else printf(" CPF Invalido\n Tente novamente");
		
	}
	else printf(" ERRO ");
	
	getch();
}
