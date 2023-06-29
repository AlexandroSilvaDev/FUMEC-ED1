/*
 ============================================================================
 Name        : Funcoes.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipo

void menu();
void receberValorInteiro( int *valor );
float receberValorReal();
float calcularNovoSalario( float salario );
float mediaSalarios( float *salario, int tamanhoVetor );
void minhaStrncpy( char destino[30], char origem[30], int quantidade );

// Funções

int main(void) {

	setbuf(stdout, NULL);

	menu();

	return 0;
}

void menu() {

	char opcao,
		 stringDestino[50],
		 stringOrigem[50];
	int numero,
		quantidade;
	float media = 0,
		  *salarioAtual;

	do {
		printf("\nMenu:\nA - Calcular novo salario\nB - Minha strncpy\nC - Finalizar\n");
		scanf(" %c", &opcao);

		opcao = toupper(opcao);

		switch ( opcao )
		{
			case 'A':

				receberValorInteiro( &numero );
				salarioAtual = ( float* ) malloc( sizeof(float) * numero );

				media = mediaSalarios( salarioAtual, numero );

				printf("\nA média dos novos salários é: %.2f\n", media);
				break;

			case 'B':

				receberValorInteiro( &quantidade );

				printf("\nDigite uma String: \n");
				//fgets(stringOrigem, quantidade, stdin);
				scanf("%s", stringOrigem);
				//fflush(stdin);

				minhaStrncpy(stringDestino, stringOrigem, quantidade);
				break;

			case 'C':

				printf("\nPrograma finalizado!");
				break;

			default:
				printf("\nOpção inválida!");
		}
	} while ( opcao != 'C' );

	free(salarioAtual);
}

void receberValorInteiro( int *valor ) {

	do {
		printf("\nDigite um número inteiro positivo: ");
		scanf("%d", valor);

		if ( *valor < 1 || *valor > 50 )
		{
			printf("\nDigite um número válido!\n");
		}
	} while ( *valor < 1 || *valor > 50 );
}

float receberValorReal() {

	float salario;

	do {
		printf("\nDigite o salário do funcionário: ");
		scanf("%f", &salario);

		if ( salario <= 0 )
		{
			printf("\nDigite um salário válido!\n");
		}

	} while ( salario <= 0 );

	return salario;
}

float calcularNovoSalario( float salario ) {

	if ( salario <= 2500 )
	{
		salario *= 1.15;
	}
	else if ( salario <= 7000 )
	{
		salario *= 1.075;
	}

	return salario;
}

float mediaSalarios( float *salario, int tamanhoVetor ) {

	float soma = 0;

	for ( int i = 0 ; i < tamanhoVetor ; i++ )
	{
		*salario = receberValorReal();
		*salario = calcularNovoSalario( *salario );
		soma += *salario;
		salario++;
	}
	salario -= tamanhoVetor;

	return soma / tamanhoVetor;
}

void minhaStrncpy( char destino[50], char origem[50], int quantidade ) {

	for ( int i = 0 ; i < quantidade ; i++ )
	{
		destino[i] = origem[i];
	}
	//printf("\nA string Destino agora é: %s\n", destino);
}
