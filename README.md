# Sistema de Gestão de Vacinas (IAED)

Este projeto é um sistema de gestão de vacinas e das respetivas inoculações, desenvolvido para a disciplina de IAED. 
Permite registar lotes de vacinas, controlar doses disponíveis, aplicar vacinas a utentes e gerir a informação de forma organizada.

## Funcionalidades principais
- Inserção de lotes de vacinas com doses iniciais (`c`)
- Listagem de vacinas disponíveis (`l`)
- Aplicação de doses a utentes (`a`)
- Remoção de vacinas (`r`) e registos de aplicações (`d`)
- Consulta de aplicações por utente (`u`)
- Simulação de passagem de tempo (`t`)
- Saída do programa (`q`)

> A interação é feita através de linhas de comando, onde cada comando aceita um número específico de argumentos.

## Tecnologias e conceitos aplicados
- Linguagem: C
- Estruturas de dados:
  - Arrays de structs para vacinas  
  - Hash tables para armazenar inoculações por utente
- Algoritmos:
  - Sorts para listagem ordenada de vacinas/utentes
- Gestão de memória dinâmica
- Modularização em `.h` e `.c`  

## Como compilar e executar
