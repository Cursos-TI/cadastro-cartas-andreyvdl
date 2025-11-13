#include "CartasSuperTrunfo.h"
#include <stdio.h>

#include "funcoesLeitoras.c"

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.
void imprimirCarta(Trunfo *carta) {
  printf(
    "Carta %d:\n"
    "Estado: %c\n"
    "Código: %s\n"
    "Nome da Cidade: %s\n"
    "População: %d\n"
    "Área: %.2f Km²\n"
    "PIB: %.2f Bilhões de reais\n"
    "Número de Pontos Turísticos: %d\n\n",
    carta->id,
    carta->estado,
    carta->codigo_da_carta,
    carta->nome_da_cidade,
    carta->populacao,
    carta->area,
    carta->pib,
    carta->num_pontos_turisticos
  );
}

void lerEntrada(Trunfo *cartas, size_t posicao) {
  lerEstado(cartas + posicao);
  // Codigo é o unico dado exclusivo
  lerCodigo(cartas, posicao);
  lerNome(cartas + posicao);
  lerPopulacao(cartas + posicao);
  lerArea(cartas + posicao);
  lerPIB(cartas + posicao);
  lerPontosTuristicos(cartas + posicao);
}

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  Trunfo cartas[2] = {0};

  // Área para entrada de dados
  for (size_t i = 0; i < 2; ++i) {
    cartas[i].id = i + 1;
    printf("Por favor insira as informações da carta carta conforme requisitado!\n");
    lerEntrada(cartas, i);
  }

  // Área para exibição dos dados da cidade
  for (int i = 0; i < 2; ++i)
    imprimirCarta(cartas + i);

  return 0;
} 
