/**
 * @file main.c 
 * @brief Função principal, onde se vai situar o menu de escolha com os respetivos comandos
 * @author ist1113459 GabrielMonte 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "aux_essenciais.h"
#include "cria_vacina.h"
#include "lista_vacina.h"
#include "aplica.h"
#include "lista_inoc.h"
#include "apaga_vacina.h"
#include "apaga_inoc.h"

/**
 * @brief Liberta a memória toda utilizada na lista de vacinas e na hash table
 * @details Percorre todos os indices da lista de vacinas e da hash table
 *          Caso estejam preenchidos, os dados são apagados
 * @param sys Chama o sistema para aceder à lista e à hash table
 */
static void liberta_memoria(Sistema *sys);

/**
 * @brief Inicializa o sistema com a data do sistema e com tudo a zeros
 * @details Inicializamos o sistema e inicializamos a hash table
 *          A hash table começa com um número primo de indices
 *          E em cada indice alocamos memória (A NULL) para ficar pronto para
 *          guardar inoculações
 * @param sys Chamamos o sistema para inicializar o sistema
 * @param estado Inteiro que nos diz que linguagem vai ter o sistema
 */
static void inicializar_Sistema(Sistema *sys, int estado);

/**
 * @brief Função principal do programa 
 * @details Vai receber argumento caso queira o programa em inglês
 *          Vai ter um switch case contendo cada comando que o utilizador queira
 *          E os comandos são respetivamente: 
 *          'c' : Cria um lote vacina
 *          'l' : Lista os lotes de vacina
 *          't' : Altera a data do sistema
 *          'a' : Aplica uma dose de um lote vacina a um utente
 *          'u' : Lista as inoculações de utentes
 *          'r' : Retira um lote de vacina 
 *          'd' : Retira uma inoculação de utente
 *          'q' : Acaba o programa e liberta a memória 
 * @param argnum Tamanho do argumento que o utilizador escreve
 * @param arg String do argumento do utilizador
 * @return 0 quando o programa acaba
 *
 */
int main(int argnum, char *arg[]){         
    char comand[MAXMAX];
    Sistema sys;
    int estado = 0;
    if(argnum > 1 && strcmp(arg[1], "pt") == 0) estado = 1;
    inicializar_Sistema(&sys, estado);
    while (fgets(comand, sizeof(comand), stdin)){
        if (sys.no_mem == 1){
            if(estado == 0){
                puts(EMEMORY);
                return 0;
            }else{
                puts(EMEMORYPT);
                return 0;
            }
        }
        switch(comand[0]) {
            case 'c' : criar_LoteVacina(&sys, comand); break;
            case 'l' : lista_LoteVacina(&sys, comand); break;
            case 't' : saltaPrinta_Data(&sys, comand); break;
            case 'a' : aplica_Dose(&sys, comand); break;
            case 'u' : lista_InoculacaoUtente(&sys, comand); break;
            case 'r' : retira_LoteVacina(&sys, comand); break;
            case 'd' : apaga_Inoculacao(&sys, comand); break; 
            case 'q' : liberta_memoria(&sys); return 0;
            default :  break;
        }
    }
    return 0;
} 

static void liberta_memoria(Sistema *sys){       //main
    for (int i = sys->inoculacao_tamanho - 1 ; i >= 0 ; i--){
        if(sys->inoculacao_hash[i] != NULL && sys->inoculacao_hash[i] != DEL){
            free(sys->inoculacao_hash[i]->nome);
            free(sys->inoculacao_hash[i]->vacina.nome);
            free(sys->inoculacao_hash[i]->vacina.lote);
            free(sys->inoculacao_hash[i]);
        }     
    }
    free(sys->inoculacao_hash);

    for (int i = (sys->contLote) - 1 ; i >= 0 ; i--){
        free(sys->vacina[i].nome);
        free(sys->vacina[i].lote);
    }
    return;
}

static void inicializar_Sistema(Sistema *sys, int estado){      //main
    sys->inoculacao_tamanho = 2803;
    sys->inoculacao_hash = calloc(sys->inoculacao_tamanho, sizeof(Inoculacao*));
    if(sys->inoculacao_hash != NULL)
        sys->no_mem = 0;
    else
        sys->no_mem = 1;
    sys->estado = estado;
    sys->contLote = sys->contUtente = 0;
    sys->data.dia = 1;
    sys->data.mes = 1;
    sys->data.ano = 2025;
}