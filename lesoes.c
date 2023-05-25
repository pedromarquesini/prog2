#include "lesoes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct lesao{
    char *tipo;
    char *diagnostico;
    char *regiao;
    float tamanho;
    char cirurgia[4];//SIM OU NÃO
    char crioterapia[4];//SIM OU NÃO
};

Lesao* lesao_alloc(Lesao *les, int qtdLesoes){
    //alocar a struct lesao com realloc 
    les = (Lesao*) realloc(les,qtdLesoes*sizeof(Lesao));
    return les;
}

Lesao* lesao_cadastro(Paciente *pct, Lesao *les){
    //FUNÇÃO INCOMPLETA - REFAZER
    
    char entrada[100];

    //tipo
    scanf("%[^\n]", entrada);
    les->tipo = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(les->tipo, entrada);
    fflush(stdin);

    //diagnostico
    scanf("%[^\n]", entrada);
    les->diagnostico = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(les->diagnostico, entrada);
    fflush(stdin);

    //regiao
    scanf("%[^\n]", entrada);
    les->regiao = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(les->regiao, entrada);
    fflush(stdin);

    //tamanho
    les->tamanho = tamanho;
    scanf("%f", &les->tamanho);

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


