/*
 * funcoes.c
 *
 *  Created on: 19 de out. de 2022
 *      Author: 13A226889818
 */

#include "biblioteca.h"
#include <stdio.h>

void imprimir( Dados *cliente )
{
	printf("\n%s", cliente->nome);
	printf("\n%s", cliente->end.rua);
	printf("\n%d", cliente->end.numero);
}

int somar( int a, int b )
{
	//printf("\n%d", a + b);
	return a + b;
}

