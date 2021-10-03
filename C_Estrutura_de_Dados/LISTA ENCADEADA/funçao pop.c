#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Torrent{
	char nome[50];
	char link[50];
	
	struct Torrent *ante, *prox;
}Torrent;

Torrent *setTorrent(Torrent *inicio){
	Torrent *nv = (Torrent*) malloc(sizeof(Torrent));
	
	printf("Nome do arquivo: ");
	scanf(" %[^\n]s", nv->nome);
	printf("Link do arquivo: ");
	scanf(" %[^\n]s", nv->link);
	
	if(inicio == NULL){
		nv->ante = NULL;
		nv->prox = NULL;
		inicio = nv;
	}
	else{
		Torrent *final = inicio;
		while(final->prox != NULL)
			final = final->prox;
		nv->prox = NULL;
		nv->ante = final;
		final->prox = nv;
	}
	
	return inicio;
}

void pop(Torrent **lista, Torrent **inicio){
	
	if(!(*lista)->ante)
		(*inicio) = (*lista);
	else if(!(*lista)->prox){
		(*lista)->ante->prox = NULL;
		(*lista)->ante = NULL;
		(*inicio)->ante = (*lista);
		(*lista)->prox = (*inicio);
		(*inicio) = (*lista);
	}
	else{
		(*lista)->ante->prox = (*lista)->prox;
		(*lista)->prox->ante = (*lista)->ante;
		(*lista)->ante = NULL;
		(*inicio)->ante = (*lista);
		(*lista)->prox = (*inicio);
		(*inicio) = (*lista);
	}
}

Torrent *busca(Torrent *inicio){
	Torrent *busca = inicio;
	char nome[50];
	
	printf("Digite o nome de busca: ");
	scanf(" %s", nome);
	
	while(busca){
		if(strcmp(nome, busca->nome)==0){
			pop(&busca, &inicio);
			return inicio;
		}
		else busca = busca->prox;
	}
	printf("Arquivo nao encontrado\n");
	return inicio;
}

void getTorrent(Torrent *inicio){
	printf(" %s\n", inicio->nome);
	if(inicio->prox)
		getTorrent(inicio->prox);
}

int main(){
	Torrent *inicio = NULL;
	int menu = -1;
	
	while(menu != 0){
		printf("\n1-Adicionar\n2-Buscar\n3-Listar\n");
		scanf(" %d", &menu);
		switch(menu){
			case(1):
				inicio = setTorrent(inicio);
				break;
			case(2):
				if(inicio)
					inicio = busca(inicio);
				else printf("Lista vazia\n");
				break;
			case(3):
				if(inicio)
					getTorrent(inicio);
				else printf("Lista vazia\n");
				break;
		}
	}
}
