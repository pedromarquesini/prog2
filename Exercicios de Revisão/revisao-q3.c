/*
  Programa que recebe como entrar um numero inteiro de livros e uma lista com identificadores,
  nesta lista, ele deve identificar quais identificadores não foram repetidos e imprimir em
  ordem crescente.
  Autor: Pedro Marquesini
  Data Inicial: 22/03/2023
*/
#include <stdio.h>

int main(void) {
  int i,j,temp,cont=0;
  int QTD_LIVROS;
  int livros[QTD_LIVROS];

  scanf("%d",&QTD_LIVROS);
  //ler a lista de livros
  for(i=0; i<QTD_LIVROS;i++){
    scanf("%d",&livros[i]);
  }
  
  //ordenar a lista
  for(i=0; i<QTD_LIVROS-1;i++){
    for(int j=i+1;j< QTD_LIVROS;j++){
      if(livros[j]<livros[i]){
        temp=livros[i];
        livros[i]=livros[j];
        livros[j]=temp;
      }    
    }
  }
   
  //verificar  
  for(i=0;i<QTD_LIVROS;i++){
    cont=0;
    for(j=0;j<QTD_LIVROS;j++){
      if(i !=j && livros[i]==livros[j]){
      //o programa verifica com todos os elementos, exceto ele próprio, se são iguais, caso contrário ele ativa o contado e para o primeiro loop e imprime o numero
        cont=1;
        break;
      }
    }
    if(!cont)printf("%d ", livros[i]);
  }
  
  return 0;
}

