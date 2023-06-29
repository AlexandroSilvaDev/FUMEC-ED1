/*
 * biblioteca.h
 *
 *  Created on: 16 de nov. de 2022
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// biblioteca

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Macro

#define RANDOM(x) rand() % (x)

// typedef

typedef struct dados dadosSimples;

// estrutura

struct dados
{
	int codigo;
	dadosSimples *proximo;
};

// Prototipo

void menu();
dadosSimples* inserirInicio( dadosSimples *inicio );
dadosSimples* inserirFinal( dadosSimples *inicio );
void inserirFimUltimo( dadosSimples **ultimo );
void impressao( dadosSimples *lista );
dadosSimples* remover( dadosSimples *lista, int cod );

#endif /* BIBLIOTECA_H_ */
