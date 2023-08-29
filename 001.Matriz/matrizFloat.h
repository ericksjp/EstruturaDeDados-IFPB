#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int linhas;
    int colunas;
    int matrizTamanho;
    float *pont;
} MatrizFloat;

MatrizFloat criarmatrizFloat(int linhas, int colunas)
{
    MatrizFloat novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.matrizTamanho = linhas * colunas;
    novaMatriz.pont = (float *)malloc(novaMatriz.matrizTamanho * sizeof(float));

    return novaMatriz;
}

float acessarElementoInt(MatrizFloat matriz, int linha, int coluna)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    return *(matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1)));
}

void inserirElementoInt(MatrizFloat matriz, int linha, int coluna, float elemento)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    *(matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1))) = elemento;
}

void preencherMatrizFloat(MatrizFloat matriz, float num)
{
    for (int c = 0; c < matriz.matrizTamanho; c++)
    {
        *(matriz.pont + c) = num;
    }
}

void imprimirMatrizFloat(MatrizFloat matriz)
{
    int breakLine = 0;
    int tamanho = matriz.matrizTamanho;
    for (int c = 0; c < tamanho; c++)
    {
        printf("%f ", *(matriz.pont + c));
        breakLine++;

        if (breakLine == matriz.colunas)
        {
            printf("\n");
            breakLine = 0;
        }
    }
}

void redimensionarMatrizFloat(MatrizFloat *matriz, int linhas, int colunas)
{
    float *vetorTemp = (float *)malloc(matriz->matrizTamanho * sizeof(float));
    for (int c = 0; c < matriz->matrizTamanho; c++)
    {
        *(vetorTemp + c) = *(matriz->pont + c);
    }

    free(matriz->pont);

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->matrizTamanho = linhas * colunas;
    matriz->pont = (float *)malloc(matriz->matrizTamanho * sizeof(float));

    for (int c = 0; c < matriz->matrizTamanho; c++)
    {
        *(matriz->pont + c) = *(vetorTemp + c);
    }

    free(vetorTemp);
}

void liberarMatrizFloat(MatrizFloat *matriz)
{
    free(matriz->pont);
    matriz->pont = NULL;
    matriz->linhas = 0;
    matriz->colunas = 0;
    matriz->matrizTamanho = 0;
}