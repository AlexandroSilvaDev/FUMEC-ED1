/*
 ============================================================================
 Name        : Diretivas.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {

	setbuf(stdout, NULL);

	endereco end;

	printf("\n%d", TAM);
	printf("\n%d", MAX( 156, 96 ));
	printf("\nRandômico: %d", RANDOM);
	printf("\n%d", SQR( 3 + 4 ));

	return 0;
}
