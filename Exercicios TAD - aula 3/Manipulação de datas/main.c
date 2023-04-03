#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(void) {
  int x=1;
  int difDias=0,difMeses=0,difAnos=0;
  tData data1,data2;

  data1=lerData();
  data2=lerData();

  difDias=diferencaDias(data1,data2);  
  printf("A diferenca em dias eh de: %d\n",difDias);
  difMeses=abs(diferencaMeses(data1,data2));
  printf("A diferenca em Meses eh de: %d\n",difMeses);
  difAnos=abs(diferencaAnos(data1,data2));
  printf("A diferenca em Anos eh de: %d\n",difAnos);
  printf("Nome do mês da 1ª Data: ");
  NomeMes(data1);
  printf("\n");
  printf("Nome do mês da 2ª Data: ");
  NomeMes(data2);
  printf("\n");
    if(Igualdade(data1,data2)){
      printf("As datas são iguais!\n");
    }else printf("As datas são diferentes!\n");
    if(ehBissexto(data1.mes) && ehBissexto(data2.mes)){
      printf("Ambos os anos são Bissextos!\n");
    }else if(ehBissexto(data1.mes)){
      printf("Apenas o primeiro ano é bissexto!\n");
    }else if(ehBissexto(data2.mes)){
      printf("Apenas o segundo ano é bissexto!\n");
    }
  printf("Na 1ª Data o mes tem: %d dias\n",qtdDiasNoMes(data1));
  printf("Na 2ª Data o mes tem: %d dias\n",qtdDiasNoMes(data2));

  data1=IncrementarDia(data1);
  data2=IncrementarDia(data2);

  printf("Datas Incrementadas!\n");
  ImprimirData(data1);
  ImprimirData(data2);  
  
  return 0;
}

