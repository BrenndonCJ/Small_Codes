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
	int m[5][5];
	int v[25],i=0;
	
	for(int l=0; l<5; l++)
		for(int c=0; c<5; c++){
			m[l][c] = 1 + (rand()%25);
			v[i++]=m[l][c];
		}
			

	for(int l=0; l<5; l++)
	{
		for(int c=0; c<5; c++)
			printf("%d\t", m[l][c]);
		printf("\n\n");
	}
	
	printf("====================================\n\n");
		
/*	for(int i=0; i<25; i++)
		printf("%d ", v[i]);
	
	printf("\n\n====================================\n\n");*/
	
	int a,cont=0;
	
	/*for(int l=0; l<5; l++)
	{
		for(int i=1; i<5; i++)
		{
			a = m[l][i];
			for(int c=i-1; c>=0; c--)
			{
				if(m[l][c] > a)
				{
					m[l][c+1] = m[l][c];
					m[l][c] = a;
				}
			}
			
		}	
	}*/
	int aux;
	for(int i=1; i<25; i++)
	{
		aux=v[i];
		for(int a=i-1; a>=0; a--)
			if(v[a] > aux)
			{
				v[a+1]=v[a];
				v[a]=aux;
			}
	}
	
		
	/*for(int i=0; i<25; i++)
		printf("%d ", v[i]);
		
	printf("\n\n====================================\n\n");*/
	
	i=0;
	for(int l=0; l<5; l++)
		for(int c=0; c<5; c++)
			m[l][c] = v[i++];

	for(int l=0; l<5; l++)
	{
		for(int c=0; c<5; c++)
			printf("%d\t", m[l][c]);
		printf("\n\n");
	}
}
