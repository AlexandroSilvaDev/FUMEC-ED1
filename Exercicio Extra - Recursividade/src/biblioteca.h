/*
 * biblioteca.h
 *
 *  Created on: 9 de nov. de 2022
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// biblioteca

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototipo

// questao 1

int multiplicacaoIterativa( int x, int y );
int multiplicacaoRecursiva( int x, int y );
int multiplicacaoRecursivaCauda( int x, int y, int resultado );

// questao 2

void multiploIterativa( int n, int q );
void multiploRecursiva( int n, int q );
void multiploRecursivaCauda( int n, int q, int i );

// questao 3

double serieIterativa( int quantidade );
double serieRecursiva( int a, int b, int expoente, int quantidade );
//float serieRecursiva( int n );
double serieRecursivaCauda( int a, int b, int expoente, int quantidade, double resultado );

// questao 4

int somaIterativa( int *vetor, int tamanho );
int somaRecursiva( int *vetor, int tamanho );
int somaRecursivaCauda( int *vetor, int tamanho, int resultado );

// questao 5

void binarioIterativo( int decimal );
void binarioRecursivo( int decimal );
void binarioRecursivoCauda( int decimal );

#endif /* BIBLIOTECA_H_ */
