#include <stdlib.h>
#include <stdio.h>

typedef struct Matriz
{
    int linhas;
    int colunas;
    int tamanho;
    int *vetor;
} Matriz;

Matriz criarMatriz(int linhas, int colunas)
{
    Matriz novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.tamanho = linhas * colunas;
    novaMatriz.vetor = (int *)malloc(linhas * colunas * sizeof(int));

    return novaMatriz;
}

void inserirElementoInt(Matriz matriz, int linha, int coluna, int elemento)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    matriz.vetor [(linha - 1) * matriz.colunas + (coluna - 1)] = elemento;
}

void preencherMatriz(Matriz matriz, int num)
{
    for (int c = 0; c < matriz.tamanho; c++)
    {
        matriz.vetor[c] = num;
    }
}

void imprimirMatriz(Matriz matriz)
{
    int breakLine = 0;
    for (int c = 0; c < matriz.tamanho; c++)
    {
        printf("%d ", matriz.vetor[c]);
        breakLine++;

        if (breakLine == matriz.colunas)
        {
            printf("\n");
            breakLine = 0;
        }
    }
}

void redimensionarMatriz(Matriz *matriz, int linhas, int colunas)
{
    int vetorTemp[linhas * colunas];
    for (int c = 0; c < matriz->tamanho; c++)
    {
        vetorTemp[c] = matriz->vetor[c];
    }

    free(matriz->vetor);

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->tamanho = linhas * colunas;
    matriz->vetor = (int *)malloc(linhas * colunas * sizeof(int));

    for (int c = 0; c < matriz->tamanho; c++)
    {
        matriz -> vetor[c] = vetorTemp [c];
    }
}

void liberarMatriz(Matriz *matriz)
{
    free(matriz->vetor);
    matriz->vetor = NULL;
    matriz->linhas = 0;
    matriz->colunas = 0;
    matriz->tamanho = 0;
}

Matriz somarMatriz(Matriz matriz1, Matriz matriz2)
{
    Matriz temp;
    if (matriz1.tamanho >= matriz2.tamanho)
    {
        temp = matriz1;
        for (int c = 0; c < matriz2.tamanho; c++)
        {
            temp.vetor[c] += matriz2.vetor[c];
        }
        return temp;
    }
    else
    {
        temp = matriz2;
        for (int c = 0; c < matriz1.tamanho; c++)
        {
            temp.vetor [c] += matriz2.vetor[c];
        }
        return temp;
    }
}
Matriz subtrairMatriz(Matriz matriz1, Matriz matriz2)
{
    Matriz temp;
    if (matriz1.tamanho >= matriz2.tamanho)
    {
        temp = matriz1;
        for (int c = 0; c < matriz2.tamanho; c++)
        {
            temp.vetor[c] -= matriz2.vetor[c];
        }
        return temp;
    }
    else
    {
        temp = matriz2;
        for (int c = 0; c < matriz1.tamanho; c++)
        {
            temp.vetor [c] -= matriz2.vetor[c];
        }
        return temp;
    }
}
Matriz multiplicarMatriz(Matriz matriz1, Matriz matriz2)
{
    Matriz temp;
    if (matriz1.tamanho >= matriz2.tamanho)
    {
        temp = matriz1;
        for (int c = 0; c < matriz2.tamanho; c++)
        {
            temp.vetor[c] *= matriz2.vetor[c];
        }
        return temp;
    }
    else
    {
        temp = matriz2;
        for (int c = 0; c < matriz1.tamanho; c++)
        {
            temp.vetor [c] *= matriz2.vetor[c];
        }
        return temp;
    }
}

int acessarElementoInt(Matriz matriz, int linha, int coluna)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    return matriz.vetor[(linha - 1) * matriz.colunas + (coluna - 1)];
}

int totalMatriz (Matriz matriz){
    int acumulador = 0;
    for (int c = 0; c < matriz.tamanho; c++){
        acumulador += matriz.vetor[c];
    }
    return acumulador;
}

int produtoMatriz (Matriz matriz){
    int acumulador = 0;
    for (int c = 0; c < matriz.tamanho; c++){
        acumulador += matriz.vetor[c];
    }
    return acumulador;
}
