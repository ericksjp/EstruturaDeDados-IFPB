#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H
#define TAMANHO 10

// enum usado para implementar as prioridades na fila
typedef enum {
    DIRETOR = 1,      // prioridade 1
    COORDENADOR = 2,  // prioridade 2
    FUNCIONARIO = 3   // prioridade 3
} Cargo;

// struct para representar um funcionario
typedef struct {
    char nome[50];
    Cargo cargo;
} Funcionario;

// estrutura para representar uma fila circular de funcionarios
typedef struct {
    int inicio, fim, qtdade;    // algunas parametros para a manipulacao do vetor;
    Funcionario vetor[TAMANHO]; // vetor com os funcionarios;
} Fila;

// Funcao responsavel por inicializar uma Fila Circular
Fila* inicializarFilaCircular();

// Funcao auxiliar que calcula uma nova posicao de acordo com a posicao informada como parametro
int nova_posicao(int posicao);

// Funcao auxiliar que calcula uma nova posicao de acordo com a posicao informada como parametro
int decrementar_posicao(int pos);

// Funcao responsavel por enfileirar um funcionario na fila de acordo com o seu cargo;
int enfileirarFilaCircular(Fila* f, char name[], Cargo cargo);

// Funcao responsavel por desenfileirar um funcionario da fila;
Funcionario* desenfileirarFilaCircular(Fila* f);

// Funcao responsavel por imprimir a fila;
void imprimeFila(Fila* f);

#endif
