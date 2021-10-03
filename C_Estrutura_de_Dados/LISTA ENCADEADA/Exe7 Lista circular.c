#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nome{
	char nome[50];
	struct Nome *prox;
}Nome;

Nome *setNome(Nome *lista){
	Nome *nv = (Nome*)malloc(sizeof(Nome));
	scanf(" %s", nv->nome);
	
	if(!lista){
		lista = nv;
		nv->prox = lista;
	}
	else{
		Nome *final = lista;
		if(final->prox == lista){
			final->prox = nv;
			nv->prox = lista;
		}
		else while(final->prox != lista)
			final = final->prox;
		
		final->prox = nv;
		nv->prox = lista;
	}
	return lista;
}

void getNome(Nome *lista){
	Nome *final = lista;
	
	if(final->prox == lista)
		printf(" %s", final->nome);
	else do{
		printf(" %s", final->nome);
		final = final->prox;
	}while(final != lista);
}

int main(){
	Nome *lista=NULL;
	int menu = -1;
	
	while(menu !=0){
		scanf(" %d", &menu);
		switch(menu){
			case 1:
				lista = setNome(lista);
				break;
			case 2:
				getNome(lista);
				break;
		}
	}
	
}

