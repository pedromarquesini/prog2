#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define INT_VETOR 1
#define FLOAT_VETOR 2
#define DOUBLE_VETOR 3
#define MAX 1000000

struct vetor{
    void *arr;
    int tam;
    int tipo;
};

Vetor *criar(int tam, int tipo){

    Vetor *v = malloc(sizeof(Vetor));
    v->tam = tam;
    v->tipo = tipo;
    //allocar memoria de acordo com o tamanho e tipo
    if(tipo == INT_VETOR){
        v->arr = malloc(tam*sizeof(int));        
    }else if(tipo == FLOAT_VETOR){
        v->arr = malloc(tam*sizeof(float));
    }else if(tipo == DOUBLE_VETOR){
        v->arr = malloc(tam*sizeof(double));
    }else{
        v->arr = NULL;
        v->tam = 0;
    }

    return v;
}

void preencher(Vetor *v){
    for(int i=0;i<v->tam;i++){
        if(v->tipo == INT_VETOR){
            ((int*)v->arr)[i] = (int)rand( )%MAX;          
        }
        else if(v->tipo == FLOAT_VETOR){
            ((float*)v->arr)[i] = (float)rand( )/RAND_MAX*MAX;
        }
        else if(v->tipo == DOUBLE_VETOR){
            ((double*)v->arr)[i] = (double)rand( )/RAND_MAX*MAX;
        }
    }
}

void imprimir(Vetor *v){
    for(int i=0;i<v->tam;i++){
        if(v->tipo == INT_VETOR){
            printf("%d ",((int*)v->arr)[i]);          
        }
        else if(v->tipo == FLOAT_VETOR){
            printf("%.3f ",((float*)v->arr)[i]);
        }
        else if(v->tipo == DOUBLE_VETOR){
            printf("%.3lf ",((double*)v->arr)[i]);
        }
    }
    printf("\n");
}

double media(Vetor *v){
    double soma = 0;
    for(int i=0;i<v->tam;i++){
        if(v->tipo == INT_VETOR){
            soma += ((int*)v->arr)[i];          
        }
        else if(v->tipo == FLOAT_VETOR){
            soma += ((float*)v->arr)[i];
        }
        else if(v->tipo == DOUBLE_VETOR){
            soma += ((double*)v->arr)[i];
        }
    }
    return soma/v->tam;
}
double variancia(Vetor *v){
    double soma = 0;
    double m = media(v);
    for(int i=0;i<v->tam;i++){
        if(v->tipo == INT_VETOR){
            soma += pow(((int*)v->arr)[i]-m,2);          
        }
        else if(v->tipo == FLOAT_VETOR){
            soma += pow(((float*)v->arr)[i]-m,2);
        }
        else if(v->tipo == DOUBLE_VETOR){
            soma += pow(((double*)v->arr)[i]-m,2);
        }
    }
    return soma/v->tam;
}
double desvio(Vetor *v){
    return sqrt(variancia(v));
}

double operacao(Vetor *v, double (*ponteiroFuncao)(Vetor *v)){
    return ponteiroFuncao(v);
}

double calculaOp(Vetor *v, char o){
    switch(o){
        case 'm':
            return operacao(v,media);
        case 'v':
            return operacao(v,variancia);
        case 'd':
            return operacao(v,desvio);
        default:
            return 0;
    }
}

void liberar(Vetor *v){
    free(v->arr);
    free(v);
}
