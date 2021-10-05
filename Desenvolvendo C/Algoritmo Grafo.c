#include <stdio.h>
#include <stdlib.h>

int main()
{
	int grafo[5][5]={{0,1,0,0,0}, {1,1,1,0,1}, {0,0,0,1,0}, {0,1,1,0,0}, {0,0,0,1,0}};
	
	for(int i=0; i<5; i++)
	{
		for(int i2=0; i2<5; i2++)
		{
				printf("%d ",grafo[i][i2]);
		}
		
				printf("\n");
	}
	
	printf("\n\n");
	
	for(int i=0; i<5; i++)
	{
		for(int i2=0; i2<5; i2++)
		{
			if(grafo[i][i2] == 1)
				printf(" Aresta = %d-%d\n", i+1,i2+1);
		}
	}

}
