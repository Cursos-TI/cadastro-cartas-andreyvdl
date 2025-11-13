#include "CartasSuperTrunfo.h"
#include <stdio.h>
#include <sys/types.h>

#include "funcoesLeitoras.c"

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

/*
static void imprimirCarta(Trunfo *carta) {
  printf(
    "Carta %d:\n"
    "Estado: %c\n"
    "Código: %s\n"
    "Nome da Cidade: %s\n"
    "População: %d\n"
    "Área: %.2f Km²\n"
    "PIB: %.2f Bilhões de reais\n"
    "Número de Pontos Turísticos: %d\n"
    "Densidade Populacional: %.2f hab/km²\n"
    "PIB per Capita: %.2f reais\n\n",
    carta->id,
    carta->estado,
    carta->codigo_da_carta,
    carta->nome_da_cidade,
    carta->populacao,
    carta->area,
    carta->pib,
    carta->num_pontos_turisticos,
    carta->densidade_populacional,
    carta->pib_per_capita
  );
}
*/

static void compararCartas(Trunfo cartas[2]) {
  printf("Comparação de Cartas:\n");

  if (cartas[0].populacao > cartas[1].populacao)
    printf("População: Carta 1 venceu (1)\n");
  else
    printf("População: Carta 2 venceu (0)\n");

  if (cartas[0].area > cartas[1].area)
    printf("Área: Carta 1 venceu (1)\n");
  else
    printf("Área: Carta 2 venceu (0)\n");

  if (cartas[0].pib > cartas[1].pib)
    printf("PIB: Carta 1 venceu (1)\n");
  else
    printf("PIB: Carta 2 venceu (0)\n");

  if (cartas[0].num_pontos_turisticos > cartas[1].num_pontos_turisticos)
    printf("Pontos Turísticos: Carta 1 venceu (1)\n");
  else
    printf("Pontos Turísticos: Carta 2 venceu (0)\n");

  if (cartas[0].densidade_populacional < cartas[1].densidade_populacional)
    printf("Densidade Populacional: Carta 1 venceu (1)\n");
  else
    printf("Densidade Populacional: Carta 2 venceu (0)\n");

  if (cartas[0].pib_per_capita > cartas[1].pib_per_capita)
    printf("PIB per Capita: Carta 1 venceu (1)\n");
  else
    printf("PIB per Capita: Carta 2 venceu (0)\n");

  if (cartas[0].super_poder > cartas[1].super_poder)
    printf("Super Poder: Carta 1 venceu (1)\n");
  else
    printf("Super Poder: Carta 2 venceu (0)\n");
}

static void lerEntrada(Trunfo *cartas, size_t posicao) {
  lerEstado(cartas + posicao);
  // Codigo é o unico dado exclusivo
  lerCodigo(cartas, posicao);
  lerNome(cartas + posicao);
  lerPopulacao(cartas + posicao);
  lerArea(cartas + posicao);
  lerPIB(cartas + posicao);
  lerPontosTuristicos(cartas + posicao);
  printf("\n"); // por questões de legibilidade no terminal
}

static inline void calcularDensidade(Trunfo *carta) {
  carta->densidade_populacional = (float)carta->populacao / carta->area;
}

static inline void calcularPIBPerCapita(Trunfo *carta) {
  carta->pib_per_capita = carta->pib / (float)carta->populacao;
}

static void calcularSuperPoder(Trunfo *carta) {
  float inverso = 1 / carta->densidade_populacional;

  carta->super_poder = (float)carta->populacao
    + carta->area
    + carta->pib
    + (float)carta->num_pontos_turisticos
    + carta->pib_per_capita
    + inverso;
}

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  Trunfo cartas[2] = {0};

  // Área para entrada de dados
  for (size_t i = 0; i < 2; ++i) {
    cartas[i].id = i + 1;
    printf("Por favor insira as informações da carta %zu conforme requisitado!\n", i + 1);
    lerEntrada(cartas, i);
  }

  // Tema 2 - Densidade populacional e PIB per capita
  for (int i = 0; i < 2; ++i) { 
    calcularDensidade(cartas + i);
    calcularPIBPerCapita(cartas + i);
    // Tema 3 - Batalha de Cartas
    calcularSuperPoder(cartas + i);
  }

  // Área para exibição dos dados da cidade
  /*
  for (int i = 0; i < 2; ++i)
    imprimirCarta(cartas + i);
  */
  compararCartas(cartas);

  return 0;
} 
