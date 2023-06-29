/*
 ============================================================================
 Name        : AlocacaoDinamica.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// Alocação de 1 int

	int *x;
	x = ( int* ) malloc ( sizeof(int) );
	*x = 13;

	// Alocação de vetor de characteres

	char *c;
	c = ( char* ) malloc(3);

	//

	double *y = ( double* ) malloc( sizeof(double) );

	printf("\n%p - %d", x, *x);

	return 0;
}
