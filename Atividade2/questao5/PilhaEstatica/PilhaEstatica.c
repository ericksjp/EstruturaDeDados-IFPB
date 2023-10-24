#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./PilhaEstatica.h"
Pilha* criar_pilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL){
        printf("Erro: Memoria Insuficiente");
        exit(1);
    }

    pilha -> n = 0;
    return pilha;
}

void empilha (Pilha *p, char v){
    if (p -> n == MAX){
        perror("Capaciade da pilha estourou");
        exit(1);
    }
    p -> vet[p->n] = v;
    p -> n++;
}

char desempilha(Pilha *p){
    if (p -> n == 0){
        perror("A pilha esta vazia");
        exit(0);
    }
    char v = p->vet[p->n-1];
    p -> n--;
    return v;
}

// funcao para verificar expressoes;
int verificar_expressao_pilha_estatica(char expressao[]){
    int len = strlen(expressao);
    if (len < 2){
        return 0;
    }

    Pilha *p = criar_pilha(); // pilha estatica

	int i;
    for (i = 0; i < len; i++){
        if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '['){
            empilha(p, expressao[i]);
        } 
        else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']'){
            if (p -> n == 0){
                free(p);
                return 0;
            } else {
                char caracter = desempilha(p);
                if ((caracter == '(' && expressao[i] != ')') || (caracter == '{' && expressao[i] != '}') || (caracter == '[' && expressao[i] != ']')){
                    free(p);
                    return 0;
                }
            }
        }
    }

    if (p -> n != 0){
        free(p);
        return 0;
    }
    free(p);
    return 1;
}

//funcao auxiliar que printa o resultado da verificao da expressao
void printar_resultado (int boolean){
    static int contador = 1;
    if (boolean)
        printf("Expressao %d esta balanceada\n", contador);
    else
        printf("Expressao %d nao esta balanceada\n", contador);
    contador++;
}

