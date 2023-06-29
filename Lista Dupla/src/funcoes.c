/*
 * funcoes.c
 *
 *  Created on: 23 de nov. de 2022
 *      Author: 13A226889818
 */

#include "biblioteca.h"

void menu()
{
	char opcao;
	dadosDupla *listaDupla = NULL;

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

				listaDupla = inserirInicio(listaDupla);
				printf("\nRegistro inserido com sucesso.");
				break;

			case 'B':

				listaDupla = inserirFinal(listaDupla);
				//inserirFimUltimo(&listaSimples);
				/*
				if ( ! listaDupla )
				{
					listaDupla = ultimoLista;
				}
				*/
				printf("\nRigistro inserido com sucesso.");
				break;

			case 'C':

				impressao(listaDupla);
				break;

			case 'D':
				cod = receberCodigo("Digite o codigo que deseja remover: ");
				listaDupla = remover(listaDupla, cod);
				printf("\nRemovido com sucesso!");
				break;

			case 'E':

				printf("\nPrograma finalizado!");
				break;

			default:

				printf("\nOpcao digitada invalida!");
		}
	} while ( opcao != 'E' );
}

dadosDupla* inserirInicio( dadosDupla *inicio )
{
	//Alocar dinamicamente o elemento novo.
	dadosDupla *novo = ( dadosDupla* ) malloc( sizeof(dadosDupla) );

	//Preencher dados básicos.
	novo->codigo = RANDOM(100);

	//Fazer o novo elemento apontar para o inicio da lista.
	novo->proximo = inicio;

	// O novo primeiro elemento não tem ninguem antes, portanto o apontamento anterior é nulo
	novo->anterior = NULL;

	// Fazer o ponteiro anterior do elemento inicial apontar para o novo elemento
	if ( inicio )
	{
		inicio->anterior = novo;
	}
	return novo;
}

dadosDupla* inserirFinal( dadosDupla *inicio )
{
	//Alocar dinamicamente o elemento novo.
	dadosDupla *novo = ( dadosDupla* ) malloc( sizeof(dadosDupla) );

	//Preencher dados básicos.
	novo->codigo = RANDOM(100);

	//Garantir que depois dele nao vem ninguem
	novo->proximo = NULL;

	if ( ! inicio )
	{
		novo->anterior = NULL;
		return novo;
	}
	else
	{
		dadosDupla *aux = inicio;

		while ( aux->proximo )
		{
			aux = aux->proximo;
		}
		aux->proximo = novo;
		novo->anterior = aux;

		return inicio;
	}
}

void impressao( dadosDupla *lista )
{
	if ( lista )
	{
		printf("\nEndereço %p - Codigo %d - Anterior %p - Proximo %p",
				lista, lista->codigo, lista->anterior, lista->proximo);
		impressao(lista->proximo);
	}
}

dadosDupla* remover( dadosDupla *lista, int cod )
{
	dadosDupla *aux = lista;

	// Enquanto houver registro valido

	while ( aux )
	{
		// Encontrei

		if ( aux->codigo == cod )
		{
			// Eh o primeiro registro

			if ( ! aux->anterior )
			{
				// Fazendo a lista apontar para o proximo da mesma

				lista = lista->proximo;

				// A lista nao pode apontar para algo que nao existe

				if ( lista )
				{
					lista->anterior = NULL;
				}
			}

			// Nao eh o primeiro

			else
			{
				// Ligar o ponteiro anterior do proximo ao proximo da lista

				aux->anterior->proximo = aux->proximo;

				// Ligar o ponteiro anterior do proximo da lista ao anterior da lista, caso ele exista

				if ( aux->proximo )
				{
					aux->proximo->anterior = aux->anterior;
				}
			}
			free(aux);
			return lista;
		}

		// nao encontrei

		else
		{
			aux = aux->proximo;
		}
	}
	printf("\nRegistro nao encontrado.");
	return lista;
}

int receberCodigo(char *frase)
{
	int cod;

	do {
		printf("\n%s: ", frase);
		scanf("%d", &cod);

		if (cod < 0){
			printf("\nValor inválido.");
		}
	} while (cod < 0);

	return cod;
}
