#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){
	char  nome_arquivo[200];
	
	char ed[200];
	
	printf("Digite o nome do arquivo a ser lido: ");
	scanf(" %[^\n]s", nome_arquivo);
	FILE *arquivo = fopen(nome_arquivo,"r+");
	
	if(!arquivo){
		arquivo = fopen(nome_arquivo, "w+");
		printf("Arquivo criado\n");
	}
	else printf("Arquivo aberto.\n");
	
	fclose(arquivo);
	
getch();
}

