#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    char dataNasc[11];
    char cpf[15];
}tPessoa;

void LePessoa(tPessoa* person,int index){
    scanf("%s",&person[index].nome);
    scanf("%s",&person[index].dataNasc);
    scanf("%s",&person[index].cpf);    
}

int main(){
    tPessoa *person = NULL;
    char op;    
    int qtdpessoa=0;
    
    while(1){
        
        printf("Deseja continuar? N para não\n");
        scanf("%c",&op);
        if((op=='n') || (op=='N')){//ERRO DE CODIGO AQUI USAR STRCMPT
            break;//interrompe o programa
        }
        qtdpessoa++;
        person=(tPessoa*) realloc(person,qtdpessoa* sizeof(tPessoa));
        
        LePessoa(person,qtdpessoa);        

    }

    free(person);

    return 0;
}