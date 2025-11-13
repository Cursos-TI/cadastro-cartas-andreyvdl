#include "CartasSuperTrunfo.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int codigoInvalido(char *codigo_input, Trunfo *cartas, size_t posicao);

void lerEstado(Trunfo *carta) {
  char estado = '\0';
  int cursor = 0;

  while (1) {
    printf("Insira o Estado, deve ser uma letra de 'A' a 'H': ");
    if (scanf("%c", &estado) == EOF)
      exit(1);

    estado = toupper(estado);

    if (estado < 'A' || estado > 'H') {
      printf("Valor inserido é invalido!\n");
      estado = '\0';
      while((cursor = getchar()) != '\n' && cursor != EOF);
    } else {
      carta->estado = estado;
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

void lerCodigo(Trunfo *cartas, size_t posicao) {
  char codigo_da_carta[CODIGO_TAMANHO] = {0};
  int cursor = 0;

  while (1) {
    printf(
      "Insira o código da carta, "
      "deve ter três caracteres, o primeiro sendo o mesmo do estado "
      "e os outros dois um numero de 01 a 04: "
    );
    if (scanf("%3s", codigo_da_carta) == EOF)
      exit(1);

    codigo_da_carta[0] = toupper(codigo_da_carta[0]);

    if (codigoInvalido(codigo_da_carta, cartas, posicao)) {
      printf("Valor inserido é invalido!\n");
      for (int i = 0; i < CODIGO_TAMANHO; ++i)
        codigo_da_carta[i] = '\0';
      while((cursor = getchar()) != '\n' && cursor != EOF);
    } else {
      for (int i = 0; i < CODIGO_TAMANHO; ++i)
        cartas[posicao].codigo_da_carta[i] = codigo_da_carta[i];
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

void lerNome(Trunfo *carta) {
  char nome_da_cidade[CIDADE_TAMANHO] = {0};
  int cursor = 0;

  while (1) {
    printf(
      "Insira o nome da cidade, limite de 255 caracteres, "
      "os caracteres extras serão ignorados: "
    );
    if (scanf("%255[^\n]", nome_da_cidade) == EOF)
      exit(1);

    if (strlen(nome_da_cidade) == 0) {
      printf("O nome da cidade não pode ser deixado em branco!\n");
    } else {
      for (int i = 0; nome_da_cidade[i]; ++i)
        carta->nome_da_cidade[i] = nome_da_cidade[i];
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

void lerPopulacao(Trunfo *carta) {
  unsigned long int populacao = 0;
  int cursor = 0;

  while (1) {
    printf("Insira o número de habitantes, como número inteiro: ");
    if (scanf("%lu", &populacao) == EOF)
      exit(1);

    if (populacao == 0) {
      printf("População não pode ser igual a 0!\n");
      populacao = 0;
      while((cursor = getchar()) != '\n' && cursor != EOF);
    } else {
      carta->populacao = populacao;
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

void lerArea(Trunfo *carta) {
  float area = 0.f;
  int cursor = 0;

  while (1) {
    printf("Insira a área da cidade em Km² no formato decimal (ex: 120.64): ");
    if (scanf("%f", &area) == EOF)
      exit(1);

    if (area < 0.000001f) { // 6 de precisão deve ser o suficiente
      printf("Área não pode ser igual ou menor a 0!\n");
      area = 0.f;
      while((cursor = getchar()) != '\n' && cursor != EOF);
    } else {
      carta->area = area;
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

void lerPIB(Trunfo *carta) {
  float pib = 0.f;
  int cursor = 0;

  while (1) {
    printf("Insira o PIB em bilhões no formato decimal (ex: 28.16): ");
    if (scanf("%f", &pib) == EOF)
      exit(1);

    if (pib < 0.f) {
      printf("PIB não pode ser negativo!\n");
      pib = 0.f;
      while((cursor = getchar()) != '\n' && cursor != EOF);
    } else {
      carta->pib = pib;
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

void lerPontosTuristicos(Trunfo *carta) {
  int pontos_turisticos = 0;
  int cursor = 0;

  while (1) {
    printf("Insira o número de pontos turísticos da cidade, como número inteiro: ");
    if (scanf("%d", &pontos_turisticos) == EOF)
      exit(1);

    if (pontos_turisticos < 0) {
      printf("Pontos turísticos não pode ser negativo!\n");
      pontos_turisticos = 0;
      while((cursor = getchar()) != '\n' && cursor != EOF);
    } else {
      carta->num_pontos_turisticos = pontos_turisticos;
      break;
    }
  }
  while((cursor = getchar()) != '\n' && cursor != EOF);
}

static int codigoInvalido(char *codigo_input, Trunfo *cartas, size_t posicao) {
  if (strlen(codigo_input) < 3)
    return -1;
  else if (codigo_input[0] != cartas[posicao].estado)
    return -1;
  else if (codigo_input[1] != '0')
    return -1;
  else if (codigo_input[2] < '1' || codigo_input[2] > '4')
    return -1;

  for (size_t i = 0; i < posicao; ++i) {
      if (strcmp(codigo_input, cartas[i].codigo_da_carta) == 0)
          return -1;
  }

  return 0;
}