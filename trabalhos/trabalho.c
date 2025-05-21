#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "teclado.h"
void acha_zero(int m[4][4], int *linha, int *coluna)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (m[i][j] == 0)
            {
                *linha = i;
                *coluna = j;
                return;
            }
        }
    }
}
void imp_mat(int m[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        printf("\n \r");
        for (int j = 0; j < 4; j++)
        {
            printf(" %d |", m[i][j]);
        }
    }
    printf("\n \r");
}
void move_cima(int m[4][4])
{
    int i, j;
    acha_zero(m, &i, &j);
    if (i < 3)
    {
        m[i][j] = m[i + 1][j];
        m[i + 1][j] = 0;
    }
}

void move_baixo(int m[4][4])
{
    int i, j;
    acha_zero(m, &i, &j);
    if (i > 0)
    {
        m[i][j] = m[i - 1][j];
        m[i - 1][j] = 0;
    }
}

void move_direita(int m[4][4])
{
    int i, j;
    acha_zero(m, &i, &j);
    if (j > 0)
    {
        m[i][j] = m[i][j - 1];
        m[i][j - 1] = 0;
    }
}

void move_esquerda(int m[4][4])
{
    int i, j;
    acha_zero(m, &i, &j);
    if (j < 3)
    {
        m[i][j] = m[i][j + 1];
        m[i][j + 1] = 0;
    }
}
void embaralha_matriz(int m[4][4])
{
    int i, j;
    int mov;
    srand(time(NULL));

    mov = 100 + rand() % 100;

    for (int k = 0; k < mov; k++)
    {
        int dir = rand() % 4;

        switch (dir)
        {
        case 0:
            move_cima(m);
            break;
        case 1:
            move_baixo(m);
            break;
        case 2:
            move_esquerda(m);
            break;
        case 3:
            move_direita(m);
            break;
        }
    }
}

bool vitoria(int m[4][4])
{
    int v[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0},
    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (m[i][j] != v[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void trata_tecla(tecla_t tec, int *p)
{
    if (tec == T_CIMA) *p = 1;
  if (tec == T_BAIXO) *p = 3;
  if (tec == T_DIREITA) *p = 2;
  if (tec == T_ESQUERDA) *p = 4;
}

int main()
{
    tec_inicia(); // inicia o modo cru
    int i = 0, v = 0;
    int m[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0},
    };

    embaralha_matriz(m);
    imp_mat(m);

    do
    {
        tecla_t tec = T_NADA;

        // Espera até o usuário apertar uma tecla válida
        while ((tec = tec_tecla()) == T_NADA)
        {
            // loop ocioso, só esperando uma tecla válida
        }

        if (tec == T_END) break;

        trata_tecla(tec, &i);

        switch (i)
        {
        case 1:
            move_cima(m);
            break;
        case 2:
            move_esquerda(m);
            break;
        case 3:
            move_baixo(m);
            break;
        case 4:
            move_direita(m);
            break;
        default:
            continue;
        }
        system("clear");
        imp_mat(m);
        v = vitoria(m);

    } while (!v);

    tec_fim(); // retorna o terminal ao modo normal
    return 0;
}