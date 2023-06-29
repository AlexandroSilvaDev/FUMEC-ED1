/*
 ============================================================================
 Name        : Ponteiros_e_AlocacaoDinamica_Pratico.c
 Author      : Alexandro Silva, Lucas Bomformagio, Teófilo Andrade, Thiago Luiz e Raian Leite
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numFuncionarios,
		numPecas,
		somaPecas = 0;
	float soma = 0,
		  maiorSalario = 0;
	char validar;

	do {
		printf("Quantos funcionários trabalham na empresa: ");
		scanf("%d", &numFuncionarios);

		if ( numFuncionarios <= 0 )
		{
			printf("\nO número de funcionários deve ser positivo, digite novamente!");
		}
	} while ( numFuncionarios <= 0 );

	float *salario = ( float* ) malloc( sizeof(float) * numFuncionarios );

	int *pecas = ( int* ) malloc( sizeof(int) * numFuncionarios );

	for ( int i = 0; i < numFuncionarios; i++ )
	{
		do {
			printf("\nDigite a quantidade de peças produzidas pelo %dº funcionário: ", i + 1);
			scanf("%d", pecas + i);

			if ( *(pecas + i) < 0 )
			{
				printf("\nO número de peças (o salário) deve ser positivo, digite novamente!");
			}
		} while ( *(pecas + i) < 0 );


		if ( *(pecas + i) >= 1 && *(pecas + i) <= 200 )
		{
			*(salario + i) = (*(pecas + i)) * 2;
		}
		else if ( *(pecas + i) >= 201 && *(pecas + i) <= 400 )
		{
			*(salario + i) = (*(pecas + i)) * 2.3;
		}
		else {
			*(salario + i) = (*(pecas + i)) * 2.5;
		}

		do {
			printf("\nO %dº funcionário é estudante (S/N)? ", i + 1);
			scanf(" %c", &validar);

			if ( validar != 'S' && validar != 'N' )
			{
				printf("\nResponda com S para sim ou N para não!");
			}
		} while ( validar != 'S' && validar != 'N' );

		if ( validar == 'S' )
		{
			*(salario + i) = *(salario + i) + ( *(salario + i) * 0.1 );
		}

		if ( maiorSalario < *(salario + i) )
		{
			maiorSalario = *(salario + i);
			numPecas = *(pecas + i);
		}

		soma += *( salario + i );
		somaPecas += *( pecas + i );
	}

	for ( int i = 0; i < numFuncionarios; i++ )
	{
		printf("\nSalário do %dº funcionário é %.2f - O número de peças produzidas "
				"por este funcionário é %d", i + 1, *(salario + i), *(pecas + i));
	}

	printf("\nA soma dos salários é %.2f", soma);
	printf("\nO maior salário é %.2f - %d peças produzidas", maiorSalario, numPecas);
	printf("\n%d peças foram produzidas ao todo neste mês.", somaPecas);

	free(salario);
	free(pecas);

	return 0;
}
