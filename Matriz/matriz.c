#include <stdio.h>
#include <stdlib.h>

typedef struct MatrizInt
{
    int linhas;
    int colunas;
    int matrizTamanho;
    char matrizTipo;
    void *pont;
} MatrizInt;

MatrizInt criarMatriz(int linhas, int colunas, char tipo)
{
    MatrizInt novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.matrizTamanho = linhas * colunas;
    if (tipo == 'c')
    {
        char *ponTest = (char *)malloc(linhas * colunas * sizeof(char));
        novaMatriz.matrizTipo = 'c';
        novaMatriz.pont = ponTest;
    }
    else if (tipo == 'd')
    {
        int *ponTest = (int *)malloc(linhas * colunas * sizeof(int));
        novaMatriz.matrizTipo = 'd';
        novaMatriz.pont = ponTest;
    }
    return novaMatriz;
}

int acessarElemento(MatrizInt matriz, int linha, int coluna)
{
    if (matriz.matrizTipo == 'c')
        return *((char *)matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1)));
    else if (matriz.matrizTipo == 'd')
        return *((int *)matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1)));
}

void inserirElemento(MatrizInt matriz, int linha, int coluna, int elemento)
{
    if (matriz.matrizTipo == 'c')
    {
        *((char *)matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1))) = elemento;
    }
    else if (matriz.matrizTipo == 'd')
    {
        *((int *)matriz.pont + ((linha - 1) * matriz.colunas + (coluna - 1))) = elemento;
    }
}

void preencherMatriz(MatrizInt matriz, int num)
{
    if (matriz.matrizTipo == 'c')
    {
        for (int c = 0; c < matriz.matrizTamanho; c++)
        {
            *((char *)matriz.pont + c) = (char)num;
        }
    }
    else if (matriz.matrizTipo == 'd')
    {
        for (int c = 0; c < matriz.matrizTamanho; c++)
        {
            *((int *)matriz.pont + c) = num;
        }
    }
}

void imprimirMatriz(MatrizInt matriz) {
    int breakLine = 0;
    int tamanho = matriz.matrizTamanho;
    
    if (matriz.matrizTipo == 'c') {
        for (int c = 0; c < tamanho; c++) {
            printf("%c ", *((char *)matriz.pont + c));
            breakLine++;
            
            if (breakLine == matriz.colunas) {
                printf("\n");
                breakLine = 0;
            }
        }
    } else if (matriz.matrizTipo == 'd') {
        for (int c = 0; c < tamanho; c++) {
            printf("%d ", *((int *)matriz.pont + c));
            breakLine++;
            
            if (breakLine == matriz.colunas) {
                printf("\n");
                breakLine = 0;
            }
        }
    }
}

// void redimensionarMatriz(MatrizInt *matriz, int linhas, int colunas) {
//     int antesTamanho = matriz->matrizTamanho;

//     // criando um vetor temporario para armazenar os dados do vetor atual
//     int *vetorTemp = (int *)malloc(antesTamanho * sizeof(int));
//     for (int c = 0; c < antesTamanho; c++) {
//         *(vetorTemp + c) = *(matriz->pont + c);
//     }

//     free(matriz->pont);

//     matriz->linhas = linhas;
//     matriz->colunas = colunas;
//     matriz->matrizTamanho = linhas * colunas;
//     matriz->pont = (int *)malloc(matriz->matrizTamanho * sizeof(int));

//     for (int c = 0; c < matriz->matrizTamanho; c++) {
//         *(matriz->pont + c) = *(vetorTemp + c);
//     }

//     free(vetorTemp);
// }

// void liberateMatriz(MatrizInt *matriz){
//     matriz->colunas = 0;
//     matriz->linhas = 0;
//     matriz->matrizTamanho = 0;
//     free(matriz->pont);
// }

// free é usado para liberar blocos de memoria alocados dinamicamente usando malloc;

int main()
{
    MatrizInt m1 = criarMatriz(10, 10, 'd');
    preencherMatriz(m1, 35);
    imprimirMatriz(m1);
    // preencherMatriz(m1, 5);
    // redimensionarMatriz(&m1, 3, 3);
    // inserirElemento(m1, 2, 2, 10);

    // for (int i = 0; i < m1.linhas; i++) {
    //     for (int j = 0; j < m1.colunas; j++) {
    //         printf("%d ", acessarElemento(m1, i, j));
    //     }
    //     printf("\n");
    // }

    // liberateMatriz(&m1);
    return 0;
}
