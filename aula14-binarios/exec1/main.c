#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[50];
    char dataNascimento[11];
    char cpf[12];
}Pessoa;

Pessoa InicializaPessoa(char *nome, char *dataNascimento, char *cpf,Pessoa p){    
    strcpy(p.nome, nome);
    strcpy(p.dataNascimento, dataNascimento);
    strcpy(p.cpf, cpf);
    return p;
}

void salvaPessoa(Pessoa p,FILE *arquivo){
    fwrite(&p, sizeof(Pessoa), 1, arquivo);
}
Pessoa lePessoa(Pessoa *p,FILE *arquivo){
    fread(p, sizeof(Pessoa), 1, arquivo);
    
}

int main(){
    FILE *arquivo;
    Pessoa p[3];
    p[0]=InicializaPessoa("Pedro","14/10/2000","06048125585",p[1]);
    p[1]=InicializaPessoa("Maria","02/02/2000","12345678911",p[2]);
    p[2]=InicializaPessoa("Jose","03/03/2000","12345678912",p[3]);

    arquivo = fopen("pessoas.bin", "wb"); //abrir pra escrita binaria
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for(int i=0;i<3;i++){
        salvaPessoa(p[i],arquivo);
    }
    fclose(arquivo);

    arquivo=fopen("pessoas.bin","rb"); //abrir pra leitura binaria

    Pessoa p2;
    for(int i=0;i<3;i++){
        lePessoa(&p2,arquivo);
        printf("Nome: %s\n",p2.nome);
        printf("Data de Nascimento: %s\n",p2.dataNascimento);
        printf("CPF: %s\n",p2.cpf);
        printf("________________\n");
    }

    fclose(arquivo);

    return 0;
}