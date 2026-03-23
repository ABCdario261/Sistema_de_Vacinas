/**
 * @file aplica.c 
 * @brief Implementação do comando 'a' relativo á aplicação de doses
 * @author ist1113459 GabrielMonte
 * @see aplica.h 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sistema.h"
#include "config.h"
#include "aplica.h"
#include "aux_vacinas.h"
#include "aux_essenciais.h"
#include "aux_hash.h"

/**
 * @brief Implementação de inoculacao_Inserir_Aplica
 * @details O que a função faz:
 * -Criamos um ciclo while para, dado um nome de utente, encontrarmos um indice livre
 * -Se o indice chegar ao limite da hash table, aumentamos o tamanho da hash table e prosseguimos
 * -Após encontrar um indice prosseguimos com a cópia de todas as informações para esse indice
 * -Se houver problemas ao alocar memória, levantamos erro de falta de memória
 * -Se a hash table estiver 50% preenchida no final, aumentamos o tamanho da mesma
 */
void inoculacao_Inserir_Aplica(Sistema *sys, char *nome_utente, char *nome_vacina, char *nome_lote){     
    int i = hash1(nome_utente, sys->inoculacao_tamanho);
    int k = hash2(nome_utente, sys->inoculacao_tamanho);
    while(sys->inoculacao_hash[i] != NULL){
        i = (i + k) % sys->inoculacao_tamanho;
        if (i >= sys->inoculacao_tamanho - 1){
            aumentar_TamanhoInoc(sys);
            i = hash1(nome_utente, sys->inoculacao_tamanho);
            k = hash2(nome_utente, sys->inoculacao_tamanho);
        }
    }
    sys->inoculacao_hash[i] = malloc(sizeof(Inoculacao));
    sys->inoculacao_hash[i]->nome = malloc(strlen(nome_utente) + 1);
    if (sys->inoculacao_hash[i]->nome == NULL) {sys->no_mem = 1; return;}
    strcpy(sys->inoculacao_hash[i]->nome, nome_utente);
    sys->inoculacao_hash[i]->vacina.nome = malloc(strlen(nome_vacina) + 1);
    if (sys->inoculacao_hash[i]->vacina.nome == NULL) {sys->no_mem = 1; return;}
    strcpy(sys->inoculacao_hash[i]->vacina.nome, nome_vacina);
    sys->inoculacao_hash[i]->vacina.lote = malloc(strlen(nome_lote) + 1);
    if (sys->inoculacao_hash[i]->vacina.lote == NULL) {sys->no_mem = 1; return;}
    strcpy(sys->inoculacao_hash[i]->vacina.lote, nome_lote);
    sys->inoculacao_hash[i]->data.dia = sys->data.dia;
    sys->inoculacao_hash[i]->data.mes = sys->data.mes;
    sys->inoculacao_hash[i]->data.ano = sys->data.ano;
    sys->inoculacao_hash[i]->ordem = sys->contUtente;
    sys->contUtente++;
    if (sys->contUtente > 0.50 * sys->inoculacao_tamanho)
        aumentar_TamanhoInoc(sys);
}

/**
 * @brief Implementação de procurarValido_LoteVacina
 * @details O que a função faz: 
 * -Recebe o nome da vacina pelo input, verificamos e "arranjamos" o nome
 * -De seguida, corremos a lista de vacinas á procura de um lote que tenha doses
 *  e que esteja na validade
 * -Se encontrar mos um devolvemos o indice, se não devolvemos -1
 */
int procurarValido_LoteVacina(Sistema *sys, char *input){     
    int i;
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';
    for (i = 0; i < sys->contLote; i++){
        if(!strcmp(input, sys->vacina[i].nome)){
            if ((sys->vacina[i].doses >= 1) && ((verifica_Data_Completa(sys, sys->vacina[i].data.dia, sys->vacina[i].data.mes, sys->vacina[i].data.ano) == 0) || (verifica_Data_Completa(sys, sys->vacina[i].data.dia, sys->vacina[i].data.mes, sys->vacina[i].data.ano) == 2)))
                return i;
        }
    }   
    return -1;
}

/**
 * @brief Implementação de procura_UtenteVacina
 * @details O que a função faz: 
 * -Cria um ciclo while onde, para cada indice correspondente ao nome utente
 *  vai encontrando uma inoculacao com o nome do utente e o nome de vacina correspondente
 * -Se encontrar verificamos se essa dose foi tomada no dia de hoje (data do sistema)
 * -Se sim, devolve o indice, se não devolve -1
 */
int procura_UtenteVacina(Sistema *sys, char* nome_utente, char *nome_vacina){    
    int i = hash1(nome_utente, sys->inoculacao_tamanho);
    int k = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[i] != NULL ){
        if (sys->inoculacao_hash[i] != DEL && strcmp(nome_utente, sys->inoculacao_hash[i]->nome) == 0 && strcmp(nome_vacina, sys->inoculacao_hash[i]->vacina.nome) == 0){
            if(verifica_Data_Completa(sys, sys->inoculacao_hash[i]->data.dia, sys->inoculacao_hash[i]->data.mes, sys->inoculacao_hash[i]->data.ano) == 2)
                return i;
        }
        i = (i + k) % sys->inoculacao_tamanho;
    }
    return -1;
}

/**
 * @brief Implementação de aplica_Dose
 * @details O que a função faz: 
 * -Cria duas strings onde vamos guardar o nome_utente e o nome_vacina
 * -Criamos um char com limite do buffer para ler o nome utente
 * -Deitamos fora o 'a' com strtok
 * -Verifixamos se a posição 3 do input tem '\"'
 * -Se tiver:
 *      -Lê nome de utente com strtok (a separar por aspas)
 *      -E de seguida lê o nome de vacina com strtok (a separar por espaços)
 *      -Como nome de vacina tem '\n', tiramos
 *      -E copiamos o nome_utente para o char auxiliar
 * -Se não tiver: 
 *      -Os passos são os mesmos mas a ler o nome de utente com strtok separamos com espaços
 * -Criamos uma string onde vai ficar o nome de utente final, e guardamos lá o nome do utente
 * -Guardamos após verificar e arranjar o nome de utente (pode dar erro de memória)
 * -Depois verificamos se existe um lote válido para a respetiva vacina
 * -E verificamos se o mesmo utente já tomou a respetiva vacina no mesmo dia 
 * -Quando estiver tudo verificado, guardamos no sistema todas as informações relativas á inoculacao
 * -Damos print do nome do lote e damos free da string auxiliar
 */
void aplica_Dose(Sistema *sys, char *input){     
    char *nome_utente, *nome_vacina;
    char nome_utente_final[MAXMAX] = "";
    nome_utente = strtok (input, " ");
    if (input[2] == '\"'){
        nome_utente = strtok (NULL, "\"");
        nome_vacina = strtok (NULL, " ");
        if (nome_vacina[strlen(nome_vacina) - 1] == '\n')
            nome_vacina[strlen(nome_vacina) - 1] = '\0';
        strcpy(nome_utente_final, nome_utente);}
    else{
        nome_utente = strtok(NULL, " ");
        strcpy(nome_utente_final, nome_utente);
        nome_vacina = strtok(NULL, " ");
        if (nome_vacina[strlen(nome_vacina) - 1] == '\n')
            nome_vacina[strlen(nome_vacina) - 1] = '\0';
    }
    char *utente_final = verifica_Arranja_NomeUtente(sys,nome_utente_final); if(utente_final == NULL) return;
    int i = procurarValido_LoteVacina(sys, nome_vacina); if (i == -1){ erro_VACUTENTE_put(sys);free(utente_final); return;}
    int u = procura_UtenteVacina(sys, utente_final, nome_vacina); if (u != -1){ erro_UTENTEVACC_put(sys); free(utente_final); return;}
    inoculacao_Inserir_Aplica(sys, utente_final, nome_vacina, sys->vacina[i].lote);
    sys->vacina[i].doses--;
    sys->vacina[i].inoctotal++; 
    printf("%s\n", sys->vacina[i].lote);
    free(utente_final);
}


