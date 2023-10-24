#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H
#define MAX 20

//estrutura pilha com vetor estatico
typedef struct {
    int n;          // elemento para a manipulacao do vetor
    char vet[MAX];  // vetor de caracteres;
} Pilha;

Pilha* criar_pilha();

void empilhar(Pilha *p, char v);

char desempilhar(Pilha *p);

// funcao para verificar expressao usando a pilha dinamica;
int verificar_expressao_pilha_estatica(char expressao[]);

//funcao auxiliar que printa o resultado da verificao da expressao
void printar_resultado (int boolean);

#endif
