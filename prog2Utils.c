#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>

/*
 * Função:  getToday
 * Obtém o dia de hoje
*/
void getToday(int *day,int *month,int *year){

  // time_t é uma estrutura especial em C
  // time() é uma função que retorna o tempo corrente do sistema. Incluindo hora,minutos, etc..
  time_t agora = time(NULL);
	
	// localtime converte um valor de time_t para uma estrutura que armazena valores de datas.
	struct tm *local = localtime(&agora);

	*day = local->tm_mday;			
	*month = local->tm_mon + 1;		
	*year = local->tm_year + 1900;

}       


/*
 * Função:  editFile 
 * --------------------
 * Edita um arquivo. Busca nas linhas por um ID e edita a posição correspondente do arquivo com o novo valor.
 *
 *  path: caminho do arquivo
  * delim: delimitador de valores do arquivo. Por exemplo, "," ou ";"
 *  id: id a ser pesquisado no arquivo. Este id deve ser correspondente a primeira linha do arquivo
 *  pos: posição do valor a ser modificado. 0-index
    newVal: nova valor a ser colodado no lugar
 *
 *  retorna: 0 caso haja erro ou 1 para ok
 *           
 *     
 */
int editFile(char path[],char delim[],int id,int pos, char newVal[]){
  const int MAX_ID = 10;
  const int MAX_BUFFER = 500;
  char res[MAX_BUFFER];
  int foundId = 0;
  int err=0;

  FILE *fp;
  fp = fopen(path,"r");
  if(fp==NULL){
    printf("erro de acesso ao arquivo \"%s\" : ",path);
    printf("%s\n", strerror(errno));
    return 0;
  }
  FILE *ftemp;
  char tempPath[MAX_BUFFER];
  strcpy(tempPath,path);
  strcat(tempPath,".tmp");
  ftemp = fopen(tempPath,"w");
  if(fp==NULL){
    printf("Erro de criação de arquivo temporário\n");
    printf("%s\n", strerror(errno));
    return 0;
  }



  while(fgets(res,MAX_BUFFER,fp)!=NULL){
    int i=0;
    int found = 0;
    char str[MAX_BUFFER];
    char *tempstr = calloc(MAX_BUFFER+1, sizeof(char));
    char *basestr = calloc(MAX_BUFFER+1, sizeof(char));
    strcpy(basestr,res);

    // o primeiro token é o ID
    char *token = strtok(basestr, delim);

    if(strtol(token,NULL,MAX_ID) == id){
      foundId = 1;

      while(token != NULL) {
        // se não chegou na posição correta, use o valor antigo
        if(i!=pos){ 
          strcat(tempstr,token);     
        }else{ // se chegou, salve o novo valor
          strcat(tempstr,newVal);  
          found = 1;
        }
        i++;

        //printf("%s\n", token);
        token = strtok(NULL, delim);
        // adicionar delimitador entre os valores
        if(token) strcat(tempstr,delim);
        
      }

      if(!found){
        printf("posicao %d nao encontrada no id %d\n",pos,id);
        err=1;
      }
      //printf("----- %s",tempstr);
    }
    
    // salva valores no arquivo temporário
    if(found)
      fputs(tempstr,ftemp);
    else
      fputs(res,ftemp);
  }
  if(!foundId){
    printf("id: %d não encontrado\n",id);
    err = 1;
  }
  fclose(fp);
  fclose(ftemp);

  if (!err){
    int ret = remove(path);
    if(ret !=0){
      printf("erro ao deletar o arquivo \"%s\" : ",path);
      printf("%s\n", strerror(errno));
      err = 1;
    }
    rename(tempPath, path);
    return 1;
 }else{
    remove(tempPath);
    return 0;
  }
}
