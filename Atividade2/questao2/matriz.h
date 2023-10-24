#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct{
    int linhas;
    int colunas;
    int tamanho;
    int *vetor;
} Matriz;

// cria uma Matriz, define seu numero de colunas e linhas e aloca o vetor;
Matriz dimensionarMatriz(int linhas, int colunas);

/*acessa a posicao no vetor pela continha e atribui ele ao numero especificado pelo usuario*/ 
void inserirElemento(Matriz matriz, int linha, int coluna, int elemento);

 /*retorna o numero na linha x e coluna y da matriz especificada pelo usuario*/
int buscaElemento(Matriz matriz, int linha, int coluna);

/*preenche a matriz com o numero informado*/
void preencherMatriz(Matriz matriz, int num);

/*preenche a matriz com a sequencia do numero informado*/
void preencherMatrizSequencia(Matriz matriz, int num);

/*preenche a diagonal principal da matriz com o numero informado*/
void preencherDiagonalPrincipal(Matriz matriz, int num);

/*percorre o vetor do struct matriz e e acessa o elemento para printar na tela usando a funcao buscaElemento*/
void imprimirMatriz(Matriz matriz);

/* soma duas matrizes de tamanhos iguais (soma de tamanhos diferentes nao sao permitidas!!! AKA matematica!)*/
Matriz somarMatriz(Matriz matriz1, Matriz matriz2);

/*2 questao / algoritmo simplificado*/
Matriz produtoMatriz(Matriz matriz1, Matriz matriz2);

/*3 questao / 3 saidas para 0*/
int ehIdentidade(Matriz matriz);

/*retorna uma matriz igual a matriz transposta da matriz informada*/
Matriz matrizTransposta(Matriz matriz);

/*verifica se a matriz B eh inversa da matriz A*/
int ehInversa(Matriz matrizA, Matriz matrizB);

/*espelha a matriz passada como parametro e retorna a matriz espelhada*/
Matriz espelharMatriz(Matriz matriz);

/*retorna o produto da diagonal principal da matriz*/
int produtoDiagonalPrincipal(Matriz matriz);

/*retorna um inteiro que representa o determinante da matriz*/
int determinanteMatriz(Matriz matriz);

#endif
