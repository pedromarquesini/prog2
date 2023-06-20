#ifndef _LESOES_H_
#define _LESOES_H_

typedef struct lesao Lesao;

//funcoes externas
Lesao* lesao_alloc(Lesao *les);
void lesao_addLesao(Lesao *lesP, Lesao *les, int qtdLesoes);
void lesao_realloc(Lesao *les, int qtdLesoes);
Lesao** lesao_cadastroLesao(Lesao **lesoes, int qtdLesoes,FILE *arquivo);
void lesao_imprimeLesoes(Lesao **les, int qtdLesoes, FILE *arquivo);
int lesao_calculaLesoes(Lesao **lesoes);
int lesao_calculaCirurgia(Lesao **lesoes,int qtdLesoes);
int lesao_calculaCrioterapia(Lesao **lesoes,int qtdLesoes);

char* lesao_getIDlesao(Lesao **lesoes, int indice);
char* lesao_getDiagnostico(Lesao *les);
char* lesao_getRegiao(Lesao *les);
float lesao_getTamanho(Lesao *les);
char* lesao_getCirurgia(Lesao *les);
char* lesao_getCrioterapia(Lesao *les);

int lesao_somaTamanho(Lesao **lesoes, int qtdLesoes);
int lesao_calculaDesvioPadrao(Lesao **lesoes, int qtdLesoes, int mediaTam);

void lesao_free(Lesao *les);
void imprimeLesao(Lesao *les);
#endif