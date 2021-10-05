#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int n;
	
	scanf(" %d",&n);
	
	int v[n],v2[n];
	
	for(int i=0; i<n; i++)
	{
		v[i] = rand()%100;
		printf("%d ",v[i]);
	}
	
	printf(" \n\n ");
	
	int cont=0, cont2=0,a=0;
	
	for(int i=1; i<n; i++)
		if(v[i] >= v[i-1])
		{
			cont++;
			if(cont > cont2)
			{
				cont2 = cont;
				a=i;
			}
		}
		else cont = 0;
		
	//printf(" %d \n\n", cont2+1);
		
	a = a-(cont2);
		
	//printf(" %d \n\n", a);
	
	for(int i=a; i<=cont2+a; i++)
		printf(" %d", v[i]);
}
