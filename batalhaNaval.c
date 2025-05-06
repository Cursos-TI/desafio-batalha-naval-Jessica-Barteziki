#include <stdio.h>

// Definições para o tabuleiro e navios
#define TAMANHO_TABULEIRO 5
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Representação do tabuleiro 5x5
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento do navio horizontal
    int navioHorizontalLinha = 1;
    int navioHorizontalColuna = 1;

    printf("Coordenadas do Navio Horizontal:\n");
    if (navioHorizontalColuna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navioHorizontalLinha][navioHorizontalColuna + i] = NAVIO;
            printf("(%d, %d)\n", navioHorizontalLinha, navioHorizontalColuna + i);
        }
    } else {
        printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
    }
    printf("\n");

    // Posicionamento do navio vertical
    int navioVerticalLinha = 3;
    int navioVerticalColuna = 0;

    printf("Coordenadas do Navio Vertical:\n");
    if (navioVerticalLinha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = NAVIO;
            printf("(%d, %d)\n", navioVerticalLinha + i, navioVerticalColuna);
        }
    } else {
        printf("Erro: Navio vertical excede os limites do tabuleiro.\n");
    }
    printf("\n");

    // Validação de sobreposição (simplificada - verifica as posições do segundo navio)
    if (tabuleiro[navioVerticalLinha][navioVerticalColuna] == NAVIO ||
        tabuleiro[navioVerticalLinha + 1][navioVerticalColuna] == NAVIO ||
        tabuleiro[navioVerticalLinha + 2][navioVerticalColuna] == NAVIO) {
        printf("Aviso: Possível sobreposição de navios (validação simplificada).\n");
    }

    // Exibe o tabuleiro (para visualização)
    printf("Tabuleiro da Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}