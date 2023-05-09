#include "pessoa.h"

struct pessoa{
    char nome[50];
    char dataNasc[11];
    char cpf[15];
};

Pessoa* InicializaPessoa(Pessoa* person){
    person=(Pessoa*) malloc(sizeof(Pessoa*));     
    
    return person;
}

void CriaPessoa(Pessoa* person,int index){
    //alocação de memória
    person = (Pessoa*) realloc(person, index* sizeof(Pessoa*));

    //declaração de variáveis
    char nome[50];
    char cpf[15];
    char dataNasc[11];

    //leitura dos dados
    char buffer[100];
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%[^\n]", nome);

    fgets(buffer, 100, stdin);
    sscanf(buffer, "%[^\n]", dataNasc);

    fgets(buffer, 100, stdin);
    sscanf(buffer, "%[^\n]", cpf);

    //atribuição dos dados    
    strcpy(person[index].nome,nome);
    strcpy(person[index].dataNasc,dataNasc);
    strcpy(person[index].cpf,cpf);
    
}

void LiberaPessoa(Pessoa* person){
    free(person);
}



