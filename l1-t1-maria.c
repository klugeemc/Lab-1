#include<stdio.h>
void cor_letra(int r, int g, int b)
  {
    printf("%c[38;2;%d;%d;%dm", 27, r, g, b);
  }
  void cor_normal()
  {
    printf("%c[0m", 27);
  }
void numero(int num){
	if(num<=126){
	cor_letra(0,255,255);
	printf(" %3d ",num);
	cor_normal();
	cor_letra(128,0,32);
	printf(" %7b ",num);
	cor_normal();
	cor_letra(57,255,20);
    printf(" %x ",num);
    cor_normal();
    cor_letra(204,153,0);
    printf(" %c  ",num);



}
else{
printf("   ");
}

}
void linha_tabela(int num){

     for (int i = 0; i < 6; i++) {
        numero(num +i *16);

}
}
int main(){
    printf("Tabela ASCII\n");
    cor_letra(0,255,255);
    printf("DECIMAL | ");
    cor_normal();
    cor_letra(128,0,32);
    printf("BINARIO | ");
    cor_normal();
    cor_letra(57,255,20);
    printf("HEXADECIMAL | ");
    cor_normal();
    cor_letra(204,153,0);
    printf("CARACTER");
    cor_normal();
    printf("\n");
    for(int i=0;i<16;i++){

    linha_tabela(32+i);



     printf("\n");
    }
    return 0;
}





