#include <stdio.h>

void imp_mat(int m[4][4]){
    for (int i = 0; i<4; i++){
            printf("\n");
        for (int j = 0; j<4; j++){
            printf(" %d |", m[i][j]);
        }
    }

}
void move_cima(int m[4][4])
{
    for (int i = 4; i>=0 ; i--){
        for (int j = 0; j<4; j++){
            if(m[i][j] == 0){
            m[i][j] = m[i+1][j];
            m[i+1][j] = 0;
            }
        }
    }
}

void move_baixo(int m[4][4])
{
    for (int i = 0; i<4; i++){
        for (int j = 0; j<4; j++){
            if(m[i][j] == 0){
            m[i][j] = m[i-1][j];
            m[i-1][j] = 0;
            }
        }
    }
}

void move_direita(int m[4][4])
{
    for (int i=0; i<4; i++){
        for (int j = 0; j < 4; j++)
        {
            if(m[i][j] == 0){
            m[i][j]=m[i][j-1];
            m[i][j-1]=0;
            }
        }
        
    }
}

void move_esquerda(int m[4][4])
{
    for (int i=0; i<4; i++){
        for (int j =4; j >= 0; j--)
        {
            if(m[i][j] == 0){
            m[i][j]=m[i][j+1];
            m[i][j+1]=0;
            }
        }
        
    }
}

int main()
{
    int m[4][4] = {
    { 7, 1, 2, 4 },
    { 5, 12, 14, 6 },
    { 8, 0, 10, 9 },
    { 3, 11, 15, 13 },
    };

    imp_mat(m);
    move_cima(m);
    printf("\n");
    imp_mat(m);
   
    move_esquerda(m);
    printf("\n");
    imp_mat(m);
   
}
