/**
 * @file aux_hash.c
 * @brief Implementação de funções essenciais para 
 *        qualquer tipo de funções relacionadas com hash
 * @author ist1113459 GabrielMonte
 * @see aux_hash.h
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sistema.h"
#include "config.h"
#include "aux_hash.h"

/**
 * @brief Implementação de proximo_primo
 * @details O que a função faz:
 * -Recebe o inteiro e:
 *      -Caso seja par aumenta 1 valor
 *      -Caso seja ímpar aumenta 2 valores
 *      -Para aumentar eficiencia 
 * -Faz verificação até à raiz de n
 * -Devolve esse primo
 */
int proximo_primo(int n) {  
    n = (n % 2 == 0) ? n + 1 : n + 2;
    while (1) {
        int primo = 1;
        for (int i = 3; i*i <= n; i += 2) {
            if (n % i == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) return n;
        n += 2; 
    }
}

/**
 * @brief Implementação de hash1
 * @details O que a função faz: 
 * -Recebe a string e o tamanho da hash table
 * -Com esses dados, e com números primos diferentes e relativamente grandes (para evitar colisões)
 * calculamos um indice (que esteja dentro da hash table) que é específico para essa string
 * -Devolvemos esse indice
 */
int hash1(char *v, int M){     
    int h, a = 31415, b = 27183;
    for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    return h;
}

/**
 * @brief Implementação de hash2
 * @details O que a função faz:
 * -Recebe a string e o tamanho da hash table
 * -Com esses dados, e com números primos diferentes e relativamente grandes (para evitar colisões)
 * calculamos um valor (que esteja dentro da hash table) que é específico para essa string
 * para depois calcular outro indice caso o indice inicial esteja ocupado
 * -Devolvemos esse valor
 */
int hash2(char *v, int M) {        
    unsigned long h = 0;
    int a = 63689, b = 378551; 
    for (; *v != '\0'; v++) {
        h = (h * a + *v) % M;
        a = a * b % (M - 1); 
    }
    return (h % (M - 1)) + 1;
}

/**
 * @brief Implementação de inoculacao_Inserir
 * @details O que a função faz: 
 * -Dada uma hash table antiga e uma nova calculamos novos indices para os utentes
 * -E guardamos na nova
 */
void inoculacao_Inserir(Sistema *sys, Inoculacao *nova){      
    char *nome_utente = nova->nome;
    int i = hash1(nome_utente, sys->inoculacao_tamanho);
    int k = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[i] != NULL)
        i = (i+k) % sys->inoculacao_tamanho;
    sys->inoculacao_hash[i] = nova;
    sys->contUtente++;
}

/**
 * @brief Implementação de aumentar_TamanhoInoc
 * @details O que a função faz: 
 * -Guarda a hash table atual do sistema
 * -Duplica o tamanho da hash table atual e encontra o primo mais próximo
 * -Apagamos todas as informações da hash table do sistema e alocamos a memória
 *  com o novo tamanho e inicializamos tudo a NULL
 * -Depois copiamos toda a informação (tirando as inoculações apagadas) da hash table antiga para a nova com os novos indices
 * -Damos free á cópia da hash table antiga que fizemos no inicio
 */
void aumentar_TamanhoInoc (Sistema *sys){            
    Inoculacao **tabela_original = sys->inoculacao_hash;
    int tamanho_antigo = sys->inoculacao_tamanho;
    int tamanho_aum = proximo_primo(2 * tamanho_antigo);
    sys->inoculacao_hash = calloc(tamanho_aum, sizeof(Inoculacao*));
    if (sys->inoculacao_hash == NULL) {sys->no_mem = 1; return;}
    sys->inoculacao_tamanho = tamanho_aum;
    sys->contUtente = 0;
    for (int i = 0; i < tamanho_antigo; i++){
        if (tabela_original[i] != NULL && tabela_original[i] != DEL)
            inoculacao_Inserir(sys, tabela_original[i]);
    }
    free(tabela_original);
}

/**
 * @brief Implementação de procura_Utente
 * @details O que a função faz:
 * -Dado a string nome_utente e o tamanho da hash table do sistema
 *  Calculamos os respetivos indices e caso encontrar mos uma posição que não seja vazia ou apagada
 *  retornamos que existe o utente
 * -
 */
int procura_Utente(Sistema *sys, char* nome_utente){          
    int i = hash1(nome_utente, sys->inoculacao_tamanho);
    int k = hash2(nome_utente, sys->inoculacao_tamanho);
    while (sys->inoculacao_hash[i] != NULL){
        if (sys->inoculacao_hash[i] != DEL && (strcmp(nome_utente, sys->inoculacao_hash[i]->nome) == 0)){
            return 1;
        }
        i = (i + k) % sys->inoculacao_tamanho;
    }
    return -1;
}