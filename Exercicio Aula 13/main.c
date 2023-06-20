#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int tam, tipo;
    //scanf("%d %d",&tam,&tipo);
    tam=10;
    tipo=1;
    Vetor *v1 = criar(tam,tipo);
    preencher(v1);
    imprimir(v1);

    printf("Media: %.2f\n",(float)calculaOp(v1,'m'));
    printf("Variancia: %.3lf\n",calculaOp(v1,'v'));
    printf("Desvio: %.d\n",(int)calculaOp(v1,'d'));

    liberar(v1);
    
    return 0;
}