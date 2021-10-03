#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct Raiz{
	int raiz;
	struct Raiz *prox, *ante;
	struct Num *inicio;
}Raiz;

typedef struct Num{
	int numero;
	
	struct Num *proxn, *anten;
}Num;


void gerarAleatorio(Num **ale){
	Num *n = (Num*)malloc(sizeof(Num));
	n->numero = rand()%101;
	n->anten = NULL;
	n->proxn = NULL;
	
	if(!*ale){
		*ale = n;
	}
	else{
		Num *fim = *ale;
		while(fim->proxn)
			fim = fim->proxn;
		n->anten = fim;
		fim->proxn = n;
	}
}

void getNum(Num *alea){
	printf(" %d ", alea->numero);
	if(alea->proxn)
		getNum(alea->proxn);
}

//===============================================================

void setRaiz(Raiz **lista, Num **n){
	Raiz *nv = (Raiz*)malloc(sizeof(Raiz));
	printf("Digite um numero: ");
	scanf(" %d", &nv->raiz);
	nv->ante = NULL;
	nv->prox = NULL;
	nv->inicio = NULL;
	
	Num *aux = *n;
	while(aux){
		if(aux->numero % nv->raiz == 0){
			
			if(!aux->anten)
				if(aux->proxn){
					*n = aux->proxn;
					aux->proxn->anten = NULL;
				}
				else *n = NULL;
			else if(!aux->proxn)
				aux->anten->proxn = NULL;
			else{
				aux->anten->proxn = aux->proxn;
				aux->proxn->anten = aux->anten;
			}
			
			Num *ins = aux;
			aux = aux->proxn;
			if(!nv->inicio){
				ins->anten = NULL;
				ins->proxn = NULL;
				nv->inicio = ins;
			}
			else{
				Num *fim = nv->inicio;
				while(fim->proxn)
					fim = fim->proxn;
				ins->anten = fim;
				ins->proxn = NULL;				
				fim->proxn = ins;
			}
		}
		else aux = aux->proxn;
	}
	
	if(!*lista)
		*lista = nv;
	else{
		Raiz *fim = *lista;
		while(fim->prox){
			fim = fim->prox;
		}
		nv->ante = fim;
		fim->prox = nv;
	}
}

void getLista(Raiz *list){
	printf(" %d", list->raiz);
	if(list->prox)
		getLista(list->prox);
}

void getMult(Raiz *ini){
	Raiz *lista = ini;
	int n;
	
	printf("Digite o numero de busca: ");
	scanf(" %d", &n);
	
	while(lista){
		if(lista->raiz == n){
			printf(" %d, multiplos: ", lista->raiz);
			Num *aux = lista->inicio;
			while(aux){
				printf("%d, ", aux->numero);
				aux = aux->proxn;
			}
			break;
		}
		else lista = lista->prox;
	}
}

int main(){
	srand(time(NULL));
	Num *aleatorio = NULL;
	Raiz *lista = NULL;
	
	int menu = -1;
	
	for(int i=0; i<10; i++)
		gerarAleatorio(&aleatorio);
	
	while(menu != 0){
		printf("Digite a opcao: 1/2/3/4\n");
		scanf(" %d", &menu);
		
		switch(menu){
			case 1:
				setRaiz(&lista, &aleatorio);
				printf("%d ", lista->raiz);
				break;
			case 2:
				getLista(lista);
				printf("\n");
				break;
			case 3:
				getNum(aleatorio);
				printf("\n");
				break;
			case 4:
				getMult(lista);
				printf("\n");
				break;
		}
	}
}
