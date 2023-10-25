#include "./funcionario.h"
#include "./interface.h"
#define arquivoCSV "./arquivo.csv"

int main() {
    Lista* lista = cria_lista();
    lista = lerDoArquivo(lista, arquivoCSV);
    interface_aplicacao(lista, arquivoCSV);
    return 0;
}