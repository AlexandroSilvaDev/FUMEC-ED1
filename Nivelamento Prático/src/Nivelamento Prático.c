/*
 ============================================================================
 Name        : Nivelamento.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	setbuf(stdout, NULL);

	int opcao, termos, cont = 1, denominador = 0;
	float soma = 0;

	do {
		do {
			printf("Escolha apenas uma dentre as opções a seguir:\n1 - Série A\n\n2 - Série B\n\n3 - Série C\n\n4 - Série D: ");
			scanf("%d", &opcao);

			if ( opcao > 0 && opcao < 4 )
			{
				do {
					printf("\nEscolha a quantidade de termos que irá utilizar: ");
					scanf("%d", &termos);

					if ( termos <= 0 )
					{
						printf("Quantidade inválida, digite novamente!\n");
					}
				} while ( termos <= 0 );
			}
		} while ( opcao < 0 && opcao > 4 );

		switch ( opcao )
		{
			case 1:
				while ( termos >= cont )
				{
					soma += ( cont + ( cont - 1 ) ) / pow(cont, 2);

					cont++;
				}
				printf("A soma é: %.3f\n", soma);
				break;

			case 2:
				do {
					soma += pow(cont, 3) / pow(10, denominador) ;

					cont++;
					denominador++;
				} while ( termos >= cont );

				printf("A soma é: %.3f\n", soma);
				break;

			case 3:
				for ( int i = 0 ; i < cont ; i++ )
				{
					if ( cont == 1 )
					{
						soma += ( cont ) / ( 3 * ( denominador + 2 ) );
					}
					else {
						soma += ( cont + 1 ) / ( 3 * ( denominador + 2 ) );
					}
					cont++;
					denominador += 2;
				}
				printf("A soma é: %.3f\n\n", soma);
				break;

			case 4:
				printf("Finalizando o programa!\n");
				break;

			default:
				printf("\nOpção inválida, tente novamente!\n\n");
		}
	} while ( opcao != 4 );


	return 0;
}
