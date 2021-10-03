#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Aluno{
	char nome[50];
	int matricula;
}Aluno;

void setAluno(FILE *a){
	Aluno nv;
	fseek(a, 0, SEEK_END);
	printf("Digite o nome do aluno: ");
	scanf(" %s", nv.nome);
	printf("Digite o numero de matricula: ");
	scanf(" %d", &nv.matricula);
	fwrite(&nv, sizeof(Aluno), 1, a);
}

void getAluno(FILE *a){
	Aluno get;
	fseek(a, 0, SEEK_SET);
	while(fread(&get, sizeof(Aluno), 1, a)){
		if(strcmp(get.nome, "\\0")!=0)
			printf("%s %d\n", get.nome, get.matricula);
	}
}

void del_arq(FILE *a, int menu, char n[]){
	if(menu == 1){
		Aluno nv;
		printf("Digite o nome do aluno: ");
		scanf(" %s", nv.nome);
		printf("Digite o numero de matricula: ");
		scanf(" %d", &nv.matricula);
		fwrite(&nv, sizeof(Aluno), 1, a);
		printf("Registro alterado com sucesso\n\n");
	}
	else if(menu == 2){
		Aluno end;
		char ss[50];
		end.nome[0] = '\\';
		end.nome[1] = '0';
		end.matricula = 0;
		fwrite(&end, sizeof(Aluno), 1, a);
		printf("Registro excluido\n\n");
	}
}

void edit_arq(FILE *a, char n[]){
	char busca[50];
	printf("Digite o nome de busca: ");
	scanf(" %s", busca);
	int flag = 0;
	Aluno get;
	fseek(a, 0, SEEK_SET);
	int cont=0;
	while(fread(&get, sizeof(Aluno), 1, a)){
		if(strcmp(busca, get.nome)==0){
			printf("Cadastro encontrado: %s\nO que deseja fazer? 1-Editar/2-Excluir\n", get.nome);
			fseek(a, cont*sizeof(Aluno), SEEK_SET);
			int menu;
			scanf(" %d", &menu);
			del_arq(a, menu, n);			
			flag = 0;
			break;
		}
		else flag = 1;
		cont++;
	}
	if(flag == 1)
		printf("Nao encontrado\n");
}

int main(){
	int menu = -1;
	char  nome_arquivo[50];
	
	printf("Digite o nome do arquivo a ser lido: ");
	scanf(" %[^\n]s", nome_arquivo);
	FILE *arquivo = fopen(nome_arquivo,"rb+");
	if(!arquivo){
		arquivo = fopen(nome_arquivo, "wb+");
		printf("Arquivo criado\n");
	}
	else printf("Arquivo aberto.\n");
	
	while(menu != 0){
		printf("1-Cadatrar\n2-Listar\n3-Buscar\n0-SAIR\nDigite o que deseja fazer: ");
		scanf(" %d", &menu);
		
		switch(menu){
			case 1:
				setAluno(arquivo);
				break;
			case 2:
				getAluno(arquivo);
				break;
			case 3:
				edit_arq(arquivo, nome_arquivo);
				break;
		}
	}
	fseek(arquivo, 0, SEEK_SET);
	Aluno get;
	int cont1 = 0, cont2 = 0;
	while(fread(&get, sizeof(Aluno), 1, arquivo)){
		cont1++;
		if(strcmp(get.nome, "\\0")==0)
			cont2++;
	}
	
	fseek(arquivo, 0, SEEK_SET);
	Aluno lista[cont1 - cont2];
	int c = 0;
	for(int i=0; i<cont1; i++){
		if(fread(&get, sizeof(Aluno), 1, arquivo) && strcmp(get.nome, "\\0")!=0){
			lista[c] = get;
			c++;
		}
	}
	
	fclose(arquivo);
	
	arquivo = fopen(nome_arquivo, "wb+");
	for(int i=0; i<(cont1-cont2); i++)
		fwrite(&lista[i], sizeof(Aluno), 1, arquivo);

	fclose(arquivo);
	
}

