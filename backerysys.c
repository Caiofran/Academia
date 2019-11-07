#include<stdio.h>
#include<stdlib.h>
#include "backerysys.h"
#include "prog2Utils.h" // biblioteca de funções auxiliares. Por exemplo editar informações de arquivos.
#define CAPACIDADE_MAXIMA 100 // valor total para armazenar em uma estrutura

struct aluno{
	int id;
	char nome[300];
	char cpf[15];
	char telefone[50];
	char email[100];
};

struct aula{
	int id;
	char tipo; 
  int dia;
	char horario[6];
	int id_prof;
	int minimo;
	int maximo;
	char faixa_etaria[6];
	struct aluno alunos[CAPACIDADE_MAXIMA];
};

struct turma{
  char dia;
  int id_prof;
  int idades;
  

};

int lerOpcao()
{
  // Recebe o valor referente a opção a ser executada
	int opcao = 0;
	// Imprime as opções disponiveis
	printf("____________Opções:____________\n");
	printf("[1] Cadastrar Aluno:\n");
	printf("[2] Cadastrar Proferssor:\n");
	printf("[3] Cadastrar Turma:\n");
	printf("[4] Inscrever aluno:\n");
	printf("[5] Cancelar inscrição:\n");
	printf("[6] Fechar turmas:\n");
  printf("[7] Confirmar turmas:\n");
	printf("[8] Fechar o programa:\n");
	printf("Opção: ");
	scanf("%d", &opcao);

	return opcao;
}

void cadastrarAluno()
{
  struct aluno aluno;
  
  printf("Codigo do aluno: ",);
  printf("Informe o nome do aluno: ");
  getchar();
  fgets(aluno.nome,300,stdin);

  printf("Informe o cpf:");
  getchar();
  fgets(aluno.cpf,15,stdin);

  printf("Informe o Telefone: ");
  getchar();
  fgets(aluno.telefone,50, stdin);

  printf("Informe o email: ");
  getchar();
  fgets(aluno.email,100,stdin);

  FILE *fp = fopen(fp,"alunos
  %d %s %s %s %s",aluno.id,aluno.nome,aluno.cpf,aluno.telefone,aluno.email);
}


void cadastrarProfessor()
{
  struct aluno professor;

  printf("Informe o nome do Professor: ");
  getchar();
  fgets(professor.nome,300,stdin);

  printf("Informe seu cpf:");
  getchar();
  fgets(professor.cpf,15,stdin);

  printf("Informe o Telefone: ");
  getchar();
  fgets(professor.telefone,50, stdin);

  printf("Informe seu email: ");
  getchar();
  fgets(professor.email,100,stdin);
  
}
/* Função newFile
 * --------------
 * Cria um novo arquivo ".txt"
 * fileName: Nome do arquivo
 * action: Comando de execução do arquivo
*/
void newFile(char fileName[], char action[]){
	FILE *myFile = fopen(fileName, action);
	if(myFile == NULL){
		printf("Arquivo não encontrado.");
		exit(0);
	}
}
/* Função: verifyFile
 * ----------------
 * Verifica se o arquivo existe
 * myFile: parametro que o nome do arquivo
*/
int verificarquivo(char meuarquivo[]){
	FILE *fileToVerify = fopen(meuarquivo, "r");
	if(fileToVerify)
		return 1; 
	else
		return 0;
}
void salvarAula(aulas)
{

}