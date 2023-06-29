/*
 ============================================================================
 Name        : Recursividade.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Prototipo

void minhaStrcpyIterativa( char *destino, char *origem );
void minhaStrcpyRecursiva( char *destino, char *origem );

int main(void) {

	setbuf(stdout, NULL);

	char destino[50],
		 origem[50];

	printf("Digite uma String origem: ");
	fgets(origem, 50, stdin);

	//minhaStrcpyIterativa(destino, origem);
	minhaStrcpyRecursiva(destino, origem);
	printf("\n%s", destino);

	return 0;
}

void minhaStrcpyIterativa( char *destino, char *origem )
{
	for ( int i = 0 ; origem[i] != '\0' ; i++ )
	{
		destino[i] = origem[i];
	}
}

void minhaStrcpyRecursiva( char *destino, char *origem )
{
	if ( *origem != '\0' )
	{
		*destino = *origem;
		minhaStrcpyRecursiva(destino + 1, origem + 1);
	}
	else {
		*destino = '\0';
	}
}
