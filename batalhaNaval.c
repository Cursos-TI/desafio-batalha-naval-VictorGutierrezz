#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // -----------------------------
    // Inicialização do tabuleiro 10x10 com 0 (água)
    // -----------------------------
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // -----------------------------
    // Coordenadas iniciais dos 4 navios (tamanho fixo 3)
    // -----------------------------
    // Navio 1 - Horizontal
    int l1 = 1, c1 = 2;

    // Navio 2 - Vertical
    int l2 = 4, c2 = 6;

    // Navio 3 - Diagonal principal (?)
    int l3 = 0, c3 = 0;

    // Navio 4 - Diagonal secundária (?)
    int l4 = 2, c4 = 7;

    int sobreposicao = 0;

    // -----------------------------
    // Função auxiliar para verificar e posicionar navio
    // -----------------------------
    void posicionar_navio(int linha, int coluna, int direcao_linha, int direcao_coluna) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int li = linha + i * direcao_linha;
            int ci = coluna + i * direcao_coluna;

            if (li < 0 || li >= TAMANHO_TABULEIRO || ci < 0 || ci >= TAMANHO_TABULEIRO || tabuleiro[li][ci] != 0) {
                sobreposicao = 1;
                return;
            }
        }

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int li = linha + i * direcao_linha;
            int ci = coluna + i * direcao_coluna;
            tabuleiro[li][ci] = 3;
        }
    }

    // -----------------------------
    // Posiciona os navios (valida dentro da função)
    // -----------------------------
    posicionar_navio(l1, c1, 0, 1); // Horizontal
    posicionar_navio(l2, c2, 1, 0); // Vertical
    posicionar_navio(l3, c3, 1, 1); // Diagonal principal (?)
    posicionar_navio(l4, c4, 1, -1); // Diagonal secundária (?)

    // -----------------------------
    // Verifica se houve sobreposição ou erro
    // -----------------------------
    if (sobreposicao) {
        printf("Erro: Navios estão fora dos limites ou se sobrepõem!\n");
    } else {
        // -----------------------------
        // Exibe o tabuleiro
        // -----------------------------
        printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

