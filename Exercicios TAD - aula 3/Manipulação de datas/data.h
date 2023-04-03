#ifndef _DATA_H
#define _DATA_H

typedef struct Data{
  int dia;
  int mes;
  int ano;
}tData;

tData lerData();
int quantidadeDias(tData data);
int diferencaDias(tData data1, tData data2);
int diferencaMeses(tData data1, tData data2);
int diferencaAnos(tData data1, tData data2);
void NomeMes(tData data);
int Igualdade(tData data1, tData data2);
int ehBissexto(int ano);
int qtdDias(tData data);
tData IncrementarDia(tData data);
int qtdDiasNoMes(tData data);
void ImprimirData(tData data);

#endif
