/**
 * @file lista_inoc.h 
 * @brief Função para o main com a respetiva letra 'u'
 *        Lista inoculações de um ou todos os utentes 
          (Com as respetivas auxiliares)
    @author ist1113459 GabrielMonte
 */
#ifndef lista_inoc
#define lista_inoc

#include "sistema.h"

/**
 * @brief Dado uma lista de indices, acedemos á sua ordem na hash table
 *        E obtemos a lista dos indices ordenados por data (crescente)
 * @param sys Chamamos o sistema para aceder à ordem das inoculações na hash table
 * @param lista_indices Lista com os indices que recebemos 
 */
void bubble_sort_por_ordem(Sistema *sys, int *lista_indices);

/**
 * @brief Função onde vamos criar a lista de indices, caso tenhamos o nome de utente
 * @param sys Chamamos o sistema para aceder à hash table
 * @param nome_utente String que contém o nome do utente 
 * @return Devolve a lista com os indices 
 */
int *cria_Lista_Indice_ComUtente(Sistema *sys, char *nome_utente);

/**
 * @brief Função onde vamos criar a lista de indices com todos os utentes
 * @param sys Chamamos o sistema para aceder à hash table
 * @return Devolve a lista com os indices
 */
int *cria_Lista_Indice_SemUtente(Sistema * sys);

/**
 * @brief Função onde dado um nome de utente, printamos as informações das inoculações
 *        do respetivo utente por ordem crescente (de data)
 * @param sys Chamamos o sistema para poder aceder à hash table
 * @param nome_utente String que vai conter o nome dp utente 
 */
void printa_Inoc_Utente (Sistema *sys, char* nome_utente);

/**
 * @brief Função onde printamos todas as informações das inoculações de todos os utentes
 *        por ordem crescente (de data) 
 * @param sys Chamamos o sistema para poder aceder à hash table
 */
void printa_Inoc_todas (Sistema *sys);

/**
 * @brief Função que recebe o input com o possível nome do utente, e que depois
 *        printa as informações das inoculações
 * @param sys Chamamos o sistema para poder aceder à hash table
 * @param input String que pode ou não conter o nome do utente 
 */
void lista_InoculacaoUtente(Sistema *sys, char *input);

#endif
