#include <stdio.h>
#include "matrizChar.h"

int main()
{
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    MatrizChar matriz = criarMatrizChar(linhas, colunas);

    char caractere;
    printf("Digite o caractere para preencher a matriz: ");
    scanf(" %c", &caractere);

    preencherMatrizChar(matriz, caractere);
    printf("\nMatriz preenchida:\n");
    imprimirMatrizChar(matriz);
    printf("\n");

    char novoCaractere;
    int linha, coluna;
    printf("Digite um novo caractere para inserir na matriz: ");
    scanf(" %c", &novoCaractere);
    printf("Digite as coordenadas da matriz na qual deseja inserir o elemento %c (ex: 2 2): ", novoCaractere);
    scanf("%d %d", &linha, &coluna);
    inserirElementoChar(matriz, linha, coluna, novoCaractere);

    printf("Matriz após inserção:\n");
    imprimirMatrizChar(matriz);
    printf("\n");

    printf("\nDigite a linha e coluna para acessar um elemento (ex: 2 2): ");
    scanf("%d %d", &linha, &coluna);
    printf("Elemento na linha %d, coluna %d: %c\n", linha, coluna, acessarElementoChar(matriz, linha, coluna));

    int novasLinhas, novasColunas;
    printf("\nDigite o número de linhas e colunas para redimensionar a matriz: ");
    scanf("%d %d", &novasLinhas, &novasColunas);
    redimensionarMatrizChar(&matriz, novasLinhas, novasColunas);

    char novoCaracterePreenchimento;
    printf("Digite um novo caractere para preencher a matriz redimensionada: ");
    scanf(" %c", &novoCaracterePreenchimento);
    preencherMatrizChar(matriz, novoCaracterePreenchimento);

    printf("\nMatriz redimensionada e preenchida:\n");
    imprimirMatrizChar(matriz);

    liberarMatrizChar(&matriz);

    return 0;
}
