/*
 * funcoes.c
 *
 *  Created on: 2 de dez. de 2022
 *      Author: Alexandro Silva, Thiago Luiz, Lucas Bomformagio e Raian Leite
 */

#include "biblioteca.h"

void menu()
{
	char opcao;
	int op,
		cod;
	Funcionario *listaSimples = NULL;
	Dependente *listaDupla = NULL;

	do {
		printf("\n------------- MENU -------------\n"
			   "A - Inserir funcionario/dependente\n"
			   "B - Excluir funcionario/dependente\n"
			   "C - Relatorios\n"
			   "D - Finalizar\n"
			   "Escolha uma das opcoes listadas acima: ");
		fflush(stdin);
		scanf(" %c", &opcao);
		opcao = toupper(opcao);

		switch ( opcao )
		{
			case 'A':

			do {
				printf("\n---------- INSERCAO ----------\n"
					   "1 - Inserir funcionario\n"
					   "2 - Inserir dependente avulso para um funcionario\n"
					   "Escolha uma das opcoes listadas acima: ");
				fflush(stdin);
				scanf("%d", &op);

				switch ( op )
				{
					case 1:

						listaSimples = inserirInicio(listaSimples, listaDupla);
						break;

					case 2:

						cod = receberCodigo("Digite o codigo do dependente");
						inserirDependente(listaSimples, listaDupla, cod, listaSimples->CPF);
						break;

					default:

						printf("\nOpcao invalida!");
				}
			} while ( op != 1 && op != 2 );

				break;

			case 'B':

				do {
					printf("\n---------- EXCLUSAO ----------\n"
						   "1 - Excluir funcionario\n"
						   "2 - Excluir dependente avulso para um funcionario\n"
						   "Escolha uma das opcoes listadas acima: ");
					fflush(stdin);
					scanf("%d", &op);

					switch ( op )
					{
						case 1:

							cod = receberCodigo("Digite o codigo do funcionario a excluir");
							removerFuncionario(listaSimples, cod);
							break;

						case 2:

							cod = receberCodigo("Digite o codigo do dependente a excluir");
							removerDependente(listaDupla, cod);
							break;

						default:

							printf("\nOpcao invalida!");
					}
				} while ( op != 1 && op != 2 );

				break;

			case 'C':

				do {
					printf("\n---------- RELATORIOS ----------\n"
						   "1 - Listar todos os dados dos funcionarios (funcionarios e dependentes)"
						   "e exibir a media salarial dos funcionarios\n"
						   "2 - Listar todos os dados de um funcionario por CPF\n"
						   "Escolha uma das opcoes listadas acima: ");
					fflush(stdin);
					scanf("%d", &op);

					switch ( op )
					{
						case 1:

							listarTodosDados(listaSimples, listaDupla);
							break;

						case 2:

							listarDadosCPF(listaSimples);
							break;

						default:

							printf("\nOpcao invalida!");
					}
				} while ( op != 1 && op != 2 );

				break;

			case 'D':

				printf("\nPrograma finalizado com sucesso.");
				break;

			default:

				printf("\nOpcao invalida!");
		}
	} while ( opcao != 'D' );
}

Funcionario* inserirInicio( Funcionario *inicio, Dependente *inicioDependente )
{
	Funcionario *novo = ( Funcionario* ) malloc( sizeof(Funcionario) );

	novo->codigo = RANDOM(1000);
	cadastrarNome(novo->nome, "Digite o nome do funcionario");
	novo->dataAdmissao = cadastrarDataAdmissao();
	novo->CPF = cadastrarCPF();
	novo->cargo = cadastrarCargo();
	novo->quantidadeDependente = cadastrarQtdeDependentes("Digite o numero de dependentes");
	novo->salario = cadastrarSalario(novo->cargo, novo->quantidadeDependente);

	if ( novo->quantidadeDependente >= 1 )
	{
		novo->dadosDependente = ( Dependente* ) malloc( sizeof(Dependente) * novo->quantidadeDependente );

		for ( int i = 0 ; i < novo->quantidadeDependente ; i++ )
		{
			novo->dadosDependente = inserirFim(inicio, inicioDependente);
		}
	}
	novo->proximo = inicio;

	return novo;
}

Funcionario* inserirDependente( Funcionario *inicio, Dependente *inicioDependente, int cod, char *cpf )
{
	Funcionario *pesquisa = inicio;
	Dependente *aux = NULL;
	int quantidade = 0;

	for ( int i = 0 ; pesquisa ; i++ )
	{
		if ( aux->codigo == cod || pesquisa->CPF )
		{
			do {
				quantidade = cadastrarQtdeDependentes("Digite o numero de dependentes Avulsos");
				inicio->quantidadeDependente += quantidade;

				if ( inicio->quantidadeDependente > 10 )
				{
					printf("\nValor total não deve ultrapassar 10 dependentes.");
					break;
				}
				Dependente *dados = ( Dependente* ) malloc( sizeof(Dependente) * inicio->quantidadeDependente );

				for ( int i = 0 ; inicio->dadosDependente ; i++ )
				{
					*dados = *inicio->dadosDependente;
					dados++;
					inicio->dadosDependente++;
					quantidade--;
				}
				for ( int x = 0 ; ( inicio->quantidadeDependente - quantidade ) ; x++ )
				{
					aux = inserirFim(inicio, inicioDependente);
					*dados = *aux;
					dados++;
					aux++;
				}
				dados -= inicio->quantidadeDependente;
				inicio->dadosDependente = dados;
			} while ( inicio->quantidadeDependente > 10 );
		}
	}
	return inicio;
}

Dependente* inserirFim( Funcionario *inicio, Dependente *inicioDependente )
{
	Dependente *novo = ( Dependente* ) malloc( sizeof(Dependente) );

	cadastrarNome(novo->nome, "Digite o nome do dependente do funcionario");
	novo->codigo += 1;
	//novo->codigo = SEQUENCIAL(inicio->codigo, 1);
	novo->idade = cadastrarIdade();
	novo->parentesco = inserirParentesco();

	novo->proximo = NULL;

	if ( ! inicioDependente )
	{
		novo->anterior = NULL;
		return novo;
	}
	else
	{
		Dependente *aux = inicioDependente;

		while ( aux->proximo )
		{
			aux = aux->proximo;
		}
		aux->proximo = novo;
		novo->anterior = aux;

		return inicioDependente;
	}
}

Funcionario* removerFuncionario( Funcionario *inicio, int cod )
{
	Funcionario *aux = inicio,
				*anterior = NULL;

	while ( aux )
	{
		if ( aux->codigo == cod )
		{
			if ( ! anterior )
			{
				inicio = inicio->proximo;
			}
			else
			{
				anterior->proximo = aux->proximo;
			}
			free(aux);
			free(aux->dadosDependente);
			return inicio;
		}
		else
		{
			anterior = aux;
			aux = aux->proximo;
		}
	}
	printf("\nRegistro nao encontrado.");
	return inicio;
}

Dependente* removerDependente( Dependente *inicioDependente, int cod )
{
	Dependente *aux = inicioDependente;

	while ( aux )
	{
		if ( aux->codigo == cod )
		{
			if ( ! aux->anterior )
			{
				inicioDependente = inicioDependente->proximo;

				if ( aux )
				{
					aux->anterior = NULL;
				}
			}
			else
			{
				aux->anterior->proximo = aux->proximo;

				if ( aux->proximo )
				{
					aux->proximo->anterior = aux->anterior;
				}
			}
			free(aux);
			return inicioDependente;
		}
		else
		{
			aux = aux->proximo;
		}
	}
	printf("\nRegistro nao encontrado.");
	return inicioDependente;
}

char inserirParentesco()
{
	char parentesco;

    do{
        printf("\nDigite o grau de parentesco do dependente: ");
        fflush(stdin);
        scanf(" %c", &parentesco);
        parentesco = toupper(parentesco);

        if ( parentesco != 'E' && parentesco != 'F' && parentesco != 'T' )
        {
            printf("Apenas aceito caracteres E, F e T");
        }
    } while ( parentesco != 'E' && parentesco != 'F' && parentesco != 'T' );

    return parentesco;
}

int cadastrarIdade()
{
	int idade;

	do {
		printf("\nDigite a idade do dependente: ");
		fflush(stdin);
		scanf("%d", &idade);

		if ( idade > 24 || idade < 0 )
		{
			printf("\nIdade invalida, digite novamente!");
		}
	} while ( idade > 24 || idade < 0 );

	return idade;
}

void cadastrarNome( char *nome, char *frase )
{
	int x;

	do {
		printf("\n%s: ", frase);
		fflush(stdin);
		scanf(" %[^\n]", nome);

	   for ( x = 0 ; x < strlen(nome) ; x++ )
	   {
		   if ( toupper(nome[x]) < 'A' || toupper(nome[x]) > 'Z')
		   {
			   printf("Nome invalido, digite novamente!");
		   }
	   }
	} while ( toupper(nome[x]) > 'A' && toupper(nome[x]) < 'Z' );
}

char* cadastrarDataAdmissao()
{
	int dia,
		mes,
		ano,
		aux = 0;
	time_t mytime;

	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);

	char *data = ( char* ) malloc( sizeof(char) * 10 );

	do {
		printf("\nDigite o dia para inclusao : ");
		fflush(stdin);
		scanf("%d", &dia);

		printf("\nDigite o mes para inclusao : ");
		fflush(stdin);
		scanf("%d", &mes);

		printf("\nDigite o ano para inclusao : ");
		fflush(stdin);
		scanf("%d", &ano);

		if ( ano < tm.tm_year )
		{
			aux = 1;
		}
		else if ( ano == tm.tm_year )
		{
			if ( mes < ( tm.tm_mon + 1 ) )
			{
				aux = 1;
			}
			else if ( mes == ( tm.tm_mon + 1 ) )
			{
				if ( dia < tm.tm_mday )
				{
					aux = 1;
				}
				else if ( dia == tm.tm_mday )
				{
					aux = 1;
				}
				else
				{
					printf("\nData de admissao invalida!");
				}
			}
		}
	} while ( aux != 0 );


	return data;
}

char* cadastrarCPF()
{
	char *cpf = ( char* ) malloc( sizeof(char) * 11 );
	int icpf[11],
	    i,
	    somador = 0,
		digito1,
		result1,
		result2,
		digito2,
		valor,
		aux = 0;


	do {
		printf("Digite o CPF: ");
		fflush(stdin);
		scanf(" %s", cpf);

		if ( strlen(cpf) == 11 )
		{
			for ( i = 0 ; i < 11 ; i++ )
			{
				icpf[i] = cpf[i] - 48;
			}

			for ( i = 0 ; i < 9 ; i++ )
			{
				somador += icpf[i] * (10 - i);
			}

			result1 = somador % 11;

			if ( (result1 == 0) || (result1 == 1) )
			{
				digito1 = 0;
			}
			else
			{
				digito1 = 11 - result1;
			}

			somador = 0;

			for ( i = 0 ; i < 10 ; i++ )
			{
				somador += icpf[i] * (11 - i);
			}

			valor = ( somador/11 ) * 11;
			result2 = somador - valor;

			if ( (result2 == 0) || (result2 == 1) )
			{
				digito2 = 0;
			}
			else
			{
				digito2 = 11 - result2;
			}

			if ( (digito1 == icpf[9]) && (digito2 == icpf[10]) )
			{
				printf("\nEste CPF e valido!.\n");
				aux = 1;
			}
			else
			{
				printf("CPF Invalido e/ou problemas com os digitos.\n");
			}
		}
		else {
			printf("\nCPF digitado invalido, digite novamente!");
		}

	} while ( aux == 0 );

	return cpf;
}

char cadastrarCargo()
{
	char op;

	do {
		printf(	"------ CARGO ------"
				"\nE - Estagiario"
				"\nJ - Nivel Junior"
				"\nP - Nivel Pleno"
				"\nS - Nivel Senior"
				"\nG - Nivel Gerencial"
				"\nSelecione umas das opcoes: ");
		fflush(stdin);
		scanf(" %c", &op);
		op = toupper(op);

		if ( op != 'E' && op != 'J' && op != 'P' && op != 'S' && op != 'G' )
		{
			printf("Opcao invalida, digite novamente.");
		}
	} while ( op != 'E' && op != 'J' && op != 'P' && op != 'S' && op != 'G' );

	return op;
}

double cadastrarSalario( char Cargo, int numDependentes )
{
	double salMinimo = 1212;
	double salario = 0;

	if ( Cargo == 'E' )
	{
		salario = salMinimo + (15.90 * numDependentes);
	}
	else if ( Cargo == 'J' )
	{
		salario = ( (salMinimo * 3) + 15.90 * numDependentes );
	}
	else if ( Cargo == 'P' )
	{
		salario = ( (salMinimo * 5) + 35.72 * numDependentes );
	}
	else if ( Cargo == 'S' )
	{
		salario = ( (salMinimo * 7) + 49 * numDependentes );
	}
	else if ( Cargo == 'G' )
	{
		salario = ( (salMinimo * 9) + 68.29 * numDependentes );
	}

	return salario;
}

int cadastrarQtdeDependentes( char *frase )
{
	int numDependentes;

	do {
		printf("\n%s: ", frase);
		fflush(stdin);
		scanf(" %d", &numDependentes);

		if ( numDependentes < 0 || numDependentes > 10 )
		{
			printf("Valor invalido, digite novamente.");
		}
	} while (numDependentes < 0 || numDependentes > 10);

	return numDependentes;
}

int receberCodigo( char *frase )
{
	int cod;

	do {
		printf("\n%s: ", frase);
		fflush(stdin);
		scanf("%d", &cod);

		if (cod < 0){
			printf("\nValor inválido.");
		}
	} while (cod < 0);

	return cod;
}

void listarTodosDados( Funcionario* lista, Dependente* listaDependente )
{

    int contador = 0;
    double salarios = 0;

    if (lista)
    {
        printf( "\n-----FUNCIONÁRIO-----\n"
                "\nCódigo: %d"
                "\nNome: %s"
                "\nData de Admissao: %s"
                "\nCPF: %s"
                "\nCargo: %c"
                "\nSalario: %lf"
                "\nQuantidade de Dependentes: %d",
				lista->codigo, lista->nome, lista->dataAdmissao, lista->CPF,
				lista->cargo, lista->salario, lista->quantidadeDependente);

        if ( lista->quantidadeDependente > 0 )
        {
            listarDadosDependentes(lista, listaDependente, lista->quantidadeDependente);
        }
        salarios += lista->salario;
        contador++;
        listarTodosDados(lista->proximo, listaDependente->proximo);
    }
    else
    {
        printf("A média dos salários dos funcionários é: %lf", (salarios / contador) );
    }
}

void listarDadosDependentes( Funcionario *lista, Dependente *listaDependente, int quantidade )
{
    if ( lista->quantidadeDependente >= 1 )
    {
        printf( "\n-----DEPENDENTE-----\n"
                "\nNome: %s"
                "\nCódigo: %d"
                "\nIdade: %d"
                "\nParentesco: %c",
				listaDependente->nome, listaDependente->codigo,
				listaDependente->idade, listaDependente->parentesco);

        listarDadosDependentes(lista->proximo, listaDependente->proximo, lista->quantidadeDependente - 1);
    }
}

void listarDadosCPF( Funcionario* lista )
{
    char *cpf = (char*) malloc( sizeof(char) );

    cpf = cadastrarCPF();

    if ( *cpf == *lista->CPF )
    {
		printf( "\n-----FUNCIONARIO-----\n"
				"\nCodigo: %d"
				"\nNome: %s"
				"\nData de Admissao: %s"
				"\nCPF: %s"
				"\nCargo: %c"
				"\nSalario: %lf"
				"\nQuantidade de Dependentes: %d",
				lista->codigo, lista->nome, lista->dataAdmissao, lista->CPF,
				lista->cargo, lista->salario, lista->quantidadeDependente);

		listarDadosCPF(lista->proximo);
	}
}
