#include <stdio.h>
#include "./PilhaEstatica.h"

int main(void) {
    char expressao1[] = "3.14 * (5.6 + 2.1))";
    char expressao2[] = "7.1 + 2.2 * [4.8 / 2.0)]";
    char expressao3[] = "{5.3 * [6.0 - 2.7]";
    char expressao4[] = "7.8 - (2.3 + 0.9 * 4.0]";
    char expressao5[] = "[8.4 + 1.0 - {2.5 / 5.0)]";
    char expressao6[] = "3.14 * {5.6 + 2.1}";
    char expressao7[] = "[7.1 + 2.2 * 4.8 / 2.0]";
    char expressao8[] = "5.3 * (6.0 - 2.7}}";
    char expressao9[] = "(7.8 - 2.3 + 0.9) * 4.0";
    char expressao10[] = "{8.4 + [1.0 - 2.5] / 5.0";
    
    printf("%s \n", expressao1);    
    if (verificar_expressao_pilha_estatica(expressao1))
        printf("Expressao 1 esta balanceada\n\n");
    else
        printf("Expressao 1 nao esta balanceada\n\n");

    printf("%s \n", expressao2);    
    if (verificar_expressao_pilha_estatica(expressao2))
        printf("Expressao 2 esta balanceada\n\n");
    else
        printf("Expressao 2 nao esta balanceada\n\n");

    printf("%s \n", expressao3);    
    if (verificar_expressao_pilha_estatica(expressao3))
        printf("Expressao 3 esta balanceada\n\n");
    else
        printf("Expressao 3 nao esta balanceada\n\n");

    printf("%s \n", expressao4);    
    if (verificar_expressao_pilha_estatica(expressao4))
        printf("Expressao 4 esta balanceada\n\n");
    else
        printf("Expressao 4 nao esta balanceada\n\n");

    printf("%s \n", expressao6);    
    if (verificar_expressao_pilha_estatica(expressao6))
        printf("Expressao 6 esta balanceada\n\n");
    else
        printf("Expressao 6 nao esta balanceada\n\n");

    printf("%s \n", expressao7);    
    if (verificar_expressao_pilha_estatica(expressao7))
        printf("Expressao 7 esta balanceada\n\n");
    else
        printf("Expressao 7 nao esta balanceada\n\n");

    printf("%s \n", expressao8);    
    if (verificar_expressao_pilha_estatica(expressao8))
        printf("Expressao 8 esta balanceada\n\n");
    else
        printf("Expressao 8 nao esta balanceada\n\n");

    printf("%s \n", expressao9);    
    if (verificar_expressao_pilha_estatica(expressao9))
        printf("Expressao 9 esta balanceada\n\n");
    else
        printf("Expressao 9 nao esta balanceada\n\n");

    printf("%s \n", expressao10);    
    if (verificar_expressao_pilha_estatica(expressao10))
        printf("Expressao 10 esta balanceada\n\n");
    else
        printf("Expressao 10 nao esta balanceada\n\n");

    return 0;
}
