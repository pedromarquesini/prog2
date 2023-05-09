#include "pessoa.h"

int main(){
    Pessoa *person = NULL;
    person = InicializaPessoa(person);
    int qtdpessoa=0;
    char op;

    printf("Deseja cadastrar uma pessoa? N para não\n");
    scanf("%c",&op);

    while ((op!='n')||(op!='N')){        
        qtdpessoa++;
        CriaPessoa(person,qtdpessoa);

        printf("Deseja continuar? N para não\n");
        fflush(stdin);//limpa buffer
        scanf("%c",&op);
        
    }

    LiberaPessoa(person);   

    return 0;
}