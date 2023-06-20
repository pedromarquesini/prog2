#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lesoes.h"
#include <math.h>


struct lesao{
    char tipo[4];
    char *diagnostico;
    char *regiao;
    float tamanho;
    char cirurgia[4];//SIM OU NÃO
    char crioterapia[4];//SIM OU NÃO
    
};
//funcao nao declarada no .h
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descartar caracteres do buffer
    }
}

//função interna
void transformaMaiusculo(char *entrada){
    //essa função vai transformar a string entrada em maiusculo
    int tam = strlen(entrada);
    for(int x=0; x<tam; x++){
        entrada[x] = toupper(entrada[x]);
    }   
}

//funcao externa
Lesao* lesao_alloc(Lesao *les){
    //alocar a struct lesao com malloc
    les = (Lesao*) malloc(sizeof(Lesao));

    //inicilizar as variaveis da struct lesao

    les->diagnostico = NULL;
    les->regiao = NULL;
    les->tamanho = 0;
    strcpy(les->cirurgia, "NÃO");
    strcpy(les->crioterapia, "NÃO");

    return les;
}

void lesao_addLesao(Lesao *lesP, Lesao *les, int qtdLesoes){
    //adicionar a lesão no vetor de lesões do paciente
    //lesP[qtdLesoes-1].tipo = les->tipo;
    lesP[qtdLesoes-1].diagnostico = les->diagnostico;
    lesP[qtdLesoes-1].regiao = les->regiao;
    lesP[qtdLesoes-1].tamanho = les->tamanho;
    strcpy(lesP[qtdLesoes-1].cirurgia, les->cirurgia);
    strcpy(lesP[qtdLesoes-1].crioterapia, les->crioterapia);

}

void lesao_realloc(Lesao *les, int qtdLesoes){
    //realocar o vetor de lesões do paciente
    les = (Lesao*) realloc(les, sizeof(Lesao)*(qtdLesoes+1));    
    
}

Lesao** lesao_cadastroLesao(Lesao **lesoes,int qtdlesoes, FILE *arquivo){
    //int qtdlesoes = 0;
    char entrada[100];
    if(qtdlesoes == 0){
        //alocar o double pointer de lesões
        lesoes = (Lesao**) malloc(sizeof(Lesao*));
    }

    //o programa vai encerrar quando o usuario digitar e
    while(1){
        scanf("%[^\n]", entrada);
        if(strcmp(entrada, "E") == 0){
            cleanBuffer();            
            break;
        }     

        qtdlesoes++;  
        //realocar o double pointer de lesões   
        lesoes = (Lesao**) realloc(lesoes, sizeof(Lesao*)*(qtdlesoes+1));

        lesoes[qtdlesoes-1] = (Lesao*) malloc(sizeof(Lesao));
        
        //diagnostico
        lesoes[qtdlesoes-1]->diagnostico = (char*) malloc((strlen(entrada)+1)*sizeof(char));
        strcpy(lesoes[qtdlesoes-1]->diagnostico, entrada);
        transformaMaiusculo(lesoes[qtdlesoes-1]->diagnostico);
        cleanBuffer();

        //regiao
        scanf("%[^\n]", entrada);
        lesoes[qtdlesoes-1]->regiao = (char*) malloc((strlen(entrada)+1)*sizeof(char));
        strcpy(lesoes[qtdlesoes-1]->regiao, entrada);
        transformaMaiusculo(lesoes[qtdlesoes-1]->regiao);
        cleanBuffer();

        //tamanho
        scanf("%f", &lesoes[qtdlesoes-1]->tamanho);
        cleanBuffer();
        
        //cirurgia
        scanf("%[^\n]", entrada);
        transformaMaiusculo(entrada);
        strcpy(lesoes[qtdlesoes-1]->cirurgia, entrada);
        cleanBuffer();

        //crioterapia
        scanf("%[^\n]", entrada);
        transformaMaiusculo(entrada);
        strcpy(lesoes[qtdlesoes-1]->crioterapia, entrada);
        cleanBuffer();

        //id da lesao - TIPO    
        //lesoes[qtdlesoes - 1]->tipo = (char*)malloc(3 * sizeof(char));
        //sprintf(lesoes[qtdlesoes - 1]->tipo, "L%d", qtdlesoes);

        char tipo[4];
        sprintf(tipo, "L%d", qtdlesoes);
        strcpy(lesoes[qtdlesoes-1]->tipo, tipo);

        fprintf(arquivo, "%s\n", lesoes[qtdlesoes-1]->tipo);
        
        //imprimeLesao(lesoes[qtdlesoes-1]);

    }  
    return lesoes;
}

void imprimeLesao(Lesao *les){
    printf("Tipo: %s\n", les->tipo);
    printf("Diagnostico: %s\n", les->diagnostico);
    printf("Regiao: %s\n", les->regiao);
    printf("Tamanho: %.2f\n", les->tamanho);
    printf("Cirurgia: %s\n", les->cirurgia);
    printf("Crioterapia: %s\n", les->crioterapia);

}

int lesao_calculaLesoes(Lesao **lesoes){
    //essa função calcula a quantidade de lesões cadastradas
    int qtdlesoes = 0;
    while(lesoes[qtdlesoes] != NULL){
        qtdlesoes++;
    }
    return qtdlesoes;
}

int lesao_calculaCirurgia(Lesao **lesoes,int qtdLesoes){
    //essa função roda o vetor de lesao comparando a string cirurgia com "SIM"
    //FUNÇÃO FUNCIONANDO CORRETAMENTE GRAZADEUS
    int qtdCirurgia=0;
    int x=0;
    for(x=0; x<qtdLesoes; x++){
        if(strcmp(lesoes[x]->cirurgia, "SIM")==0){
            qtdCirurgia++;
        }
    }
    return qtdCirurgia;
}

int lesao_calculaCrioterapia(Lesao **lesoes,int qtdLesoes){
    //essa função roda o vetor de lesao comparando a string crioterapia com "SIM"
    int qtdCrioterapia=0;
    int x=0;
    for(x=0; x<qtdLesoes; x++){
        if(strcmp(lesoes[x]->crioterapia, "SIM")==0){
            qtdCrioterapia++;
        }
    }
    return qtdCrioterapia;
}

char* lesao_getIDlesao(Lesao **lesoes, int indice){
    //retorna o tipo da lesao
    return lesoes[indice]->tipo;
}

void lesao_imprimeLesoes(Lesao **les, int qtdLesoes, FILE *arquivo){

    //transformar em maiusculo
    transformaMaiusculo(les[qtdLesoes-1]->diagnostico);
    transformaMaiusculo(les[qtdLesoes-1]->regiao);
    transformaMaiusculo(les[qtdLesoes-1]->cirurgia);
    transformaMaiusculo(les[qtdLesoes-1]->crioterapia);

   //fprintf(arquivo, "\nDESCRICAO DAS LESOES:\n");
   int x=0;
    for(x=0; x<qtdLesoes; x++){
         fprintf(arquivo, "%s - %s - %s - %.0fMM", les[x]->tipo, les[x]->diagnostico, les[x]->regiao, les[x]->tamanho);
         if(strcmp(les[x]->cirurgia, "SIM")==0){
              fprintf(arquivo, " - ENVIADA PARA CIRURGIA\n");
         }else if(strcmp(les[x]->crioterapia, "SIM")==0){
              fprintf(arquivo, " - ENVIADA PARA CRIOTERAPIA\n");
         }else{
              fprintf(arquivo, "\n");
         }
    }

}

int lesao_somaTamanho(Lesao **lesoes, int qtdLesoes){
    //essa função calcula o tamanho total das lesões
    int tamanhoTotal=0;
    int x=0;
    for(x=0; x<qtdLesoes; x++){
        tamanhoTotal += lesoes[x]->tamanho;
    }
    return tamanhoTotal;
}

int lesao_calculaDesvioPadrao(Lesao **lesoes, int qtdLesoes, int mediaTam){
    //essa função calcula o desvio padrão do tamanho das lesões
    int desvioPadrao=0;
    int x=0;
    for(x=0; x<qtdLesoes; x++){
        desvioPadrao += pow((lesoes[x]->tamanho - mediaTam), 2);
    }
    desvioPadrao = sqrt(desvioPadrao/qtdLesoes);
    return desvioPadrao;
}

char* lesao_getDiagnostico(Lesao *les){
    return les->diagnostico;
}
char* lesao_getRegiao(Lesao *les){
    return les->regiao;
}
float lesao_getTamanho(Lesao *les){
    return les->tamanho;
}
char* lesao_getCirurgia(Lesao *les){
    return les->cirurgia;
}
char* lesao_getCrioterapia(Lesao *les){
    return les->crioterapia;
}

void lesao_free(Lesao *les){  
        free(les->diagnostico);
        free(les->regiao);
        free(les);          
}
 