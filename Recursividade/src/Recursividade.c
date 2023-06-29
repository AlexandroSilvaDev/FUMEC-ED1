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

// Protótipo

int fatorialIterativo( int x );
int fatorialRecursiva( int x );

int main(void) {

	setbuf(stdout, NULL);

	//printf("\n5! = %d", fatorialIterativo(5));
	printf("\n5! = %d", fatorialRecursiva(5));

	return EXIT_SUCCESS;
}

int fatorialIterativo( int x )
{
	int fatorial = 1;

	while ( x > 1 )
	{
		fatorial *= x;
		x--;
	}
	return fatorial;
}

int fatorialRecursiva( int x )
{
	if ( x > 1 ) // Caso recursivo
	{
		return x * fatorialRecursiva(x - 1);
	}
	else // Caso base
	{
		return 1;
	}
}
