/*
 * biblioteca.h
 *
 *  Created on: 2 de dez. de 2022
 *      Author: Alexandro Silva, Thiago Luiz, Lucas Bomformagio e Raian Leite
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Macro

#define RANDOM(x) rand() % (x)
#define SEQUENCIAL(x, y) (x) + (y)

// typedefs

typedef struct dependente Dependente;
typedef struct funcionario Funcionario;

// Estruturas

struct dependente
{
	char nome[50];
	int codigo;
	int idade;
	char parentesco;

	Dependente *anterior;
	Dependente *proximo;
};

struct funcionario
{
	int codigo;
	char nome[50];
	char *dataAdmissao;
	char *CPF;
	char cargo;
	double salario;
	int quantidadeDependente;
	Dependente *dadosDependente;

	Funcionario *proximo;
};

// Prototipos

void menu();
Funcionario* inserirInicio( Funcionario *inicio, Dependente *inicioDependente );
Funcionario* inserirDependente( Funcionario *inicio, Dependente *inicioDependente, int cod, char *cpf );
Dependente* inserirFim( Funcionario *inicio, Dependente *inicioDependente );
Funcionario* removerFuncionario( Funcionario *inicio, int cod );
Dependente* removerDependente( Dependente *inicioDependente, int cod );
char inserirParentesco();
int cadastrarIdade();
void cadastrarNome( char *nome, char *frase );
char* cadastrarDataAdmissao();
char* cadastrarCPF();
char cadastrarCargo();
double cadastrarSalario( char Cargo, int numDependentes );
int cadastrarQtdeDependentes();
int receberCodigo( char *frase );
void listarTodosDados( Funcionario* dados, Dependente* dadosDependente );
void listarDadosDependentes( Funcionario *dados, Dependente *dadosDependente, int quantidade );
void listarDadosCPF( Funcionario* dados );


#endif /* BIBLIOTECA_H_ */
