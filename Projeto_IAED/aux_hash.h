/**
 * @file aux_hash.h
 * @brief Funções essenciais para qualquer tipo de funções relacionadas com hash
 * @author ist1113459 GabrielMonte
 */

#ifndef aux_hash
#define aux_hash

#include "sistema.h"

/**
 * @brief Dado um inteiro, encontramos o primo mais próximo
 * @param n Inteiro dado
 * @return Número primo maior e mais próximo de n
 */
int proximo_primo(int n);

/**
 * @brief Dado uma string, e o tamanho da hash table, calculamos um indice para essa string
 * @param v String dada
 * @param M Tamanho da hash table
 * @return Indice para a respetiva string na hash table
 */
int hash1(char *v, int M);

/**
 * @brief Dado uma string, e o tamanho da hash table, calculamos um número para que se
 *        hash1 estiver ocupado, usamos este hash2 para calcular o próximo indice
 * @param v String dada
 * @param M Tamanho da hash table
 * @return Número auxiliar para calcular novo indice
 */
int hash2(char *v, int M);

/**
 * @brief Dado uma hash table antiga, adicionamos para a hash table nova todas as
 *        informações da antiga para a nova com os novos indices
 * @param sys Chamamos o sistema para guardar as informações novas na nova hash table
 * @param nova Hash table antiga de onde vamos copiar as informações
 */
void inoculacao_Inserir(Sistema *sys, Inoculacao *nova);

/**
 * @brief Aumentamos o tamanho da hash table de inoculações
 *        e copiamos as informações
 * @param sys Chamamos o sistema onde está guardada a hash table
 * @note Usada exclusivamente para aumentar_TamanhoInoc
 */
void aumentar_TamanhoInoc(Sistema *sys);

/**
 * @brief Dado um nome de utente verificamos na hash table se o utente existe
 * @param sys Chamamos o sistema para aceder à hash table
 * @param nome_utente String do nome_utente
 * @return 
 *            1 - Se o utente existir 
 *           -1 - Se o utente não existir 
 */
int procura_Utente(Sistema *sys, char* nome_utente);

#endif