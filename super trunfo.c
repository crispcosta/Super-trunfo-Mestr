#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4]; // Exemplo: "A01"
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} CartaSuperTrunfo;

// Função para inserir os dados de uma carta
void inserirCarta(CartaSuperTrunfo *carta) {
    printf("\nDigite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    while (getchar() != '\n'); // Consume the newline character left by scanf

    printf("Digite o código da cidade (ex: A01): ");
    scanf("%3s", carta->codigo);
    carta->codigo[3] = '\0'; // Ensure null-termination
    while (getchar() != '\n'); // Consume the newline character left by scanf
    
    printf("Digite o nome da cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite a população da cidade: ");
    scanf("%lu", &carta->populacao);
    
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    
    // Cálculos adicionais
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }
    
    if (carta->populacao > 0) {
        carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao; // Convertendo PIB para reais
    } else {
        carta->pibPerCapita = 0;
    }
    
    // Cálculo do Super Poder
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita + (carta->densidadePopulacional > 0 ? (1 / (carta->densidadePopulacional + 1)) : 0);
}

// Função para exibir os dados de uma carta
void exibirCarta(CartaSuperTrunfo carta) {
    printf("\n==== Dados da Carta ====");
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n habitantes", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("\nSuper Poder: %.2f\n", carta.superPoder);
}

// Função para comparar e exibir os resultados das cartas
void compararCartas(CartaSuperTrunfo c1, CartaSuperTrunfo c2) {
    printf("\n=== Comparação de Cartas ===\n");
    printf("População: Carta %d venceu\n", c1.populacao > c2.populacao ? 1 : (c1.populacao < c2.populacao ? 2 : 0));
    printf("Área: Carta %d venceu\n", c1.area > c2.area ? 1 : (c1.area < c2.area ? 2 : 0));
    printf("PIB: Carta %d venceu\n", c1.pib > c2.pib ? 1 : (c1.pib < c2.pib ? 2 : 0));
    printf("Pontos Turísticos: Carta %d venceu\n", c1.pontosTuristicos > c2.pontosTuristicos ? 1 : (c1.pontosTuristicos < c2.pontosTuristicos ? 2 : 0));
    printf("Densidade Populacional: Carta %d venceu\n", c1.densidadePopulacional > c2.densidadePopulacional ? 1 : (c1.densidadePopulacional < c2.densidadePopulacional ? 2 : 0));
    printf("PIB per Capita: Carta %d venceu\n", c1.pibPerCapita > c2.pibPerCapita ? 1 : (c1.pibPerCapita < c2.pibPerCapita ? 2 : 0));
    printf("Super Poder: Carta %d venceu\n", c1.superPoder > c2.superPoder ? 1 : (c1.superPoder < c2.superPoder ? 2 : 0));
}

int main() {
    CartaSuperTrunfo carta1, carta2;
    
    printf("\n=== Insira os dados da primeira carta ===");
    inserirCarta(&carta1);
    
    printf("\n=== Insira os dados da segunda carta ===");
    inserirCarta(&carta2);
    
    printf("\n=== Exibindo Cartas ===");
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    compararCartas(carta1, carta2);
    
    return 0;
}
