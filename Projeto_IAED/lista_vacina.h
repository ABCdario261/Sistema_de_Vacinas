/**
 * @file lista_vacina.h
 * @brief Função para o main com a respetiva letra 'l'
 *        Lista a lista de vacinas (todas ou as pedidas)
 * @author ist1113459 GabrielMonte
 */

#ifndef lista_vacina
#define lista_vacina

#include "sistema.h"

/**
 * @brief Dados o nome ou nomes (ou nada) de vacinas no input
 *        Printamos as informações das vacinas pedidas (ou todas)
 * @param sys Chamamos o sistema para aceder á lista de vacinas
 * @param input String que pode conter o nome das vacinas a listar
 */
void lista_LoteVacina(Sistema *sys, char *input);

#endif