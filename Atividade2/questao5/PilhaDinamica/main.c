#include <stdio.h>
#include "./PilhaDinamica.h"

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
    printar_resultado( verificar_expressao_pilha_dinamica(expressao1) );
    printf("\n%s \n", expressao2);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao2) );
    printf("\n%s \n", expressao3);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao3) );
    printf("\n%s \n", expressao4);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao4) );
    printf("\n%s \n", expressao5);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao5) );
    printf("\n%s \n", expressao6);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao6) );
    printf("\n%s \n", expressao7);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao7) );
    printf("\n%s \n", expressao8);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao8) );
    printf("\n%s \n", expressao9);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao9) );
    printf("\n%s \n", expressao10);        
    printar_resultado( verificar_expressao_pilha_dinamica(expressao10) );
    return 0;
}
