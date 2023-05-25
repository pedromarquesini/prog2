#include "paciente.h"
#include "lesoes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct paciente{
    char *nome;
    char cartaoSus[20];
    char dataNascimento[11];//formato dd/mm/aaaa
    int idade;
    char sexo[10]; // Masculino, Feminino ou Outros
    char telefone[15];//formato (xx)xxxxx-xxxx
    char diabetes[4];//SIM OU NAO
    char fumante[4];
    char alergiaMedicamento[4];
    char *nomeMedicamentoAlergia;
    char historicoCancer[4];
    char tipoPele[4];//I, II, III, IV, V ou VI
    Lesao *lesoes;
    int qtdLesoes;
    int qtdcirurgia;
    int qtdCrioterapia;    
};

//função externa do sistema
void ImprimeMenu(){
    
   printf("######################### MENU INICIAL ###########################\n");
    printf("Escolha uma opcao:\n");
    printf("- Pre-cadastrar um paciente (P ou p)\n");
    printf("- Iniciar um atendimento (A ou a)\n");
    printf("- Buscar um paciente (B ou b)\n");
    printf("- Gerar relatorio (R ou r)\n");
    printf("- Finalizar programa (F ou f)\n");
    printf("###############################################################\n");

}

//funções internas
int calcularIdade(char data[11]) {
    int dia, mes, ano;
    int diaVerificacao=11, mesVerificacao=05, anoVerificacao=2023;
    int idade;

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    idade = anoVerificacao - ano;

    if (mesVerificacao < mes || (mesVerificacao == mes && diaVerificacao < dia)) {
        idade--;
    }

    return idade;
}

void transformaMaiuscula(char *texto){
    int i;
    for(i=0; texto[i]!='\0'; i++){
        if(texto[i]>='a' && texto[i]<='z'){
            texto[i] = texto[i] - 32;
        }
    }
}

int ValidaCartaoSus(Paciente** bd_pacientes, char cartaoSus[20]) {
    // Verifica se o cartão já está cadastrado em algum paciente do bd_pacientes
    for (int i = 0; bd_pacientes[i] != NULL; i++) {
        if (strcmp(bd_pacientes[i]->cartaoSus, cartaoSus) == 0) {
            return 0; // O cartão já está cadastrado
        }
    }

    // Valida o cartão SUS
    int contadorDigitos = 0;
    for (int i = 0; cartaoSus[i] != '\0'; i++) {
        if (cartaoSus[i] >= '0' && cartaoSus[i] <= '9') {
            contadorDigitos++;
        } else if (cartaoSus[i] != '-') {
            return 0; // Caractere inválido encontrado
        }
    }

    if (contadorDigitos == 15) {
        return 1; // O cartão é válido
    }

    return 0; // O cartão é inválido
}

void atualizaDadosClinicos(Paciente* pct){
    //Nesta funcao o usuario podera atualizar os dados clinicos do paciente
    //sendo eles: diabetes, fumante, alergia a medicamento, historico de cancer e tipo de pele
    char entrada[100];
    

    //diabetes
    scanf("%[^\n]", entrada);
    fflush(stdin);//limpa o buffer do teclado
    strcpy(pct->diabetes, entrada); 

    //fumante
    scanf("%[^\n]", entrada);
    fflush(stdin);
    strcpy(pct->fumante, entrada);

    //alergia a medicamento
    printf("O paciente possui alergia a medicamento?\n");
    scanf("%[^\n]", entrada);
    fflush(stdin);
    strcpy(pct->alergiaMedicamento, entrada);
    
        if(strcmp(pct->alergiaMedicamento, "SIM")==0){
            scanf("%[^\n]", entrada);  
            fflush(stdin);
            pct->nomeMedicamentoAlergia = (char*) malloc(sizeof(char)*strlen(entrada));         
            strcpy(pct->nomeMedicamentoAlergia, entrada);
        }

    //historico de cancer
    scanf("%[^\n]", entrada);
    fflush(stdin);
    strcpy(pct->historicoCancer, entrada);

    //tipo de pele do paciente
    scanf("%[^\n]", entrada);
    fflush(stdin);
    strcpy(pct->tipoPele, entrada);
    
}

int buscaIndicePaciente(Paciente** bd_pacientes, char cartaoSus[20]) {
    // Retorna o índice do paciente no bd_pacientes
    for (int i = 0; bd_pacientes[i] != NULL; i++) {
        if (strcmp(bd_pacientes[i]->cartaoSus, cartaoSus) == 0) {
            return i;
        }
    }

    return -1; // Paciente não encontrado
}

//funções externas
Paciente** paciente_InicializaSistema(){
    //inicializa o sistema com um vetor de pacientes
    Paciente **bd_pacientes = (Paciente**) malloc(sizeof(Paciente*));
    // bd_pacientes[0] = NULL;
    return bd_pacientes;
}



void paciente_realizaConsulta(Paciente **bd_pacientes, int qtdPacientes, char cartaoSus[20]){
    
    int i; //indice do paciente
        if(paciente_verificaCadastro(bd_pacientes, cartaoSus, qtdPacientes)){
            i=buscaIndicePaciente(bd_pacientes, cartaoSus);
            atualizaDadosClinicos(bd_pacientes[i]);
            //cadastra lesões do paciente
        }else{
            printf("Paciente nao cadastrado!\n");
        }  
    
}

int paciente_verificaCadastro(Paciente** bd_pacientes, char cartaoSus[20],int qtdPacientes){
    //essa função verifica se ja tem um usuario pre cadastrado de acordo com o cartão do sus
    for(int x=0; x<qtdPacientes; x++){
        if(strcmp(bd_pacientes[x]->cartaoSus, cartaoSus)==0){
            return 1;
        }
    }
    return 0;//se não tiver nenhum paciente cadastrado com esse cartão do sus, retorna 0

    
}

void paciente_geraArquivoBusca(Paciente** bd_pacientes,char cartaoSus[20]){
    // essa função vai gerar um arquivo busca_%s.txt, onde %s é o cartão do sus do paciente
    //     nome
    //     data de nascimento
    //     genero
    //     telefone

    //     se possui diabetes
    //     se é fumante
    //     se possui alergia a medicamento
    //     se possui historico de cancer
    //     tipo de pele

    //     lesões
    //     qtd de lesões
    //     qtd enviadas para cirurgia
    //     qtd enviadas para crioterapia

    //     descricao das lesoes no padrão:
    //     tipo - diagnostico - regiao - tamanho - enviada para cirurgia ou crioterapia ou nada


    
    FILE *file;
        if(file==NULL){
            printf("Erro ao abrir arquivo de busca!\n");
            return;
        }
    char nomeArquivo[100];
    sprintf(nomeArquivo, "busca_%s.txt", cartaoSus);
    file = fopen(nomeArquivo, "w");
    int i=buscaIndicePaciente(bd_pacientes, cartaoSus);

    //transforma as letras para caixa alta

    transformaMaiuscula(bd_pacientes[i]->nome);
    transformaMaiuscula(bd_pacientes[i]->sexo);
    transformaMaiuscula(bd_pacientes[i]->nomeMedicamentoAlergia);
    
    fprintf(file, "Nome: %s\n", bd_pacientes[i]->nome);

    fclose(file);
}


void paciente_preCadastro(Paciente **bd_paciente, int qtdPaciente){
    bd_paciente = (Paciente**) realloc(bd_paciente, (qtdPaciente+1)*sizeof(Paciente*));//adiciona um espaço no vetor de pacientes
    bd_paciente[qtdPaciente] = (Paciente*) malloc(sizeof(Paciente));
    bd_paciente[qtdPaciente+1]=NULL;
    char entrada[100];    

    //realizar precadastro com nome, cartao do sus, data de nascimento, telefone e sexo
    //nome
    printf("Digite o nome do paciente:\n");
    fgets(entrada, 100, stdin);
    bd_paciente[qtdPaciente]->nome = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(bd_paciente[qtdPaciente]->nome, entrada);

    //cartao do sus
    printf("Digite o cartao do SUS do paciente:\n");
    fgets(entrada, 20, stdin);
        if(ValidaCartaoSus(bd_paciente,entrada)){
            strcpy(bd_paciente[qtdPaciente]->cartaoSus, entrada);
        }else {
            printf("Cartao do SUS invalido ou já cadastrado!\n");
            return;
        }    
    
    //data de nascimento
    printf("Digite a data de nascimento do paciente (dd/mm/aaaa):\n");
    fgets(entrada, 11, stdin);
    strcpy(bd_paciente[qtdPaciente]->dataNascimento, entrada);
    bd_paciente[qtdPaciente]->idade = calcularIdade(bd_paciente[qtdPaciente]->dataNascimento);

    //telefone
    printf("Digite o telefone do paciente:\n");
    fgets(entrada, 20, stdin);
    strcpy(bd_paciente[qtdPaciente]->telefone, entrada);

    //sexo
    printf("Digite o sexo do paciente (Masculino ou Feminino):\n");
    fgets(entrada, 20, stdin);
    strcpy(bd_paciente[qtdPaciente]->sexo, entrada);

}

void paciente_LiberaPacientes(Paciente **bd_paciente, int qtdPaciente){
    for(int x=0; x<qtdPaciente; x++){
        free(bd_paciente[x]->nome);
        free(bd_paciente[x]->nomeMedicamentoAlergia);
        lesao_free(bd_paciente[x]->lesoes);
    }
    free(bd_paciente);
}
