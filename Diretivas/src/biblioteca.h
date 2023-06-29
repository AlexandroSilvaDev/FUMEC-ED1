/*
 * biblioteca.h
 *
 *  Created on: 19 de out. de 2022
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Constantes

#define TAM 10

// Macro

#define MAX(a, b) ( (a) > (b) ) ? (a) : (b)
#define RANDOM rand()
#define SQR(x) (x) * (x)

// typedef (apelido)

typedef struct endereco endereco;
typedef struct dados Dados;

// Estrutura

struct endereco
{
	char rua[20],
		 bairro[20];
	int numero,
		cep;
};

struct dados
{
	char nome[30],
		 genero;
	int idade;
	double valor;
	endereco end;
};

// Prototipo

void imprimir( Dados *cliente );
int somar( int a, int b );

#endif /* BIBLIOTECA_H_ */
