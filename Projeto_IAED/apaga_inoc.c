/**
 * @file apaga_inoc.c 
 * @brief Implementação do comando com letra 'd' relativo à eliminação
 *        de inoculações do utente 
 * @author ist1113459 GabrielMonte
 * @see apaga_inoc.h 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sistema.h"
#include "config.h"
#include "aux_essenciais.h"
#include "aux_hash.h"
#include "aux_vacinas.h"

/**
 * @brief Implementação de verifica_Arranja_DataApagaInoc_dia
 * @details O que a função faz: 
 * -Criamos um inteiro onde vamos guardar o dia
 * -Como recebemos o dia com um espaço antes do número, apagamos esse espaço
 * -Obtemos o tamanho da string com o dia e transformamos em inteiro
 * -Devolvemos o inteiro
 */
int verifica_Arranja_DataApagaInoc_Dia(char* diach){
    int dia = 0;
    while (*diach == ' ')
        diach++;
    int tamanho = strlen(diach);
    for (int i = 0; i < tamanho; i++)
        dia = (dia * 10) + (diach[i] - '0');
    return dia;
}
 /**
  * @brief Implementação de verifica_Arranja_DataApagaInoc_Mes
  * @details O que a função faz: 
  * -Criamos um inteiro onde vamos guardar o mês
  * -Obtemos o tamanho da string com o mês e transformamos em inteiro
  * -Devolvemos o inteiro
  */
int verifica_Arranja_DataApagaInoc_Mes(char* mesch){
    int mes = 0,tamanho = strlen(mesch);
    for (int i = 0; i < tamanho; i++)
        mes = (mes * 10) + (mesch[i] - '0');
    return mes;
}

/**
 * @brief Implementação de verifica_Arranja_DataApagaInoc_Ano
 * @details O que a função faz: 
 * -Criamos um inteiro onde vamos guardar o ano
 * -Obtemos o tamanho da string com o mês e transformamos em inteiro
 * -Devolvemos o inteiro
 */
int verifica_Arranja_DataApagaInoc_Ano(char* anoch){
    int ano = 0, tamanho = strlen(anoch);
    for (int i = 0; i < tamanho; i++)
        if( anoch[i] != '\n')
            ano = (ano * 10) + (anoch[i] - '0');
    return ano;

}

/**
 * @brief Implementação de verifica_Arranja_DataApagaInoc_Total
 * @details O que a função faz: 
 * -Verifica a data consoante o dia, mês e ano dado com a do sistema
 * -Se a data estiver válida devolve 1
 * -Se a data não for válida levanta erro e devolve -1
 */
int verifica_Arranja_DataApagaInoc_Total(Sistema *sys, int dia, int mes, int ano){
    if((verifica_Data_Completa(sys, dia, mes ,ano) != -1) && (verifica_Data_Completa(sys, dia, mes ,ano) != 2)){
        if(sys->estado == 0)
            puts(EDATE);
        else
            puts(EDATEPT);
        return -1;
    }
    return 1;
}

/**
 * @brief Implementação de retira_Utente
 * @details O que a funçao faz: 
 * -Procuramos os respetivos indices para o nome do utente na hash table
 * -Se na posição indice da hash table, o conteudo não for nulo, nem apagado, e que tenha
 *  a informação quanto ao nome do utente e a data igual, damos free do hash nessa posição
 * -E marcamos essa posição na hash table como apagado
 */
void retira_Utente(Sistema *sys, char* nome_utente, int dia, int mes, int ano){
    int i = hash1(nome_utente, sys->inoculacao_tamanho);
    int k = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[i] != NULL){
        if(sys->inoculacao_hash[i] != DEL && (strcmp(sys->inoculacao_hash[i]->nome, nome_utente) == 0) && (sys->inoculacao_hash[i]->data.dia == dia) && (sys->inoculacao_hash[i]->data.mes == mes) && (sys->inoculacao_hash[i]->data.ano == ano)){
            free(sys->inoculacao_hash[i]->nome); free(sys->inoculacao_hash[i]->vacina.nome); free(sys->inoculacao_hash[i]->vacina.lote); free(sys->inoculacao_hash[i]); sys->inoculacao_hash[i] = DEL; sys->contUtente--;
        }
        else i = (i + k) % sys->inoculacao_tamanho;
    }
}


/**
 * @brief Implementação de retira_UtenteComLote
 * @details O que a funçao faz: 
 * -Procuramos os respetivos indices para o nome do utente na hash table
 * -Se na posição indice da hash table, o conteudo não for nulo, nem apagado, e que tenha
 *  a informação quanto ao nome do utente, data igual e o mesmo nome de lote, damos free do hash nessa posição
 * -E marcamos essa posição na hash table como apagado
 */

void retira_UtenteComLote(Sistema *sys, char* nome_utente, char* nome_lote, int dia, int mes, int ano ){
    int i = hash1(nome_utente, sys->inoculacao_tamanho);
    int k = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[i] != NULL ){
        if(sys->inoculacao_hash[i] != DEL && (strcmp(sys->inoculacao_hash[i]->nome, nome_utente) == 0) && (strcmp(sys->inoculacao_hash[i]->vacina.lote, nome_lote) == 0) && (sys->inoculacao_hash[i]->data.dia == dia) && (sys->inoculacao_hash[i]->data.mes == mes) && (sys->inoculacao_hash[i]->data.ano == ano)){
            free(sys->inoculacao_hash[i]->nome); free(sys->inoculacao_hash[i]->vacina.nome); free(sys->inoculacao_hash[i]->vacina.lote); free(sys->inoculacao_hash[i]); sys->inoculacao_hash[i] = DEL; sys->contUtente--; 
        }
        else i = (i + k) % sys->inoculacao_tamanho;
    }
}

/**
 * @brief Implementação de apaga_Inoc_SemLote
 * @details O que a função faz: 
 * -Chama retira_Utente() para apagar as informações quando á hash table
 * -E printa quantas inoculações do utente apagámos
 */
void apaga_Inoc_SemLote(Sistema *sys, char *nome_utente, int aplica_inicial, int dia, int mes, int ano){
    retira_Utente(sys, nome_utente, dia, mes, ano);
    int aplica_final = aplica_inicial - (sys->contUtente);
    printf("%d\n", aplica_final);
}

/**
 * @brief Implementação de apaga_Inoc_ComLote
 * @details O que a função faz: 
 * -Chama retira_UtenteComLote() para apagar as informações quando á hash table
 * -E printa quantas inoculações do utente apagámos
 */
void apaga_Inoc_ComLote(Sistema *sys, char *nome_utente, char *nome_lote, int aplica_inicial, int dia, int mes, int ano){
    retira_UtenteComLote(sys, nome_utente, nome_lote, dia, mes, ano);
    int aplica_final = aplica_inicial - (sys->contUtente);
    printf("%d\n", aplica_final);
}

/**
 * @brief Implementação de arranjar_NomeUtente_ApagaInoc
 * @details O que a função faz: 
 * -Com strtok, deitamos fora o comando da função e obtemos o nome do utente
 * -Fazemos a devida verifcação com as aspas e formatamos o nome do utente
 * -Devolve mos o nome do utente bem formatado
 */
char *arrajar_NomeUtente_ApagaInoc(char *input){
    char *nome_utente, nome_utente_final[MAXMAX] = "";
    nome_utente = strtok(input, " ");
    if (input[2] == '\"'){
        nome_utente = strtok (NULL, "\"");
        if (nome_utente[strlen(nome_utente) - 1] == '\n')
            nome_utente[strlen(nome_utente) - 1] = '\0';
        strcpy(nome_utente_final, nome_utente);
    }else if (input[2] != '\0'){
        nome_utente = strtok(NULL, " ");
        if (nome_utente[strlen(nome_utente) - 1] == '\n')
            nome_utente[strlen(nome_utente) - 1] = '\0';
        strcpy(nome_utente_final, nome_utente);
    } 
    return nome_utente;
}

/**
 * @brief Implementação de apaga_Inoculacao
 * @details O que a função faz: 
 * -Inicializamos as variáveis todas, e guardamos o número de inoculacoes totais atuais
 * -Lê-mos e formatamos o nome do utente e verificamos se ele existe
 * -Se não existir levantamos erro de utente não existente
 * -De seguida lê-mos a data
 * -Se a data for NULL :
 *      -Apagamos todas as inoculações do utente
 * -Se a data não for NULL : 
 *      -Arranjamos as datas e verificamos se são válidas
 *      -De seguida lê-mos o nome do lote
 *      -Se o nome do lote for NULL : 
 *          -Apagamos todas as inoculações do utente na data dada
 *      -Se o nome do lote não for NULL : 
 *          -Apagamos todas as inoculações do utente na data dada e no lote dado
 */
void apaga_Inoculacao(Sistema *sys, char *input){
    char *nome_utente, *diach, *mesch, *anoch;
    int aplica_inicial = sys->contUtente, dia = 0, mes = 0, ano = 0;
    nome_utente = arrajar_NomeUtente_ApagaInoc(input);
    if (procura_Utente(sys, nome_utente) == -1){ printf("%s: ", nome_utente); erro_NOUTENTE_put(sys); return;}
    diach = strtok(NULL, "-");
    if(diach != NULL){
        dia = verifica_Arranja_DataApagaInoc_Dia(diach);
        mesch = strtok(NULL, "-");
        mes = verifica_Arranja_DataApagaInoc_Mes(mesch);
        anoch = strtok(NULL, " ");
        ano = verifica_Arranja_DataApagaInoc_Ano(anoch);
        if(verifica_Arranja_DataApagaInoc_Total(sys, dia, mes, ano) == -1) return;
        char *nome_lote = strtok (NULL, " ");
        if(nome_lote == NULL){
            apaga_Inoc_SemLote(sys, nome_utente, aplica_inicial, dia, mes, ano);
        }
        else{
            if (nome_lote[strlen(nome_lote) - 1] == '\n')
                nome_lote[strlen(nome_lote) - 1] = '\0';
            if(procurar_Lote(sys, nome_lote) == -1){ printf("%s: ", nome_lote); erro_NOLOTE_put(sys); return;}
            apaga_Inoc_ComLote(sys, nome_utente, nome_lote, aplica_inicial, dia, mes, ano);
        }
    }else{
        apaga_Inoc_SemLote(sys, nome_utente, aplica_inicial, sys->data.dia, sys->data.mes, sys->data.ano);
    }
} 
