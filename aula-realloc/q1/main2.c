#include <stdio.h>
#include <stdlib.h>

int main(){
    float input;
    float* notas = (float*) malloc (sizeof(float));
    int qtd=1;
    int cont=0;

    printf("Digite uma nota:");
    scanf("%f",&input);

    while(input>0){
        notas[cont]=input;
        qtd++; cont++;
        notas = (float*) realloc(notas, qtd*sizeof(float));

        scanf("%f",&input);
    }

    //calcula media
    //calcula dp

    free(notas);
    return 0;
}