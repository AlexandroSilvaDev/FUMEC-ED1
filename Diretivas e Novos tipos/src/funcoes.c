/*
 * funcoes.c
 *
 *  Created on: 20 de out. de 2022
 *      Author: xande
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"

// questao 1

void menu()
{
	char opcao;
	Produto *produto = NULL;
	int numProdutos;
	double media = 0;

	do {
		printf("\n---------------- MENU ----------------\n"
			   "A - Criar estrutura para preenchimento\n"
			   "B - Preencher dados\n"
			   "C - Exibir produtos com estoque zerado\n"
			   "D - Exibir produtos cadastrados\n"
			   "E - finalizar\n");
		scanf(" %c", &opcao);
		opcao = toupper(opcao);

		switch (opcao)
		{
			case 'A':

				if ( produto )
				{
					free( produto );
				}
				numProdutos = totalProdutos();
				produto = ( Produto* ) malloc( sizeof(Produto) * numProdutos );
				break;

			case 'B':

				if ( produto )
				{
					cadastroProdutos(produto, numProdutos);
				}
				break;

			case 'C':

				exibirProdutosFaltando(produto, numProdutos);
				break;

			case 'D':

				exibirEstoqueCompleto(produto, numProdutos, &media);
				printf("\nMédia: %lf", media);
				break;

			case 'E':

				printf("\nPrograma finalizado com sucesso!");
				break;

			default:

				printf("\nOpção escolhida inválida!");
		}
	} while ( opcao != 'E' );

}

// questao 3

int totalProdutos()
{
	int numero;

	do {
		printf("\nDigite o número total de produtos: ");
		scanf("%d", &numero);

		if ( numero <= 0 )
		{
			printf("\nNúmero inválido, o número deve ser positivo!\n");
		}
	} while ( numero <= 0 );

	return numero;
}

// questao 4

void cadastroProdutos( Produto *produto, int numProdutos )
{
	for ( int i = 0 ; i < numProdutos ; i++ )
	{
		cadastrarNome( produto->descricao );
		produto->codigo = RANDOM;
		cadastrarPreco( &produto->preco );
		cadastrarQuantidade( produto );
		produto++;
		printf("\n");
	}
	printf("\nCadastro efetuado com sucesso!");
}

void cadastrarNome( char *nome )
{
	do {
		printf("\nDigite o nome: ");
		scanf(" %[^\n]", nome);

		if ( strlen(nome) == 0 )
		{
			printf("\nÉ obrigatório informar o nome!\n");
		}
	} while ( strlen(nome) == 0 );
}

void cadastrarPreco( double *preco )
{
	do {
		printf("\nDigite o preço: ");
		scanf("%lf", preco);

		if ( *preco < 0 )
		{
			printf("\nO preço deve ser positivo!\n");
		}
	} while ( *preco < 0 );
}

void cadastrarQuantidade( Produto *listaProduto )
{
	do {
		printf("\nDigite a quantidade do produto %s: ", listaProduto->descricao);
		scanf("%d", &listaProduto->quantidade);

		if ( listaProduto->quantidade < 0 )
		{
			printf("\nA quantidade deve ser positiva!\n");
		}
	} while ( listaProduto->quantidade < 0 );
}

// questao 5

void exibirProdutosFaltando( Produto *produto, int numProdutos )
{
	for ( int i = 0 ; i < numProdutos ; i++ )
	{
		if ( produto->quantidade == 0 )
		{
			printf("\nNome: %s", produto->descricao);
			printf("\nCódigo: %d", produto->codigo);
			printf("\nPreço: %lf", produto->preco);
			printf("\nQuantidade: %d\n", produto->quantidade);
		}
		produto++;
	}
}

// questao 6

void exibirEstoqueCompleto( Produto *produto, int numProdutos, double *media )
{
	double soma = 0;

	for ( int i = 0 ; i < numProdutos ; i++ )
	{
		printf("\nNome: %s", produto[i].descricao);
		printf("\nCódigo: %d", produto[i].codigo);
		printf("\nPreço: %lf", produto[i].preco);
		printf("\nQuantidade: %d\n", produto[i].quantidade);

		soma += produto[i].preco;
	}
	*media = soma / numProdutos;
}
