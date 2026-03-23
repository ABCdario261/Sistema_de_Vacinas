/**
 * @file aux_vacinas.c 
 * @brief Implementação das funções essenciais para todas as funções relativas
 *        às vacinas/lotevacinas
 * @author ist1113459 GabrielMonte
 * @see aux_vacinas.h 
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
 * @brief Implementação de ordenar_PorData_LoteVacina
 * @details O que a função faz:
 * -A função implementa um algoritmo de Insertion Sort que ordena a partir de: 
 *      - 1. Por data (crescente)
 *      - 2. Se a data tiver ordenada, vai por ordem alfabética pelo nome do lote
 * -Devolve a lista no sistema atualizada com as vacinas ordenadas
 */
void ordenar_PorData_LoteVacina (Sistema *sys){     //Vacina
    int i = 1;
    for (; i < sys->contLote; i++){
        Vacina key = sys->vacina[i];
        int j = i - 1;
        while (j >= 0 && 
            (sys->vacina[j].data.ano > key.data.ano || 
            (sys->vacina[j].data.ano == key.data.ano && sys->vacina[j].data.mes > key.data.mes) || 
            (sys->vacina[j].data.ano == key.data.ano && sys->vacina[j].data.mes == key.data.mes && sys->vacina[j].data.dia > key.data.dia) || 
            (sys->vacina[j].data.ano == key.data.ano && sys->vacina[j].data.mes == key.data.mes && sys->vacina[j].data.dia == key.data.dia && strcmp(sys->vacina[j].lote, key.lote) > 0))) {
            sys->vacina[j + 1] = sys->vacina[j];
            j--;
    }
    sys->vacina[j + 1] = key;
    
    }
}
 
/**
 * @brief Implementação de verifica_Nomelote
 * @details O que a função faz:
 * -Verifica se o tamanho do nomelote está dentro dos limites pedidos
 * -Se não estiver levanta erro de lote inválido
 * -De seguida verifica cada indice da string nome lote para:
 *      -Verificar se os digitos variam entre 0 e 9
 *      -Verifcar se as suas letras variam entre A e F maiousculos
 * -Se estas verificações falharem levanta erro de lote inválido
 * -Finalmente verificamos se no sistema já existe um lote com o mesmo nome
 * -Se existir levantamos erro de número de lote duplicado
 */
int verifica_Nomelote(Sistema *sys, char *nomelote){   //Vacina
    int i = 0;
    if (strlen(nomelote) > 20){
        if (sys->estado == 0)
            puts(EMAXDIGLOTE);
        else
            puts(EMAXDIGLOTEPT);
        return -1;
    }
    for (i = 0; nomelote[i] != '\0'; i++){
        if (!( ((nomelote[i] >= '0') && (nomelote[i] <= '9')) || ((nomelote[i] >= 'A') && (nomelote[i] <= 'F')) )){
        if (sys->estado == 0)
            puts(EMAXDIGLOTE);
        else    
            puts(EMAXDIGLOTEPT);
        return -1;
        }
    }
    for (i = 0; i < sys->contLote; i++){
        if (strcmp(nomelote, sys->vacina[i].lote) == 0){
            if(sys->estado == 0)
                puts(ESAMELOTE);
            else
                puts(ESAMELOTEPT);
            return -1;
        }
    }
    return 0;
}


/**
 * @brief Implementação de verifica_Vacina_Dose 
 * @details O que a função faz: 
 * -Verifica se o número de doses é positivo e diferente de zero
 * -Se não for levanta erro de quantidade inválida
 * -Verifica se o tamanho da vacina está dentro dos limites pedidos
 * -Se não estiver levanta erro de nome inválido
 * -Finalmente verificamos se o sistema já atingiu o número máximo de lotes permitido
 * -Se sim levantamos erro de demasiadas vacinas
 */
int verifica_Vacina_Dose(Sistema *sys, char *nomevacina, int doses){    //Vacina
    if (doses < 0){
        if(sys -> estado == 0)
            puts(EDOSES);
        else    
            puts(EDOSESPT);
        return -1;
    }
    if(strlen(nomevacina) > 50){ 
        if(sys -> estado == 0)
            puts(EMAXDIGVAC);
        else
            puts(EMAXDIGVACPT);
        return -1;
    }
    if(sys->contLote >= MAXLOTESVACINAS){
        if (sys -> estado == 0)
            puts(EMAXVAC);
        else 
            puts(EMAXVACPT);
        return -1;
    }
    return 0;
}


/**
 * @brief Implementação de procurar_LoteVacina
 * @details O que a função faz: 
 * -Arranja o nome da vacina (tira o espaço no final)
 * -De seguida vê na lista de vacinas se existe algum indice (a começar no zero) com o mesmo nome de vacina
 * -Se houver devolve o indice, senão devolve -1
 */
int procurar_LoteVacina(Sistema *sys, char *input){    //Vacina
    int i;
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';
    for (i = 0; i < sys->contLote; i++){
        if(!strcmp(input, sys->vacina[i].nome))
        return i;
    }
    return -1;
}
 
/**
 * @brief Implementação de print_LoteVacina
 * @details O que a função faz:
 * -Dá print do nome da vacina e de seguida do lote (com o indice dado)
 * -Dá print da data de criação dessa vacina
 * -E finalmente dá print das doses existentes e tomadas
 */
void print_LoteVacina(Sistema *sys, int i){ //Vacina
    printf("%s %s ", sys->vacina[i].nome, sys->vacina[i].lote);
    printa_Data(sys->vacina[i].data.dia, sys->vacina[i].data.mes, sys->vacina[i].data.ano);
    printf(" %d %d\n", sys->vacina[i].doses, sys->vacina[i].inoctotal);
}
 
/**
 * @brief Implementação de verifica_Nomevacina
 * @details O que a função faz: 
 * -Verifica se o nome da vacina ultrapassa o tamanho válido
 * -Se sim levanta erro e devolve -1, senão apenas devolve 0
 */
int verifica_Nomevacina (Sistema *sys, char *nome){ //Vacina
    if (strlen(nome) >= MAXNOMEVACINA) {
        if (sys->estado == 0)
            puts(EMAXDIGVAC);
        else
            puts(EMAXDIGVACPT);
        return -1;
    }
    return 0;
}

/**
 * @brief Implementação de verifica_Existe_Lotevacina
 * @details O que a função faz: 
 * -De acordo com o indice que recebe: 
 *      -Se for -1 (indice inválido): 
 *           - Dá print do nome da vacina e levanta erro de vacina inexistente
 *           - Devolve -1
 *      -Se for diferente que 1 devolve 0
 */
int verifica_Existe_Lotevacina (Sistema *sys, char *nome, int i){    //Vacina
    if (i == -1) {
        printf("%s: ", nome);
        if(sys->estado == 0)
        puts(ENOVACINE);
        else
        puts(ENOVACINEPT);
        return -1;
    }
    return 0;
}
    
/**
 * @brief Implementação de procurar_Lote
 * @details O que a função faz: 
 * -Corre a lista de vacinas toda á procura de um indice onde o nome do lote seja igual á do dado
 * -Se houver, devolve o próprio indice, se não devolve -1
 */
int procurar_Lote(Sistema *sys, char *nome_lote){             //Vacina
    int i;
    for (i = 0; i < sys->contLote; i++){
        if((strcmp(nome_lote, sys->vacina[i].lote) == 0))
            return i;
    }
    return -1;
}

