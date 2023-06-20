#include "paciente.h"
#include <math.h>

struct paciente{
    char *nome;
    char cartaoSus[20];
    char dataNascimento[11];//formato dd/mm/aaaa
    int idade;
    char sexo[10]; // Masculino, Feminino ou Outros
    char telefone[15];//formato (xx)xxxxx-xxxx
    char *endereco;

    char diabetes[4];//SIM OU NAO
    char fumante[4];
    char alergiaMedicamento[4];
    char *nomeMedicamentoAlergia;
    char historicoCancer[4];
    char tipoPele[4];//I, II, III, IV, V ou VI

    Lesao **lesoes;
    int qtdLesoes;
    int qtdcirurgia;
    int qtdCrioterapia;    
    int qtdAtendimentos;
};

typedef struct {
    char nome[50];
    int quantidade;
}Diagnostico;

typedef struct {
    char nome[50];
    int quantidade;
}Regiao;


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

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descartar caracteres do buffer
    }
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

int ValidaCartaoSus(Paciente** bd_pacientes, char cartaoSus[20],int qtdpacientes) {
    // Verifica se o cartão já está cadastrado em algum paciente do bd_pacientes
    for (int i = 0; i<qtdpacientes; i++) {
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

Paciente* atualizaDadosClinicos(Paciente* pct){
    //Nesta funcao o usuario podera atualizar os dados clinicos do paciente
    //sendo eles: diabetes, fumante, alergia a medicamento, historico de cancer e tipo de pele
    char entrada[100];
    
    //diabetes
    scanf("%[^\n]", entrada);
    limparBuffer();//limpa o buffer do teclado
    transformaMaiuscula(entrada);//transforma a string em maiuscula
    strcpy(pct->diabetes, entrada); 

    //fumante
    scanf("%[^\n]", entrada);
    limparBuffer();
    transformaMaiuscula(entrada);
    strcpy(pct->fumante, entrada);

    //alergia a medicamento    
    scanf("%[^\n]", entrada);
    limparBuffer();
    //transforma maiuscula
    transformaMaiuscula(entrada);
    strcpy(pct->alergiaMedicamento, entrada);

        if(strcmp(pct->alergiaMedicamento, "SIM")==0){
            scanf("%[^\n]", entrada);  
            limparBuffer();
            transformaMaiuscula(entrada);
            pct->nomeMedicamentoAlergia = (char*) malloc(sizeof(char)*strlen(entrada));         
            strcpy(pct->nomeMedicamentoAlergia, entrada);
        }

    //historico de cancer
    scanf("%[^\n]", entrada);
    limparBuffer();
    transformaMaiuscula(entrada);
    strcpy(pct->historicoCancer, entrada);

    //tipo de pele do paciente
    scanf("%[^\n]", entrada);
    limparBuffer();
    transformaMaiuscula(entrada);
    strcpy(pct->tipoPele, entrada);
    
    // teste- imprimir dados clinicos do paciente
    // printf("Dados clinicos do paciente:\n");
    // printf("Diabetes: %s\n", pct->diabetes);
    // printf("Fumante: %s\n", pct->fumante);
    // printf("Alergia a medicamento: %s\n", pct->alergiaMedicamento);
    // printf("Nome do medicamento: %s\n", pct->nomeMedicamentoAlergia);
    // printf("Historico de cancer: %s\n", pct->historicoCancer);
    // printf("Tipo de pele: %s\n", pct->tipoPele);

    return pct;
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
    
    Paciente **bd_pacientes = (Paciente**) malloc(sizeof(Paciente*));   

    return bd_pacientes;

}

Paciente** paciente_realizaConsulta(char* caminho_pasta,Paciente **bd_pacientes, int qtdPacientes, char cartaoSus[20], int qtdAtendimentos){
    
    char nome_arquivo[100];
    char entrada[100];
    sprintf(nome_arquivo, "%s/logs/log_%d.txt",caminho_pasta, qtdAtendimentos);
    FILE *arquivo = fopen(nome_arquivo, "w");
                
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de log.\n");
        exit(1); // Encerrar o programa
    }                
                
    int i; //indice do paciente
        
    printf("Paciente %s de %d anos cadastrado! A consulta pode ser iniciada\n", bd_pacientes[qtdPacientes-1]->nome, bd_pacientes[qtdPacientes-1]->idade);
    i=buscaIndicePaciente(bd_pacientes, cartaoSus);

    scanf("%[^\n]", entrada);//data do atendimento
    limparBuffer();

    fprintf(arquivo, "%s\n", bd_pacientes[i]->cartaoSus);//imprimir cartao sus do paciente no arquivo
    fprintf(arquivo,"%s\n",entrada);//imprimir data do atendimento

    bd_pacientes[i]=atualizaDadosClinicos(bd_pacientes[i]);

    //verifica se o paciente ja realizou alguma consulta
    if(bd_pacientes[i]->qtdAtendimentos==0){
        bd_pacientes[i]->qtdLesoes=0;
        bd_pacientes[i]->qtdcirurgia=0;
        bd_pacientes[i]->qtdCrioterapia=0;
    }

    //printf("indo cadastrar lesao de numero %d\n", bd_pacientes[i]->qtdLesoes);
    bd_pacientes[i]->lesoes = lesao_cadastroLesao(bd_pacientes[i]->lesoes,bd_pacientes[i]->qtdLesoes,arquivo);    
    bd_pacientes[i]->qtdAtendimentos++;
    printf("Consulta realizada com sucesso!\n");      
    //printf("aqui ja da seg fault");

    //pegar a quantidade de lesões,cirurgia e crioterapia do paciente    
    bd_pacientes[i]->qtdLesoes = lesao_calculaLesoes(bd_pacientes[i]->lesoes);
    bd_pacientes[i]->qtdcirurgia = lesao_calculaCirurgia(bd_pacientes[i]->lesoes, bd_pacientes[i]->qtdLesoes);
    bd_pacientes[i]->qtdCrioterapia = lesao_calculaCrioterapia(bd_pacientes[i]->lesoes, bd_pacientes[i]->qtdLesoes);
    
    
    //printf("Agora o paciente tem %d lesões, %d cirurgias e %d crioterapias\n", bd_pacientes[i]->qtdLesoes, bd_pacientes[i]->qtdcirurgia, bd_pacientes[i]->qtdCrioterapia);
    //teste-imprimir dados das qtd de lesoes
    // printf("Dados das lesoes:\n");  
    // printf("Quantidade de lesoes: %d\n", bd_pacientes[i]->qtdLesoes);
    // printf("Quantidade de cirurgias: %d\n", bd_pacientes[i]->qtdcirurgia);
    // printf("Quantidade de crioterapias: %d\n", bd_pacientes[i]->qtdCrioterapia);

    //teste-imprimir dados das lesoes
    //printf("Lesoes do Paciente: %s\n", bd_pacientes[i]->nome);
    for(int x=0; x<bd_pacientes[i]->qtdLesoes; x++){
        
        //imprimeLesao(bd_pacientes[i]->lesoes[i]);

    }
    
    fclose(arquivo);
    return bd_pacientes;
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

Paciente** paciente_preCadastro(Paciente **bd_paciente, int qtdPaciente){
    
    bd_paciente = (Paciente**) realloc(bd_paciente, (qtdPaciente+1)*sizeof(Paciente*));//adiciona um espaço no vetor de pacientes
    bd_paciente[qtdPaciente] = (Paciente*) malloc(sizeof(Paciente));
    
    if(bd_paciente[qtdPaciente]==NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    char entrada[100];    

    //realizar precadastro com nome, cartao do sus, data de nascimento, telefone e sexo
    //nome
    scanf("%[^\n]", entrada);
    limparBuffer();
    bd_paciente[qtdPaciente]->nome = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(bd_paciente[qtdPaciente]->nome, entrada);
    
    //cartao do sus
    scanf("%[^\n]", entrada);
    limparBuffer();
        if(ValidaCartaoSus(bd_paciente,entrada,qtdPaciente)){
            strcpy(bd_paciente[qtdPaciente]->cartaoSus, entrada);
        }else {
            printf("Cartao do SUS invalido ou já cadastrado!\n");
            free(bd_paciente[qtdPaciente]->nome);
            return bd_paciente;
        }    
    
    //data de nascimento
    scanf("%[^\n]", entrada);
    limparBuffer();
    strcpy(bd_paciente[qtdPaciente]->dataNascimento, entrada);
    bd_paciente[qtdPaciente]->idade = calcularIdade(bd_paciente[qtdPaciente]->dataNascimento);

    //telefone
    scanf("%[^\n]", entrada);
    limparBuffer();
    strcpy(bd_paciente[qtdPaciente]->telefone, entrada);

    //endereço
    scanf("%[^\n]", entrada);
    limparBuffer();
    bd_paciente[qtdPaciente]->endereco = (char*) malloc((strlen(entrada)+1)*sizeof(char));
    strcpy(bd_paciente[qtdPaciente]->endereco, entrada);

    //sexo
    scanf("%[^\n]", entrada);
    limparBuffer();
    strcpy(bd_paciente[qtdPaciente]->sexo, entrada);

    //iniciar contadores
    bd_paciente[qtdPaciente]->qtdLesoes = 0;
    bd_paciente[qtdPaciente]->qtdcirurgia = 0;
    bd_paciente[qtdPaciente]->qtdCrioterapia = 0;
    bd_paciente[qtdPaciente]->qtdAtendimentos = 0;


    // //imprimir dados do paciente para conferencia
    // printf("Nome: %s\n", bd_paciente[qtdPaciente]->nome);
    // printf("Cartao do SUS: %s\n", bd_paciente[qtdPaciente]->cartaoSus);
    // printf("Data de nascimento: %s\n", bd_paciente[qtdPaciente]->dataNascimento);
    // printf("Idade: %d\n", bd_paciente[qtdPaciente]->idade);
    // printf("Telefone: %s\n", bd_paciente[qtdPaciente]->telefone);
    // printf("Sexo: %s\n", bd_paciente[qtdPaciente]->sexo);
    // printf("Lesoes: %d, Cirurgias: %d, Crioterapias: %d\n", bd_paciente[qtdPaciente]->qtdLesoes, bd_paciente[qtdPaciente]->qtdcirurgia, bd_paciente[qtdPaciente]->qtdCrioterapia);

    return bd_paciente;
}

void paciente_imprimePaciente(Paciente **bd_pacientes,char cartaoSus[20], int qtdPacientes){
    //essa função imprime os dados do paciente
    int x=0;
    x = buscaIndicePaciente(bd_pacientes, cartaoSus);        
            printf("Nome: %s\n", bd_pacientes[x]->nome);
            printf("Cartao do SUS: %s\n", bd_pacientes[x]->cartaoSus);
            printf("Data de nascimento: %s\n", bd_pacientes[x]->dataNascimento);
            printf("Idade: %d\n", bd_pacientes[x]->idade);
            printf("Telefone: %s\n", bd_pacientes[x]->telefone);
            printf("Sexo: %s\n", bd_pacientes[x]->sexo);
            printf("\nPossui Alergia?: %s\n", bd_pacientes[x]->alergiaMedicamento);
            printf("Quantidade de lesoes: %d\n", bd_pacientes[x]->qtdLesoes);
            printf("Quantidade de cirurgias: %d\n", bd_pacientes[x]->qtdcirurgia);
            printf("Quantidade de crioterapias: %d\n", bd_pacientes[x]->qtdCrioterapia);
            printf("Lesoes:\n");
            //lesao_imprimeLesoes(bd_pacientes[x]->lesoes);
           
    return;
}

void paciente_LiberaPacientes(Paciente **bd_paciente, int qtdPaciente){
    
    for(int x=0; x<qtdPaciente; x++){
        free(bd_paciente[x]->nome);   
        free(bd_paciente[x]->endereco);  
        if(strcmp(bd_paciente[x]->alergiaMedicamento, "SIM")==0){            
            free(bd_paciente[x]->nomeMedicamentoAlergia);  
        }
        if(bd_paciente[x]->qtdLesoes>0){//para casos com pelo menos uma lesao
            for(int i=0; i<bd_paciente[x]->qtdLesoes; i++){

                lesao_free(bd_paciente[x]->lesoes[i]);
            }    
            free(bd_paciente[x]->lesoes);   
        }
        if(bd_paciente[x]->qtdLesoes==0){//tratando casos com nenhuma lesao cadastrada
            free(bd_paciente[x]->lesoes);
        }
                           
        free(bd_paciente[x]);
    }
    free(bd_paciente);
}


//funcoes contadores
int contaPacientes(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(bd_pacientes[i]->qtdAtendimentos > 0){
            cont++;
        }
    }
    return cont;
}
int contaLesoes(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(bd_pacientes[i]->qtdAtendimentos > 0){
            cont += bd_pacientes[i]->qtdLesoes;
        }
    }
    return cont;
}

float calculaIdadeMedia(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    float media=0;
    for(int i=0; i<qtdPacientes; i++){
        if(bd_pacientes[i]->qtdAtendimentos >= 0){
            media += bd_pacientes[i]->idade;
            cont++;
        }
    }
    media = media/cont;
    return media;
}
float calculaDesvioPadraoIdade(Paciente **bd_pacientes, int qtdPacientes, float media){
    int cont=0;
    float desvio=0;
    for(int i=0; i<qtdPacientes; i++){
        if(bd_pacientes[i]->qtdAtendimentos >= 0){
            desvio += pow((bd_pacientes[i]->idade - media),2);
            cont++;
        }
    }
    desvio = sqrt(desvio/cont);
    return desvio;
}

int contaMasc(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(strcmp(bd_pacientes[i]->sexo, "MASCULINO")==0){
            cont++;
        }
    }
    return cont;
}
int contaFem(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(strcmp(bd_pacientes[i]->sexo, "FEMININO")==0){
            cont++;
        }
    }
    return cont;
}
int contaOutros(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(strcmp(bd_pacientes[i]->sexo, "OUTROS")==0){
            cont++;
        }
    }
    return cont;
}

float calculaTamanhoMedioLesao(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    float media=0;
    for(int i=0; i<qtdPacientes; i++){
        //usando a função lesao_getTamanho para calcular o tamanho medio das lesões
        if(bd_pacientes[i]->qtdAtendimentos > 0){
            for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
                media += lesao_getTamanho(bd_pacientes[i]->lesoes[j]);
                cont++;
            }            
        }
    }
    media = media/cont;
    return media;
}

int contaCirurgia(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(bd_pacientes[i]->qtdAtendimentos > 0){
            cont += bd_pacientes[i]->qtdcirurgia;
        }
    }
    return cont;
}
int contaCrioterapia(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    for(int i=0; i<qtdPacientes; i++){
        if(bd_pacientes[i]->qtdAtendimentos > 0){
            cont += bd_pacientes[i]->qtdCrioterapia;
        }
    }
    return cont;
}

//contadores de regiao - face, abdome antebraco braco canela couro cabeludo coxa dorso mao outros orelha pe peitoral
int contaFace(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "FACE")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaABDOME(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "ABDOME")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaANTEBRACO(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "ANTEBRACO")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaBRACO(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "BRACO")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaCANELA(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "CANELA")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaCOUROCABELUDO(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "COURO CABELUDO")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaCOXA(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "COXA")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaDORSO(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "DORSO")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaMAO(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "MAO")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaOUTROS(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "OUTROS")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaORELHAS(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "ORELHAS")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaPE(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "PE")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaPEITORAL(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;    
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getRegiao(bd_pacientes[i]->lesoes[j]), "PEITORAL")==0){
                cont++;
            }
        }        
    }
    return cont;
}

//contadores de diagnostico
int contaCeratoseActi(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com CERATOSE ACTINICA
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "CERATOSE ACTINICA")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaCarcinomaBaso(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com CARCINOMA BASOCELULAR
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "CARCINOMA BASOCELULAR")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaCarcinomaEspino(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com CARCINOMA ESPINOCELULAR
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "CARCINOMA ESPINOCELULAR")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaMelanoma(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com MELANOMA
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "MELANOMA")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaDiagOutros(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com MELANOMA
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "OUTROS")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaNevo(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com NEVO
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "NEVO")==0){
                cont++;
            }
        }        
    }
    return cont;
}
int contaCeratoseSebor(Paciente **bd_pacientes, int qtdPacientes){
    int cont=0;
    //compara a string com CERATOSE SEBORREICA
    for(int i=0; i<qtdPacientes; i++){
        
        for(int j=0; j<bd_pacientes[i]->qtdLesoes; j++){
            if(strcmp(lesao_getDiagnostico(bd_pacientes[i]->lesoes[j]), "CERATOSE SEBORREICA")==0){
                cont++;
            }
        }        
    }
    return cont;
}

float calculaPct(int x, float total){
    float pct=0;
    if(x==0){//tive que fazer isso para não dar erro de divisão por zero
        return 0;
    }else{    
        pct = (x*100)/total;
        return pct;
    }
}

//funções de arquivo
void imprimirDiagnosticosOrdenados(FILE* arquivo,int contCeratoseActi, int contCarcinomaBaso, int contCarcinomaEspi, int contMelanomas, int contNevo, int contCeratoseAbo,int contDiagOutros, int contLesoes) {
    Diagnostico diagnosticos[] = {
        {"CERATOSE ACTINICA", contCeratoseActi},
        {"CARCINOMA BASOCELULAR", contCarcinomaBaso},
        {"CARCINOMA ESPINOCELULAR", contCarcinomaEspi},
        {"MELANOMA", contMelanomas},
        {"NEVO", contNevo},
        {"CERATOSE SEBORREICA", contCeratoseAbo},
        {"OUTROS",contDiagOutros}
    };
    
    //utilizei essa forma para calcular o tamanho do array, para caso aumente a quantidade de possiveis diagnosticos, a função continue funcionando
     int tamanhoDiagnosticos = sizeof(diagnosticos) / sizeof(diagnosticos[0]);/*
        Para este algoritmo de ordenação foi utilizado a técnica de bubble sort juntamente com a função strcmp
            - a função strcmp retorna 1 quando a str1 é maior lexicograficamente que a str2, ou seja, na ordem alfabetica a str1 vem primeiro
            - retorna -1 quando ela a str1 é menor que a 2a, ou seja, a str vem primeiro na ordem alfabetica
            -retorna 0 quando as strs sao exatamente iguais
    */
    int i, j;
    for (i = 0; i < tamanhoDiagnosticos - 1; i++) {
        for (j = 0; j < tamanhoDiagnosticos - i - 1; j++) {
            if (diagnosticos[j].quantidade < diagnosticos[j + 1].quantidade ||
                (diagnosticos[j].quantidade == diagnosticos[j + 1].quantidade &&
                 strcmp(diagnosticos[j].nome, diagnosticos[j + 1].nome) > 0)) {
                Diagnostico temp = diagnosticos[j];
                diagnosticos[j] = diagnosticos[j + 1];
                diagnosticos[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < tamanhoDiagnosticos; i++) {
        fprintf(arquivo,"- %s: %d (%.2f%%)\n", diagnosticos[i].nome, diagnosticos[i].quantidade, calculaPct(diagnosticos[i].quantidade, contLesoes));
    }
}

void imprimirRegioesOrdenadas(FILE* arquivo,int face,int abd, int anteb, int braco, int canela, int cabelo, int coxa, int dorso, int mao, int outros, int orelha,int pe, int peitoral,int contLesoes) {
    Regiao regiao[] = {
        {"FACE", face},
        {"ABDOME",abd},
        {"ANTEBRACO",anteb},
        {"BRACO",braco},
        {"CANELA",canela},
        {"COURO CABELUDO",cabelo},
        {"COXA",coxa},
        {"DORSO",dorso},
        {"MAO",mao},
        {"OUTROS",outros},
        {"ORELHA",orelha},
        {"PE",pe},
        {"PEITORAL",peitoral}
        
    };
    
    //utilizei essa forma para calcular o tamanho do array, para caso aumente a quantidade de possiveis diagnosticos, a função continue funcionando
     int tamanhoregiao = sizeof(regiao) / sizeof(regiao[0]);/*
        Para este algoritmo de ordenação foi utilizado a técnica de bubble sort juntamente com a função strcmp
            - a função strcmp retorna 1 quando a str1 é maior lexicograficamente que a str2, ou seja, na ordem alfabetica a str1 vem primeiro
            - retorna -1 quando ela a str1 é menor que a 2a, ou seja, a str vem primeiro na ordem alfabetica
            -retorna 0 quando as strs sao exatamente iguais
    */
    int i, j;
    for (i = 0; i < tamanhoregiao - 1; i++) {
        for (j = 0; j < tamanhoregiao - i - 1; j++) {
            if (regiao[j].quantidade < regiao[j + 1].quantidade ||
                (regiao[j].quantidade == regiao[j + 1].quantidade &&
                 strcmp(regiao[j].nome, regiao[j + 1].nome) > 0)) {
                Regiao temp = regiao[j];
                regiao[j] = regiao[j + 1];
                regiao[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < tamanhoregiao; i++) {
        fprintf(arquivo,"- %s: %d (%.2f%%)\n", regiao[i].nome, regiao[i].quantidade, calculaPct(regiao[i].quantidade, contLesoes));
    }
}


void paciente_geraRelatorio(Paciente **bd_pacientes, int qtdPacientes, FILE *arquivo){
    //contadores    
    int contPacientes=0;
    int idademediaT=0;
    float idademedia=0, desvioPadraoIdade=0;
    int contFeminino=0, contMasculino=0, contOutros=0;
    float pctFemini=0, pctMasculino=0,pctOutros=0;
    float tamanhoMedioLesao=0, desvioPadraoLesao=0;
    int contLesoes=0, contCirurgia=0, contCrioterapia=0;       
    int contCeratoseActi=0, contCarcinomaBaso=0, contCarcinomaEspi=0, contMelanomas=0, contNevo=0,contCeratoseAbo=0;
    
    contPacientes = contaPacientes(bd_pacientes, qtdPacientes);
    idademedia = calculaIdadeMedia(bd_pacientes, qtdPacientes);
    idademediaT = idademedia;
    if(contPacientes==0)idademediaT = 0;    
    desvioPadraoIdade = calculaDesvioPadraoIdade(bd_pacientes, qtdPacientes, idademediaT);
    if(contPacientes==0)desvioPadraoIdade = 0;

    contFeminino = contaFem(bd_pacientes, qtdPacientes);
    pctFemini = calculaPct(contFeminino, qtdPacientes);
    contMasculino = contaMasc(bd_pacientes, qtdPacientes);
    pctMasculino = calculaPct(contMasculino, qtdPacientes);
    contOutros = contaOutros(bd_pacientes, qtdPacientes);
    pctOutros = calculaPct(contOutros, qtdPacientes);
    //calcular o total de lesoes
    for(int i=0;i<qtdPacientes;i++) contLesoes+=(bd_pacientes[i]->qtdLesoes);
    
    for(int i=0;i<qtdPacientes;i++){
        if(bd_pacientes[i]->qtdLesoes>0){
            tamanhoMedioLesao+=lesao_somaTamanho(bd_pacientes[i]->lesoes, bd_pacientes[i]->qtdLesoes);
        }
    }
    tamanhoMedioLesao = tamanhoMedioLesao/contLesoes;
    for(int i=0;i<qtdPacientes;i++){
        if(bd_pacientes[i]->qtdLesoes>0){            
            desvioPadraoLesao=lesao_calculaDesvioPadrao(bd_pacientes[i]->lesoes, bd_pacientes[i]->qtdLesoes, tamanhoMedioLesao);
        }
    }
    //desvioPadraoLesao = sqrt(desvioPadraoLesao/contLesoes);


    contCirurgia = contaCirurgia(bd_pacientes, qtdPacientes);
    contCrioterapia = contaCrioterapia(bd_pacientes, qtdPacientes);
    //contar regiao
    int contFace=contaFace(bd_pacientes,qtdPacientes);
    int contABDOME=contaABDOME(bd_pacientes,qtdPacientes);
    int contANTEBRACO=contaANTEBRACO(bd_pacientes,qtdPacientes);
    int contBRACO=contaBRACO(bd_pacientes,qtdPacientes);
    int contCANELA=contaCANELA(bd_pacientes,qtdPacientes);
    int contCOUROCABELUDO=contaCOUROCABELUDO(bd_pacientes,qtdPacientes);
    int contCOXA=contaCOXA(bd_pacientes,qtdPacientes);
    int contDORSO=contaDORSO(bd_pacientes,qtdPacientes);
    int contMAO=contaMAO(bd_pacientes,qtdPacientes);
    int contOUTROS=contaOUTROS(bd_pacientes,qtdPacientes);
    int contORELHA=contaORELHAS(bd_pacientes,qtdPacientes);
    int contPE=contaPE(bd_pacientes,qtdPacientes);
    int contPEITORAL=contaPEITORAL(bd_pacientes,qtdPacientes);

    //conta diagnosticos
    contCeratoseActi = contaCeratoseActi(bd_pacientes, qtdPacientes);
    contCarcinomaBaso = contaCarcinomaBaso(bd_pacientes, qtdPacientes);
    contCarcinomaEspi = contaCarcinomaEspino(bd_pacientes, qtdPacientes);
    contMelanomas = contaMelanoma(bd_pacientes, qtdPacientes);
    contNevo = contaNevo(bd_pacientes, qtdPacientes);
    contCeratoseAbo = contaCeratoseSebor(bd_pacientes, qtdPacientes);
    int cont_DiagOutros=contaDiagOutros(bd_pacientes,qtdPacientes);
    float pctCirurgia=0, pctCrioterapia=0;

    if(contLesoes>0){
    pctCirurgia = calculaPct(contCirurgia, contLesoes);
    pctCrioterapia = calculaPct(contCrioterapia, contLesoes);
    }else{
        pctCirurgia = 0;
        pctCrioterapia = 0;
    }

    if(contLesoes==0){
        tamanhoMedioLesao = 0;
        desvioPadraoLesao = 0;
    }
    //IMPRESSOES
    fprintf(arquivo,"NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", contPacientes);
    fprintf(arquivo,"IDADE MEDIA: %d +- %d ANOS\n", idademediaT,(int) desvioPadraoIdade);
    fprintf(arquivo,"DISTRIBUICAO POR GENERO:\n");
    fprintf(arquivo,"- FEMININO: %.2f%%\n", pctFemini);
    fprintf(arquivo,"- MASCULINO: %.2f%%\n", pctMasculino);
    fprintf(arquivo,"- OUTROS: %.2f%%\n", pctOutros);
    fprintf(arquivo,"TAMANHO MEDIO DAS LESOES: %d +- %d MM\n", (int) tamanhoMedioLesao, (int) desvioPadraoLesao);
    fprintf(arquivo,"NÚMERO TOTAL DE LESOES: %d\n", contLesoes);
    fprintf(arquivo,"NÚMERO TOTAL DE CIRURGIAS: %d (%.2f%%)\n", contCirurgia, pctCirurgia);
    fprintf(arquivo,"NÚMERO TOTAL DE CRIOTERAPIA: %d (%.2f%%)\n", contCrioterapia, pctCrioterapia);
    fprintf(arquivo,"DISTRIBUICAO POR DIAGNOSTICO:\n");
    
    //imprimir contadores lesoes
    imprimirDiagnosticosOrdenados(arquivo,contCeratoseActi, contCarcinomaBaso, contCarcinomaEspi, contMelanomas, contNevo, contCeratoseAbo,cont_DiagOutros, contLesoes);
    fprintf(arquivo,"DISTRIBUICAO POR REGIAO DO CORPO:\n");
    imprimirRegioesOrdenadas(arquivo,contFace,contABDOME,contANTEBRACO,contBRACO,contCANELA,contCOUROCABELUDO,contCOXA,contDORSO,contMAO,contOUTROS,contORELHA,contPE,contPEITORAL,contLesoes);
}

void paciente_geraResumo(Paciente **bd_pacientes, int qtdPacientes, FILE *arquivo){
    int contLesoes=0,contCirurgias=0,contCriot=0;

    for(int i=0;i<qtdPacientes;i++) contLesoes+=(bd_pacientes[i]->qtdLesoes);
    contCirurgias = contaCirurgia(bd_pacientes, qtdPacientes);
    contCriot = contaCrioterapia(bd_pacientes, qtdPacientes);
    
    fprintf(arquivo,"PACIENTES: %d\n",qtdPacientes);
    fprintf(arquivo,"LESOES: %d\n",contLesoes);
    fprintf(arquivo,"CIRURGIAS: %d\n",contCirurgias);
    fprintf(arquivo,"CRIOTERAPIAS: %d",contCriot);
}


void paciente_imprimeIDlesoes(Paciente **bd_pacientes, char cartaoSus[20], int qtdPacientes, FILE *arquivo){
    //essa função imprime os tipos das lesões do paciente
    int x=0;
    char saida[100];
    x = buscaIndicePaciente(bd_pacientes, cartaoSus);
    
    for(int i=0; i<bd_pacientes[x]->qtdLesoes; i++){
        strcpy(saida, lesao_getIDlesao(bd_pacientes[x]->lesoes,i));
        fprintf(arquivo, "%s\n", saida );
    }
}

void paciente_geraArquivoBusca(Paciente **bd_pacientes, char cartaoSus[20], int qtdPacientes, FILE *arquivo){
    
    int i=buscaIndicePaciente(bd_pacientes, cartaoSus);

    //transforma as letras para caixa alta

    transformaMaiuscula(bd_pacientes[i]->nome);
    transformaMaiuscula(bd_pacientes[i]->sexo);


    //verifica se tem alergia a medicamento
    if(strcmp(bd_pacientes[i]->alergiaMedicamento, "SIM") == 0){
        transformaMaiuscula(bd_pacientes[i]->nomeMedicamentoAlergia);
    }    
    transformaMaiuscula(bd_pacientes[i]->endereco);
    fprintf(arquivo, "NOME: %s\n", bd_pacientes[i]->nome);
    fprintf(arquivo, "DATA DE NASCIMENTO: %s (%d ANOS)\n", bd_pacientes[i]->dataNascimento, bd_pacientes[i]->idade);
    fprintf(arquivo, "GENERO: %s\n", bd_pacientes[i]->sexo);
    fprintf(arquivo, "TELEFONE: %s\n", bd_pacientes[i]->telefone);
    fprintf(arquivo,"ENDERECO: %s\n",bd_pacientes[i]->endereco);
    //verificar se o atendimento é maior que 0
    if(bd_pacientes[i]->qtdAtendimentos > 0){
        fprintf(arquivo, "DIABETES: %s\n", bd_pacientes[i]->diabetes);
        fprintf(arquivo, "FUMANTE: %s\n", bd_pacientes[i]->fumante);
        fprintf(arquivo, "ALERGIA A MEDICAMENTO: %s", bd_pacientes[i]->alergiaMedicamento);
            if(strcmp(bd_pacientes[i]->alergiaMedicamento, "SIM")==0){
                fprintf(arquivo, " - %s", bd_pacientes[i]->nomeMedicamentoAlergia);
            }
        fprintf(arquivo,"\n");
        fprintf(arquivo, "HISTORICO DE CANCER: %s\n", bd_pacientes[i]->historicoCancer);
        fprintf(arquivo, "TIPO DE PELE: %s\n", bd_pacientes[i]->tipoPele);
        fprintf(arquivo, "\nLESOES:\n");
        fprintf(arquivo, "TOTAL: %d\n", bd_pacientes[i]->qtdLesoes);
        fprintf(arquivo, "ENVIADA PARA CIRURGIA: %d\n", bd_pacientes[i]->qtdcirurgia);
        fprintf(arquivo, "ENVIADA PARA CRIOTERAPIA: %d\n", bd_pacientes[i]->qtdCrioterapia);
        fprintf(arquivo, "\nDESCRICAO DAS LESOES:\n");
            if(bd_pacientes[i]->qtdLesoes > 0){
                lesao_imprimeLesoes(bd_pacientes[i]->lesoes, bd_pacientes[i]->qtdLesoes ,arquivo);
            }
    }    
}