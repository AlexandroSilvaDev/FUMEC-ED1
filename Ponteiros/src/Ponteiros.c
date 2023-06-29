/*
 ============================================================================
 Name        : Ponteiros.c
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

	int idade = 25;
	int *pontIdade = &idade;

	printf ("\nDigite a idade: ");
	scanf("%d", pontIdade);

	printf("\nVáriavel idade (forma direta) tem o endereço %p - conteúdo %d", &idade, idade);
	printf("\nVáriavel idade (forma indireta) tem o endereço %p - conteúdo %d", pontIdade, *pontIdade);
	printf("\nVáriavel *pontIdade tem o endereço %p - conteúdo %p", &pontIdade, pontIdade);

	/*
	int *pontIdade = &idade;
	printf("%p", pontIdade);
	*/

	return 0;
}
