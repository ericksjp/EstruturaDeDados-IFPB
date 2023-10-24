#include <stdlib.h>
#include <stdio.h>
#include "./matriz.h"

Matriz dimensionarMatriz(int linhas, int colunas){
    Matriz novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.tamanho = linhas * colunas;
    novaMatriz.vetor = (int *)malloc(linhas * colunas * sizeof(int));
    if (novaMatriz.vetor == NULL){
        printf("Error: Memoria insuficiente para a alocacao da matriz");
        exit(1);
    }

    return novaMatriz;
}

void inserirElemento(Matriz matriz, int linha, int coluna, int elemento) {
     matriz.vetor[(linha - 1) * matriz.colunas + (coluna - 1)] = elemento; 
}

int buscaElemento(Matriz matriz, int linha, int coluna) { 
    return matriz.vetor[(linha - 1) * matriz.colunas + (coluna - 1)]; 
} 

void preencherMatriz(Matriz matriz, int num){
    int l;
    for (l = 1; l <= matriz.linhas; l++){
        int c;
        for (c = 1; c <= matriz.colunas; c++){
            inserirElemento(matriz, l, c, num);
        }
    }
} 

void preencherMatrizSequencia(Matriz matriz, int num){
    int l;
    for (l = 1; l <= matriz.linhas; l++){
        int c;
        for (c = 1; c <= matriz.colunas; c++){
            inserirElemento(matriz, l, c, num);
            num++;
        }
    }
}

void preencherDiagonalPrincipal(Matriz matriz, int num){
    int l;
    for (l = 1; l <= matriz.linhas; l++){
        int c;
        for (c = 1; c <= matriz.colunas; c++){
            if (l == c)
                inserirElemento(matriz, l, c, num);
        }
    }
} 

void imprimirMatriz(Matriz matriz){
    int l;
    for (l = 1; l <= matriz.linhas; l++){
        int c;
        for (c = 1; c <= matriz.colunas; c++){
            printf("%d ", buscaElemento(matriz, l, c));
        }
        printf("\n");
    }
} 

Matriz somarMatriz(Matriz matriz1, Matriz matriz2){
    if (matriz1.tamanho != matriz2.tamanho){
        perror("Se as dimensões de duas matrizes não são iguais, a soma não é definida. By matematica himself.");
        exit(1);
    }

    Matriz temp = matriz1;
    int l;
    for (l = 1; l <= matriz1.linhas; l++){
        int c;
        for (c = 1; c <= matriz1.colunas; c++){
            int resultSoma = buscaElemento(matriz1, l, c) + buscaElemento(matriz2, l, c);
            inserirElemento(temp, l, c, resultSoma);
        }
    }
    return temp;
} 

Matriz produtoMatriz(Matriz matriz1, Matriz matriz2){
    if (matriz1.colunas != matriz2.linhas){
        perror("Erro: As dimensoes das matrizes nao sao compativeis para multiplicacao\n");
        exit(1);
    }

    Matriz temp = dimensionarMatriz(matriz1.linhas, matriz2.colunas);
    int i;
    for (i = 1; i <= matriz1.linhas; i++){
        int j;
        for (j = 1; j <= matriz2.colunas; j++){
            int acumulador = 0;
            int k;
            for (k = 1; k <= matriz1.colunas; k++){
                acumulador += buscaElemento(matriz1, i, k) * buscaElemento(matriz2, k, j);
            }
            inserirElemento(temp, i, j, acumulador);
        }
    }
    return temp;
} 

int ehIdentidade(Matriz matriz){
    if (matriz.colunas != matriz.linhas)
        return 0;
    int i;
    for (i = 1; i <= matriz.linhas; i++){
        int c;
        for (c = 1; c <= matriz.colunas; c++){
            if (i == c && buscaElemento(matriz, i, c) != 1)
                return 0;
            if (i != c && buscaElemento(matriz, i, c) != 0)
                return 0;
        }
    }
    return 1;
} 

Matriz matrizTransposta(Matriz matriz){
    Matriz temp = dimensionarMatriz(matriz.colunas, matriz.linhas);
    int c;
    for (c = 1; c <= matriz.colunas; c++){
        int l;
        for (l = 1; l <= matriz.linhas; l++){
            int elemento = buscaElemento(matriz, l, c);
            inserirElemento(temp, c, l, elemento);
        }
    }
    return temp;
} 

int ehInversa(Matriz matrizA, Matriz matrizB){
    if (matrizA.linhas != matrizA.colunas)
        return 0;
    Matriz matrizProduto = produtoMatriz(matrizA, matrizB);
    if (ehIdentidade(matrizProduto))
        return 1;
    return 0;
}

Matriz espelharMatriz(Matriz matriz){
    Matriz espelhada = dimensionarMatriz(matriz.linhas, matriz.colunas);
    int l;
    for (l = 1; l <= matriz.linhas; l++){
        int colunaEspelhada = 1;
        int c;
        for (c = matriz.colunas; c >= 1; c--){
            int elemento = buscaElemento(matriz, l, c);
            inserirElemento(espelhada, l, colunaEspelhada, elemento);
            colunaEspelhada++;
        }
        colunaEspelhada = 1;
    }
    return espelhada;
}

int produtoDiagonalPrincipal(Matriz matriz){
    int multiplicador = 1;
    int l;
    for (l = 1; l <= matriz.linhas; l++){
        int c;
        for (c = matriz.colunas; c >= 1; c--){
            if (c == l)
                multiplicador *= buscaElemento(matriz, l, c);
        }
    }
    return multiplicador;
}

int determinanteMatriz(Matriz matriz){
    if (matriz.linhas != matriz.colunas){
        perror("Erro: A determinante eh uma propiedade exclusiva das matrizes quadradas.");
        exit(1);
    }
    int diagonalPrincipalProduto = produtoDiagonalPrincipal(matriz);
    int diagonalSecundariaProduto = produtoDiagonalPrincipal(espelharMatriz(matriz));
    return diagonalPrincipalProduto - diagonalSecundariaProduto;
} 
