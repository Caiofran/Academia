#ifndef padariasys_h
#define padariasys_h

// Valores do tipo cliente
typedef struct clients clients;

// Valores do tipo produto
typedef struct product product;

// Valores do tipo venda
typedef struct sales sales;

// Função que verifica se um arquivo existe
int verificarquivo(char meuarquivo[]);

// Função para registrar um novo cliente
void newClient();

// Função para registrar um novo produto no sistema
void newProduct();

// Função para identificar a opção que o cliente quer realizar
int readOption();

// Função para salvar as vendas feitas na data
void saveSales(sales *salesToSave);

// Função para para criar um novo arquivo
void newFile(char fileName[], char action[]);

// Função para editar um arquivo
void updateFile();

// Gera o nome do arquivo ".pvf"
void gerarPvf(char *fileName);

// Função que realiza uma venda
void sell(sales *venda);

// Verifica se o cliente está com débito em aberto
void verifyDebt(char *path);

// Lista as vendas feitas na data
void listSales();

// Zera ou diminui a divida do cliente
void quitarDivida();

//Casdratrar o aluno
void cadastrarAluno();

//Casdratrar o professor
void cadastrarProfessor();

#endif