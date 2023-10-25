#ifndef INTERFACE_H
#define INTERFACE_H
#include "./funcionario.h"

/**
 * funcao que implementa a interface principal da aplicacao de gerenciamento de funcionarios.
 * Apartir dessa funcao o usuario vai poder manipular a Lista de Funcionarios.
 * @param l  ponteiro para a lista de funcionarios que vai ser manipulada durante a execucao do programa.
 * @param csvLink uma string com o link para o arquivo csv onde os dados serao persistidos.
 */
void interface_aplicacao(Lista* l, char csvLink[]);

#endif