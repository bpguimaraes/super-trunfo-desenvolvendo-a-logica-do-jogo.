#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular os indicadores derivados
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir uma carta
void exibirCarta(Carta carta, int numero) {
    printf("Carta %d - %s (%s)\n", numero, carta.nomeCidade, carta.estado);
}

// Função principal
int main() {
    // Criação de duas cartas pré-definidas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 230000000000.0, 15};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6700000, 1182.3, 150000000000.0, 10};

    // Cálculo dos indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Escolha do atributo para comparação
    // Altere esta linha para comparar outro atributo: "populacao", "area", "pib", "densidade", "pibPerCapita"
    char atributoEscolhido[] = "populacao";

    // Impressão inicial
    printf("\nComparação de cartas (Atributo: %s)\n\n", atributoEscolhido);

    // Comparação com base no atributo escolhido
    if (strcmp(atributoEscolhido, "populacao") == 0) {
        exibirCarta(carta1, 1);
        printf("População: %d\n", carta1.populacao);
        exibirCarta(carta2, 2);
        printf("População: %d\n", carta2.populacao);

        if (carta1.populacao > carta2.populacao)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta1.populacao < carta2.populacao)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");

    } else if (strcmp(atributoEscolhido, "area") == 0) {
        exibirCarta(carta1, 1);
        printf("Área: %.2f km²\n", carta1.area);
        exibirCarta(carta2, 2);
        printf("Área: %.2f km²\n", carta2.area);

        if (carta1.area > carta2.area)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta1.area < carta2.area)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");

    } else if (strcmp(atributoEscolhido, "pib") == 0) {
        exibirCarta(carta1, 1);
        printf("PIB: %.2f\n", carta1.pib);
        exibirCarta(carta2, 2);
        printf("PIB: %.2f\n", carta2.pib);

        if (carta1.pib > carta2.pib)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta1.pib < carta2.pib)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");

    } else if (strcmp(atributoEscolhido, "densidade") == 0) {
        exibirCarta(carta1, 1);
        printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
        exibirCarta(carta2, 2);
        printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);

        // Menor densidade vence
        if (carta1.densidadePopulacional < carta2.densidadePopulacional)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta1.densidadePopulacional > carta2.densidadePopulacional)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");

    } else if (strcmp(atributoEscolhido, "pibPerCapita") == 0) {
        exibirCarta(carta1, 1);
        printf("PIB per capita: %.2f\n", carta1.pibPerCapita);
        exibirCarta(carta2, 2);
        printf("PIB per capita: %.2f\n", carta2.pibPerCapita);

        if (carta1.pibPerCapita > carta2.pibPerCapita)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (carta1.pibPerCapita < carta2.pibPerCapita)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");

    } else {
        printf("Atributo inválido selecionado para comparação.\n");
    }

    return 0;
}
