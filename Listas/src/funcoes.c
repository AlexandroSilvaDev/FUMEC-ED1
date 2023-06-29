/*
 * funcoes.c
 *
 *  Created on: 16 de nov. de 2022
 *      Author: 13A226889818
 */

#include "biblioteca.h"

void menu()
{
	char opcao;
	dadosSimples *listaSimples = NULL,
				 *ultimoLista = NULL;
	int cod;

	do {
		printf("\n---- MENU ----\n"
			   "\nA - Inserir inicio"
			   "\nB - Inserir fim"
			   "\nC - Impressao"
			   "\nD - Remover"
			   "\nE - Finalizar"
			   "\nDigite sua opcao: ");
		scanf(" %c", &opcao);
		opcao = toupper(opcao);

		switch ( opcao )
		{
			case 'A':

				listaSimples = inserirInicio(listaSimples);
				printf("\nRigistro inserido com sucesso.");
				break;

			case 'B':

				//listaSimples = inserirFinal(listaSimples);
				inserirFimUltimo(&listaSimples);

				if ( ! listaSimples )
				{
					listaSimples = ultimoLista;
				}
				printf("\nRigistro inserido com sucesso.");
				break;

			case 'C':

				impressao(listaSimples);
				break;

			case 'D':
				printf("\nDigite o codigo a ser removido: ");
				scanf("%d", &cod);
				listaSimples = remover(listaSimples, cod);
				break;

			case 'E':

				printf("\nPrograma finalizado!");
				break;

			default:

				printf("\nOpcao digitada invalida!");
		}
	} while ( opcao != 'E' );
}

dadosSimples* inserirInicio( dadosSimples *inicio )
{
	//Alocar dinamicamente o elemento novo.

	dadosSimples *novo = ( dadosSimples* ) malloc( sizeof(dadosSimples) );

	//Preencher dados básicos.

	novo->codigo = RANDOM(100);

	//Fazer o novo elemento apontar para o inicio da lista.

	novo->proximo = inicio;

	//Atualizar a lista fora da funcao.

	return novo;
}

dadosSimples* inserirFinal( dadosSimples *inicio )
{
	//Alocar dinamicamente o elemento novo.

	dadosSimples *novo = ( dadosSimples* ) malloc( sizeof(dadosSimples) );

	//Preencher dados básicos.

	novo->codigo = RANDOM(100);

	//Garantir que depois dele nao vem ninguem

	novo->proximo = NULL;

	// Lista vazia o novo é o primeiro

	if ( ! inicio )
	{
		return novo;
	}

	// Nao eh o primeiro

	else
	{
		dadosSimples *aux = inicio;

		while ( aux->proximo )
		{
			aux = aux->proximo;
		}
		aux->proximo = novo;

		return inicio;
	}
}

void inserirFimUltimo( dadosSimples **ultimo )
{
	//Alocar dinamicamente o elemento novo.

	dadosSimples *novo = ( dadosSimples* ) malloc( sizeof(dadosSimples) );

	//Preencher dados básicos.

	novo->codigo = RANDOM(100);

	//Garantir que depois dele nao vem ninguem

	novo->proximo = NULL;

	// Se houver ultimo atual, altera-o para ser o penultimo

	if ( *ultimo )
	{
		(*ultimo)->proximo = novo;
	}

	// Atualizar o ultimo

	(*ultimo) = novo;
}

void impressao( dadosSimples *lista )
{
	if ( lista )
	{
		printf("\nEndereço %p - Codigo %d - Proximo %p",
				lista, lista->codigo, lista->proximo);
		impressao(lista->proximo);
	}
}

dadosSimples* remover( dadosSimples *lista, int cod )
{
	dadosSimples *aux = lista,
			     *anterior = NULL;

	// Enquanto houver registro valido

	while ( aux )
	{
		// encontrei

		if ( aux->codigo == cod )
		{
			// Eh o primeiro registro

			if ( !anterior )
			{
				lista = lista->proximo;
			}

			// nao eh o primeiro

			else
			{
				anterior->proximo = aux->proximo;
			}
			free(aux);
			return lista;
		}

		// nao encontrei

		else
		{
			anterior = aux;
			aux = aux->proximo;
		}
	}
	printf("\nRegistro nao encontrado.");
	return lista;
}
