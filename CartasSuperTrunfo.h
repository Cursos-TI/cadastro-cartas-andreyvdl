#ifndef _CARTAS_SUPER_TRUNFO_H
    #define _CARTAS_SUPER_TRUNFO_H 1

    #define CODIGO_TAMANHO 4
    #define CIDADE_TAMANHO 256
/**
 * Estado: Uma letra de 'A' a 'H' (representando um dos oito estados). Tipo: char
 * Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03). Tipo: char[] (um array de caracteres, ou string)
 * Nome da Cidade: O nome da cidade. Tipo: char[] (string)
 * População: O número de habitantes da cidade. Tipo: int
 * Área (em km²): A área da cidade em quilômetros quadrados. Tipo: float
 * PIB: O Produto Interno Bruto da cidade. Tipo: float
 * Número de Pontos Turísticos: A quantidade de pontos turísticos na cidade. Tipo: int
 */
typedef struct Trunfo {
    char nome_da_cidade[CIDADE_TAMANHO], codigo_da_carta[CODIGO_TAMANHO];
    float area, pib, densidade_populacional, pib_per_capita;
    int num_pontos_turisticos, populacao, id;
    char estado;
} Trunfo;

#endif