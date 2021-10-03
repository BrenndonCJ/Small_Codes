#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Veiculo{
	char modelo[50], placa[8];
	int ano;
	int totalmultas;
	
	struct Veiculo *prox, *ante;
	struct Multa *multa;
	
}Veiculo;

typedef struct Multa{
	char data[11]
	int cod, valor;
	
	struct Multa *prox;
};

int main(){
	Veiculo *listaVeiculo = NULL;
	Multa *listaMulta = NULL;
	
	int menu = -1;
	
	while(menu != 0){
		
	}
}
