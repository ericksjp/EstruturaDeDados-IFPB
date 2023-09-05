#include <stdlib.h>
#include <stdio.h>

typedef struct MatrizInt
{
    int linhas;
    int colunas;
    int matrizTamanho;
    int *pont;
} MatrizInt;

MatrizInt criarMatrizInt(int linhas, int colunas)
{
    MatrizInt novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.matrizTamanho = linhas * colunas;
    novaMatriz.pont = (int *)malloc(novaMatriz.matrizTamanho * sizeof(int));

    return novaMatriz;
}

int acessarElementoInt(MatrizInt matriz, int linha, int coluna)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    return matriz.pont[(linha - 1) * matriz.colunas + (coluna - 1)];
}

void inserirElementoInt(MatrizInt matriz, int linha, int coluna, int elemento)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    *(matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1))) = elemento;
}

MatrizInt somarMatrizInt(MatrizInt matriz1, MatrizInt matriz2)
{
    MatrizInt temp;
    if (matriz1.matrizTamanho >= matriz2.matrizTamanho)
    {
        temp = matriz1;
        imprimirMatrizInt(temp);
        for (int c = 0; c < matriz2.matrizTamanho; c++)
        {
            *(temp.pont + c) += *(matriz2.pont + c);
        }
        return temp;
    }
    else
    {
        temp = matriz2;
        imprimirMatrizInt(temp);
        for (int c = 0; c < matriz1.matrizTamanho; c++)
        {
            *(temp.pont + c) += *(matriz2.pont + c);
        }
        return temp;
    }
}

void preencherMatrizInt(MatrizInt matriz, int num)
{
    for (int c = 0; c < matriz.matrizTamanho; c++)
    {
        *(matriz.pont + c) = num;
    }
}

void imprimirMatrizInt(MatrizInt matriz)
{
    int breakLine = 0;
    int tamanho = matriz.matrizTamanho;
    for (int c = 0; c < tamanho; c++)
    {
        printf("%d ", *(matriz.pont + c));
        breakLine++;

        if (breakLine == matriz.colunas)
        {
            printf("\n");
            breakLine = 0;
        }
    }
}

void redimensionarMatrizInt(MatrizInt *matriz, int linhas, int colunas)
{
    int *vetorTemp = (int *)malloc(matriz->matrizTamanho * sizeof(int));
    for (int c = 0; c < matriz->matrizTamanho; c++)
    {
        *(vetorTemp + c) = *(matriz->pont + c);
    }

    free(matriz->pont);

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->matrizTamanho = linhas * colunas;
    matriz->pont = (int *)malloc(matriz->matrizTamanho * sizeof(int));

    for (int c = 0; c < matriz->matrizTamanho; c++)
    {
        *(matriz->pont + c) = *(vetorTemp + c);
    }

    free(vetorTemp);
}

void liberarMatrizInt(MatrizInt *matriz)
{
    free(matriz->pont);
    matriz->pont = NULL;
    matriz->linhas = 0;
    matriz->colunas = 0;
    matriz->matrizTamanho = 0;
}