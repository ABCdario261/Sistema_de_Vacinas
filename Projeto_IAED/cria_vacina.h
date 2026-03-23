/**
 * @file cria_vacina.h
 * @brief Função para o main com a respetiva letra 'c'
 *        Cria um lote com vacinas
 * @author ist1113459 GabrielMonte
 */

#ifndef cria_vacina
#define cria_vacina

#include "sistema.h"

/**
 * @brief Dado informações a partir do input acerca do lote vacina
 *        Criamos o lotevacina e guardamos no sistema
 * @param sys Chamamos o sistema para guardar o lote e para verificar se
 *            cumpre datas, se não está repetido, etc...
 * @param input String com todas as informações acerca do lote vacina 
 */
void criar_LoteVacina(Sistema *sys, char *input);

#endif