/**
 * @file apaga_vacina.h 
 * @brief Função para o main com a respetiva letra 'r'
 *        Apaga um lote de vacina (com as respetivas auxiliares)
 * @author ist1113459 GabrielMonte
 */
#ifndef apaga_vacina
#define apaga_vacina

#include "sistema.h"

/**
 * @brief Dado um indice de vacina, apagamos os dados dessa vacina
 *        e a partir desse indice, passamos as vacinas seguintes uma posicao atras
 * @param sys Chamamos o sistema para alterar na lista de vacinas a vacina apagada
 * @param i Indice da vacina que queremos apagar
 */
void retira_vacina(Sistema *sys, int i);

/**
 * @brief Dado um nome de lote, apagamos esse lote da lista de vacinas
 * @param sys Chamamos o sistema para alterar a lista de vacinas
 * @param input String onde vai estar o nome do lote
 * @note Função principal que vai para o main
 */
void retira_LoteVacina(Sistema *sys, char *input);

#endif

