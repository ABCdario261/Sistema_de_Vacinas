/**
 * @file aplica.h 
 * @brief Função para o main com a respetiva letra 'a'
 *        Aplica uma dose a um utente 
 * @author ist1113459 GabrielMonte
 */

#ifndef aplica
#define aplica

#include "sistema.h"
/** 
 * @brief Dados o nome do utente, da vacina e do lote atualizamos a hashtable
 *        com esta aplicação (no devido indice) no sistema
 * @param sys Chamamos o sistema para atualizar a hash table
 * @param nome_utente String que guarda o nome do utente
 * @param nome_vacina String que guarda o nome da vacina
 * @param nome_lote String que guarda o nome do lote
*/
void inoculacao_Inserir_Aplica(Sistema *sys, char *nome_utente, char *nome_vacina, char *nome_lote);
 
/**
  * @brief Dado o nome da vacina, procura no sistema uma vacina com o mesmo nome
  *        que esteja válida
  * @param sys Chamamos o sistema para aceder á lista de vacinas
  * @param input String onde está guardada o nome da vacina
  * @return Retorna se encontrar uma vacina válida devolve o indice, senão retorna -1
  */
int procurarValido_LoteVacina(Sistema *sys, char *input);

/**
 * @brief Dado o nome do utente e da vacina, vai encontrando um indice
 *        na hash table onde (na data do sistema) o utente tenha tomado essa vacina
 * @param sys Chamamos o sistema para aceder a hash table
 * @param nome_utente String onde está guardada o nome do utente
 * @param nome_vacina String onde está guardada o nome da vacina
 * @return 
 *           Indice(utente) : Se encontrou um utente 
 *          -1 : Se não encontrou nenhum utente 
 */
int procura_UtenteVacina(Sistema *sys, char* nome_utente, char *nome_vacina);

/**
 * @brief Função principal do main que aplica a dose a um utente
 * @param sys Chamamos o sistema para atualizar a lista de vacina e a hash table
 * @param input String onde vão estar nomes de utente, vacina, lote, e datas e doses
 */
void aplica_Dose(Sistema *sys, char *input);

#endif