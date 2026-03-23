/**
 * @file aux_essenciais.h
 * @brief Funções essenciais para qualquer tipo de funções (vacinas/inoculações)
 * @author ist1113459 GabrielMonte
 */

#ifndef aux_essenciais
#define aux_essenciais

#include "sistema.h"
/**
 * @brief Verifica se o ano é bissexto
 * @param ano Ano a verificar
 * @return 0 se não for bissexto, 1 se for bissexto
 */
int verifica_Bissexto (int ano);

/**
 * @brief Verifica se a data dada é válida 
 * @param dia Dia a verificar
 * @param mes Mes a verificar
 * @param ano Ano a verificar
 * @return -1 se não for válido, 0 se for válido
 */
int verifica_Data_Valida (int dia, int mes, int ano);

/**
 * @brief Verifica se a data é válida quanto á do sistema
 * @param sys Chamamos o sistema para termos a data do sistema
 * @param dia Dia a verificar
 * @param mes Mes a verificar
 * @param ano Ano a verificar
 * @return 
 *      -1: Se a data for anterior à do sistema
 *       0: Se a data for posterior à do sistema
 *       2: Se a data for igual à do sistema 
 */
int verifica_Data_Sistema (Sistema *sys, int dia, int mes, int ano);

/**
 * @brief Verifica a data com as duas funções de data complementar juntas
 * @param sys Chamamos o sistema para termos a data do sistema
 * @param dia Dia a verificar
 * @param mes Mes a verificar
 * @param ano Ano a verificar
 * @return 
 *       1: Se a data for inválida
 *      -1: Se a data for anterior à do sistema
 *       2: Se a data for posterior à do sistema
 *       0: Se a data for igual à do sistema
 */
int verifica_Data_Completa (Sistema *sys, int dia, int mes, int ano);

/**
 * @brief Recebe a data e printa a data de acordo com o enunciado
 * @param dia Dia a printar
 * @param mes Mes a printar
 * @param ano Ano a printar
 */
void printa_Data (int dia, int mes, int ano);

/**
 * @brief Muda a data do sistema para a que o utilizador escolhe
 * @param sys Chamamos o sistema para mudar internamente a data
 * @param input Recebemos o input do utilizador com a data
 */
void saltaPrinta_Data (Sistema *sys, char *input);

/**
 * @brief Função utilizada para printar erro de stock
 * @param sys Chamamos o sistema para saber que linguagem é usada
 */
void erro_VACUTENTE_put (Sistema *sys);

/**
 * @brief Função utilizada para printar erro de utente já vacinado
 * @param sys Chamamos o sistema para saber que linguagem é usada
 */
void erro_UTENTEVACC_put (Sistema *sys);

/**
 * @brief Função utilizada para printar erro de utente não existente
 * @param sys Chamamos o sistema para saber que linguagem é usada
 */
void erro_NOUTENTE_put (Sistema *sys);

/**
 * @brief Função utilizada para printar o erro de lote não existente 
 * @param sys Chamamos o sistema para saber que linguagem é usada
 */
void erro_NOLOTE_put (Sistema *sys);

/**
 * @brief Recebe um nome de utente e arranja-a para não estar mal formatada
 * @param sys Chamamos o sistema em caso de houver erro de memória
 * @param nome_utente_final Nome recebido para arranjar
 * @return Devolve o nome_utente arranjado
 * @note Esta função está em essenciais pois, é usada em Aplica_Dose e em Lista_Inoculações
 */
char* verifica_Arranja_NomeUtente(Sistema *sys, char* nome_utente_final);

#endif

