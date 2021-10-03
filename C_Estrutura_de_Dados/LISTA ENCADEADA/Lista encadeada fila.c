#include <stdlib.h>
#include <stdio.h>

typedef struct Time{
	char nome[300];
	int cod;
	
	struct Time *prox;
}Time;

Time *setTime(Time *lista){
	
	Time *nv = (Time*) malloc(sizeof(Time));
	
	printf("Digite o nome do time: ");
	scanf(" %[^\n]s", nv->nome);
	printf("Digite o codigo do time: ");
	scanf(" %d", &nv->cod);
		
	if(lista==NULL){
		
		nv->prox = NULL;
		lista = nv;
	}
	else{
		Time *aux = lista;
		while(aux->prox != NULL)
			aux = aux->prox;
			
		nv->prox = NULL;
		aux->prox = nv;
	}
	
	return lista;
}

void getTime(Time *lista){
	
	Time *aux = lista;
	
	if(aux==NULL){
	}
	else{
		do{
			printf("%s\t%d\n", aux->nome, aux->cod);
			aux = aux->prox;
			
		}while(aux != NULL);
	}
}

int main(){
	Time *lista=NULL;
	
	int menu = -1;
	
	while(menu != 0){		
		
		printf("O que deseja fazer ?\n1-Cadastrar time\n2-Listar time\n");
		scanf(" %d", &menu);
		
		switch(menu){
			case(1):
				lista = setTime(lista);
				break;
			
			case(2):
				getTime(lista);
				break;
			
		}
	}
}

/*typedef struct Teste{
	int i;
	struct Teste *prox;
}Teste;

Teste *setvalue(Teste *lista){
	Teste *n = (Teste*) malloc(sizeof(Teste));
	
	scanf(" %d", &n->i);
	
	if(lista == NULL){
		n->prox = NULL;
		lista = n;
	}
	else{
		Teste *aux = lista;
		while(aux->prox != NULL)
			aux = aux->prox;
		
		n->prox = NULL;
		aux->prox = n;
	}
	
	return lista;
}

void getvalue(Teste *lista){
	Teste *aux = lista;
	
	if(aux->prox == NULL){
	}
	else{
		while(aux != NULL){
			printf(" %d", aux->i);
			aux = aux->prox;
		}
	}
	
}

int main(){
	Teste *lista = NULL;
	
	lista = setvalue(lista);
	lista = setvalue(lista);
	lista = setvalue(lista);
	
	getvalue(lista);
}*/


