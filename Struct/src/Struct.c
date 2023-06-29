/*
 ============================================================================
 Name        : Struct.c
 Author      : Alexandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct endereco endereco;
typedef struct dados Dados;

// Prototipos

void imprimir( Dados *cliente );

struct endereco
{
	char rua[20],
		 bairro[20];
	int numero,
		cep;
};

struct dados
{
	char nome[30],
		 genero;
	int idade;
	double valor;
	endereco end;
};

int main(void) {

	setbuf(stdout, NULL);

	//struct dados dadosCliente;
	Dados dadosCliente;
	dadosCliente.genero = 'M';

	printf("\nValor de compra (R$): ");
	scanf("%lf", &dadosCliente.valor);

	printf("\nNome do cliente: ");
	scanf(" %[^\n]", dadosCliente.nome);

	printf("\nGênero do cliente %s é: %c",
			dadosCliente.nome, dadosCliente.genero);

	// preencher endereço

	printf(" %[^\n]", dadosCliente.end.numero);

	imprimir( &dadosCliente );

	return 0;
}

void imprimir( Dados *cliente )
{
	printf("\n%s", cliente->nome);
	printf("\n%s", cliente->end.rua);
	printf("\n%s", cliente->end.numero);
}
