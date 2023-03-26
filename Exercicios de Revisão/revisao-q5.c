/*
  Programa que faz a movimentação de um personagem no estilo de um labirinto
  seguindo prioridades de movimentação
  autor: Pedro Marquesini
  data inicial: 22/03/2023
*/
#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 4
#define Verde 0
#define Vermelho 1
#define Passagem 3


int main(void) {

  int mapa[QTD_LINHAS][QTD_COLUNAS];
  int playerX,playerY,finalX,finalY;
  printf("Escreva o mapa: \n");
  //ler o mapa
  for(int i=0;i<QTD_LINHAS;i++){
    for(int j=0;j<QTD_COLUNAS;j++){
      //printf("Posição ( %d, %d):",i,j);
      scanf("%d",&mapa[i][j]);
    }
  }
  
  //ler as posições do jogador
  printf("Digite a posição inicial do jogador");
  scanf("%d %d",&playerX,&playerY);

  printf("Digite a posição final do jogador");
  scanf("%d %d",&finalX,&finalY);

  /*
    ORDEM DE PRIORIDADE: BDEC
        BAIXO- AUMENTA LINHA E MANTEM COLUNA
        DIREITA- MANTEM LINHA E AUMENTA COLUNA
        ESQUERDA- MANTEM LINHA E DIMINUI COLUNA
        CIMA - DIMINUI LINHA E MANTEM COLUNA

    
  */
 int key=1; //variavel que quando acabar as opções de movimentação ela se tornará zero
  mapa[playerX][playerY]=Passagem;//definir como passagem a posição inicial
  //Movimentação
  while(key==1){  
        if(mapa[playerX+1][playerY]==0){//baixo
            mapa[playerX+1][playerY]=Passagem;            
            playerX++;
            if(playerX==finalX && playerY==finalY)key=0;//verifica fim de jogo
        }
        else if(mapa[playerX][playerY+1]==0){//direita
            mapa[playerX][playerY+1]=Passagem;
            playerY++;
            if(playerX==finalX && playerY==finalY)key=0;
        }
        else if(mapa[playerX][playerY-1]==0){//esquerda
            mapa[playerX][playerY-1]=Passagem;
            playerY--;
            if(playerX==finalX && playerY==finalY)key=0;
        }
        else if(mapa[playerX-1][playerY]==0){//cima
            mapa[playerX-1][playerY]=Passagem;            
            playerX--;
            if(playerX==finalX && playerY==finalY)key=0;
        }
        else{
          key=0;//como acabou a possibilidade de movimento, o jogo chega ao fim
        }
  }

  //imprimir o mapa
  for(int i=0;i<QTD_LINHAS;i++){
    for(int j=0;j<QTD_COLUNAS;j++){
      printf("%d",mapa[i][j]);
    }
    printf("\n");
  }  
  
  return 0;
}