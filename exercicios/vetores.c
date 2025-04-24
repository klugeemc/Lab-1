#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void impvet(int n, float vet[n])
{
    printf("[");
  for(int i = 0; i<n; i ++){
    printf("%.1f, ",vet[i]);
  }
    printf("]");
}
void levet(int n, float vet[n])
{
    printf("digite %d valores\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%f",&vet[i]);
    }
}
void preenchevet(int n, float vet[n])
{
    for (int i = 0; i<n;i++)
    {
        vet[i] = rand() %1000 / 10;

    }
}
float calcmed(int n, float vet[n])
{
    float media,soma=0;
    for(int i=0; i<n; i++){
        soma+= vet[i];
    }
    media = soma/n;
    return(media);
}
float omaior(int n, float vet[n])
{
    float maior=vet[0];
    for(int i = 1;i<n;i++){
        if(vet[i]>maior){
            maior=vet[i];
        }
    }
    return(maior);
}
int main()
{
    srand(time(NULL));
    float valor[5];
    float media;

    preenchevet(5,valor);
    impvet(5,valor);
    media = calcmed(5,valor);
    printf("\na media deles e: %f",media);
    printf("o maior numero e: %f",omaior(5,valor));


}
