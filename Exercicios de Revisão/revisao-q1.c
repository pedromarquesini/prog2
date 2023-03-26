/*
  Programa para ler dois circulos e calcular se eles colidem
  Autor: Pedro Marquesini
  Data inicial: 22/03/2023
*/
#include <stdio.h>
#include <math.h>

int main(void) {
  int cx,cy,r1,dx,dy,r2,difx,dify;
  float dist;
  //leitura dos pontos
  printf("Ponto 1 e raio: ");
  scanf("%d %d %d",&cx,&cy,&r1);  
  printf("Ponto 2: ");
  scanf("%d %d %d",&dx,&dy,&r2);  

  //calculando a distancia dos pontos 
  difx = dx-cx;
  dify=dy-cy;
  dist=pow(difx,2)+pow(dify,2);
  dist=sqrt(dist);

  //verificando a colisao
  if(dist <= (r1+r2)) printf("Colisao Detectada!");
  else printf("Colisao Nao Detectada");
  
  return 0;
}