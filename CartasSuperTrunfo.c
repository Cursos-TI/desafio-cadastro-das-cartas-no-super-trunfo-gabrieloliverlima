#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa a semente para geração de números aleatórios
    srand(time(0));

    // Declaração de variáveis para armazenar atributos das cartas
    int ataque1 = rand() % 100 + 1;
    int ataque2 = rand() % 100 + 1;
    int defesa1 = rand() % 100 + 1;
    int defesa2 = rand() % 100 + 1;
    int recuo1 = rand() % 100 + 1;
    int recuo2 = rand() % 100 + 1;
    
    char primeiroAtributo, segundoAtributo;
    int resultado1, resultado2, soma1, soma2;
    
    // Exibe mensagem inicial do jogo
    printf("Bem-vindo ao Super Trunfo!\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("A. Ataque\nD. Defesa\nR. Recuo\n");
    scanf(" %c", &primeiroAtributo);

    // Processa a escolha do primeiro atributo usando switch
    switch (primeiroAtributo) {
        case 'A': case 'a':
            printf("Você escolheu Ataque!\n");
            resultado1 = (ataque1 > ataque2) ? 1 : (ataque1 < ataque2) ? -1 : 0;
            break;
        case 'D': case 'd':
            printf("Você escolheu Defesa!\n");
            resultado1 = (defesa1 > defesa2) ? 1 : (defesa1 < defesa2) ? -1 : 0;
            break;
        case 'R': case 'r':
            printf("Você escolheu Recuo! (menor valor vence)\n");
            resultado1 = (recuo1 < recuo2) ? 1 : (recuo1 > recuo2) ? -1 : 0;
            break;
        default:
            printf("Opção inválida. Encerrando jogo.\n");
            return 0;
    }

    // Exibe menu para escolher o segundo atributo (diferente do primeiro)
    printf("\nEscolha o segundo atributo para comparar:\n");
    if (primeiroAtributo != 'A' && primeiroAtributo != 'a') printf("A. Ataque\n");
    if (primeiroAtributo != 'D' && primeiroAtributo != 'd') printf("D. Defesa\n");
    if (primeiroAtributo != 'R' && primeiroAtributo != 'r') printf("R. Recuo\n");
    scanf(" %c", &segundoAtributo);

    // Processa a escolha do segundo atributo
    switch (segundoAtributo) {
        case 'A': case 'a':
            printf("Você escolheu Ataque!\n");
            resultado2 = (ataque1 > ataque2) ? 1 : (ataque1 < ataque2) ? -1 : 0;
            break;
        case 'D': case 'd':
            printf("Você escolheu Defesa!\n");
            resultado2 = (defesa1 > defesa2) ? 1 : (defesa1 < defesa2) ? -1 : 0;
            break;
        case 'R': case 'r':
            printf("Você escolheu Recuo! (menor valor vence)\n");
            resultado2 = (recuo1 < recuo2) ? 1 : (recuo1 > recuo2) ? -1 : 0;
            break;
        default:
            printf("Opção inválida. Encerrando jogo.\n");
            return 0;
    }
    
    // Calcula a soma dos dois atributos escolhidos para cada carta
    soma1 = (resultado1 == 1 ? ataque1 : resultado1 == -1 ? ataque2 : 0) +
            (resultado2 == 1 ? defesa1 : resultado2 == -1 ? defesa2 : 0);
    soma2 = (resultado1 == 1 ? ataque2 : resultado1 == -1 ? ataque1 : 0) +
            (resultado2 == 1 ? defesa2 : resultado2 == -1 ? defesa1 : 0);
    
    // Exibe os resultados
    printf("\nResultados:\n");
    printf("Atributos escolhidos: %c e %c\n", primeiroAtributo, segundoAtributo);
    printf("Carta 1: Ataque = %d, Defesa = %d, Recuo = %d, Soma = %d\n", ataque1, defesa1, recuo1, soma1);
    printf("Carta 2: Ataque = %d, Defesa = %d, Recuo = %d, Soma = %d\n", ataque2, defesa2, recuo2, soma2);
    
    // Determina o vencedor final
    if (soma1 > soma2)
        printf("Carta 1 venceu!\n");
    else if (soma2 > soma1)
        printf("Carta 2 venceu!\n");
    else
        printf("Empate!\n");
    
    return 0;
}