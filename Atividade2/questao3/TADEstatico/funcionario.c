#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "./funcionario.h"

ListaFuncionario cria_lista(int quantidadeMaxima){
    if (quantidadeMaxima > MAX) {
        printf("Erro: A quantidade máxima de funcionários deve ser no máximo %d.\n", MAX);
        exit(1);
    } else if (quantidadeMaxima < 1) {
        printf("Erro: A quantidade mínima de funcionários deve ser pelo menos 1.\n");
        exit(1);
    }

    ListaFuncionario novaLista;
    novaLista.quantidadeAtual = 0;
    novaLista.quantidadeMaxima = quantidadeMaxima;
    return novaLista;
}


Funcionario criarFuncionario(Id id, char nome[], char cargo[], float salario) {
    Funcionario novo;
    strcpy(novo.id, id);
    strcpy(novo.nome, nome);
    strcpy(novo.cargo, cargo);
    novo.salario = salario;
    return novo;
}

int adicionarFuncionario(ListaFuncionario* l, Funcionario funcionario) {
    if (l->quantidadeAtual < l->quantidadeMaxima) {

        int posicaoInsercao = 0;
        while (posicaoInsercao < l->quantidadeAtual && strcmp(funcionario.nome, l->vetor[posicaoInsercao].nome) > 0) {
            posicaoInsercao++;
        }
        
        int i;
        for (i = l->quantidadeAtual; i > posicaoInsercao; i--) {
            l->vetor[i] = l->vetor[i - 1];
        }

        l->vetor[posicaoInsercao] = funcionario;
        l->quantidadeAtual++;
        return 1;
    } else {
        printf("Error: Vetor cheio\n");
        return 0;
    }
}

int removerFuncionario(ListaFuncionario* l,char key[]) {
    int i;
    for (i = 0; i < l->quantidadeAtual; i++) {
        if (strcmp(l->vetor[i].id, key) == 0 || strcmp(l->vetor[i].nome, key)) {
            int j;
            for (j = i; j < l->quantidadeAtual - 1; j++) {
                l->vetor[j] = l->vetor[j + 1];
            }
            l->quantidadeAtual--;
            return 1;
        }
    }
    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------

// funcao auxiliar
void to_lower(char string[]) {
    int len = strlen(string);
    int i;
    for (i = 0; i < len; i++) {
        string[i] = tolower(string[i]);
    }
}

/*funcao auxiliar - strcmp (case insensitive)*/
int stricmp(const char s1[], const char s2[]){
    if (strlen(s1) != strlen(s2)){
        return 1;
    }

    int c;
    for (c = 0 ; c < (int)strlen(s1); c++){
        int c1 = tolower(s1[c]);
        int c2 = tolower(s2[c]);

        if (c1 != c2)
            return 1;
    }
    return 0;
}

ListaFuncionario buscarFuncionarios(ListaFuncionario l, int criterio, char key[]){
    ListaFuncionario encontrados = cria_lista(l.quantidadeMaxima);

    if (criterio > 0 && criterio < 5){
        char search_key[51];
        if (criterio == 1){
            strcpy(search_key, key);
            sprintf(search_key, "%f", atof(key));
        } else if (criterio == 2 || criterio == 3){
            strcpy(search_key,key);
            to_lower(search_key);   
        }

        int i;
        for (i = 0; i < l.quantidadeAtual; i++) {
            switch(criterio){
                case 1:
                { //buscar por salario
                    char salarioString[51];
                    sprintf(salarioString, "%f", l.vetor[i].salario);
                    if (stricmp(search_key, salarioString) == 0) {
                        encontrados.vetor[encontrados.quantidadeAtual] = l.vetor[i];
                        encontrados.quantidadeAtual++;
                    } break;
                }
                case 2:
                { //buscar por nome;
                    if (stricmp(search_key, l.vetor[i].nome) == 0){
                        encontrados.vetor[encontrados.quantidadeAtual] = l.vetor[i];
                        encontrados.quantidadeAtual++;
                    } break;
                }
                case 3:
                { //buscar por cargo;
                    if (stricmp(search_key, l.vetor[i].cargo) == 0){
                        encontrados.vetor[encontrados.quantidadeAtual] = l.vetor[i];
                        encontrados.quantidadeAtual++;
                    } break;
                }
                case 4:
                { //buscar por id;
                    if (stricmp(key, l.vetor[i].id) == 0){
                        encontrados.vetor[encontrados.quantidadeAtual] = l.vetor[i];
                        encontrados.quantidadeAtual++;
                        return encontrados;
                    }
                }
            }
        }
    }
    return encontrados;
}

// ------------------------------------------------------------------------------------------------------------------------------------

void listarFuncionario(Funcionario funcionario) {
    printf("ID: %s\n", funcionario.id);
    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: R$ %.2f\n", funcionario.salario);
}

void listarFuncionarios(ListaFuncionario l) {
    int i;
    for (i = 0; i < l.quantidadeAtual; i++) {
        printf("---------------------------------------------\n");
        listarFuncionario(l.vetor[i]);
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------

void bubbleSort(ListaFuncionario* l, int ordem, int criterio) {
    int i, j;
    Funcionario aux;
    int comparador;

    for (i = 0; i < l->quantidadeAtual - 1; i++) {
        for (j = 0; j < l->quantidadeAtual - i - 1; j++) {
            switch (criterio) {
                case 1: // ordenacao por salario
                    comparador = ordem * (l->vetor[j].salario - l->vetor[j + 1].salario);
                    break;
                case 2: // ordenacao por nome
                    comparador = ordem * strcmp(l->vetor[j].nome, l->vetor[j + 1].nome);
                    break;
                case 3: // ordenacao por cargo
                    comparador = ordem * strcmp(l->vetor[j].cargo, l->vetor[j + 1].cargo);
                    break;
                case 4: // ordenacao por ID
                    comparador = ordem * strcmp(l->vetor[j].id, l->vetor[j + 1].id);
                    break;
            }

            if (comparador > 0) {
                aux = l->vetor[j];
                l->vetor[j] = l->vetor[j + 1];
                l->vetor[j + 1] = aux;
            }
        }
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------

/*Funcao pra pegar os dados do csv e colocar no vetor*/
void salvarNoArquivo(ListaFuncionario l, char arquivoCSVLink[]) {
    FILE *arquivo = fopen(arquivoCSVLink, "w"); 

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    int i;
    for (i = 0; i < l.quantidadeAtual; i++) {
        fprintf(arquivo, "%s,%s,%s,%.2f\n", l.vetor[i].id, l.vetor[i].nome, l.vetor[i].cargo, l.vetor[i].salario);
    }

    fclose(arquivo);
}

/*Funcao pra pegar os dados do csv e colocar no vetor*/
void lerDoArquivo(ListaFuncionario* l, char arquivoCSVLink[]){
    FILE *arquivo = fopen(arquivoCSVLink, "r");
    char linha[1001];

    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    int i;
    for (i = 0; i < l->quantidadeMaxima; i++){
        if (fgets(linha, sizeof(linha), arquivo) != NULL){
            if (sscanf(linha, "%10[^,],%50[^,],%50[^,],%f", l->vetor[i].id, l->vetor[i].nome, l->vetor[i].cargo, &l->vetor[i].salario) != 4){
                printf("\n--- Erro na linha %d do arquivo CSV, corrija-o. ---\n", i + 1);
                exit(1);
            }
            l->quantidadeAtual++;
        }
        else{
            break;
        }
    }

    fclose(arquivo);
}

// ------------------------------------------------------------------------------------------------------------------------------------

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void monitorarEncerramento(int *encerrar) {
    (*encerrar)++;
    if (*encerrar >= 5) {
        printf("Encerrando a aplicação por motivos de segurança.\n");
        exit(1);
    }
}

int validarNome(char nome[]) {
    int len = strlen(nome);

    if (len < 3) {
        return 0;
    }

	int c;
    for (c = 0; c < len; c++) {
        if (nome[c] == ',' || (isalpha(nome[c]) > 0 && isblank(nome[c]) > 0)) {
            return 0;
        }
    }
    return 1;
}

void gerarIdValido(ListaFuncionario l, Id id) {
    srand(time(NULL));

    int i;
    while (1) {
        for (i = 0; i < 6; i++) {
            int random_number = rand() % 10;
            char numero_string[2];
            sprintf(numero_string, "%d", random_number);
            numero_string[1] = '\0';
            id[i] = numero_string[0];
        }
        id[6] = '\0';

        for (i = 0; i < l.quantidadeAtual; i++) {
            if (strcmp(id, l.vetor[i].id) == 0) {
                continue;
            }
        }
        break;
    }
}

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>

void pausarPrograma() {
    getch();
}

#else
#include <termios.h>
#include <unistd.h>

void pausarPrograma() {
    struct termios terminal;

    tcgetattr(STDIN_FILENO, &terminal);
    terminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);

    getchar();

    terminal.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}
#endif
