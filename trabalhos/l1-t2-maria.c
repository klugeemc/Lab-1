#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "teclado.h"
#include "video.h"

void acha_zero(int m[4][4], int *linha, int *coluna) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j] == 0) {
                *linha = i;
                *coluna = j;
                return;
            }
        }
    }
}

void move_cima(int m[4][4]) {
    int i, j;
    acha_zero(m, &i, &j);
    if (i < 3) {
        m[i][j] = m[i + 1][j];
        m[i + 1][j] = 0;
    }
}

void move_baixo(int m[4][4]) {
    int i, j;
    acha_zero(m, &i, &j);
    if (i > 0) {
        m[i][j] = m[i - 1][j];
        m[i - 1][j] = 0;
    }
}

void move_direita(int m[4][4]) {
    int i, j;
    acha_zero(m, &i, &j);
    if (j > 0) {
        m[i][j] = m[i][j - 1];
        m[i][j - 1] = 0;
    }
}

void move_esquerda(int m[4][4]) {
    int i, j;
    acha_zero(m, &i, &j);
    if (j < 3) {
        m[i][j] = m[i][j + 1];
        m[i][j + 1] = 0;
    }
}

void embaralha_matriz(int m[4][4]) {
    int mov;
    srand(time(NULL));
    mov = 100 + rand() % 100;

    for (int k = 0; k < mov; k++) {
        int dir = rand() % 4;

        switch (dir) {
            case 0: move_cima(m); break;
            case 1: move_baixo(m); break;
            case 2: move_esquerda(m); break;
            case 3: move_direita(m); break;
        }
    }
}

bool vitoria(int m[4][4]) {
    int v[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0},
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j] != v[i][j]) {
                return false;
            } else {
                printf("VOCE VENCEU");
            }
        }
    }
    return true;
}

void trata_tecla(tecla_t tec, int *p) {
    if (tec == T_CIMA) *p = 3;
    if (tec == T_BAIXO) *p = 1;
    if (tec == T_DIREITA) *p = 2;
    if (tec == T_ESQUERDA) *p = 4;
    if (tec == T_END) *p = 5;
}

void desenha_tela(int m[4][4]) {
    cor_t fundo_geral = {230, 230, 250};
    cor_t fundo_peca = {205, 92, 92};
    cor_t fundo_vazio = {128, 0, 0};
    cor_t cor_texto = {255, 255, 255};

    vid_limpa();

    vid_cor_fundo(fundo_geral);
    vid_cor_texto(cor_texto);
    for (int linha = 1; linha <= 24; linha++) {
        posicao_t p = {linha, 1};
        vid_pos(p);
        for (int coluna = 1; coluna <= 80; coluna++) {
            vid_impc(' ');
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            posicao_t p;
            p.linha = 5 + i * 2;
            p.coluna = 10 + j * 6;

            vid_pos(p);

            if (m[i][j] == 0) {
                vid_cor_fundo(fundo_vazio);
                vid_imps("      ");
            } else {
                vid_cor_fundo(fundo_peca);
                char buf[8];
                sprintf(buf, " %2d   ", m[i][j]);
                vid_imps(buf);
            }
        }
    }

    vid_atualiza();
}

int main() {
    tec_inicia();
    int i = 0, v = 0;
    int m[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0},
    };

    embaralha_matriz(m);
    vid_inicia();
    desenha_tela(m);

    do {
        tecla_t tec = T_NADA;

        while ((tec = tec_tecla()) == T_NADA) {}

        if (tec == T_END) break;

        trata_tecla(tec, &i);

        switch (i) {
            case 1: move_cima(m); break;
            case 2: move_esquerda(m); break;
            case 3: move_baixo(m); break;
            case 4: move_direita(m); break;
            case 5: break;
            default: continue;
        }

        desenha_tela(m);
        v = vitoria(m);

    } while (!v);

    tec_fim();
    vid_fim();
    return 0;
}