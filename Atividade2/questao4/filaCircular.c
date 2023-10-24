#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./FilaCircular.h"

Fila* inicializarFilaCircular(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL){
        printf("-----!!! Error: Memoria insuficiente\n");
        exit(1);
    }
    fila -> inicio = 0;
    fila -> fim = -1;
    fila -> qtdade = 0;
    return fila;
}

int nova_posicao(int posicao){
    return (posicao + 1) % TAMANHO;
}

int decrementar_posicao(int pos){
    if (pos - 1 < 0)
        return TAMANHO - 1;
    return pos - 1;
}

int enfileirarFilaCircular(Fila* f, char name[], Cargo cargo){

    if (f->qtdade == TAMANHO){
        printf("-------- Erro ao inserir %s: A fila esta cheia\n", name);
        return 0;
    }
    f -> fim = nova_posicao(f -> fim);
    int posicao = f->fim;

    // a magica da prioridade;
    while (posicao != f -> inicio && cargo < f -> vetor[decrementar_posicao(posicao)].cargo){
        f->vetor[posicao] = f->vetor[decrementar_posicao(posicao)];
        posicao = decrementar_posicao(posicao);
    }

    f -> vetor[posicao].cargo = cargo;
    strcpy(f -> vetor[posicao].nome,name);
    f -> qtdade++;
    return 1;
}

Funcionario* desenfileirarFilaCircular(Fila* f){
    if (f -> qtdade == 0){
        printf("-------- Error: A fila esta vazia\n");
        return NULL;
    }
    Funcionario* returnValue = &f -> vetor[f -> inicio];
    f -> inicio = nova_posicao(f -> inicio);
    f -> qtdade--;
    return returnValue;
}

void imprimeFila(Fila* f) {
    if (f->qtdade == 0) {
        printf("-------- Error: A fila esta vazia\n");
        return;
    }
    int posicao = f->inicio;
    int c;
    for (c = 0; c < f -> qtdade; c++){
        printf("%d: %s / ", c + 1, f->vetor[posicao].nome);
        switch (f->vetor[posicao].cargo) {
            case FUNCIONARIO:
                printf("Funcionario\n"); break;
            case COORDENADOR:
                printf("Coordenador\n"); break;
            case DIRETOR:
                printf("Diretor\n"); break;
            default:
                printf("penetra\n");
        }
        posicao = nova_posicao(posicao);
    }
}
