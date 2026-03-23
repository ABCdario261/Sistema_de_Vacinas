/**
 * @file lista_inoc.c
 * @brief Implementação do comando com letra 'u' relativo á listagem 
 *        de inoculações
 * @author ist1113459 GabrielMonte 
 * @see lista_inoc.h 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sistema.h"
#include "config.h"
#include "aux_essenciais.h"
#include "aux_hash.h"

/**
 * @brief Implementação de bubble_sort_por_ordem
 * @details O que a função faz: 
 * -Ao receber a lista de indice, primeiro vai contar quantos indices existem
 * -A lista vem sempre com um -1 (indice inválido) a sinalizar o final da lista
 * -A seguir utiliza o algoritmo bubble sort para ordenar os indices segundo a ordem das inoculações
 * -A hash table não é alterada, apenas a lista de indices
 * -Devolve a lista de indices ordenada por ordem 
 */
void bubble_sort_por_ordem(Sistema *sys, int *lista_indices) { //hashing_lista 
    int trocou;  
    int num_indices = 0;
    for (int i = 0; lista_indices[i] != -1; i++)
        num_indices++;
    for (int i = 0; i < num_indices - 1; i++) {
        trocou = 0;  
        for (int j = 0; j < num_indices - i - 1; j++) {
            if (sys->inoculacao_hash[lista_indices[j]]->ordem > sys->inoculacao_hash[lista_indices[j + 1]]->ordem) {
                int temp = lista_indices[j];
                lista_indices[j] = lista_indices[j + 1];
                lista_indices[j + 1] = temp;
                trocou = 1;  
            }
        }
        if (!trocou) break;
    }
}

/**
 * @brief Implementação de cria_Lista_Indice_ComUtente
 * @details O que a função faz: 
 * -Dado um nome do utente, calcula os indices e verifica quantos indices
 *  com o nome do utente estão preenchidos
 * -Criamos então uma lista de indices com tamanho do número de indices mais 1
 * -Percorremos outra vez a hash table e guardamos os indices do mesmo nome de utente
 *  na lista de inteiros
 * -Finalmente, quando não houver mais indices, colocamos -1 no final da lista a sinalizar
 *  que já não há mais indices a verificar
 * -Devolvemos a lista de indices
 */
int *cria_Lista_Indice_ComUtente(Sistema *sys, char *nome_utente){     
    int cont = 0;
    int hash_1 = hash1(nome_utente, sys->inoculacao_tamanho);
    int hash_2 = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[hash_1] != NULL){
        if (sys->inoculacao_hash[hash_1] != DEL && strcmp(nome_utente, sys->inoculacao_hash[hash_1]->nome) == 0)
            cont ++;
        hash_1 = (hash_1 + hash_2) % sys->inoculacao_tamanho;
    }    
    int *lista_indices = malloc((cont + 1) * sizeof(int));
    if (lista_indices== NULL) {sys->no_mem = 1; return NULL;}
    int j = 0;
    hash_1 = hash1(nome_utente, sys->inoculacao_tamanho);
    hash_2 = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[hash_1] != NULL){
        if (sys->inoculacao_hash[hash_1] != DEL && strcmp(nome_utente, sys->inoculacao_hash[hash_1]->nome) == 0)
            lista_indices[j++] = hash_1;
        hash_1 = (hash_1 + hash_2) % sys->inoculacao_tamanho;
    }
    lista_indices[j] = -1;
    return lista_indices;
}

/**
 * @brief Implementação de cria_Lista_Indice_SemUtente
 * @details O que a função faz: 
 * -Cria uma lista de indices com o tamanho de todas as inoculações existentes
 * -De seguida percorremos a hash table toda, e onde houver inoculações, guardamos 
 *  o indice na lista de indices
 * -Colocamos -1 no final da lista para sinalizar que acabou a lista 
 * -E devolvemos a lista
 */
int *cria_Lista_Indice_SemUtente(Sistema * sys){         //lista_inoc
    int j = 0;
    int *lista_indices = malloc((sys->contUtente + 1) * sizeof(int));
    if (lista_indices== NULL) {sys->no_mem = 1; return NULL;}
    for(int i = 0; i < sys->inoculacao_tamanho; i++){
        if(sys->inoculacao_hash[i] != NULL && sys->inoculacao_hash[i] != DEL)
            lista_indices[j++] = i;
    }
    lista_indices[j] = -1;
    return lista_indices;
}
/**
 * @brief Implementação de printa_Inoc_Utente
 * @details O que a função faz:
 * -Chamamos a função específica para criar a lista de indices respetivos ao nome do utente
 * -Mandamos ordenar com a lista com a função respetiva de ordenamento
 * -Como temos a lista ordenada, basta printar (pela ordem de esquerda á direta) as informações
 *  das inoculações nesses indices
 * -Damos free á lista que utilizamos
 */
void printa_Inoc_Utente (Sistema *sys, char* nome_utente){           //lista_inoc
    int* indice_utente = cria_Lista_Indice_ComUtente(sys, nome_utente);
    if (indice_utente == NULL) return;
    bubble_sort_por_ordem(sys,indice_utente);
    for (int i = 0; indice_utente[i] != -1; i++){
        printf("%s %s ", nome_utente, sys->inoculacao_hash[indice_utente[i]]->vacina.lote);
        printa_Data(sys->inoculacao_hash[indice_utente[i]]->data.dia,sys->inoculacao_hash[indice_utente[i]]->data.mes,sys->inoculacao_hash[indice_utente[i]]->data.ano);
        putchar('\n');
    }
    free(indice_utente);
}

/**
 * @brief Implementação de printa_Inoc_Utente
 * @details O que a função faz: 
 * -Mandamos criar uma lista com os indices todos ocupados por inoculações
 * -Mandamos ordenar a lista com a função respetiva de ordenamento
 * -E percorremos a lista de indices ordenada e printamos a respetiva informação da 
 *  inoculação de cada indice
 * -Damos free da lista que usamos
 */
void printa_Inoc_todas (Sistema *sys){           //lista_inoc
    int* indice_utente = cria_Lista_Indice_SemUtente(sys);
    if (indice_utente == NULL) return;
    bubble_sort_por_ordem(sys,indice_utente);
    for (int i = 0; indice_utente[i] != -1; i++){
        printf("%s %s ", sys->inoculacao_hash[indice_utente[i]]->nome, sys->inoculacao_hash[indice_utente[i]]->vacina.lote);
        printa_Data(sys->inoculacao_hash[indice_utente[i]]->data.dia,sys->inoculacao_hash[indice_utente[i]]->data.mes,sys->inoculacao_hash[indice_utente[i]]->data.ano);
        putchar('\n');
    }
    free(indice_utente);
}

/**
 * @brief Implementação de lista_InoculacaoUtente
 * @details O que a função faz: 
 * -Usamos o strtok para deitar fora o comando
 * -E usamos de novo o strtok para ober o nome do utente
 * -Se não for NULL :
 *      -Verificamos se o nome do utente tem aspas ou não
 *      -Após formatar bem o nome do utente verificamos se o utente existe
 *      -Se não existir levanta erro de utente não existente
 *      -Se existir printamos todas as informações das inoculações do utente
 * -Se for NULL :
 *      -Printamos todas as informações das inoculações de todos os utentes
 */
void lista_InoculacaoUtente(Sistema *sys, char *input){       //lista_inoc
    char *nome_utente;
    char nome_utente_final[MAXMAX] = "";
    int tamanho = strlen(input);
    nome_utente = strtok (input, " ");
    if(tamanho >= 3){
        if (input[2] == '\"'){
            nome_utente = strtok (NULL, "\"");
            if (nome_utente[strlen(nome_utente) - 1] == '\n')
                nome_utente[strlen(nome_utente) - 1] = '\0';
            strcpy(nome_utente_final, nome_utente);
        }else{
            nome_utente = strtok(NULL, " ");
            if (nome_utente[strlen(nome_utente) - 1] == '\n')
                nome_utente[strlen(nome_utente) - 1] = '\0';
            strcpy(nome_utente_final, nome_utente);
        }
        char *utente_final = verifica_Arranja_NomeUtente(sys, nome_utente_final); if(utente_final == NULL) return;
        if (procura_Utente(sys, utente_final) == -1){ printf("%s: ", utente_final); erro_NOUTENTE_put(sys); return;}
        printa_Inoc_Utente(sys, utente_final);
        free(utente_final);
    }else
        printa_Inoc_todas(sys); 
}





