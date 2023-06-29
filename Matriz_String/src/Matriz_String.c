/*
 ============================================================================
 Name        : Matriz_String.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	printf("\n O gasto de memoria de um int é: %li", sizeof(int));

	// vetor

	//int vetor[3];    Dimensionando
	int vetor[] = {34, 96, 15};
	vetor[0] = 196;

	for ( int i = 0; i < 3; i++ )
	{
		vetor[i] = i * 10;
		printf("\nPosição %d: ", i+1);
		scanf("%i", &vetor[i]);
		printf("\nValor digitado: %i - %p", vetor[i], &vetor[i]);
	}

	// Matriz



	// String

	char letra = 'A';
	printf("\n%d - %c", letra, letra);

	char string[10];
	return 0;
}
