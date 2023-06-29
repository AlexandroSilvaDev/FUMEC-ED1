/*
 ============================================================================
 Name        : Exercitar.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	// Exercitar - 1

	setbuf(stdout, NULL);

	char string[50], string2[50];

	printf("\nDigite uma string: ");
	fgets(string, 50, stdin);

	// Exercitar - 2

	string[strlen(string) - 1] = '\0';

	printf("\nDigite outra string: ");
	fgets(string2, 50, stdin);
	string2[strlen(string2) - 1] = '\0';

	// Exercitar - 3
	/*
	strcpy(string, "Alexandro"); // copia em string o conteudo da string "Alexandro".
	strncpy(string2, "Alexandro", 3); // copia na string2 a string "Alexandro", porém só os 3 caracteres, mantendo o restante.
	*/
	printf("\nA 1° string é %s e a 2° é %s.", string, string2);
	printf("\n%d  -  %d", strlen(string), strlen(string2));

	// Exercitar - 4

	strcat(string2, string);
	printf("\nA 1° string é %s e a 2° é %s.", string, string2);

	if ( strcmp(string, string2) == 1 )
	{
		printf("\n%s  -  %s", string2, string);
	}
	else {
		printf("\n%s  -  %s", string, string2);
	}

	return 0;
}
