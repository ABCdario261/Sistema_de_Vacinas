/**
 * @file sistema.h
 * @brief Ficheiro onde estão guardados as estruturas usadas no projeto
 * @author ist1113459 GabrielMonte
 */
#ifndef sistema
#define sistema

#include "config.h" 

/**
 * @brief Estrutura para armazenar datas (dia, mes, ano)
 */
typedef struct data{
    int dia; /**< Dia da data */
    int mes; /**< Mes da data */
    int ano; /**< Ano da data */
}Data;

/**
 * @brief Estrutura para armazenar vacinas e as suas características
 * @note Campos incluem nome de vacina e lote, doses disponiveis/tomadas e data
 */
typedef struct vacina{
    char *nome; /**< Nome da vacina*/
    char *lote; /**< Nome do lote */
    int doses; /**< Número de doses*/
    int inoctotal; /**< Número de doses tomadas */
    Data data; /**< Data de criação da vacina */
}Vacina;

/**
 * @brief Estrutura para armazenar as inoculações e as suas informações
 * @note Campos incluem nome do utente que tomou, a data, a vacina, e a ordem de toma
 */
typedef struct inoculacao{
    char *nome; /**< Nome do utente */
    int ordem; /**< Ordem de aplicação*/
    Data data; /**< Data da aplicação*/
    Vacina vacina; /**< Vacina aplicada*/
}Inoculacao;

/**
 * @brief Estrutura onde armazenamos as informações todas acerca de vacinas, inoculações e utentes
 * @note Campos incluem, memória, estado da lingua, número de utentes e inoculações e hash table para inoculações
 */
typedef struct sistema{
    int no_mem; /**< Verificador de memória */
    int contLote; /**< Contador do número de lotes */
    int contUtente; /**< Contador do número de utentes */
    int estado; /**< Verificador da língua utilizada */
    int inoculacao_tamanho; /**< Inteiro com o tamanho da hash table */
    Data data; /**< Data do sistema */
    Vacina vacina[MAXLOTESVACINAS]; /**< Vacinas guardadas em lista */
    Inoculacao **inoculacao_hash; /**< Inoculações guardadas em hash table */
}Sistema;

#endif