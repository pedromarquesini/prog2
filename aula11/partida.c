#include "partida.h"
#include <stdlib.h>

struct partida{
    int time1, time2;
    int golsT1,golsT2;
};

Partida* partida_construir(){
    Partida *p= (Partida*) malloc (sizeof(Partida));
    if(p==NULL){
        printf("Erro de alocação de memória");
        exit(1);        
    }
    p->time1=0;
    p->time2=0;
    p->golsT1=0;
    p->golsT2=0;

    return p;
}

void partida_ler(Partida *p){
    scanf("%d %d %d %d\n", &p->time1,&p->time2,&p->golsT1,&p->golsT2);

}

int partida_jogou(Partida *p,int aux){
    if((p->time1 == aux)|| (p->time2==aux)){
        return 1;
    }else return 0;
}

int partida_vencedor(Partida *p){
    if(p->golsT1>p->golsT2){
        return p->time1;
    }else if(p->golsT2>p->golsT1){
        return p->time2;
    }else return -1;//empate
}

void partida_destruir(Partida *p){
    free(p);
}