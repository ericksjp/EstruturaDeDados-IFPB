#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int linhas;
    int colunas;
    int matrizTamanho;
    char *pont;
} MatrizChar;

MatrizChar criarMatrizChar(int linhas, int colunas)
{
    MatrizChar novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.matrizTamanho = linhas * colunas;
    novaMatriz.pont = (char *)malloc(novaMatriz.matrizTamanho * sizeof(char));

    return novaMatriz;
}

char acessarElementoChar(MatrizChar matriz, int linha, int coluna)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    return *(matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1)));
}

void inserirElementoChar(MatrizChar matriz, int linha, int coluna, char elemento)
{
    if (linha < 1 || linha > matriz.linhas || coluna < 1 || coluna > matriz.colunas)
    {
        printf("Erro: Índices fora dos limites da matriz.\n");
        exit(1);
    }
    *(matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1))) = elemento;
}

void preencherMatrizChar(MatrizChar matriz, char elemento)
{
    for (int c = 0; c < matriz.matrizTamanho; c++)
    {
        *(matriz.pont + c) = elemento;
    }
}

// MatrizChar somarMatrizChar(MatrizChar matriz1, MatrizChar matriz2)
// {
//     if (matriz1.matrizTamanho >= matriz2.matrizTamanho)
//     {
//         for (int c = 0; c < matriz2.matrizTamanho; c++)
//         {
//             *(matriz1.pont + c) += *(matriz2.pont + c);
//             imprimirMatrizChar(matriz1);
//             return matriz1;
//         }
//     }
//     else
//     {
//         for (int c = 0; c < matriz1.matrizTamanho; c++)
//         {
//             *(matriz2.pont + c) += *(matriz1.pont + c);
//             return matriz2;
//         }
//     }
// }

void imprimirMatrizChar(MatrizChar matriz)
{
    int breakLine = 0;
    int tamanho = matriz.matrizTamanho;
    for (int c = 0; c < tamanho; c++)
    {
        printf("%c ", *(matriz.pont + c));
        breakLine++;

        if (breakLine == matriz.colunas)
        {
            printf("\n");
            breakLine = 0;
        }
    }
}

void redimensionarMatrizChar(MatrizChar *matriz, int linhas, int colunas)
{
    char *vetorTemp = (char *)malloc(matriz->matrizTamanho * sizeof(char));
    for (int c = 0; c < matriz->matrizTamanho; c++)
    {
        *(vetorTemp + c) = *(matriz->pont + c);
    }

    free(matriz->pont);

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->matrizTamanho = linhas * colunas;
    matriz->pont = (char *)malloc(matriz->matrizTamanho * sizeof(char));

    for (int c = 0; c < matriz->matrizTamanho; c++)
    {
        *(matriz->pont + c) = *(vetorTemp + c);
    }

    free(vetorTemp);
}

void liberarMatrizChar(MatrizChar *matriz)
{
    free(matriz->pont);
    matriz->pont = NULL;
    matriz->linhas = 0;
    matriz->colunas = 0;
    matriz->matrizTamanho = 0;
}