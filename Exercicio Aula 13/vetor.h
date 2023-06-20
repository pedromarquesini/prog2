#ifndef _VETOR_H_
#define _VETOR_H_

typedef struct vetor Vetor;

Vetor *criar(int tam, int tipo);
void preencher(Vetor *v);
void imprimir(Vetor *v);
void liberar(Vetor *v);
double calculaOp(Vetor *v, char o);

#endif