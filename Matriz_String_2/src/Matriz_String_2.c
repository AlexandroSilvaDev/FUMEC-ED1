/*
 ============================================================================
 Name        : Matriz_String_2.c
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
	char letra = 'A';

	char string[10] = "Amanda";

	printf("\nDigite uma string: ");
	//gets(string);
	//fgets(string, 10, stdin);
	//scanf("%s", string); // sem o & por ser vetor. Só pega string sem espaço no meio.
	scanf("%[^\n]", string); // Pega a string com espaço também

	printf("\nConteúdo digitado: %s finalizado.", string);

	return 0;
}
