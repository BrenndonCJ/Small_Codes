#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

int senha()
{
	char buff[300]={0};
	char c = '1';
	int pos = 0;
	
	
	while(c != 13)
	{
		c = getch();
		if(c != 13 && c != 8 && c != 9 && c != -32 && c != 80 && c != 77 && c != 75 && c != 72)
		{
			buff[pos++] = c;
			printf("*");
		}
		else if(c == 8 && pos)
			 {
			 	buff[pos--] = '\0';
			 	printf("%s","\b \b");
			 }
	}
	
	printf("\n\n");
	for(int i=0; i<pos; i++)
		printf("%d ", buff[i]);
}
	
int main()
{	
	senha();
	
	printf("\n\nLimite function\n\n");
	
	senha();

}
