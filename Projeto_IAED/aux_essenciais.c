/**
 * @file aux_essenciais.c
 * @brief Implementação de funções essenciais
 * @author ist1113459 GabrielMonte
 * @see aux_essenciais.h
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sistema.h"
#include "config.h"
#include "aux_essenciais.h"

/**
 * @brief Implementação de verifica_bissexto
 * @details Anos são bissextos se for um ano:
 * -Divisível por 4, exceto múltiplo de 100 não divisível por 400
 */
int verifica_Bissexto (int ano){   
    int bissexto = 0;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        bissexto = 1;
    return bissexto;
}

/**
 * @brief Implementação de verifica_Data_Valida
 * @details O que a função faz:
 * -Usa verifica_Bissexto() para verificar se o ano é bissexto
 * -Utiliza-se um switch para separar os meses com (30/31/28) dias
 * -Será uma data inválida se o dia for menor que 0 e maior que o máx do respetivo mês
 */
int verifica_Data_Valida (int dia, int mes, int ano){   
    int bissexto = verifica_Bissexto (ano);
    switch(mes){
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if ((dia <= 0) || (dia > 31))
                return -1; 
            break;
        case 4: 
        case 6:
        case 9:
        case 11:
            if ((dia <= 0) || (dia > 30))
                return -1; 
            break;
        case 2: 
            if(((bissexto == 0 && ((dia <= 0) || (dia > 28)))) || (bissexto == 1 && ((dia <= 0) || (dia > 29)))) //Se o ano for bissexto
                return -1;
            break;
        default: return -1;
    }
    return 0;
}

/**
 * @brief Implementação do verifica_Data_Sistema
 * @details O que a função faz:
 * -Compara a data que a do sistema
 * -Retorna um determinado valor se for igual, maior ou menor
 */
int verifica_Data_Sistema (Sistema *sys, int dia, int mes, int ano){     
    if (ano < sys->data.ano)
        return -1;

    if (ano == sys->data.ano){
        if(mes < sys->data.mes)
            return -1;
    }
    if ((ano == sys ->data.ano) && (mes == sys->data.mes)){
        if (dia < sys->data.dia)
            return -1;
    }
    if ((ano == sys ->data.ano) && (mes == sys->data.mes) && (dia == sys->data.dia))
        return 2;
    
    return 0;
}

/**
 * @brief Implementação do verifica_Data_Completa
 * @details O que a função faz:
 * -Chama verifica_Data_valida para verificar se a data é válida ou não
 * -Após saber que é válida, devolve o return do verifica_Data_Sistema
 */
int verifica_Data_Completa (Sistema *sys, int dia, int mes, int ano){    
    if (verifica_Data_Valida(dia, mes, ano) != 0)
        return 1;
    return verifica_Data_Sistema(sys, dia, mes, ano);
}

/**
 * @brief Implementação do printa_Data
 * @details O que a função faz:
 * -Dá print da data dada considerando dois fatores:
 *      -Se o dia tem um ou dois valores (Se tiver um adiciona zero antes)
 *      -Se o mês tem um ou dois valores (Se tiver um adiciona zero antes)
 */
void printa_Data(int dia, int mes, int ano){     
    if ((dia >= 10) && (mes >= 10))
        printf("%d-%d-%d", dia, mes, ano);
    else if (mes >= 10)
        printf("0%d-%d-%d", dia, mes, ano);
    else if (dia >= 10)
        printf("%d-0%d-%d", dia, mes, ano);
    else
        printf("0%d-0%d-%d", dia, mes, ano);
}

/**
 * @brief Implementação do saltaPrinta_Data
 * @details O que a função faz:
 * -Verifica se o utilizador pôs uma data
 * -Se pôs: 
 *      -Lê o dia o mês e o ano
 *      -Usando verifica_Data_Completa, verifica a data
 *      -Neste caso, a data tem que ser superior ou igual á data do sistema
 *      -Se for o caso, muda a data do sistema e printa a nova data
 *      -Se não for o caso devolve erro de data inválida
 * -Se não pôs: 
 *      -Simplesmente dá print da data do sistema
 */
void saltaPrinta_Data(Sistema *sys, char *input){      
    char *data;
    int dia, mes, ano;
    data = strtok(input, " ");
    data = strtok(NULL, " ");
    if (data != NULL){
        sscanf(data,"%d-%d-%d", &dia, &mes, &ano);
        if((verifica_Data_Completa(sys, dia, mes, ano) != -1) && (verifica_Data_Completa(sys, dia, mes, ano) != 1)){
            sys->data.dia = dia;
            sys->data.mes = mes;
            sys->data.ano = ano;
        } else{
            if (sys->estado == 0)
                puts(EDATE);
            else
                puts(EDATEPT);
            return;}
        printa_Data(sys->data.dia, sys->data.mes, sys->data.ano);
        putchar('\n');
    }
    else{
        printa_Data(sys->data.dia, sys->data.mes, sys->data.ano);
        putchar('\n');
    }
}

/**
 * @brief Implementação do erro_VACUTENTE_put
 * @details O que a função faz:
 * -Esta função só é chamada se houver erro
 * -Simplesmente devolve a mensagem de erro dependendo da linguagem do sistema
 * @note Implementada para mais simplificação
 */
void erro_VACUTENTE_put(Sistema *sys){        
    if(sys->estado == 0)
        puts(E0VACUTENTE);
    else
        puts(E0VACUTENTEPT);
    return;
}

/**
 * @brief Implementação do erro_UTENTEVACC_put
 * @details O que a função faz:
 * -Esta função só é chamada se houver erro
 * -Simplesmente devolve a mensagem de erro dependendo da linguagem do sistema
 * @note Implementada para mais simplificação
 */
void erro_UTENTEVACC_put(Sistema *sys){          
    if(sys->estado == 0)
        puts(EUTENTEVACC);
    else
        puts(EUTENTEVACCPT);
    return;
}


/**
 * @brief Implementação do erro_NOUTENTE_put
 * @details O que a função faz:
 * -Esta função só é chamada se houver erro
 * -Simplesmente devolve a mensagem de erro dependendo da linguagem do sistema
 * @note Implementada para mais simplificação
 */
void erro_NOUTENTE_put (Sistema *sys){         
    if (sys->estado == 0)
        puts(ENOUTENTE);
    else 
        puts(ENOUTENTEPT);
    return;
}

/**
 * @brief Implementação do erro_NOLOTE_put
 * @details O que a função faz:
 * -Esta funçáo só é chamada se houver erro
 * -Simplesmente devolve a mensagem de erro dependendo da linguagem do sistema 
 * @note Implementada para mais simplificação
 */
void erro_NOLOTE_put (Sistema *sys){  
    if(sys->estado == 0)
        puts(ENOLOTE);
    else
        puts(ENOLOTEPT);
    return;
}

/**
 * @brief implementação do verifica_Arranja_NomeUtente
 * @details O que a função faz:
 * -Recebe o nome do utente e alocamos memória para guardar esse nome de utente numa string
 * -Se não tiver memória devolve erro de memória
 * -E agora arranja o nome do utente dependendo da sua formatação
 * -Se o nome do utente tiver aspas no inicio e fim:
 *      -Retiramos as aspas
 *      -Adicionamos '\0' no final
 *      -Copiamos a string para a string que criamos
 * -Se não tiver aspas, simplesmente copiamos
 * -Devolvemos então essa string com o nome do utente
 */
char* verifica_Arranja_NomeUtente(Sistema *sys, char* nome_utente_final){       
    char *utente_final = malloc(strlen(nome_utente_final) + 1);
    if (utente_final == NULL){sys->no_mem = 1; return NULL;}
    if ((nome_utente_final[0] == '\"') && (nome_utente_final[strlen(nome_utente_final) - 1] == '\"')){
        int tamanho = strlen(nome_utente_final);
        strncpy(utente_final, nome_utente_final + 1, tamanho - 2); 
        utente_final[tamanho - 2] = '\0'; 
    }else{
        strcpy(utente_final,nome_utente_final);
    }
    return (utente_final);
}