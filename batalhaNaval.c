#include <stdio.h>

#define TAM 10             // Tamanho do tabuleiro
#define TAM_HAB 5          // Tamanho fixo das matrizes de habilidade (5x5)
#define NAVIO 3            // Valor do navio
#define AGUA 0             // Valor da água
#define HABILIDADE 5       // Valor da área afetada por habilidades

// Função para sobrepor a matriz de habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha_tab = origem_linha + (i - offset);
                int coluna_tab = origem_coluna + (j - offset);

                // Validação de limites do tabuleiro
                if (linha_tab >= 0 && linha_tab < TAM && coluna_tab >= 0 && coluna_tab < TAM) {
                    // Apenas marca como área de habilidade se não for navio
                    if (tabuleiro[linha_tab][coluna_tab] == AGUA)
                        tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // --- POSICIONAMENTO DOS 4 NAVIOS ---

    // Horizontal
    for (int j = 2; j < 5; j++) tabuleiro[1][j] = NAVIO;

    // Vertical
    for (int i = 4; i < 7; i++) tabuleiro[i][6] = NAVIO;

    // Diagonal principal ?
    for (int i = 0; i < 3; i++) tabuleiro[i][i] = NAVIO;

    // Diagonal secundária ?
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][7 - i] = NAVIO;

    // --- MATRIZ HABILIDADE CONE (triângulo para baixo) ---
    int cone[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i) && i <= TAM_HAB / 2) {
                cone[i][j] = 1;
            }
        }
    }

    // --- MATRIZ HABILIDADE CRUZ ---
    int cruz[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // --- MATRIZ HABILIDADE OCTAEDRO (losango) SEM USAR abs ---
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int dist_linha = (i > centro) ? i - centro : centro - i;
            int dist_coluna = (j > centro) ? j - centro : centro - j;
            if (dist_linha + dist_coluna <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // --- APLICAÇÃO DAS HABILIDADES NO TABULEIRO ---
    aplicar_habilidade(tabuleiro, cone, 6, 2);       // Cone em (6,2)
    aplicar_habilidade(tabuleiro, cruz, 3, 8);       // Cruz em (3,8)
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);   // Octaedro em (7,7)

    // --- EXIBIÇÃO FINAL ---
    exibir_tabuleiro(tabuleiro);

    return 0;
}

