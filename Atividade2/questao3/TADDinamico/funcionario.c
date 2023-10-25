#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "./funcionario.h"

Lista* cria_lista(){
    return NULL;
}

static void checkAlocacaoMemoria(void *alocacao) {
    if (alocacao == NULL) {
        perror("Erro: Falha na alocacao de memoria.");
        exit(1);
    }
}

Lista *inicializa(void) {
    return NULL;
}

Funcionario criarFuncionario(Id id, char nome[], char cargo[], float salario) {
    Funcionario novo;
    strcpy(novo.id, id);
    strcpy(novo.nome, nome);
    strcpy(novo.cargo, cargo);
    novo.salario = salario;
    return novo;
}

Lista* inserir(Lista *l, Funcionario funcionario) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    checkAlocacaoMemoria(novo);

    novo->data = funcionario;
    novo->prox = l;

    return novo;
}

Lista* removerFuncionario(Lista* l, char key[]) {
    Lista* anterior = NULL;
    Lista* atual = l;

    while (atual != NULL) {
        if (strcmp(atual->data.id, key) == 0 || strcmp(atual->data.nome, key) == 0) {
            if (anterior == NULL) {
                Lista* aux = atual;
                atual = atual->prox;
                free(aux);
            } else {
                anterior->prox = atual->prox;
                free(atual);
            }
            return l;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return l;
}

// ------------------------------------------------------------------------------------------------------------------------------------

void to_lower(char string[]);
int stricmp(const char s1[], const char s2[]);

Lista* buscarFuncionarios(Lista l, int criterio, char key[]){
    Lista* encontrados = cria_lista();

    if (criterio > 0 && criterio < 5){
        char search_key[51];
        if (criterio == 1){
            strcpy(search_key, key);
            sprintf(search_key, "%f", atof(key));
        } else if (criterio == 2 || criterio == 3){
            strcpy(search_key,key);
            to_lower(search_key);   
        }

        Lista* i;
        for (i = &l; i != NULL; i = i->prox){
            switch (criterio){
                case 1:
                { // buscar por salario
                    char salarioString[51];
                    sprintf(salarioString, "%f", i->data.salario);
                    if (stricmp(search_key, salarioString) == 0)
                    {
                        encontrados = inserir(encontrados, i->data);
                    }
                    break;
                }
                case 2:
                { // buscar por nome;
                    if (stricmp(search_key, i->data.nome) == 0)
                    {
                        encontrados = inserir(encontrados, i->data);
                    }
                    break;
                }
                case 3:
                { // buscar por cargo;
                    if (stricmp(search_key, i->data.cargo) == 0)
                    {
                        encontrados = inserir(encontrados, i->data);
                    }
                    break;
                }
                case 4:
                { // buscar por id;
                    if (stricmp(key, i->data.id) == 0)
                    {
                        encontrados = inserir(encontrados, i->data);
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

void listarFuncionarios(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p -> prox) {
        printf("---------------------------------------------\n");
        listarFuncionario(p->data);
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------

void troca(Lista* a, Lista* b) {
    Funcionario temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Lista* l, int ordem, int criterio) {
    Lista* atual = NULL;
    int comparador;

    while (l) {
        atual = l->prox;

        while (atual) {
            switch (criterio) {
                case 1: // ordenacao por salario
                    comparador = ordem * (l->data.salario - atual->data.salario);
                    break;
                case 2: // ordenacao por nome
                    comparador = ordem * strcmp(l->data.nome, atual->data.nome);
                    break;
                case 3: // ordenacao por cargo
                    comparador = ordem * strcmp(l->data.cargo, atual->data.cargo);
                    break;
                case 4: // ordenacao por ID
                    comparador = ordem * strcmp(l->data.id, atual->data.id);
                    break;
                
            }
            if (comparador > 0) {
                troca(l, atual);
            }
            atual = atual->prox;
        }
        l = l->prox;
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------

/*Funcao pra pegar os dados do csv e colocar no vetor*/
void salvarNoArquivo(Lista* l, char arquivoCSVLink[]) {
    FILE *arquivo = fopen(arquivoCSVLink, "w"); 

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        fprintf(arquivo, "%s,%s,%s,%.2f\n", p->data.id, p->data.nome, p->data.cargo, p->data.salario);
    }

    fclose(arquivo);
}

/*Funcao pra pegar os dados do csv e colocar no vetor*/
Lista* lerDoArquivo(Lista* l, char arquivoCSVLink[]){
    FILE *arquivo = fopen(arquivoCSVLink, "r");
    char linha[1001];

    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    int i = 0;
    Funcionario aux;
    while(1) {
        if (fgets(linha, sizeof(linha), arquivo) != NULL){
            Id id;
            char nome[51];
            char cargo[51];
            float salario;
            if (sscanf(linha, "%7[^,],%50[^,],%50[^,],%f", id, nome,cargo, &salario) != 4){
                printf("\n--- Erro na linha %d do arquivo CSV, corrija-o. ---\n", i + 1);
                exit(1);
            }
            aux = criarFuncionario(id,nome,cargo,salario);
            l = inserir(l, aux);
        } else{
            break;
        }
        i++;
    }

    fclose(arquivo);
    return l;
}

// ------------------------------------------------------------------------------------------------------------------------------------

void desalocarMemoria(Lista** l){
    Lista* p = *l;
    while (p != NULL){
        Lista* temp = p;
        p = p -> prox;
        free(temp);
    }
}

int tamanho(Lista* l){
    int i = 0;
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        i++;
    return i;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void monitorarEncerramento(int *encerrar) {
    (*encerrar)++;
    if (*encerrar >= 5) {
        printf("Encerrando a aplica��o por motivos de seguran�a.\n");
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

void gerarIdValido(Lista* l, Id id) {
    srand(time(NULL));

    int i;
    Lista* p;
    while (1) {
        for (i = 0; i < 6; i++) {
            int random_number = rand() % 10;
            char numero_string[2];
            sprintf(numero_string, "%d", random_number);
            numero_string[1] = '\0';
            id[i] = numero_string[0];
        }
        id[6] = '\0';

        for (p = l; p != NULL; p = p->prox) {
            if (strcmp(id, p->data.id) == 0) {
                continue;
            }
        }
        break;
    }
}

void to_lower(char string[]) {
    int len = strlen(string);
    int i;
    for (i = 0; i < len; i++) {
        string[i] = tolower(string[i]);
    }
}

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
