/*
 * biblioteca.h
 *
 *  Created on: 23 de nov. de 2022
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Macro

#define RANDOM(x) rand() % (x)

// typedef

typedef struct dados dadosDupla;

// Estruturas

struct dados
{
	int codigo;
	dadosDupla *anterior;
	dadosDupla *proximo;
};

// Prototipos

void menu();
dadosDupla* inserirInicio( dadosDupla *inicio );
dadosDupla* inserirFinal( dadosDupla *inicio );
void impressao( dadosDupla *lista );
dadosDupla* remover( dadosDupla *lista, int cod );
int receberCodigo(char *frase);

#endif /* BIBLIOTECA_H_ */
