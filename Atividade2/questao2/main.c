#include <stdio.h>
#include "./matriz.h"

int main( void ){

    printf("Matriz 1: \n");
    Matriz matriz1 = dimensionarMatriz(3, 2);
    preencherMatrizSequencia(matriz1, 1);
    imprimirMatriz(matriz1);
    printf("\n");
    
    printf("Matriz 2: \n");
    Matriz matriz2 = dimensionarMatriz(2, 3);
    preencherMatrizSequencia(matriz2, 4);
    imprimirMatriz(matriz2);
    printf("\n");
    
    printf("Produto Matriz 1 * Matriz 2:\n");
    Matriz matrizProduto = produtoMatriz(matriz1, matriz2);
    imprimirMatriz(matrizProduto);
    printf("--------------------------------------------------------------------------------------------------------------\n");

    printf("Matriz 3: \n");
    Matriz matriz3 = dimensionarMatriz(3, 4);
    preencherMatrizSequencia(matriz3, 11);
    imprimirMatriz(matriz3);
    printf("\n");
    
    printf("Matriz 4: \n");
    Matriz matriz4 = dimensionarMatriz(3, 4);
    preencherMatrizSequencia(matriz4, 15);
    imprimirMatriz(matriz4);
    printf("\n");
    
    printf("Matriz transposta do soma das matrizes 3 e 4: \n");
    Matriz matrizTranspostaDaSoma = matrizTransposta(somarMatriz(matriz3, matriz4));
    imprimirMatriz(matrizTranspostaDaSoma);
    
    printf("--------------------------------------------------------------------------------------------------------------\n");
    
    printf("Matriz 5: \n");
    Matriz matriz5 = dimensionarMatriz(3, 3);
    preencherMatriz(matriz5, 0);
    inserirElemento(matriz5, 1, 1, 1);
    inserirElemento(matriz5, 2, 2, 1);
    inserirElemento(matriz5, 3, 3, 1);
    imprimirMatriz(matriz5);
    if (ehIdentidade(matriz5)){
        printf("A matriz 5 eh uma matriz identidade!\n");
    }else{
        printf("A matriz 5 nao eh uma matriz identidade\n");
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");
    
    printf("Matriz 6: \n");
    Matriz matriz6 = dimensionarMatriz(2, 2);
    inserirElemento(matriz6, 1, 1, 2);
    inserirElemento(matriz6, 1, 2, -5);
    inserirElemento(matriz6, 2, 1, -1);
    inserirElemento(matriz6, 2, 2, 3);
    imprimirMatriz(matriz6);
    printf("\n");
    
    printf("Matriz 7: \n");
    Matriz matriz7 = dimensionarMatriz(2, 2);
    inserirElemento(matriz7, 1, 1, 3);
    inserirElemento(matriz7, 1, 2, 5);
    inserirElemento(matriz7, 2, 1, 1);
    inserirElemento(matriz7, 2, 2, 2);
    imprimirMatriz(matriz7);
    printf("\n");

    if (ehInversa(matriz6, matriz7)){
        printf("A matriz 7 eh inversa da matriz 6, porque o produto dessas matrizes resultou numa matriz identidade.\n");
    }else{
        printf("A matriz 7 nao eh inversa da matriz 6, porque o produto dessas matrizes nao resultou numa matriz identidade.\n");
    }

    printf("--------------------------------------------------------------------------------------------------------------\n");
    
    printf("Matriz 8: \n");
    Matriz matriz8 = dimensionarMatriz(2, 2);
    inserirElemento(matriz8, 1, 1, 3);
    inserirElemento(matriz8, 1, 2, 5);
    inserirElemento(matriz8, 2, 1, -1);
    inserirElemento(matriz8, 2, 2, 2);
    int determinante = determinanteMatriz(matriz8);
    printf("A determinante dessa matriz eh %d \n",determinante);

    return 1;
}
