/*
 ============================================================================
 Name        : Exer�cio.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca.h"

/*
	Dentro do main, os metodos comentados sao os que nao estao funcionando 100%, mas pode testar para tirar a duvida.
 */

int main(void) {

	setbuf(stdout, NULL);

	int x,
		y,
		quantidade,
		resultado = 0,
		inteiro = 1,
		decimal;
	double a = 1,
		   b = 10,
		   expoente = 0;

	// questao 1

	printf("Digite um número inteiro positivo: ");
	scanf("%d", &x);

	printf("\nDigite outro número inteiro positivo: ");
	scanf("%d", &y);

	printf("\n%d * %d = %d", x, y, multiplicacaoIterativa(x, y));
	printf("\n---------------\n");
	printf("\n%d * %d = %d", x, y, multiplicacaoRecursiva(x, y));
	printf("\n---------------\n");
	printf("\n%d * %d = %d", x, y, multiplicacaoRecursivaCauda(x, y, resultado));
	printf("\n---------------\n");

	// questao 2

	printf("\nOs %d primeiros múltiplos de %d são:\n", y, x);
	multiploIterativa(x, y);
	printf("\n---------------\n");
	multiploRecursiva(x, y);
	printf("\n---------------\n");
	multiploRecursivaCauda(x, y, inteiro);
	printf("\n---------------\n");

	// questao 3

	printf("\nDigite a quantidade de termos para calcular a série: ");
	scanf("%d", &quantidade);

	printf("\nO resultado da série de %d termos é: %.2lf", quantidade, serieIterativa(quantidade));
	printf("\n---------------\n");
	printf("\nO resultado da série de %d termos é: %.2lf", quantidade, serieRecursiva(a, b, expoente, quantidade));
	printf("\n---------------\n");
	printf("\nO resultado da série de %d termos é: %.2lf", quantidade, serieRecursivaCauda(a, b, expoente, quantidade, resultado ));
	printf("\n---------------\n");

	// questao 4

	int *vetorInteiros = ( int* ) malloc( sizeof(int) * quantidade );

	for ( int i = 0 ; i < quantidade ; i++ )
	{
		vetorInteiros[i] = rand() % 100;
		inteiro++;
		printf("\n%d", vetorInteiros[i]);
	}
	//vetorInteiros -= 10; não precisa pois percorri o vetor utilizando indexação.
	printf("\nA soma dos inteiros do vetor é: %d", somaIterativa(vetorInteiros, quantidade));
	printf("\n---------------\n");
	printf("\nA soma dos inteiros do vetor é: %d", somaRecursiva(vetorInteiros, quantidade));
	printf("\n---------------\n");
	printf("\nA soma dos inteiros do vetor é: %d", somaRecursivaCauda(vetorInteiros, quantidade, resultado));
	printf("\n---------------\n");

	// questao 5

	printf("\nDigite um número de base decimal: ");
	scanf("%d", &decimal);

	//binarioIterativo(decimal);
	binarioRecursivo(decimal);
	//binarioRecursivoCauda(decimal);

	return EXIT_SUCCESS;
}
