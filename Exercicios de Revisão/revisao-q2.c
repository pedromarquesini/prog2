/*
  Programa para imprimir o triangulo de Floyd
  Autor: Pedro Marquesini  
  Data Inicial: 22/03/2023
*/
#include <stdio.h>

int main(void) {
  int n,cont=1,aux;
  scanf("%d",&n);
  //imprimir a quantidade N de linhas
  for(int i=1;i<=n;i++){
    //na primeira linha vai ter 1 elemento, na segunda 2 e assim respectivamente
    for(int j=1;j<=i;j++){
      printf("%d ",cont);//o contador sera incrementado toda vez que ele imprimir
      cont++;
    }
    printf("\n");
  }
  return 0;
}