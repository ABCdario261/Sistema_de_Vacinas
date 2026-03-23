/**
 * @file apaga_vacina.c 
 * @brief Implementação do comando com letra 'r' relativo á eliminação
 *        de um lote de vacina
 * @author ist1113459 GabrielMonte
 * @see apaga_vacina.h 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sistema.h"
#include "config.h"
#include "aux_essenciais.h"
#include "aux_vacinas.h"

/**
 * @brief Implementação de retira_vacina
 * @details O que a função faz:
 * -Criamos uma cópia inteira do indice
 * -Apagamos as informações relativas a essa vacina na lista 
 * -E passamos as vacinas seguintes para a esquerda
 * -Diminuimos no sistema o contador de lotes
 */
/*void retira_vacina(Sistema *sys, int i){    
    int u = i;
    free(sys->vacina[i].nome);
    free(sys->vacina[i].lote);
    for (; u < sys->contLote - 1; u++){
        sys->vacina[u] = sys->vacina[u + 1];
    }
    sys->contLote--;
}*/

/**
 * @brief Implementação de retira_LoteVacina
 * @details O que a função faz: 
 * -Criamos um array onde vamos guardar o nome do lote
 * -Verificamos se esse lote existe, se não existir levantamos erro
 * -Se existir, printamos as inoculacoes que esse lote deu, se não deu nenhuma
 *  retiramos a vacina
 * -Se deu inoculacoes, simplesmente atualizamos o lote para ter 0 doses disponiveis
 */
void retira_LoteVacina(Sistema *sys, char *input){
    char nomelote[MAXNOMELOTE + 1];
    sscanf(input,"%*s %20s", nomelote);
    int i = procurar_Lote (sys, nomelote);
    if (i != -1){
        printf("%d\n",sys->vacina[i].inoctotal);
        if (sys->vacina[i].inoctotal == 0)
            sys->vacina[i].doses = 0;
        else
            sys->vacina[i].doses = 0;
    }else{
        printf("%s: ", nomelote);
        if (sys->estado == 0)
            puts(ENOLOTE);
        else
            puts(ENOLOTEPT);    
    }     
}