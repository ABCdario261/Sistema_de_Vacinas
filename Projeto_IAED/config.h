/**
 * @file config.h 
 * @brief Ficheiro onde se guarda as constantes necessárias para o projeto
 * @author ist1113459 GabrielMonte
 */


#ifndef config
#define config

/**
 * @brief Constante do tamanho do nome da vacina
 */
#define MAXNOMEVACINA 50

/**
 * @brief Constante do tamanho do nome do lote
 */
#define MAXNOMELOTE 20

/**
 * @brief Constante do nome de utente
 * @note Não utilizado (pois pode ter mais que 200)
 *       No enunciado é dito que á partida não ultrapassa 200 bytes
 */
#define MAXNOMEUTENTE 200

/**
 * @brief Constante do número máximo de lotes de vacina
 */
#define MAXLOTESVACINAS 1000

/**
 * @brief Constante do número máximo do buffer
 */
#define MAXMAX 65536

/**
 * @brief Constante de verificação
 */
#define DEL ((void*)-1)

/**
 * @brief Mensagem de erro de demasiadas vacinas em ING
 */
#define EMAXVAC "too many vaccines"

/**
 * @brief Mensagem de erro de número de lote duplicado em ING
 */
#define ESAMELOTE "duplicate batch number"

/**
 * @brief Mensagem de erro de lote inválido em ING
 */
#define EMAXDIGLOTE "invalid batch"

/**
 * @brief Mensagem de erro de nome inválido em ING
 */
#define EMAXDIGVAC "invalid name"

/**
 * @brief Mensagem de erro de nome inválido em ING
 */
#define EMAXUTENTE "invalid name"

/**
 * @brief Mensagem de erro de data inválida em ING
 */
#define EDATE "invalid date"

/**
 * @brief Mensagem de erro de doses inválidas em ING
 */
#define EDOSES "invalid quantity"

/**
 * @brief Mensagem de erro de vacina inexistente em ING
 */
#define ENOVACINE "no such vaccine"

/**
 * @brief Mensagem de erro de doses inexistentes em ING
 */
#define E0VACUTENTE "no stock"

/**
 * @brief Mensagem de erro de lote inexistente em ING
 */
#define ENOLOTE "no such batch"

/**
 * @brief Mensagem de erro de já vacinado em ING
 */
#define EUTENTEVACC "already vaccinated"

/**
 * @brief Mensagem de erro de utente inexistente em ING
 */
#define ENOUTENTE "no such user"

/**
 * @brief Mensagem de erro de falta de memória em ING
 */
#define EMEMORY "no memory"

/**
 * @brief Mensagem de erro de demasiadas vacinas em PT
 */
#define EMAXVACPT "demasiadas vacinas"

/**
 * @brief Mensagem de erro de número de lote duplicado
 */
#define ESAMELOTEPT "número de lote duplicado"

/**
 * @brief Mensagem de erro de lote inválido em PT
 */
#define EMAXDIGLOTEPT "lote inválido"

/**
 * @brief Mensagem de erro de nome inválido em PT
 */
#define EMAXDIGVACPT "nome inválido"

/**
 * @brief Mensagem de erro de nome inválido em PT
 */
#define EMAXUTENTEPT "nome inválido"

/**
 * @brief Mensagem de erro de data inválida em PT
 */
#define EDATEPT "data inválida"

/**
 * @brief Mensagem de erro de quantidade inválida em PT
 */
#define EDOSESPT "quantidade inválida"

/**
 * @brief Mensagem de erro de vacina inexistente em PT
 */
#define ENOVACINEPT "vacina inexistente"

/**
 * @brief Mensagem de erro de doses esgotadas em PT
 */
#define E0VACUTENTEPT "esgotado"

/**
 * @brief Mensagem de erro de lote inexsitente em PT
 */
#define ENOLOTEPT "lote inexistente"

/**
 * @brief Mensagem de erro de já vacinado em PT
 */
#define EUTENTEVACCPT "já vacinado"

/**
 * @brief Mensagem de erro de utente inexsitente em PT
 */
#define ENOUTENTEPT "utente inexistente"

 /**
  * @brief Mensagem de erro de falta de memória em PT
  */
#define EMEMORYPT "sem memória"

#endif 