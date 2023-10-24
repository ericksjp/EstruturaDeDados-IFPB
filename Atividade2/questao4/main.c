#include <stdio.h>
#include <stdlib.h>
#include "./FilaCircular.h"

int main(void) {
    Fila* fila = inicializarFilaCircular();
    
    // enfileirar funcionarios
    enfileirarFilaCircular(fila, "Erick", FUNCIONARIO);
    enfileirarFilaCircular(fila, "San Tropero", COORDENADOR);
    enfileirarFilaCircular(fila, "Pink", FUNCIONARIO);
    enfileirarFilaCircular(fila, "Jorge", FUNCIONARIO);
    enfileirarFilaCircular(fila, "Madruga", DIRETOR);

    // imprimir a fila
    printf("Fila para imprimir papel:\n");
    imprimeFila(fila);

    // desenfileirar funcionarios
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);

    // imprimir a fila apos desenfileirar
    printf("\nFila após 2 funcionarios serem atendidos:\n");
    imprimeFila(fila);

    // enfileirar funcionarios
    enfileirarFilaCircular(fila,"Mohamed", DIRETOR);
    enfileirarFilaCircular(fila,"Ze", COORDENADOR);
    enfileirarFilaCircular(fila,"Jack", FUNCIONARIO);
    enfileirarFilaCircular(fila,"Mario", COORDENADOR);
    enfileirarFilaCircular(fila,"Francisco", FUNCIONARIO);
    enfileirarFilaCircular(fila,"Augusto", DIRETOR);
    enfileirarFilaCircular(fila,"Sid Barreto", FUNCIONARIO);

    // imprimir a fila
    printf("\nFila apos 7 novos funcionarios entrarem na fila:\n");
    imprimeFila(fila);

    // desenfileirar funcionarios
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);
    desenfileirarFilaCircular(fila);

    // imprimir a fila apos desenfileirar
    printf("\nFila apos 8 funcionarios serem atendidos:\n");
    imprimeFila(fila);

    // Liberar a memória alocada para a fila
    free(fila);

    return 0;
}

