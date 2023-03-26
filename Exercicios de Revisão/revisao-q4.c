/*
  Programa para transformar numero decimal em octal
  Autor: Pedro Marquesini
  Data Inicial: 22/03/2023
*/
#include <stdio.h>

int main(void) {
  int n,octal=0,resto, i=1;//sempre importante iniciar variaveis que seão incrementadas

  scanf("%d",&n);
  /*
    Para transformação foi utilizado o seguinte método:
      -pega o resto do numero dividido por 8
      -divide o numero por 8
      -pega o resto da divisão e multiplica por um variavel i que a cada vez que rodar, multiplicará por 10 para ajustar à casa decimal
      
  */
  while(n!=0){
    resto = n%8;
    n /= 8;
    octal+= resto*i;
    i*=10;//!!!!! sempre mutiplicar por 10 para ajustar à casa decimal
  }

  printf("A conversão para octal é: %d",octal);
  
  return 0;
}