#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcionario.h"
#include "./interface.h"

// marcando as funcoes que nao vao ser exportadas com static

static void interface_cadastro(Lista** l);
static void interface_remocao (Lista** l);
static void interface_busca(Lista* l);
static void interface_ordenacao(Lista** l);

void interface_aplicacao(Lista* l, char csvLink[]) {
    int opcao;    // Variavel para armazenar a opcao escolhida pelo usuario.
    int monitorEncerramento = 0;

    // Loop principal que exibe o menu e permite que o usu rio escolha as operacoes.
    while (1) {
        int tam = tamanho(l);
        system("cls || clear");
        printf("--- SISTEMA DE GERENCIAMENTO DE FUNCIONARIOS --- (Tad Dinamico)\n");
        printf("--- Funcionarios cadastrados: (%d)\n", tam);
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
            monitorarEncerramento(&monitorEncerramento);
            printf("--- Input invalido. Tente novamente...");
            limparBuffer();
            pausarPrograma();
            system("cls || clear");
        } else {
            // Executa a opera  o correspondente   op  o escolhida pelo usu rio.
            switch (opcao) {
                case 1:
                    interface_cadastro(&l);
                    break;
                case 2:
                    interface_remocao(&l);
                    break;
                case 3:
                    interface_busca(l);
                    break;
                case 4:
                    interface_ordenacao(&l);
                    break;
                case 5:
                {
                    system("cls || clear");
                    printf("--- Listagem de Funcionarios (%d):\n", tam);
                    listarFuncionarios(l);
                    printf("---------------------------------------------\n");
                    limparBuffer();
                    printf("--- Pressiona uma tecla para continuar...");
                    pausarPrograma();
                    break;
                }
                case 6:
                {
                    salvarNoArquivo(l, csvLink);
                    printf("\nInformacoes atualizadas no banco de dados.\n");
                    printf("--- Pressiona uma tecla para continuar...");
                    limparBuffer();
                    pausarPrograma();
            		system("cls || clear");
                    break;
                }
                case 7:
                {
                    printf("\nAplicacao encerrada.\n");
                    return;
                }
            }
        }
    }
}

// -------------------------------------------------------------------------------------------------------------------------------

static void interface_cadastro(Lista** l) {
    system("cls || clear"); // Limpa a tela para uma apresenta  o mais limpa.
    limparBuffer();  // Limpa o buffer de entrada de teclado.
    int monitorEncerramento = 0;

    // Loop principal que exibe o menu e permite que o usu rio inpute os dados.
    while (1) {
        printf("             --- INTERFACE DE CADASTRO ---\n");

        char nome[51] = "";
        char cargo[51] = "";
        float salario = 0;

        printf("Informe o nome do Funcionario: ");
        scanf("%50[^\n]", nome);

        // Verifica se o nome informado   v lido.
        if (validarNome(nome) == 0) {
            monitorarEncerramento(&monitorEncerramento);
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
            monitorarEncerramento(&monitorEncerramento);
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
            monitorarEncerramento(&monitorEncerramento);
            limparBuffer();
            printf("--- Input invalido. Tente novamente...");
            pausarPrograma();
            system("cls || clear");
            continue;
        }

        Id id;
        gerarIdValido(*l, id);
        Funcionario novoFuncionaro = criarFuncionario(id, nome, cargo, salario);

        // Insere o novo funcion rio na vetor.
        *l = inserir(*l, novoFuncionaro);

        printf("--- Funcionario cadastrado com sucesso [id %s] ---\n", id);
        printf("Pressione qualquer tecla para voltar ao menu principal...");
        limparBuffer();
        pausarPrograma();
        break;
    }
}

// -------------------------------------------------------------------------------------------------------------------------------

static void interface_remocao(Lista** l){
    limparBuffer();
    system("cls || clear"); // Limpa a tela para uma apresenta  o mais limpa.

    printf("             --- INTERFACE DE REMOCAO ---\n");

    // verifica se h  funcionarios na lista;
    if (*l == NULL) {
        printf("        --- Nao ha funcionarios Registrados. ---\nPressione qualquer tecla para voltar ao menu principal...");
        pausarPrograma();
    } else {
        char key[51];
        printf("Informe o Nome ou o ID do funcionario que deseja remover: ");
        scanf("%50[^\n]", key);

        int len = strlen(key);

        Lista* funcionarioRemovido;
        if (len == 6)
            funcionarioRemovido = buscarFuncionarios(**l, 4, key);
        else {
            funcionarioRemovido = buscarFuncionarios(**l,2,key);
        }

        //Verifica se o usuario existe
        if (funcionarioRemovido != NULL) {
            printf("\n%s foi removido com sucesso.\n\n", funcionarioRemovido->data.nome);
            *l = removerFuncionario(*l, funcionarioRemovido->data.id);
        } else {
            printf("\n--- O funcionario de Nome ou Id %s nao foi encontrado no sistema.\n\n", key);
        }
        desalocarMemoria(&funcionarioRemovido);

        printf("Pressione qualquer tecla para voltar ao menu principal...");
        limparBuffer();
        pausarPrograma();
    }
}

// -------------------------------------------------------------------------------------------------------------------------------

static void interface_busca(Lista* l){
    system("cls || clear"); // Limpa a tela para uma apresenta  o mais limpa.
    limparBuffer();  // Limpa o buffer de entrada de teclado.
    int opcao;
    int monitorEncerramento = 0;

    // Loop principal que exibe o menu e permite que o usu rio inpute os dados.
    while (1) {
        printf("             --- INTERFACE DE BUSCA ---\n");
        printf("---------------------------------------------\n");
        if (l == NULL) {
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
        if (scanf("%d", &opcao) == 0 || (opcao < 0 && opcao > 6)){
            monitorarEncerramento(&monitorEncerramento);
            limparBuffer();
            printf("--- Input invalido. Tente novamente...");
            pausarPrograma();
            system("cls || clear");
            continue;
        }
        if (opcao == 5){
            return;
        }else{
            char key[51];
            printf("\nInforme a chave da busca de acordo com a sua opcao de busca -> ");
            limparBuffer();
            scanf("%50[^\n]", key);

            Lista* encontrados = buscarFuncionarios(*l, opcao, key);

            system("cls || clear");
            printf("--- Funcionarios encontrados com a key \"%s\":\n",key);
            if (encontrados == NULL)
                printf("---------------------------------------------\n                     NONE\n");
            else
                listarFuncionarios(encontrados);
            printf("---------------------------------------------\n");
            desalocarMemoria(&encontrados);
        }
        limparBuffer();
        printf("Pressione qualquer botao para voltar ao menu...");
        pausarPrograma();
        system("cls || clear");
    }
}

// -------------------------------------------------------------------------------------------------------------------------------

static void interface_ordenacao(Lista** l){
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
                bubbleSort(*l, 1, 4);
                break;
            }
            case 2:
            {
                printf("\n--- Vetor ordenado por ID em ordem decrescente!\n");
                bubbleSort(*l, -1, 4);
                break;
            }
            case 3:
            {
                printf("\n--- Vetor ordenado por Nome em ordem crescente!\n");
                bubbleSort(*l, 1, 2);
                break;
            }
            case 4:
            {
                printf("\n--- Vetor ordenado por Nome em ordem decrescente!\n");
                bubbleSort(*l, 1, 2);
                break;
            }
            case 5:
            {
                printf("\n--- Vetor ordenado por Cargo em ordem crescente!\n");
                bubbleSort(*l, 1, 3);
                break;
            }
            case 6:
            {
                printf("\n--- Vetor ordenado por Cargo em ordem decrescente!\n");
                bubbleSort(*l, -1, 3);
                break;
            }
            case 7:
            {
                printf("\n--- Vetor ordenado por Salario em ordem crescente!\n");
                bubbleSort(*l, 1, 1);
                break;
            }
            case 8:
            {
                printf("\n--- Vetor ordenado por Salario em ordem decrescente!\n");
                bubbleSort(*l, -1, 1);
                break;
            }default:
                break;
        }

        limparBuffer();
        printf("--- Pressiona uma tecla para continuar...");
        pausarPrograma();
        system("cls || clear");
    }
}
