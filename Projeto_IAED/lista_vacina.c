/**
 * @file lista_vacina.c 
 * @brief Implementação do comando 'l' relativo á listagem das vacinas
 * @author ist1113459 GabrielMonte
 * @see lista_vacina.h 
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
 * @brief Implementação de lista_LoteVacina
 * @details O que a função faz: 
 * -Cria uma string onde vamos guardar o nome ou nomes das vacinas dadas
 * -Usa strtok (separados por espaços) para tirar a letra 'l' relativa ao comando
 * -E usamos outra vez para obter o nome da vacina
 * -Verificamos se o nome da vacina não veio NULL
 * -Se não veio NULL : 
 *      -Criamos um while até que o nome da vacina venha NULL
 *      -"Arranjamos" o nome da vacina (pois se for o último vem com '\n')
 *      -Verificamos se o nome da vacina é válido
 *      -Se não for levanta erro de nome inválido mas continua a listagem
 *      -De seguida verificamos se a vacina já existe no sistema e obtemos o indice
 *      -Se o indice for inválido levanta erro de vacina inválida mas continua a listagem
 *      -Se tudo passar nas verificações, damos print da informação do lote e seguimos para o próximo (se houver)
 * -Se veio NULL :
 *      -Corremos um for pela lista de vacinas toda e damos print das informações de todas as vacinas
 * @note Se houver erros, a função lê imediatamente o próximo nome
*/
void lista_LoteVacina(Sistema *sys, char *input) {     //Vacina
    char *nome;
    nome = strtok(input, " "); 
    nome = strtok (NULL, " ");
    if (nome != NULL){ 
        while (nome != NULL) {
        int tamanho = strlen(nome);
        if (nome[tamanho - 1] == '\n')
            nome[tamanho - 1] = '\0';
        if (verifica_Nomevacina(sys, nome) == -1){
            nome = strtok(NULL, " ");
            continue;
        }
        int i = procurar_LoteVacina(sys, nome);
        if (verifica_Existe_Lotevacina(sys, nome, i) == -1){
            nome = strtok(NULL, " ");
            continue;
        }
        print_LoteVacina(sys, i); 
        nome = strtok(NULL, " ");  
        }
    }
    else{
        int i = 0;
        for (i = 0; i < sys->contLote ; i++){
        print_LoteVacina(sys, i);
        }
    }
}