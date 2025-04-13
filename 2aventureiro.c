#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para calcular a densidade demográfica
void calcularDensidade(Carta *carta) {
    if (carta->area > 0) {
        carta->densidadeDemografica = carta->populacao / carta->area;
    } else {
        carta->densidadeDemografica = 0;
    }
}

// Função para exibir uma carta
void exibirCarta(Carta carta, int numero) {
    printf("Carta %d - %s\n", numero, carta.nomePais);
}

// Função principal
int main() {
    // Definindo duas cartas fixas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1847020000000.0, 25, 0};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1647000000000.0, 15, 0};

    // Calculando densidades
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int opcao;

    // Exibindo o menu
    printf("===== Super Trunfo - Comparação de Cartas =====\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção (1 a 5): ");
    scanf("%d", &opcao);

    printf("\nComparação entre:\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    printf("\n");

    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área (km²)\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta1.area < carta2.area) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB (em dólares)\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2f\n", carta2.nomePais, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta1.pib < carta2.pib) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade demográfica (menor vence)
            printf("Atributo: Densidade Demográfica (hab/km²)\n");
            printf("%s: %.2f\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2f\n", carta2.nomePais, carta2.densidadeDemografica);

            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta1.densidadeDemografica > carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida. Por favor, escolha um número entre 1 e 5.\n");
    }

    return 0;
}
