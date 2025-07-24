#include <stdio.h>

// Definição da estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[3]; // Corrigido para string
    char codigo[5]; // 4 + \0
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

int main() {
    struct Carta carta1, carta2;

    // Leitura dos dados da carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf(" %2s", carta1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf(" %4s", carta1.codigo);
    printf("Nome da Cidade: ");
    getchar(); // limpar \n anterior
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = '\0'; // remover newline

    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Leitura dos dados da carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf(" %2s", carta2.estado);
    printf("Código da Carta (ex: B03): ");
    scanf(" %4s", carta2.codigo);
    printf("Nome da Cidade: ");
    getchar(); // limpar \n anterior
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos para carta 1
    carta1.densidadePopulacional = (carta1.area > 0) ? carta1.populacao / carta1.area : 0;
    carta1.pibPerCapita = (carta1.populacao > 0) ? (carta1.pib * 1e9) / carta1.populacao : 0;
    carta1.superPoder = carta1.populacao + carta1.area + carta1.pib +
                        carta1.pontosTuristicos + carta1.pibPerCapita +
                        ((carta1.densidadePopulacional > 0) ? 1.0 / carta1.densidadePopulacional : 0);

    // Cálculos para carta 2
    carta2.densidadePopulacional = (carta2.area > 0) ? carta2.populacao / carta2.area : 0;
    carta2.pibPerCapita = (carta2.populacao > 0) ? (carta2.pib * 1e9) / carta2.populacao : 0;
    carta2.superPoder = carta2.populacao + carta2.area + carta2.pib +
                        carta2.pontosTuristicos + carta2.pibPerCapita +
                        ((carta2.densidadePopulacional > 0) ? 1.0 / carta2.densidadePopulacional : 0);

    // Exibição dos dados da carta 1
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    // Exibição dos dados da carta 2
    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);

    // Comparações
    printf("\n--- Comparação ---\n");

    printf("População: %s venceu\n", carta1.populacao > carta2.populacao ? carta1.nomeCidade : (carta2.populacao > carta1.populacao ? carta2.nomeCidade : "Empate"));
    printf("Área: %s venceu\n", carta1.area > carta2.area ? carta1.nomeCidade : (carta2.area > carta1.area ? carta2.nomeCidade : "Empate"));
    printf("PIB: %s venceu\n", carta1.pib > carta2.pib ? carta1.nomeCidade : (carta2.pib > carta1.pib ? carta2.nomeCidade : "Empate"));
    printf("Pontos Turísticos: %s venceu\n", carta1.pontosTuristicos > carta2.pontosTuristicos ? carta1.nomeCidade : (carta2.pontosTuristicos > carta1.pontosTuristicos ? carta2.nomeCidade : "Empate"));
    printf("Densidade Populacional (menor vence): %s venceu\n", carta1.densidadePopulacional < carta2.densidadePopulacional ? carta1.nomeCidade : (carta2.densidadePopulacional < carta1.densidadePopulacional ? carta2.nomeCidade : "Empate"));
    printf("PIB per Capita: %s venceu\n", carta1.pibPerCapita > carta2.pibPerCapita ? carta1.nomeCidade : (carta2.pibPerCapita > carta1.pibPerCapita ? carta2.nomeCidade : "Empate"));
    printf("Super Poder: %s venceu\n", carta1.superPoder > carta2.superPoder ? carta1.nomeCidade : (carta2.superPoder > carta1.superPoder ? carta2.nomeCidade : "Empate"));

    return 0;
}
