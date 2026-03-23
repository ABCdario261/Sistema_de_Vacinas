/**
 * @file cria_vacina.c
 * @brief Implementação do comando com letra 'c' relativo à criação
 *        de lotes vacina
 * @author ist1113459 GabrielMonte 
 * @see cria_vacina.h 
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
 * @brief Implementação de criar_LoteVacina
 * @details O que a função faz: 
 * -Criamos os respetivos inteiros e strings onde vamos guardas as informações
 * -Lê-mos a partir do input todas as informações acerca do lote vacina
 * -Começamos por verificar se o nome do lote é válido com a função verifica_NomeLote()
 * -De seguida verificamos se a data é anterior à do sistema com verifica_Data_Completa
 * -E no finalmente verificamos o núemro de doses, o nome da vacina e o número de lotes já existentes
 * -Se alguma das verificações falhar levanta erro
 * -Se estiver tudo correto, guardamos no próximo indice disponivel na lista de vacinas
 *  todas as informações acerca do lote vacina e aumentamos o contador dos lotes
 * -Se o malloc falhar levanta erro de memória
 * -No final damos print do nome do lote que criamos e ordenamos todas as vacinas por ordem de criação
 */
void criar_LoteVacina(Sistema *sys, char *input){    //Vacina
    char nomelote[MAXNOMELOTE+2], nomevacina[MAXNOMEVACINA+2];
    int dia, mes, ano, doses;
    sscanf(input,"%*s %21s %d-%d-%d %d %51[^ \t\n]", nomelote, &dia, &mes, &ano, &doses, nomevacina);
    if (verifica_Nomelote(sys, nomelote) == -1)
        return;
    if((verifica_Data_Completa(sys, dia, mes, ano) == -1) || (verifica_Data_Completa(sys, dia, mes, ano) == 1)){
        if(sys->estado == 0)
            puts(EDATE);
        else
            puts(EDATEPT);
        return;
    }
    if (verifica_Vacina_Dose(sys, nomevacina, doses) == -1) return;
    int tamanho = strlen(nomevacina); ///AQUI TESTE
    if(tamanho > 1){
        if(nomevacina[0] >= 'a' && nomevacina[0] <= 'z'){
            printf("vaccine name cannot begin with a lowercase letter\n"); return;
        }
    }
    sys->vacina[sys->contLote].lote = malloc(strlen(nomelote) + 1);
    if (sys->vacina[sys->contLote].lote == NULL) {sys->no_mem = 1; return;}
    strcpy(sys->vacina[sys->contLote].lote, nomelote);
    sys->vacina[sys->contLote].data.dia = dia; 
    sys->vacina[sys->contLote].data.mes = mes;
    sys->vacina[sys->contLote].data.ano = ano;
    sys->vacina[sys->contLote].doses = doses;
    sys->vacina[sys->contLote].inoctotal = 0;
    sys->vacina[sys->contLote].nome = malloc(strlen(nomevacina) + 1);
    if (sys->vacina[sys->contLote].nome == NULL) {sys->no_mem = 1; return;}
    strcpy(sys->vacina[sys->contLote].nome, nomevacina);
    printf("%s\n", sys->vacina[sys->contLote].lote);
    sys->contLote++;
    ordenar_PorData_LoteVacina(sys);
}