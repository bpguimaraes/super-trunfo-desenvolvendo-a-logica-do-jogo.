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
    carta->densidadeDemografica = carta->area > 0 ? carta->populacao / carta->area : 0;
}

// Função para exibir menu de atributos
void exibirMenu(int escolhido) {
    printf("Escolha um atributo para comparação:\n");
    if (escolhido != 1) printf("1 - População\n");
    if (escolhido != 2) printf("2 - Área\n");
    if (escolhido != 3) printf("3 - PIB\n");
    if (escolhido != 4) printf("4 - Pontos Turísticos\n");
    if (escolhido != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
}

// Função para obter o valor de um atributo
float obterValor(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para comparar dois valores com base no tipo de atributo
int comparar(float valor1, float valor2, int atributo) {
    if (atributo == 5) { // Densidade Demográfica (menor vence)
        return (valor1 < valor2) ? 1 : (valor1 > valor2) ? 2 : 0;
    } else {
        return (valor1 > valor2) ? 1 : (valor1 < valor2) ? 2 : 0;
    }
}

// Função para imprimir o nome do atributo
void imprimirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
        default: printf("Atributo Inválido");
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1847020000000.0, 25, 0};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1647000000000.0, 15, 0};

    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
            printf("Opção inválida ou repetida. Tente novamente.\n");
        }
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    // Obter os valores para cada atributo
    float valor1_attr1 = obterValor(carta1, atributo1);
    float valor2_attr1 = obterValor(carta2, atributo1);
    float valor1_attr2 = obterValor(carta1, atributo2);
    float valor2_attr2 = obterValor(carta2, atributo2);

    // Somando os valores (sem alterar regras de comparação)
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Exibindo resultados
    printf("\n===== Resultado da Comparação =====\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    printf("Atributo 1: ");
    imprimirNomeAtributo(atributo1);
    printf("\n  %s: %.2f\n", carta1.nomePais, valor1_attr1);
    printf("  %s: %.2f\n", carta2.nomePais, valor2_attr1);

    printf("\nAtributo 2: ");
    imprimirNomeAtributo(atributo2);
    printf("\n  %s: %.2f\n", carta1.nomePais, valor1_attr2);
    printf("  %s: %.2f\n", carta2.nomePais, valor2_attr2);

    printf("\nSoma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nomePais, soma1);
    printf("  %s: %.2f\n", carta2.nomePais, soma2);

    // Resultado final
    if (soma1 > soma2) {
        printf("\nResultado: %s venceu a rodada!\n", carta1.nomePais);
    } else if (soma2 > soma1) {
        printf("\nResultado: %s venceu a rodada!\n", carta2.nomePais);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
