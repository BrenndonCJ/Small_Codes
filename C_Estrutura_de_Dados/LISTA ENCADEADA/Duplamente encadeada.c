#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Time{
	char nome[50];
	int cod;
	
	struct Time *ante, *prox;
}Time;

Time *setTime(Time *inicio){
	Time *nv = (Time*) malloc(sizeof(Time));
	
	printf("Nome: ");
	scanf(" %s", nv->nome);
	printf("Codigo: ");
	scanf(" %d", &nv->cod);
	
	if(inicio == NULL){
		nv->ante = NULL;
		nv->prox = NULL;
		inicio = nv;
	}
	else{
		Time *final = inicio;
		while(final->prox != NULL)
			final = final->prox;
		nv->prox = NULL;
		nv->ante = final;
		final->prox = nv;
	}
	
	return inicio;
}

void getTime(Time *inicio){
	Time *aux = inicio;
	
	do{
		printf(" %s\n", aux->nome);
		aux = aux->prox;
	}while(aux != NULL);
	
	aux = inicio;
	
	while(aux->prox != NULL)
		aux = aux->prox;
	do{
		printf(" %s\n", aux->nome);
		aux = aux->ante;
	}while(aux != NULL);
}

int main(){
	Time *inicio = NULL;
	int menu = -1;
	
	while(menu != 0){
		printf("1-Cadastrar\n2-Listar\n");
		scanf(" %d", &menu);
		switch(menu){
			case(1):
				inicio = setTime(inicio);
				break;
			case(2):
				getTime(inicio);
				break;
		}
	}

}

