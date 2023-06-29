/*
 ============================================================================
 Name        : Atividade.c
 Author      : Alexandro, Thiago
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipos

void menu();
void solicitarString( char *string, char *frase );
int minhaStrcmp( char *origem, char *destino );
int solicitarNumeroInteiro( char *frase );
void preecherVetor( int *inteiros, int tamanho );
void somaNumerosVetor( int *inteiros, int tamanho );

// Main

int main(void) {

	setbuf(stdout, NULL);

	menu();

	return 0;
}

// questão 1

void menu()
{
	char opcao;
	char destino[50],
		 origem[50];
	int comparacao,
		tamanhoVetor,
		*inteiros;

	do {
		printf("\n----------Menu----------\n"
				"A - Minha strcmp\n"
				"B - Soma das posições do vetor\n"
				"C - Finalizar programa\n");
		scanf(" %c", &opcao);

		opcao = toupper(opcao);

		switch ( opcao )
		{
			case 'A':

				solicitarString(origem, "Digite a String origem");
				solicitarString(destino, "Digite a String destino");
				comparacao = minhaStrcmp(origem, destino);

				printf("\nOrigem: %s\n"
						"Destino: %s", origem, destino);
				printf("\nO resultado da comparação é: %d\n\n", comparacao);
				break;

			case 'B':

				tamanhoVetor = solicitarNumeroInteiro("Digite o tamanho do vetor que será criado");

				inteiros = ( int* ) malloc( sizeof(int) * tamanhoVetor );

				preecherVetor(inteiros, tamanhoVetor);

				printf("------ VETOR INTEIROS ------\n");

				for ( int i = 0 ; i < tamanhoVetor ; i++ )
				{
					printf("| %d ", *inteiros);
					inteiros++;
				}
				printf("|\n");
				inteiros -= tamanhoVetor;

				somaNumerosVetor(inteiros, tamanhoVetor);

				printf("\nA soma das posições do vetor é: %d\n", *inteiros);
				break;

			case 'C':

				printf("\nPrograma finalizado!");
				break;

			default:

				printf("\nOpção inválida!");
		}
	} while ( opcao != 'C' );

}

// questão 2

void solicitarString( char *string, char *frase )
{
	printf("\n%s: ", frase);
	scanf("%s", string);
}

// questão 3

int minhaStrcmp( char origem[50], char destino[50] )
{
	int contOrigem = 0,
		contDestino = 0;

	for ( int x = 0 ; destino[x] != '\0' ; x++ )
	{
		contDestino++;
	}
	for ( int x = 0 ; origem[x] != '\0' ; x++ )
	{
		contOrigem++;
	}

	if ( contOrigem < contDestino )
	{
		for ( int i = 0 ; i < contOrigem ; i++ )
			{
				if ( origem[i] < destino[i] )
				{
					return -1;
				}
				else if ( origem[i] > destino[i] )
				{
					return 1;
				}
			}
	}
	else if ( contOrigem > contDestino )
	{
		for ( int i = 0 ; i < contDestino ; i++ )
			{
				if ( origem[i] < destino[i] )
				{
					return -1;
				}
				else if ( origem[i] > destino[i] )
				{
					return 1;
				}
			}
	}
	else {
		for ( int i = 0 ; i < contOrigem ; i++ )
			{
				if ( origem[i] < destino[i] )
				{
					return -1;
				}
				else if ( origem[i] > destino[i] )
				{
					return 1;
				}
			}
	}
	return 0;
}

// questão 4

int solicitarNumeroInteiro( char *frase )
{
	int numero;

	do {
		printf("\n%s: ", frase);
		scanf("%d", &numero);

		if ( numero < 1 || numero > 2500 )
		{
			printf("\nNúmero inválido! Digite entre 1 e 2500.");
		}
	} while ( numero < 1 || numero > 2500 );

	return numero;
}

// questão 5

void preecherVetor( int *inteiros, int tamanho )
{
	for ( int i = 0 ; i < tamanho ; i++ )
	{
		*inteiros = solicitarNumeroInteiro("Digite um número inteiro entre 1 e 2500");
		inteiros++;
	}
}

//questão 6

void somaNumerosVetor( int *inteiros, int tamanho )
{
	for ( int i = 0 ; i < tamanho - 1 ; i++ )
	{
		inteiros[0] += inteiros[i + 1];
	}
}
