#ifndef _LESOES_H_
#define _LESOES_H_

typedef struct lesao Lesao;

Lesao* lesao_alloc(Lesao *les, int qtdLesoes);
Lesao* lesao_cadastro(Lesao *les);
void lesao_free(Lesao *les);


#endif