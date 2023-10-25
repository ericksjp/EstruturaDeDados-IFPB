#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX 50
#define arquivoCSV "./arquivo.csv"

typedef char Id[7];

typedef struct funcionario{
    Id id;
    char nome[51];
    char cargo[51];
    float salario;
} Funcionario;

int quantidadeAtual;

//vetor estatica que vai guardar os funcionarios;
Funcionario vetorFuncionarios[MAX];

// -------------------------------------------------------------------------------------------------------------------------------
void interface_principal();
void lerDoArquivo();

int main() {
    lerDoArquivo();
    interface_principal();
    return 0;
}
// -------------------------------------------------------------------------------------------------------------------------------
void interface_cadastro();
void interface_remocao ();
void interface_busca();
void interface_ordenacao();

void limparBuffer();
void pausarPrograma();
int validarNome(char nome[]);
void bubbleSort(int ordem, int criterio);
void gerarIdValido(Id id);
void to_lower(char string[]);
void monitorarEncerramento();
int adicionarFuncionario(Id id, char nome[], char cargo[], float salario);
void listarFuncionarios();
void salvarEmArquivo();
int removerFuncionario(char key[]);
void listarFuncionario(Funcionario funcionario);
Funcionario* buscarFuncionarios(int criterio, int *quantidade, char key[]);
int stricmp(const char s1[], const char s2[]);
int monitorEncerramento = 0;
// ------------------------------------------------------------------------------------------------------------------------------
void interface_principal() {
    int opcao;    // Vari vel para armazenar a op  o escolhida pelo usu rio.

    // Loop principal que exibe o menu e permite que o usu rio escolha as opera  es.
    while (1) {
        system("cls || clear");
        printf("--- SISTEMA DE GERENCIAMENTO DE FUNCIONARIOS (Sem Tad)---\n");
        printf("--- Funcionarios cadastrados: (%d/%d)\n",quantidadeAtual,MAX);
        printf("---------------------------------------------\n");

        // Exibe o menu de opcoes.
        printf("Escolha uma das Opcoes disponiveis:\n");
        printf("    1. Interface de Cadastro\n");
        printf("    2. Interface de Remocao\n");
        printf("    3. Interface de Busca\n");
        printf("    4. Interface de ordenacao\n");
        printf("    5. Listar Funcionarios\n");
        printf("    6. Persistir informacoes no Banco de Dados\n");
        printf("    7. Encerrar aplicacao\n");

        printf("--> ");

        // L  a op  o escolhida pelo usu rio.
        if (scanf("%d", &opcao) == 0 || (opcao < 0 || opcao > 7)) {
            monitorarEncerramento();
            printf("--- Input invalido. Tente novamente...");
            limparBuffer();
            pausarPrograma();
            system("cls || clear");
        } else {
            // Executa a opera  o correspondente   op  o escolhida pelo usu rio.
            switch (opcao) {
                case 1:
                    interface_cadastro();
                    break;
                case 2:
                    interface_remocao();
                    break;
                case 3:
                    interface_busca();
                    break;
                case 4:
                    interface_ordenacao();
                    break;
                case 5:
				{
                    system("cls || clear");
                    printf("--- Listagem de Funcionarios (%d/%d):\n", quantidadeAtual,MAX);
                    listarFuncionarios();
                    printf("---------------------------------------------\n");
                    limparBuffer();
                    printf("--- Pressiona uma tecla para continuar...");
                    pausarPrograma();
                    break;
                }
				case 6:
				{
                    salvarEmArquivo();
                    printf("\nInformacoes atualizadas no banco de dados.\n");
                    printf("--- Pressiona uma tecla para continuar...");
                    limparBuffer();
                    pausarPrograma();
            		system("cls || clear");
                    break;
                }
				case 7:
                    printf("\nAplicacao encerrada.\n");
                    return;
            }
        }
    }
}
// -------------------------------------------------------------------------------------------------------------------------------
void interface_cadastro() {
    system("cls || clear"); // Limpa a tela para uma apresenta  o mais limpa.
    limparBuffer();  // Limpa o buffer de entrada de teclado.

    if (quantidadeAtual == MAX){
            printf("             --- PAGINA DE CADASTRO ---\n");
            printf("--- Vetor Cheio (%d/%d)! Nao eh possivel registrar novos funcionarios.\n", quantidadeAtual,MAX);
            printf("--- Pressione qualquer tecla para voltar ao menu principal...");
            pausarPrograma();
            return;
    }

    // Loop principal que exibe o menu e permite que o usu rio inpute os dados.
    while (1) {
        printf("             --- PAGINA DE CADASTRO ---\n");

        char nome[51] = "";
        char cargo[51] = "";
        float salario = 0;

        printf("Informe o nome do Funcionario: ");
        scanf("%50[^\n]", nome);

        // Verifica se o nome informado   v lido.
        if (validarNome(nome) == 0) {
            monitorarEncerramento();
            limparBuffer();
            printf("--- Input invalido. Tente novamente...");
            pausarPrograma();
            system("cls || clear");
            continue;
        }

        limparBuffer();

        printf("Informe o cargo do Funcionario: ");
        scanf("%50[^\n]", cargo);

        // Verifica se o cargo informado   v lido.
        if (validarNome(cargo) == 0) {
            monitorarEncerramento();
            limparBuffer();
            printf("--- Input invalido. Tente novamente...");
            pausarPrograma();
            system("cls || clear");
            continue;
        }

        limparBuffer();

        // Verifica se o sal rio informado   valido.
        printf("Informe o salario do Funcionario: ");
        if (scanf("%f", &salario) == 0 || salario < 1) {
            monitorarEncerramento();
            limparBuffer();
            printf("--- Input invalido. Tente novamente...");
            pausarPrograma();
            system("cls || clear");
            continue;
        }

        Id id;
        gerarIdValido(id);

        // Insere o novo funcion rio na vetor.
        adicionarFuncionario(id, nome, cargo, salario);

        printf("--- Funcionario cadastrado com sucesso [id %s] ---\n", id);
        printf("Pressione qualquer tecla para voltar ao menu principal...");
        limparBuffer();
        pausarPrograma();
        break;
    }
}
// -------------------------------------------------------------------------------------------------------------------------------
void interface_remocao(){
    limparBuffer();
    system("cls || clear"); // Limpa a tela para uma apresenta  o mais limpa.

    printf("             --- INTERFACE DE REMOCAO ---\n");

    // verifica se h  funcionarios na lista;
    if (quantidadeAtual == MAX) {
        printf("        --- Nao ha funcionarios Registrados. ---\nPressione qualquer tecla para voltar ao menu principal...");
        pausarPrograma();
    } else {
        char key[51];
        printf("Informe o Nome ou o ID do funcionario que deseja remover: ");
        scanf("%50[^\n]", key);

        printf("%d \n", strcmp(key,vetorFuncionarios[0].nome));

        //Verifica se o usuario existe
        if (removerFuncionario(key)) {
            printf("\n%s foi removido com sucesso.\n", key);
        } else {
            printf("\n--- O funcionario de Nome ou Id %s nao foi encontrado no sistema.\n\n", key);
        }

        printf("Pressione qualquer tecla para voltar ao menu principal...");
        limparBuffer();
        pausarPrograma();
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
void interface_busca(){
    system("cls || clear"); // Limpa a tela para uma apresenta  o mais limpa.
    limparBuffer();  // Limpa o buffer de entrada de teclado.
    int opcao;

    // Loop principal que exibe o menu e permite que o usu rio inpute os dados.
    while (1) {
        printf("             --- INTERFACE DE BUSCA ---\n");
        printf("---------------------------------------------\n");
        if (quantidadeAtual == 0) {
            printf("        --- Nao ha funcionarios Registrados. ---\nPressione qualquer tecla para voltar ao menu principal...");
            pausarPrograma();
            return;
        }

        printf("Escolha uma das Opcoes disponiveis:\n");

        printf("    1. Buscar Funcionario(s) por Salario;\n");
        printf("    2. Buscar Funcionario(s) por Nome;\n");
        printf("    3. Buscar Funcionario(s) por Cargo;\n");
        printf("    4. Buscar Funcionario(s) por ID;\n");
        printf("    5. Voltar ao menu principal\n");

        printf("--> ");
        if (scanf("%d", &opcao) == 0 || (opcao < 1 && opcao > 5)){
            monitorarEncerramento();
            limparBuffer();
            printf("--- Input invalido. Tente novamente...");
            pausarPrograma();
            system("cls || clear");
            continue;
        } else if (opcao == 5){
            return;
        }else{
            char key[51];
            printf("\nInforme a chave da busca de acordo com a sua opcao de busca -> ");
            limparBuffer();
            pausarPrograma();
            scanf("%51[^\n]", key);

            int quantidade  = 0;
            Funcionario *encontrados = buscarFuncionarios(opcao, &quantidade, key);

            system("cls || clear");
            printf("--- Funcionarios encontrados com a key \"%s\"\n",key);
            printf("---------------------------------------------\n");
            if (encontrados == NULL){
                printf("                     NONE\n");
                printf("---------------------------------------------\n");
            }else{
                int i;
                for (i = 0; i < quantidade; i++){
                    listarFuncionario(encontrados[i]);
                    printf("---------------------------------------------\n");
                }
                free(encontrados);
            }
        }
        limparBuffer();
        printf("Pressione qualquer botao para voltar ao menu...");
        pausarPrograma();
        system("cls || clear");
    }
}

// -------------------------------------------------------------------------------------------------------------------------------

void interface_ordenacao(){
    limparBuffer();
    system("cls || clear");
    printf("             --- INTERFACE DE ORDENACAO ---\n");
    printf("---------------------------------------------\n");
    printf("Escolha uma das opcoes disponiveis: \n");
    printf("    1. Ordenar por ID (crescente);\n");
    printf("    2. Ordenar por ID (decrescente);\n");
    printf("    3. Ordenar por Nome (crescente);\n");
    printf("    4. Ordenar por Nome (decrescente);\n");
    printf("    5. Ordenar por Cargo (crescente);\n");
    printf("    6. Ordenar por Cargo (decrescente);\n");
    printf("    7. Ordenar por Salario (crescente);\n");
    printf("    8. Ordenar por Salario (decrescente);\n");
    printf("    Outro. Voltar ao menu principal;\n");
    printf("--> ");

    int opcao; // Vari vel para armazenar a op  o escolhida pelo usu rio.

    if (scanf("%d", &opcao) == 0 || (opcao < 0 || opcao > 8)) {
        printf("--- Pressione uma tecla para continuar...");
        limparBuffer();
        pausarPrograma();
        system("cls || clear");
    } else {
        switch (opcao) {
            case 1:
            {
                printf("\n--- Vetor ordenado por ID em ordem crescente!\n");
                bubbleSort(1, 4);
                break;
            }
            case 2:
            {
                printf("\n--- Vetor ordenado por ID em ordem decrescente!\n");
                bubbleSort(-1, 4);
                break;
            }
            case 3:
            {
                printf("\n--- Vetor ordenado por Nome em ordem crescente!\n");
                bubbleSort(1, 2);
                break;
            }
            case 4:
            {
                printf("\n--- Vetor ordenado por Nome em ordem decrescente!\n");
                bubbleSort(1, 2);
                break;
            }
            case 5:
            {
                printf("\n--- Vetor ordenado por Cargo em ordem crescente!\n");
                bubbleSort(1, 3);
                break;
            }
            case 6:
            {
                printf("\n--- Vetor ordenado por Cargo em ordem decrescente!\n");
                bubbleSort(-1, 3);
                break;
            }
            case 7:
            {
                printf("\n--- Vetor ordenado por Salario em ordem crescente!\n");
                bubbleSort(1, 1);
                break;
            }
            case 8:
            {
                printf("\n--- Vetor ordenado por Salario em ordem decrescente!\n");
                bubbleSort(-1, 1);
                break;
            }
            default:
                break;
        }

        limparBuffer();
        printf("--- Pressiona uma tecla para continuar...");
        pausarPrograma();
        system("cls || clear");
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
Funcionario criarFuncionario(Id id, char nome[], char cargo[], float salario) {
    Funcionario novo;
    strcpy(novo.id, id);
    strcpy(novo.nome, nome);
    strcpy(novo.cargo, cargo);
    novo.salario = salario;
    return novo;
}

int adicionarFuncionario(Id id, char nome[], char cargo[], float salario) {
    if (quantidadeAtual < MAX) {
        Funcionario novoFuncionario = criarFuncionario(id, nome, cargo, salario);

        int posicaoInsercao = 0;
        while (posicaoInsercao < quantidadeAtual && strcmp(novoFuncionario.nome, vetorFuncionarios[posicaoInsercao].nome) > 0) {
            posicaoInsercao++;
        }

        int i;
        for (i = quantidadeAtual; i > posicaoInsercao; i--) {
            vetorFuncionarios[i] = vetorFuncionarios[i - 1];
        }

        vetorFuncionarios[posicaoInsercao] = novoFuncionario;
        quantidadeAtual++;
        return 1;
    } else {
        printf("Error: Vetor cheio\n");
        return 0;
    }
}

Funcionario *buscarFuncionarios(int criterio, int *quantidade, char key[])
{
    Funcionario *encontrados = NULL;
    if (criterio > 0 && criterio < 5){
        char search_key[51];
        if (criterio == 1){
            strcpy(search_key, key);
            sprintf(search_key, "%f", atof(key));
        } else if (criterio == 2 || criterio == 3){
            strcpy(search_key, key);
            to_lower(search_key);
        }

        int i;
        int contador = 0;
        for (i = 0; i < quantidadeAtual; i++){
            switch (criterio){
                case 1:
                { // buscar por salario
                    char salarioString[51];
                    sprintf(salarioString, "%f", vetorFuncionarios[i].salario);
                    if (stricmp(search_key, salarioString) == 0){
                        encontrados = (Funcionario *)realloc(encontrados, (i + 1) * sizeof(Funcionario));
                        encontrados[contador] = vetorFuncionarios[i];
                        contador++;
                    }
                    break;
                }
                case 2:
                { // buscar por nome;
                    if (stricmp(search_key, vetorFuncionarios[i].nome) == 0) {
                        encontrados = (Funcionario *)realloc(encontrados, (i + 1) * sizeof(Funcionario));
                        encontrados[contador] = vetorFuncionarios[i];
                        contador++;
                    }
                    break;
                }
                case 3: { // buscar por cargo;
                    if (stricmp(search_key, vetorFuncionarios[i].cargo) == 0){
                        encontrados = (Funcionario *)realloc(encontrados, (i + 1) * sizeof(Funcionario));
                        encontrados[contador] = vetorFuncionarios[i];
                        contador++;
                    }
                    break;
                }
                case 4:
                { // buscar por id;
                    if (stricmp(key, vetorFuncionarios[i].id) == 0) {
                        encontrados = (Funcionario *)realloc(encontrados, (i + 1) * sizeof(Funcionario));
                        encontrados[contador] = vetorFuncionarios[i];
                        *quantidade = 1;
                        return encontrados;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        *quantidade = contador;
    }
    return encontrados;
}

int removerFuncionario(char key[]) {
    int i;
    for (i = 0; i < quantidadeAtual; i++) {
        if (strcmp(key,vetorFuncionarios[i].nome) == 0 || strcmp(key, vetorFuncionarios[i].id) == 0) {
            int j;
            for (j = i; j < quantidadeAtual - 1; j++) {
                vetorFuncionarios[j] = vetorFuncionarios[j + 1];
            }
            quantidadeAtual--;
            return 1;
        }
    }
    return 0;
}
// -------------------------------------------------------------------------------------------------------------------------------
void listarFuncionario(Funcionario funcionario) {
    printf("ID: %s\n", funcionario.id);
    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: R$ %.2f\n", funcionario.salario);
}

void listarFuncionarios() {
    int i;
    for (i = 0; i < quantidadeAtual; i++) {
        printf("---------------------------------------------\n");
        listarFuncionario(vetorFuncionarios[i]);
    }
}
// -------------------------------------------------------------------------------------------------------------------------------

// * Ordena um vetor de funcionários com base na ordem e criterio passados como parametro usando o algoritmo Bubble Sort.
void bubbleSort(int ordem, int criterio) {
    int i, j;
    Funcionario aux;
    int comparador;

    for (i = 0; i < quantidadeAtual - 1; i++) {
        for (j = 0; j < quantidadeAtual - i - 1; j++) {
            switch (criterio) {
                case 1: // ordenacao por salario
                    comparador = ordem * (vetorFuncionarios[j].salario - vetorFuncionarios[j + 1].salario);
                    break;
                case 2: // ordenacao por nome
                    comparador = ordem * strcmp(vetorFuncionarios[j].nome, vetorFuncionarios[j + 1].nome);
                    break;
                case 3: // ordenacao por cargo
                    comparador = ordem * strcmp(vetorFuncionarios[j].cargo, vetorFuncionarios[j + 1].cargo);
                    break;
                case 4: // ordenacao por ID
                    comparador = ordem * strcmp(vetorFuncionarios[j].id, vetorFuncionarios[j + 1].id);
                    break;
            }

            if (comparador > 0) {
                aux = vetorFuncionarios[j];
                vetorFuncionarios[j] = vetorFuncionarios[j + 1];
                vetorFuncionarios[j + 1] = aux;
            }
        }
    }
}
// -------------------------------------------------------------------------------------------------------------------------------
void salvarEmArquivo() {
    FILE *arquivo = fopen(arquivoCSV, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    int i;
    for (i = 0; i < quantidadeAtual; i++) {
        fprintf(arquivo, "%s,%s,%s,%.2f\n", vetorFuncionarios[i].id, vetorFuncionarios[i].nome, vetorFuncionarios[i].cargo, vetorFuncionarios[i].salario);
    }

    fclose(arquivo);
}

/*Fun��o pra pegar os dados do csv e colocar no vetor*/
void lerDoArquivo(){
    FILE *arquivo = fopen(arquivoCSV, "r");
    char linha[1001];

    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    int i;
    for (i = 0; i < MAX; i++){
        if (fgets(linha, sizeof(linha), arquivo) != NULL){
            if (sscanf(linha, "%10[^,],%50[^,],%50[^,],%f", vetorFuncionarios[i].id, vetorFuncionarios[i].nome, vetorFuncionarios[i].cargo, &vetorFuncionarios[i].salario) != 4){
                printf("\n--- Erro na linha %d do arquivo CSV, corrija-o. ---\n", i + 1);
                exit(1);
            }
            quantidadeAtual++;
        }
        else{
            break;
        }
    }

    fclose(arquivo);
}
// -------------------------------------------------------------------------------------------------------------------------------
void gerarIdValido(Id id) {
    srand(time(NULL));

    int i;
    while (1){
        for (i = 0; i < 6; i++) {
            int random_number = rand() % 10;
            char numero_string[2];
            sprintf(numero_string, "%d", random_number);
            numero_string[1] = '\n';
            id[i] = numero_string[0];
        }
        id[6] = '\0';

        for (i = 0; i < quantidadeAtual; i++){
            if (strcmp(id,vetorFuncionarios[i].id) == 0){
                continue;
            }
        }
        break;
    }
}

void monitorarEncerramento() {
    monitorEncerramento++;
    if (monitorEncerramento >= 5) {
        printf("Encerrando aplicacao por motivos de seguranca.\n");
        exit(1);
    }
}

int validarNome(char nome[]){
    int len = strlen(nome);

    if (len < 3){
        return 0;
    }

	int c;
    for (c = 0; c < len; c++){
        if (nome[c] == ',' || (isalpha(nome[c]) > 0 && isblank(nome[c]) > 0)){
            return 0;
        }
    }
    return 1;
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

void limparBuffer() {
    if (stdin != NULL) {
        int limpador = '0';
        while (limpador != EOF && limpador != '\n')
            limpador = getchar();
    }
}


#if defined(_WIN32) || defined(_WIN64)
	#include <conio.h>
	#include <windows.h>

	void pausarPrograma(){
		getch();
	}

#else
	#include <termios.h>
	#include <unistd.h>

	void pausarPrograma(){
	    struct termios terminal;

	    tcgetattr(STDIN_FILENO, &terminal);
	    terminal.c_lflag &= ~(ICANON | ECHO);
	    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);

		getchar();

	    terminal.c_lflag |= (ICANON | ECHO);
	    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
	}
#endif
