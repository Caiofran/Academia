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
  int max;
  int min;
};

// **aqui vão os protótipos de suas funções**

// por exemplo, uma função para salvar as aulas em um arquivo
void salvarAula(struct aula *aulasAsalvar);

// função para mostrar menu na tela e ler opção digitada
int lerOpcao();

// Programa Principal 
int main ()
{
		struct aula aulas[CAPACIDADE_MAXIMA];
		
    int opcao=1;
    
    do{
        puts("Academia superação\nDigite a opcao: ");
        opcao = lerOpcao();
        switch (opcao)
        {
           case 1: // 1- Cadastra aluno
           // Se o arquivo não existir, gera um novo arquivo
				    if(!verificarquivo(":aluno.txt"))
            { 
					    newFile(":cliente.txt","w");
					    cadastrarAluno();
				    }// Executa a função
				    else {
					  cadastrarAluno();
				    }
             break;

           case 2: // 2-  Cadastrar professor
             //void cadastrarProfessor()
             if(!verificarquivo(":aluno.txt"))
            { 
					    newFile(":professor.txt","w");
					    cadastrarProfessor();
				    }// Executa a função
				    else {
					  cadastrarProfessor();
				    }
             break;

					 case 3: // 3- Cadastrar turma
             break;
             
           case 4:  // 4- Inscrever aluno
             break;
             
           case 5:  // 5- Cancelar inscrição
             break;
       
           case 6:  // 6- Fechar turmas
             break;
           
           case 7:  // 7- Confirmar turmas
             break;

						case 8:  // 8- Fechar o programa
						 //salvarAula(aulas);
						 exit(0);
             break;

						default:
							printf("Opcao invalida, tente novamente.\n");
							break;
                      
        }
     }while (opcao>0 && opcao<9);

  return 0;
} // fim do main 