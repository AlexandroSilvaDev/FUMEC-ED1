/*
 ============================================================================
 Name        : Estudo Prova 1.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipos

void minhaStrcat( char *destino, char *origem );
int retornarValorInteiro( char *frase );
char retornarConceito( int numero );
void armazenarStatus( int *vet1, char *vet2, int numero );
float funca05( int *vetorInt, char *vetorChar, int tamanho );
void menu();

int main(void) {

	setbuf(stdout, NULL);

	menu();

	return 0;
}

// questão 1

void minhaStrcat( char destino[50], char origem[50] )
{
	int i,
	    x,
		j = 0,
		cont = 0;
	char concatenacao[50];

	// strlen()

	for ( i = 0 ; destino[i] != '\0' ; i++ )
	{
		cont++;
	}

	// strcat()

	for ( x = 0 ; x < cont ; x++ )
	{
		concatenacao[x] = destino[x];
	}

	for (  ; x < 50 ; x++ )
	{
		concatenacao[x] = origem[j];
		j++;
	}

	destino = concatenacao;

	printf("A string destino agora é: %s\n", destino);
}

// questão 2

int retornarValorInteiro( char *frase )
{
	int valor;

	do {
		printf("\n%s:", frase);
		scanf("%d", &valor);

		if ( valor < 1 || valor > 100 )
		{
			printf("\nDigite um número válido!");
		}
	} while ( valor < 1 || valor > 100 );

	return valor;
}

// questão 3

char retornarConceito( int numero )
{
	char conceito;

	if ( numero < 20 )
	{
		conceito = 'R';
		printf("\nReprovado!");
	}
	else if ( numero < 60 )
	{
		conceito = 'E';
		printf("\nProva Especial!");
	}
	else
	{
		conceito = 'A';
		printf("\nAprovado!");
	}

	return conceito;
}

// questão 4

void armazenarStatus( int *vet1, char *vet2, int numero )
{
	for ( int i = 0 ; i < numero ; i++ )
	{
		*vet1 = retornarValorInteiro("Digite a nota");
		*vet2 = retornarConceito(*vet1);

		printf("\nA nota é %d e o conceito é %c!\n", *vet1, *vet2);

		vet1++;
		vet2++;
	}
	/*
	funca05(vet1, vet2, numero);

	vet1 -= numero;
	vet2 -= numero;
	*/
}

// questão 5

float funca05( int *vetorInt, char *vetorChar, int tamanho )
{
	float soma = 0,
		  menorNota = 0;

	armazenarStatus(vetorInt, vetorChar, tamanho);

	printf("\n---- CONTEÚDO DOS VETORES ----\n");

	for ( int i = 0 ; i < tamanho ; i++ )
	{
		printf("| %d | %c |\n", *vetorInt, *vetorChar);

		soma += *vetorInt;
		vetorInt++;
		vetorChar++;

		if ( menorNota < *vetorInt )
		{
			menorNota = *vetorInt;
		}
	}
	printf("--------------------------------\n");

	return soma / tamanho;
}

// questão 6

void menu()
{
	char opcao,
	     destino[50],
		 origem[50],
		 *conceito;
	int *nota,
		tamanho;
	float media = 0;

	do {
		printf("\nMenu:\nA - Minha strcat"
				"\nB - Calcular média das notas dos alunos"
				"\nC - Finalizar programa\n");
		scanf(" %c", &opcao);

			opcao = toupper(opcao);

		switch (opcao)
		{
			case 'A':

				printf("Digite a string de destino: ");
				scanf("%s", destino);

				printf("Digite a string de origem: ");
				scanf("%s", origem);

				minhaStrcat( destino, origem );
				break;

			case 'B':

				tamanho = retornarValorInteiro("Digite o tamanho dos vetores");

				nota = ( int* ) malloc( sizeof(int) * tamanho );

				conceito = ( char* ) malloc( sizeof(char) * tamanho );

				media = funca05(nota, conceito, tamanho);

				printf("\nA média das notas é: %.2f\n", media);
				break;

			case 'C':

				printf("\nPrograma finalizado!");
				break;

			default:

				printf("\nOpção inválida!");
		}
	} while ( opcao != 'C' );

}

