/**
 * @file aux_vacinas.h
 * @brief Funções essenciais para todas as funções relacionadas com vacinas/lotevacinas
 * @author ist1113459 GabrielMonte
 */

#ifndef aux_vacinas
#define aux_vacinas 

#include "sistema.h"

/**
 * @brief Função específica para ordenar todas as vacinas por ordem de criação
 * @param sys Onde guardamos a lista de vacinas e onde vamos atualizar
 */
void ordenar_PorData_LoteVacina (Sistema *sys);

/**
 * @brief Função para verificar se o nome do lote está correto
 * @param sys Chamamos o sistema para, se no caso de houver erros, sabermos a lingua utilizada
 * @param nomelote String onde está contido o nome do lote
 * @return 
 *          -1 : Se o nome do lote estiver inválido
 *           0 : Se o nome do lote estiver válido 
 *          
 */
int verifica_Nomelote(Sistema *sys, char *nomelote);

/**
 * @brief Função para verificar o número de doses, o nome da vacina, e o número de lotes no sistema
 * @param sys Chamamos o sistema para, verificar a lingua dos erros, e o número de lotes já existentes
 * @param nomevacina String que contém o nome da vacina que queremos verificar
 * @param doses Número de doses que queremos verificar
 * @return 
 *          -1 : Se alguma das verificações falhar
 *           0 : Se nenhuma verificação falhar            
 *          
 */
int verifica_Vacina_Dose(Sistema *sys, char *nomevacina, int doses);

/**
 * @brief Função que "arranja" o nome da vacina e que encontra o indice 
 *        mais pequeno na lista das vacinas onde o nome da vacina é igual 
 *        aquele que procura o utilizador
 * @param sys Chamamos o sistema para aceder à lista de vacinas
 * @param input String onde está guardado o nome da vacina
 * @return 
 *           Indice(vacina): Se encontrou alguma vacina
 *          -1 : Se não encontrou nenhuma vacina
 */
int procurar_LoteVacina(Sistema *sys, char *input);

/**
 * @brief Função que dá print às informações todas acerca do lote vacina
 * @param sys Chamamos o sistema para aceder à lista e ás informações
 * @param i Indice da vacina que queremos tirar as informações
 */
void print_LoteVacina(Sistema *sys, int i);

/**
 * @brief Função que verifica se o nome da vacina está válido
 * @param sys Chamamos o sistema para que, se houver erro, sabermos a língua
 * @param nome String que contém o nome da vacina que queremos verificar
 * @return 
 *          -1 : Se o nome não estiver válido
 *           0 : Se o nome estiver válido
 */
int verifica_Nomevacina (Sistema *sys, char *nome);

/**
 * @brief Função que verifica se o indice da vacina dado é válido
 * @param sys Chamamos o sistema para saber a língua que estamos a usar
 * @param nome String que contém o nome da vacina
 * @param i Inteiro que contém o indice da vacina
 * @return
 *          -1 : Se o indice for inválido
 *           0 : Se o indice for válido
 */
int verifica_Existe_Lotevacina (Sistema *sys, char *nome, int i);

/**
 * @brief Função onde, dado o nome do lote, encontramos na lista de vacinas, o indice
 *        mais pequeno com o mesmo nome do lote
 * @param sys Chamamos o sistema para ter acesso á lista de vacinas
 * @param nome_lote String que guarda o nome do lote que queremos procurar
 * @return 
 *          -1 : Se não encontrar nenhum lote com o mesmo nome no sistema
 *           Indice(lote) : Se encontrar um lote com o mesmo nome no sistema
 */
int procurar_Lote(Sistema *sys, char *nome_lote);


#endif