#include <stdlib.h>
#include <stdio.h>

typedef struct Num{
	int n;
	struct Num *ante, *prox;
}Num;

Num *setNum(Num *meio){
	Num *nv = (Num*) malloc(sizeof(Num));
	
	printf("Digite um numero: ");
	scanf(" %d", &nv->n);
	
	if(meio == NULL){
		nv->ante = NULL;
		nv->prox = NULL;
		return nv;
	}
	else{
		Num *ins = meio;
		while(ins->ante != NULL || ins->prox != NULL){
			if(nv->n == ins->n){
				free(nv);
				return meio;
			}
			else if(nv->n < ins->n)
					if(ins->ante != NULL)
						ins = ins->ante;
					else break;
			else if(ins->prox != NULL)
				ins = ins->prox;
			else break;
		}
		
		if(nv->n < ins->n){
			nv->ante = NULL;
			nv->prox = NULL;
			ins->ante = nv;
		}
		else {
			nv->ante = NULL;
			nv->prox = NULL;
			ins->prox = nv;
		}
	}
	return meio;
}

void getNum(Num *meio){
	
	if(meio->ante)
		getNum(meio->ante);
	if(meio->prox)
		getNum(meio->prox);
	
	printf(" %d", meio->n);
}

int main(){
	Num *meio = NULL;
	int menu = -1;
	
	while(menu !=0){
		printf("1-Cadastrar um numero\n2-Imprimir a arvore\n0-Sair\n ");
		scanf(" %d", &menu);
		
		switch(menu){
			case(1):
				meio = setNum(meio);
				break;
			case(2):
				printf("Impressao modo busca em largura\n");
				getNum(meio);
				printf("\n");
				break;
		}
	}
}
