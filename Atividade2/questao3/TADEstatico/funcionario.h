#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#define MAX 50

// -----------------------------------------------------------------------------------------------------------------------------------

typedef char Id[7];

typedef struct{
    Id id;
    char nome[51];
    char cargo[51];
    float salario;
} Funcionario;


typedef struct{
    int quantidadeAtual;
    int quantidadeMaxima;
    Funcionario vetor[MAX];
} ListaFuncionario;

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * Cria uma nova instancia de ListaFuncionarios com o vetor estatico aonde os funcionarios serao armazenados.
 *
 * @param quantidadeMaxima A quantidade maxima de funcionários que a lista pode conter (entre 1 e 50).
 * @return A estrutura ListaFuncionarios criada e inicializada.
 */
ListaFuncionario cria_lista(int quantidadeMaxima);

/**
 * Funcao auxiliar que cria uma nova instanscia de Funcionario.
 *
 * @param all Informacoes para a criacao do funcionario
 * @return A estrutura Funcionario criada.
 */
Funcionario criarFuncionario(Id id, char nome[], char cargo[], float salario);

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * Funcao auxiliar que adiciona um Funcionario no vetor da estrutura Lista Funcionarios.
 * 
 * @param l A lista de funcionários na qual a busca sera realizada.
 * @param funcionario Funcionario a ser inserido no vetor
 * @return Flags 1 (true) ou 0 (false).
 */
int adicionarFuncionario(ListaFuncionario* l, Funcionario funcionario);

/**
 * Funcao para remover um funcionario da estrutura com base no ID ou nome.
 * 
 * @param l A lista de funcionários na qual a busca sera realizada.
 * @param key Valor que sera usado para procurar o funcionario na lista 
 * @return Flags 1 (true) ou 0 (false).
 */
int removerFuncionario(ListaFuncionario* l, char key[]);

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * Funcao para buscar funcionarios na estrutura com base em um criterio.
 * 
 * @param l A lista de funcionarios na qual a busca sera realizada.
 * @param criterio inteiro que especifica o criterio de busca (1 para salario, 2 para nome, 3 para cargo, 4 para ID).
 * @return retorna uma Lista de Funcionarios com os funcionarios achados na estrutura
 */
ListaFuncionario buscarFuncionarios(ListaFuncionario l, int criterio, char key[]);

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * Lista as informacoes de um funcionario.
 *
 * @param funcionario Funcionario a ser listado.
 */
void listarFuncionario(Funcionario funcionario);

/**
 * Lista as informacoes de todos os funcionarios na lista de funcionarios.
 *
 * @param l A lista de funcionarios na qual a listagem sera realizada.
 */
void listarFuncionarios(ListaFuncionario l);

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * Funcao que ordena o vetor de uma lista de funcionarios de acordo com um criterio e ordem especificados.
 *
 * @param l A lista de funcionarios na qual a ordenacao sera realizada.
 * @param ordem inteiro que especifica a ordem da ordenacao (1 para crescente, -1 para decrescente)
 * @param criterio inteiro que especifica o criterio de ordenacao (1 para salario, 2 para nome, 3 para cargo, 4 para ID).
 */
void bubbleSort(ListaFuncionario* l, int ordem, int criterio);

// -----------------------------------------------------------------------------------------------------------------------------------

/**
 * Salva os dados de uma lista de funcionarios em um arquivo CSV.
 *
 * @param l lista de funcionarios a ser salva.
 * @param arquivoCSVLink link do arquivo CSV onde os dados serao salvos.
 */
void salvarNoArquivo(ListaFuncionario l, char arquivoCSVLink[]);

/**
 * Le os dados de um arquivo CSV e preenche uma lista de funcionarios.
 *
 * @param l lista de funcionarios onde os dados serao armazenados.
 * @param arquivoCSVLink - link do arquivo CSV a ser lido.
 */
void lerDoArquivo(ListaFuncionario* l, char arquivoCSVLink[]);

// -----------------------------------------------------------------------------------------------------------------------------------

/* Função para limpar o buffer de entrada */
void limparBuffer();

/* Função para verificar o encerramento do programa */
void monitorarEncerramento(int *encerrar);

/* Função para validar um nome */
int validarNome(char nome[]);

/* Função para gerar um ID valido */
void gerarIdValido(ListaFuncionario l, Id id);

/*Funcao que para a execucao do programa e espera uma teclada do usuario*/
void pausarPrograma();

#endif
