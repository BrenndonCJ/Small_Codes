#include <stdlib.h>
#include <stdio.h>

typedef struct Time{
	char nome[300];
	int cod;
	struct Time *prox;
}Time;

Time *setTime(Time *inicio){
	Time *nv = (Time*) malloc(sizeof(Time));
	
	printf("Digite o nome do time: ");
	scanf(" %[^\n]s", nv->nome);
	printf("Digite o codigo do time: ");
	scanf(" %d", &nv->cod);
	
	if(inicio == NULL){
		nv->prox = NULL;
		inicio = nv;
	}
	else{
		Time *aux = inicio;
		while(aux->prox != NULL)
			aux = aux->prox;
		
		nv->prox = NULL;
		aux->prox = nv;
	}
	
	return inicio;
}

void getTime(Time *inicio){
	Time *aux = inicio;
	
	if(aux == NULL){
	}
	else
		while(aux != NULL){
			printf("%s\t%d\n", aux->nome, aux->cod);
			aux = aux->prox;
	}
}

void menu(Time *inicio){
	int menu = -1;
	
	while(menu !=0){
		printf("O que deseja fazer ?(1-cadastrar/2-listar): ");
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

int main(){
	
	Time *inicio=NULL;
	
	menu(inicio);
}

/*Time *setTime(Time *lista){
	Time *nv = (Time*) malloc(sizeof(Time));
	
	printf("Digite o nome do time: ");
	scanf(" %[^\n]s", nv->nome);
	printf("Digite o codigo do time: ");
	scanf(" %d", &nv->cod);
	
	if(lista == NULL){
		nv->prox = NULL;
		lista = nv;
	}
	else{
		nv->prox = lista;
		lista = nv;
	}
	
	return nv;
}

void getTime(Time *lista){
	Time *aux = lista;
	
	if(aux == NULL){
	}
	else{
		do{
			printf(" %s", aux->nome);
			aux = aux->prox;
			
		}while(aux != NULL);
	}
}

void menu(Time *inicio){
	int menu = -1;
	
	while(menu !=0){
		printf("O que deseja fazer ?(1-cadastrar/2-listar): ");
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


int main(){
	Time *lista;
	
	menu(lista);
}*/
