#include "time.h"
#include <stdio.h>
#include <stdlib.h>

struct time{
    char nome[33];
    char estado[3];
};

Time *time_construir(){
    Time *t= (Time*)malloc(sizeof(Time));
        if(t==NULL){
            printf("Erro de alocação de memória!\n");
            exit(1);
        }
    return t;
}

void time_ler(Time *t){
    scanf("%s %s", t->nome,t->estado);

}

void time_mostrar(Time *t){
    printf("%s [%s]\n", t->nome,t->estado);
}

void time_destruir(Time *t){
    free(t);
}