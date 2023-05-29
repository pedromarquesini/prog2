#include "lesoes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


struct lesao{
    char *tipo;
    char *diagnostico;
    char *regiao;
    float tamanho;
    char cirurgia[4];//SIM OU NÃO
    char crioterapia[4];//SIM OU NÃO
};

//função interna
void transformaMaiusculo(char *entrada){
    //essa função vai transformar a string entrada em maiusculo
    int tam = strlen(entrada);
    for(int x=0; x<tam; x++){
        entrada[x] = toupper(entrada[x]);
    }   
}

Lesao* lesao_alloc(Lesao *les){
    //alocar a struct lesao com malloc
    les = (Lesao*) malloc(sizeof(Lesao));

    //inicilizar as variaveis da struct lesao
    les->tipo = NULL;
    les->diagnostico = NULL;
    les->regiao = NULL;
    les->tamanho = 0;
    strcpy(les->cirurgia, "NÃO");
    strcpy(les->crioterapia, "NÃO");

    return les;
}

void lesao_addLesao(Lesao *lesP, Lesao *les, int qtdLesoes){
    //adicionar a lesão no vetor de lesões do paciente
    lesP[qtdLesoes-1].tipo = les->tipo;
    lesP[qtdLesoes-1].diagnostico = les->diagnostico;
    lesP[qtdLesoes-1].regiao = les->regiao;
    lesP[qtdLesoes-1].tamanho = les->tamanho;
    strcpy(lesP[qtdLesoes-1].cirurgia, les->cirurgia);
    strcpy(lesP[qtdLesoes-1].crioterapia, les->crioterapia);

}

void lesao_realloc(Lesao *les, int qtdLesoes){
    //realocar o vetor de lesões do paciente
    les = (Lesao*) realloc(les, sizeof(Lesao)*qtdLesoes);    
    
}

Lesao* lesao_cadastro(Lesao *les){
    //a função vai gerar um lesao e retornará para ser adicionada ao vetor de lesões do paciente
    les = (Lesao*) malloc(sizeof(Lesao));
    char entrada[100];

    //tipo
    scanf("%[^\n]", entrada);
    les->tipo = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(les->tipo, entrada);
    transformaMaiusculo(les->tipo);
    fflush(stdin);

    //diagnostico
    scanf("%[^\n]", entrada);
    les->diagnostico = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(les->diagnostico, entrada);
    transformaMaiusculo(les->diagnostico);
    fflush(stdin);

    //regiao
    scanf("%[^\n]", entrada);
    les->regiao = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(les->regiao, entrada);
    transformaMaiusculo(les->regiao);
    fflush(stdin);

    //tamanho    
    scanf("%f", &les->tamanho);
    fflush(stdin);

    //cirurgia
    scanf("%[^\n]", entrada);
    strcpy(les->cirurgia, entrada);    
    transformaMaiusculo(les->cirurgia);
    fflush(stdin);

    //crioterapia
    scanf("%[^\n]", entrada);
    strcpy(les->crioterapia, entrada);
    fflush(stdin);

    return les;
   
}

void lesao_free(Lesao *les){

    //liberar todas as variaveis de lesao
    free(les->tipo);
    free(les->diagnostico);
    free(les->regiao);

    //liberar a struct lesao
    free(les);
}


