#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcionario.h"
#include "./interface.h"
#define arquivoCSV "./arquivo.csv"

int main() {
    ListaFuncionario lista = cria_lista(50);
    lerDoArquivo(&lista, arquivoCSV);
    interface_aplicacao(&lista, arquivoCSV);
    return 0;
}