#ifndef _PESSOA_H_
#define _PESSOA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa Pessoa; //o primeiro nome é o da struct, e o segundo é o utilizado no código

Pessoa* InicializaPessoa(Pessoa* person);
void LiberaPessoa(Pessoa* person);
void CriaPessoa(Pessoa* person,int index);



#endif