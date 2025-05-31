#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // -----------------------------
    // Declara��o e inicializa��o do tabuleiro com 0 (�gua)
    // -----------------------------
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // -----------------------------
    // Navios representados com arrays de tamanho 3
    // -----------------------------
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // -----------------------------
    // Coordenadas iniciais dos navios (definidas no c�digo)
    // -----------------------------
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // -----------------------------
    // Verifica��o de limites e sobreposi��o (simplificada)
    // -----------------------------
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        int sobreposicao = 0;

        // Verifica se h� sobreposi��o nos locais onde o navio horizontal ser� colocado
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Verifica se h� sobreposi��o nos locais onde o navio vertical ser� colocado
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {
                    sobreposicao = 1;
                    break;
                }
            }
        }

        if (!sobreposicao) {
            // -----------------------------
            // Posiciona o navio horizontal
            // -----------------------------
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }

            // -----------------------------
            // Posiciona o navio vertical
            // -----------------------------
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }

            // -----------------------------
            // Exibe o tabuleiro
            // -----------------------------
            printf("Tabuleiro Batalha Naval (0 = �gua, 3 = navio):\n\n");
            for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
                for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: os navios se sobrep�em!\n");
        }

    } else {
        printf("Erro: coordenadas inv�lidas! O navio sairia do tabuleiro.\n");
    }

    return 0;
}

