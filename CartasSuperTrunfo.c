#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cartas
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area, pib;
    int pontosTuristicos;
    float densidadePopulacional;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("\nDigite a letra do estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf(" %s", carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^"]", carta->nomeCidade);
    
    printf("Digite a população da cidade: ");
    scanf(" %lu", &carta->populacao);
    
    printf("Digite a área da cidade em km²: ");
    scanf(" %f", &carta->area);
    
    printf("Digite o PIB da cidade em bilhões de reais: ");
    scanf(" %f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &carta->pontosTuristicos);
    
    // Cálculo da densidade populacional
    carta->densidadePopulacional = carta->populacao / carta->area;
}

// Função para comparar atributos
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\nComparação de Cartas:\n");
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %lu habitantes\n", c1.nomeCidade, c1.populacao);
            printf("%s: %lu habitantes\n", c2.nomeCidade, c2.populacao);
            if (c1.populacao > c2.populacao) printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao) printf("%s venceu!\n", c2.nomeCidade);
            else printf("Empate!\n");
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", c1.nomeCidade, c1.area);
            printf("%s: %.2f km²\n", c2.nomeCidade, c2.area);
            if (c1.area > c2.area) printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.area > c1.area) printf("%s venceu!\n", c2.nomeCidade);
            else printf("Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", c1.nomeCidade, c1.pib);
            printf("%s: %.2f bilhões\n", c2.nomeCidade, c2.pib);
            if (c1.pib > c2.pib) printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.pib > c1.pib) printf("%s venceu!\n", c2.nomeCidade);
            else printf("Empate!\n");
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", c1.nomeCidade, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.nomeCidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos) printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos) printf("%s venceu!\n", c2.nomeCidade);
            else printf("Empate!\n");
            break;
        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.nomeCidade, c1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", c2.nomeCidade, c2.densidadePopulacional);
            if (c1.densidadePopulacional < c2.densidadePopulacional) printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.densidadePopulacional < c1.densidadePopulacional) printf("%s venceu!\n", c2.nomeCidade);
            else printf("Empate!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;
    
    // Cadastro das cartas
    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);
    
    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);
    
    // Menu de escolha do atributo
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("Digite sua escolha: ");
    scanf(" %d", &opcao);
    
    // Comparação das cartas com base na escolha do usuário
    compararCartas(carta1, carta2, opcao);
    
    return 0;
}
