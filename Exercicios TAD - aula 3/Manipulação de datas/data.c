#include "data.h"
#include <stdio.h>
#include <stdlib.h>

tData lerData(){
  tData data;
  char dataString[11];
  int dia=0,mes=0,ano=0;

  printf("Digite uma data no formato \"dd/mm/yyyy\": ");
  scanf("%s", dataString);

  // Utiliza a função sscanf para realizar a leitura dos valores da string
  sscanf(dataString, "%d/%d/%d", &dia, &mes, &ano);
  printf("Data Lida: %.2d/%.2d/%.2d\n",dia,mes,ano);
  data.ano=ano;
  data.dia=dia;
  data.mes=mes;
  return data;
}

int quantidadeDias(tData data) {
  int dias = 0;
  
  // Soma os dias de cada ano bissexto anterior à data
  for(int i = 1; i < data.ano; i++) {
    if(ehBissexto(i)) {
      dias += 366;
    } else {
      dias += 365;
    }
  }
  
  // Soma os dias de cada mês anterior à data
  for(int i = 1; i < data.mes; i++) {
    switch(i) {
      case 2: // Fevereiro
        if(ehBissexto(data.ano)) {
          dias += 29;
        } else {
          dias += 28;
        }
        break;
      case 4: case 6: case 9: case 11: // Meses com 30 dias
        dias += 30;
        break;
      default: // Meses com 31 dias
        dias += 31;
        break;
    }
  }
  
  // Soma os dias da data atual
  dias += data.dia;
  
  return dias;
}

int diferencaDias(tData data1, tData data2) {
  int dias1 = quantidadeDias(data1);
  int dias2 = quantidadeDias(data2);
  
  return abs(dias2 - dias1);
}

int diferencaMeses(tData data1, tData data2){
  int mes1=0,mes2=0;
  //transformando os anos em meses
  mes1=data1.ano*12+data1.mes;
  mes2=data2.ano*12+data2.mes;
  
  return mes2-mes1;
}

int diferencaAnos(tData data1, tData data2){
  int ano1=0,ano2=0;
  ano1=data1.ano;
  ano2=data2.ano;

  //para nao retornar valor negativo
  if(ano1>ano2)return ano1-ano2;
  else return ano2-ano1;
}

void NomeMes(tData data){
  switch(data.mes){
    case 1:
      printf("Janeiro");
    break;
    case 2:
      printf("Fevereiro");
    break;
    case 3:
      printf("Março");
    break;
    case 4:
      printf("Abril");
    break;
    case 5:
      printf("Maio");
    break;
    case 6:
      printf("Junho");
    break;
    case 7:
      printf("Julho");
    break;
    case 8:
      printf("Agosto");
    break;
    case 9:
      printf("Setembro");
    break;
    case 10:
      printf("Outubro");
    break;
    case 11:
      printf("Novembro");
    break;
    case 12:
      printf("Dezembro");
    break;
  }
}

int Igualdade(tData data1, tData data2){
  if(data1.ano==data2.ano && data1.mes==data2.mes && data1.dia==data2.dia)return 1;
    else return 0;
}

int ehBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int qtdDias(tData data){
//transformando os anos para dias e somando com a quantidade de dias
  int dias1 = data.ano*365+data.dia;  
  for(int i=1;i<data.mes;i++){//transformando os meses para dias
    if(i==2){
      dias1+=28;
      if(ehBissexto(data.ano)){//verificação de ano bissexto
        dias1++;
      }
    }else if(i==4 || i==6 || i==9 || i==11)dias1+=30;
    else dias1=+31;
  }
  return dias1;
}

tData IncrementarDia(tData data){
  /*
  Função para incrementar um dia
    Algoritmo:
      -Verificar o mês pertencente
      -Verificar se o dia é menor que a data máxima do mes
        -Verificar se precisa alterar o mes ou ano
  */
  if(data.mes==1 || data.mes==3 || data.mes==5 || data.mes==7 || data.mes==8 || data.mes==10 || data.mes==12){//Meses com 31 dias
    if(data.dia<31)data.dia++;//casos menores que 31 dias
    else if(data.dia==31){
      data.dia=1;
      if(data.mes==12){
        data.ano++;
        data.mes=1;
      }else if(data.mes<12)data.mes++;//Meses menores que 12 prosseguirão normalmente
    }
    
  }else if(data.mes==4 || data.mes==6 || data.mes==9 || data.mes==11){//Meses com 30 dias
    if(data.dia<30)data.dia++;//casos menores que 30 dias
    else if(data.dia==30){
      data.dia=1;
      if(data.mes==12){
        data.ano++;
        data.mes=1;
      }else if(data.mes<12)data.mes++;//Meses menores que 12 prosseguirão normalmente
    }
    
  }else if(data.mes==2){//Meses com 28/29 dias
    if(ehBissexto(data.ano)){//Caso o ano seja bissexto
      if(data.dia<29)data.dia++;//casos menores que 29 dias
      else if(data.dia==29){
        data.dia=1;
        if(data.mes==12){
          data.ano++;
          data.mes=1;
        }else if(data.mes<12)data.mes++;
        
    }      
    }else if(!ehBissexto(data.ano)){//caso o ano nao seja bissexto
      if(data.dia<28)data.dia++;//casos menores que 28 dias
      else if(data.dia==28){
        data.dia=1;
        if(data.mes==12){
          data.ano++;
          data.mes=1;
        }else if(data.mes<12)data.mes++;
      }
    }
  }
  return data;
}

int qtdDiasNoMes(tData data){
  switch(data.mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    break;
    
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    break;
    
    case 2:
      if(ehBissexto(data.mes))return 29;
      else return 28;
    break;
  }
}

void ImprimirData(tData data){
  printf("Data: %.2d/%.2d/%.2d\n",data.dia,data.mes,data.ano);
}
