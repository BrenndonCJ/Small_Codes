#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void mgotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x, y});
}

int main()
{
	srand(time(NULL));
	
	int v[20];
	int  busca;
	
	for(int i=0; i<20; i++)
		v[i] = rand()%51;
	for(int i=0; i<20; i++)
		printf("%d ", v[i]);
	
	mgotoxy(0,3);
	
	int aux;
	for(int i=1; i <= 20; i++)
	{
		aux=v[i];
		for(int a=i-1; a >= 0; a--)
		{
			if(v[a] > aux)
			{
				Sleep(100);
				v[a+1]=v[a];
				v[a]=aux;
				mgotoxy(0,3);
				for(int p=0; p<20; p++)
					printf("%d ", v[p]);
				
			}
		}
	}
	//for( i=0; i<20; i++)	printf("%d ", v[i]);
	int inicial= 0, final= 19, meio, encont = 0;
	mgotoxy(0,5);
	
	scanf(" %d", &busca);	
	while((inicial <= final) && (encont == 0))
	{
		meio = (inicial + final) / 2;
		if(busca == v[meio])
			encont= 1;

		if(busca < v[meio])
			final = meio-1;
		else inicial = meio+1;
	}
	if(encont == 1)
		printf("\n\nValor encontrado %d no indice %d", v[meio] , meio+1);
	else printf("O valor nao se encontra nesse vetor");
		
}
