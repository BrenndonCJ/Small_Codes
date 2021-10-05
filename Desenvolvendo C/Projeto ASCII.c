#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <string.h>
#include <ctype.h>
#include <windows.h>

void mgotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

int main()
{
	char str[100] = {0};
	int strpc[100] = {0};
	int pos=0;
	int intec, cont=0;
	
	/*fgets(str, 100, stdin); fgets = Le string com espaços
	printf("%s", str);*/
	
	char tecla='1';
	int x=1,y=0,x2=1;
	mgotoxy(x,2);
	while(tecla != 13)
	{
		
		tecla = getch();
		
		if(tecla == 13)
		{
			mgotoxy(x2,4);
			printf(" %d", tecla);
			printf("	");
		}
		if(isprint(tecla))
		{
			mgotoxy(x++,2);
			str[pos++] = tecla;
			printf("*");
			/*intec = tecla;
			while(intec != 0)
			{
				cont++;
				intec = intec / 10;				
			}*/
			mgotoxy(x2,4);
			/*x2 += cont;
			cont = 0;*/
			printf(" %d", tecla);
			printf("%s" , " ");
		}
		else if( tecla == 8 && pos )
        {
        	mgotoxy(x--,2);
            str[ pos-- ] = '\0';
            printf("%s", "\b \b");
			mgotoxy(x2,4);
			//x2++;
			printf("%d", tecla);
			printf("%s" , "	");
        }
	}
	
	mgotoxy(1,6);
	for(int i=0; i<pos; i++)
		printf("%d ",str[i]);
	
	printf("\n\n");
	printf("=============================================================================================\n\n");
	printf(" 69 32 118 101 114 100 97 100 101 32 101 115 115 101 32 98 105 108 101 116 101 33");	
	
	x=1;
	x2=1;
	for(int i=0; i<22; i++)
	{
		mgotoxy(x++,11);
		scanf(" %d", &strpc[i]);
		intec = strpc[i];
		while(intec != 0)
			{
				cont++;
				intec /= 10;				
			}
		mgotoxy(x2++,13);
		printf("%c", strpc[i]);
		x += cont;
		cont = 0;
	}
	
	/*mgotoxy(1,13);
	for(int i=0; i<22; i++) printf("%c",strpc[i]);*/
	
	printf("\n\n");
	
	getch();
}
