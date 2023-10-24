#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./PilhaDinamica.h"

Pilha* criar_pilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL){
        printf("Erro: Memoria Insuficiente");
        exit(1);
    }

    pilha -> inicio = NULL;
    return pilha;
}

void empilhar(Pilha *p, char v){
    NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL){
        printf("Erro: Memoria Insuficiente");
        exit(1);
    }

    novo -> caracter = v;
    novo -> proximo = p -> inicio;
    p -> inicio = novo;
}

char desempilhar(Pilha *p){
    if (p -> inicio == NULL){
        perror("A pilha esta vazia");
        exit(0);
    }
    char v = p->inicio->caracter;
    NoPilha* remove = p -> inicio;
    p -> inicio = p -> inicio -> proximo;
    free(remove);
    return v;
}

// desaloca a pilha e todos os seus nos da memoria
void desalocar_pilha(Pilha** p){
    while ((*p)->inicio != NULL){
        desempilhar(*p);
    }

    free(*p);
    *p = NULL;
}

// funcao para verificar expressao;
int verificar_expressao_pilha_dinamica(char expressao[]){
    int len = strlen(expressao);
    if (len < 2){
        return 0;
    }

    Pilha *p = criar_pilha(); //pilha dinamica;

	int i;
    for (i = 0; i < len; i++){
        if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '['){
            empilhar(p, expressao[i]);
        } 
        else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']'){
            if (p -> inicio == NULL){
                desalocar_pilha(&p);
                return 0;
            } else {
                char caracter = desempilhar(p);
                if ((caracter == '(' && expressao[i] != ')') || (caracter == '{' && expressao[i] != '}') || (caracter == '[' && expressao[i] != ']')){
                    desalocar_pilha(&p);
                    return 0;
                }
            }
        }
    }

    if (p -> inicio != NULL){
        desalocar_pilha(&p);
        return 0;
    }

    desalocar_pilha(&p);
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
