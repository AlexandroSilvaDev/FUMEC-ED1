/*
 * biblioteca.h
 *
 *  Created on: 20 de out. de 2022
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Constante



// Macro

#define RANDOM rand() % 50

// typedef

// questao 2

typedef struct produto Produto;

// Estrutura

struct produto
{
	char descricao[40];
	int codigo;
	double preco;
	int quantidade;
};

// Prototipo

void menu();
int totalProdutos();
void cadastroProdutos( Produto *produto, int numProdutos );
void cadastrarNome( char *nome );
void cadastrarPreco( double *preco );
void cadastrarQuantidade( Produto *listaProduto );
void exibirProdutosFaltando( Produto *produto, int numProdutos );
void exibirEstoqueCompleto( Produto *produto, int numProdutos, double *media );

#endif /* BIBLIOTECA_H_ */
