#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

//estrutura pilha com alocacao dinamica (no da pilha)
typedef struct noPilha{
    char caracter;
    struct noPilha* proximo;
} NoPilha;

//estrutura pilha com alocacao dinamica (pilha)
typedef struct {
    NoPilha* inicio;
} Pilha;

Pilha* criar_pilha();

void empilhar(Pilha *p, char v);

char desempilhar(Pilha *p);

// desaloca a pilha e todos os seus nos da memoria
void desalocar_pilha(Pilha** p);

// funcao para verificar expressao usando a pilha dinamica;
int verificar_expressao_pilha_dinamica(char expressao[]);

//funcao auxiliar que printa o resultado da verificao da expressao
void printar_resultado (int boolean);

#endif
