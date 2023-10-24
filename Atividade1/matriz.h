#include <stdlib.h>
#include <stdio.h>

typedef struct Matriz{
    int linhas;
    int colunas;
    int tamanho;
    int *vetor;
} Matriz;

Matriz dimensionarMatriz(int linhas, int colunas){
    Matriz novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.tamanho = linhas * colunas;
    novaMatriz.vetor = (int *)malloc(linhas * colunas * sizeof(int));
    if (novaMatriz.vetor == NULL){
        perror("Memoria insuficiente para a instanciacao da Matriz em memoria!!");
        exit(0);
    }
    return novaMatriz;
}

void adicionaElemento(Matriz matriz, int elemento, int linha, int coluna) {
     matriz.vetor[(linha - 1) * matriz.colunas + (coluna - 1)] = elemento; 
}

int buscaElemento(Matriz matriz, int linha, int coluna) { 
    return matriz.vetor[(linha - 1) * matriz.colunas + (coluna - 1)]; 
} 

void zerarMatriz(Matriz matriz){
    for (int l = 1; l <= matriz.linhas; l++){
        for (int c = 1; c <= matriz.colunas; c++){
            adicionaElemento(matriz, 0, l, c);
        }
    }
} 

void imprimirMatriz(Matriz matriz){
    for (int l = 1; l <= matriz.linhas; l++){
        for (int c = 1; c <= matriz.colunas; c++){
            printf("%d ", buscaElemento(matriz, l, c));
        }
        printf("\n");
    }
} 

/*1 Questão*/
Matriz produto_Matriz(Matriz matriz1, Matriz matriz2)
{
    if (matriz1.colunas != matriz2.linhas){
        perror("Erro: As dimensoes das matrizes nao sao compativeis para multiplicacao\n");
        exit(0);
    }
    Matriz temp = dimensionarMatriz(matriz1.linhas, matriz2.colunas);
    for (int i = 1; i <= matriz1.linhas; i++){
        for (int j = 1; j <= matriz2.colunas; j++){
            int acumulador = 0;
            for (int k = 1; k <= matriz1.colunas; k++){
                acumulador += buscaElemento(matriz1, i, k) * buscaElemento(matriz2, k, j);
            }
            adicionaElemento(temp, acumulador, i, j);
        }
    }
    return temp;
} 

// Auxiliar questao 2
Matriz somarMatriz(Matriz matriz1, Matriz matriz2){
    if (matriz1.tamanho != matriz2.tamanho){
        perror("Se as dimensões de duas matrizes não são iguais, a soma não é definida. By matematica himself.");
        exit(0);
    }
    Matriz temp = matriz1;
    for (int l = 1; l <= matriz1.linhas; l++){
        for (int c = 1; c <= matriz1.colunas; c++){
            int resultSoma = buscaElemento(matriz1, l, c) + buscaElemento(matriz2, l, c);
            adicionaElemento(temp, resultSoma, l, c);
        }
    }
    return temp;
} 

//Auxiliar questao 2
Matriz matrizTransposta(Matriz matriz){
    Matriz temp = dimensionarMatriz(matriz.colunas, matriz.linhas);
    for (int c = 1; c <= matriz.colunas; c++){
        for (int l = 1; l <= matriz.linhas; l++){
            int elemento = buscaElemento(matriz, l, c);
            adicionaElemento(temp, elemento, c, l);
        }
    }
    return temp;
} 

// Questão 2
void transposta_da_soma_Matriz(Matriz matriz1, Matriz matriz2){
    Matriz temp = matrizTransposta( somarMatriz(matriz1,matriz2) );
    imprimirMatriz(temp);
}

// 3 questao
int identidade_Matriz(Matriz matriz){
    if (matriz.colunas != matriz.linhas)
        return 0;
    for (int i = 1; i <= matriz.linhas; i++){
        for (int c = 1; c <= matriz.colunas; c++){
            if (i == c && buscaElemento(matriz, i, c) != 1)
                return 0;
            if (i != c && buscaElemento(matriz, i, c) != 0)
                return 0;
        }
    }
    return 1;
} 

// Questão 4
int inversa_Matriz(Matriz matrizA, Matriz matrizB){
    if (matrizA.linhas != matrizA.colunas)
        return 0;
    Matriz matrizProduto = produto_Matriz(matrizA, matrizB);
    if (identidade_Matriz(matrizProduto))
        return 1;
    return 0;
}

