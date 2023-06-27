#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeArquivo(){
    FILE *arq;
    arq = fopen("img-1-int.bin", "rb");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    int x,y,z;

    fread(&x, sizeof(int), 1, arq);
    fread(&y,sizeof(int),1,arq);
    fread(&z,sizeof(int),1,arq);//ignorar o z

    int matriz[x][y];
    int cont=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            fread(&matriz[i][j],sizeof(int),1,arq);
            cont++;
        }
    }

    //acha o maior e menor valor da matriz
    int maior=matriz[0][0], menor=matriz[0][0],soma=0;
    int qtd=0;

    for(int i=0; i<x;i++){
        for(int j=0;j<y;j++){
            if(matriz[i][j]>maior){
                maior=matriz[i][j];
            }else if(matriz[i][j]<menor){
                menor=matriz[i][j];
            }
            soma+=matriz[i][j];
            
        }
    }
  
    int media=soma/cont;   

    printf("Maior: %d\nMenor: %d\nMedia: %d\n",maior,menor,media);

    fclose(arq);
}

int main(){
   LeArquivo();
    return 0;
}