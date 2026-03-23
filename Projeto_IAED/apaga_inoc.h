/**
 * @file apaga_inoc.h 
 * @brief Função para o main com a respetiva letra 'd'
 *        Apaga um utente na hash table de inoculações
 * @author ist1113459 GabrielMonte
 */

#ifndef apaga_inoc
#define apaga_inoc

#include "sistema.h"

/**
 * @brief Dado uma string que contém o dia, transformamos em inteiro
 * @param diach String com o dia
 * @return Devolve o dia em inteiro
 */
int verifica_Arranja_DataApagaInoc_Dia(char* diach);

/**
 * @brief Dado uma string que contém o mês, transformamos em inteiro
 * @param mesch String com o mês
 * @return Devolve o mês em inteiro
 */
int verifica_Arranja_DataApagaInoc_Mes(char* mesch);

/**
 * @brief Dado uma string que contém o ano, transformamos em inteiro
 * @param anoch String com o ano
 * @return Devolve o ano em inteiro
 */
int verifica_Arranja_DataApagaInoc_Ano(char* anoch);

/**
 * @brief Função que verifica se a data dada é valida
 * @param sys Chamamos o sistema para comparar a data
 * @param dia Dia dado
 * @param mes Mes dado
 * @param ano Ano dado
 * @return
 *      -1 : Se a data não for válida
 *       1 : Se a data for válida
 */
int verifica_Arranja_DataApagaInoc_Total(Sistema *sys, int dia, int mes, int ano);

/**
 * @brief Função que dado um nome de utente e uma data
 *        apagamos as inoculações segundo essas informações
 * @param sys Chamamos o sistema para aceder á hash table
 * @param nome_utente String com nome do utente
 * @param dia Dia dado
 * @param mes Mes dado
 * @param ano Ano dado 
 */
void retira_Utente(Sistema *sys, char* nome_utente, int dia, int mes, int ano);

/**
 * @brief Função que dado um nome de utente, um nome de lote e uma data,
 *        apagamos as inoculações segundo essas informações
 * @param sys Chamamos o sistema para aceder á hash table
 * @param nome_utente String com o nome do utente
 * @param nome_lote String com o nome do lote
 * @param dia Dia dado
 * @param mes Mes dado
 * @param ano Ano dado
 */
void retira_UtenteComLote(Sistema *sys, char* nome_utente, char* nome_lote, int dia, int mes, int ano );

/**
 * @brief Função que dado um nome de utente, o número de inoculações totais atuais, e uma data
 *        Apagamos as inoculações desse utente e devolvemos a diferença entre
 *        as inoculações antes e depois de retirarmos as inoculações do utilizador 
 *        (que vão ser as inoculações do próprio utente)
 * @param sys Chamamos o sistema para aceder á hash table e para atualizá-la
 * @param nome_utente String que guarda o nome do utente
 * @param aplica_inicial Número de inoculações totais antes de apagar
 * @param dia Dia dado
 * @param mes Mes dado
 * @param ano Ano dado
 */
void apaga_Inoc_SemLote(Sistema *sys, char *nome_utente, int aplica_inicial, int dia, int mes, int ano);

/**
 * @brief Função que dado um nome de utente, um nome de lote, o número de inoculações totais, e uma data
 *        Apagamos as inoculações desse utente e devolvemos a diferença entre
 *        as inoculações antes e depois de retirarmos as inoculações do utilizador 
 *        (que vão ser as inoculações do próprio utente)
 * @param sys Chamamos o sistema para aceder á hash table e para atualiza-la
 * @param nome_utente String que guarda o nome de utente
 * @param nome_lote String que guarda o nome do lote 
 * @param aplica_inicial Número de inoculações totais antes de apagar
 * @param dia Dia dado
 * @param mes Mes dado
 * @param ano Ano dado
 */
void apaga_Inoc_ComLote(Sistema *sys, char *nome_utente, char *nome_lote, int aplica_inicial, int dia, int mes, int ano);

/**
 * @brief Função que dado uma string com o nome do utente
 *        Arranjamos o nome do utente e devolvemos bem formatada
 * @param input String que guarda o nome do utente total
 * @return Devolve o nome do utente bem formatada
 */
char *arrajar_NomeUtente_ApagaInoc(char *input);

/**
 * @brief Função que dado uma string com nome do utente e possivelmente
 *        um nome de lote e uma data, apagamos as inoculações desse utente
 *        segundo as informações dadas
 * @param sys Chamamos o sistema para aceder á hash table e atualizá-la
 * @param input String que vai conter o nome do utente e possivelmente nome de lote e data
 */
void apaga_Inoculacao(Sistema *sys, char *input);

#endif