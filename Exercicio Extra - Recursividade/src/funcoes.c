/*
 * funcoes.c
 *
 *  Created on: 9 de nov. de 2022
 *      Author: 13A226889818
 */

#include "biblioteca.h"

// questao 1

int multiplicacaoIterativa( int x, int y )
{
	int multiplicacao = 0;

	for ( int i = 0 ; i < y ; i++ )
	{
		multiplicacao += x;
	}
	return multiplicacao;
}

int multiplicacaoRecursiva( int x, int y )
{
	if ( x > 1  && y != 0 )
	{
		return y + multiplicacaoRecursiva(x - 1, y);
	}
	else if ( x == 0 )
	{
		return x;
	}
	else
	{
		return y;
	}
}

int multiplicacaoRecursivaCauda( int x, int y, int resultado )
{
	if ( x > 1  && y != 0 )
	{
		return multiplicacaoRecursivaCauda(x - 1, y, y + resultado);
	}
	else if ( x == 0 )
	{
		return x;
	}
	else
	{
		return resultado + y;
	}
}

// questao 2

void multiploIterativa( int n, int q )
{
	int fator = 1,
		resultado = 0;

	for ( int i = 0 ; i < q ; i++ )
	{
		resultado = n * fator;
		printf("\n%dº - %d x %d = %d", i + 1, n, fator, resultado);
		fator++;
	}
}

void multiploRecursiva( int n, int q )
{
	int resultado;

	if ( q >= 1 && n != 0 )
	{
		resultado = n * q;
		multiploRecursiva(n, q - 1);
		printf("\n%dº - %d x %d = %d", q, n, q, resultado);
	}
	else if ( n == 0 )
	{
		printf("\nTodos os multiplos de 0 são iguais a 0.");
	}
	/*
	else {
		resultado = n * q;
		printf("\n%dº - %d x %d = %d", q, n, q, resultado);
	}
	*/
}

void multiploRecursivaCauda( int n, int q, int i )
{
	int resultado;

	if ( q >= i && n != 0 )
	{
		resultado = n * i;
		printf("\n%dº - %d x %d = %d", i, n, i, resultado);
		multiploRecursivaCauda(n, q, i + 1);
	}
	else if ( n == 0 )
	{
		printf("\nTodos os multiplos de 0 são iguais a 0.");
	}
}
/*
char multiploRecursivaCauda( int n, int q, char solucao[1000] )
{
	int resultado;

	if ( q >= 1 && n != 0 )
	{
		resultado = n * q;
		solucao += "\n" + q + "º - " + n + " x " + q +
				   " = " + resultado;
		return multiploRecursivaCauda(n, q - 1, solucao);
	}
	else if ( n == 0 )
	{
		solucao = "\nTodos os multiplos de 0 são iguais a 0.";
		return solucao;
	}
	return "";
}
*/

// questao 3

double serieIterativa( int quantidade )
{
	double a = 1,
		   b = 10,
		   expoente = 0,
		   numerador,
		   denominador,
		   resultado = 0;

	for ( int i = 0 ; i < quantidade ; i++ )
	{
		numerador = pow(a, 3);
		denominador = pow(b, expoente);
		resultado += numerador / denominador;
		a++;
		expoente++;
	}
	return resultado;
}


 /*
float serieRecursiva( int n )
{
	if ( n > 1 )
	{
		return pow(n, 3) / pow(10, n - 1) + serieRecursiva(n - 1);
	}
	else {
		return pow(n, 3) / pow(10, n - 1);
	}
}

float serieRecursivaCauda( int n, float resultado )
{
	if ( n > 1 )
	{
		return serieRecursiva(n - 1, pow(n, 3) / pow(10, n - 1) + resultado);
	}
	else {
		return resultado;
	}
}
  */
double serieRecursiva( int a, int b, int expoente, int quantidade )
{
	double numerador,
		   denominador;

	if ( quantidade >= 1 )
	{
		numerador = pow(a, 3);
		denominador = pow(b, expoente);
		return numerador / denominador + serieRecursiva(++a, b, ++expoente, --quantidade);
	}
	else {
		return 0;
	}
}

double serieRecursivaCauda( int a, int b, int expoente, int quantidade, double resultado )
{
	double numerador,
		   denominador;

	if ( quantidade >= 1 )
	{
		numerador = pow(a, 3);
		denominador = pow(b, expoente);
		resultado += numerador / denominador;
		return serieRecursivaCauda(++a, b, ++expoente, --quantidade, resultado);
	}
	else {
		return resultado;
	}
}

/*
	Primeiramente, achei que era um metodo apenas para exibir (inclusive eh onde
	estou tendo dificuldades ja que nao temos string), posteriormente criei os
	metodos acima para atender a retorno do resultado solicitado.
 */

/*
void serieIterativa( int a, int b, int quantidade )
{
	int expoente = 0;

	for ( int i = 0 ; i < quantidade ; i++ )
	{
		printf("\n%.0lf\n___ +\n\n%.0lf\n-----\n", pow(a, 3), pow(b, expoente));
		a++;
		expoente++;
	}
}

void serieRecursiva( int a, int b, int expoente, int quantidade )
{
	double numerador = 0,
		   denominador = 0;

	if ( quantidade >= 1 )
	{
		numerador = pow(a, 3);
		denominador = pow(b, expoente);
		serieRecursiva(++a, b, ++expoente, --quantidade);
		printf("\n%.0lf\n___ +\n\n%.0lf\n-----\n", numerador, denominador);
	}
	else {
		return;
	}
}
*/

// questao 4

int somaIterativa( int *vetor, int tamanho )
{
	int soma = 0;

	for ( int i = 0 ; i < tamanho ; i++ )
	{
		soma += vetor[i];
	}
	return soma;
}

int somaRecursiva( int *vetor, int tamanho )
{
	if ( tamanho > 1 )
	{
		return *vetor + somaRecursiva(vetor + 1, tamanho - 1);
	}
	else {
		return *vetor;
	}
}

int somaRecursivaCauda( int *vetor, int tamanho, int resultado )
{
	if ( tamanho > 1 )
		{
			return somaRecursivaCauda(++vetor, --tamanho, *vetor + resultado);
		}
		else {
			return *vetor + resultado;
		}
}

// questao 5

void binarioIterativo( int decimal )
{
	int contador = 0;

	while ( decimal != 0 )
	{
		decimal = decimal/2;
		contador++;
	}
}

void binarioRecursivo( int decimal )
{
	if ( decimal == 0 )
	{
		printf("\n%d", decimal);
	}
	else {
		binarioRecursivo(decimal/2);
		printf("%d", decimal % 2);
	}
}

void binarioRecursivoCauda( int decimal )
{
	if ( decimal == 0 )
	{
		printf("\n%d", decimal);
	}
	else {
		printf("%d", decimal % 2);
		binarioRecursivo(decimal/2);
	}
}

