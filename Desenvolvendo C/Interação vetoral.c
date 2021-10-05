#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int main()
{
	srand(time(NULL));
	
	int x, y, k;
		
	scanf(" %d", &k);
	int v[k];
	scanf(" %d", &x);
	scanf(" %d", &y);
	
	for(int i=0; i<k; i++)
		v[i] = x + (rand() % (y-x+1));
		
	for(int i=0; i<k; i++)
		printf("%d ", v[i]);
}
