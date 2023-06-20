#include "paciente.h"
#include "lesoes.h"

void criaPastas(char *nome_pasta){
    //criar pastas de saida
    char comando[100];
    sprintf(comando, "mkdir ./%s/buscas", nome_pasta);
    system(comando);
    sprintf(comando, "mkdir ./%s/logs", nome_pasta);
    system(comando);
    sprintf(comando, "mkdir ./%s/relatorio", nome_pasta);
    system(comando);
}

int main(int argc, char* argv[]){

    Paciente **bd_pacientes = paciente_InicializaSistema();
    char opcao;
    int qtdPacientes=0, s_qtdAtendimentos=0;
    char temp_cartaoSus[20];
    char nome_arquivo[200];
    char caminho_pasta[100];    
    
    if(argc<2){
        printf("Erro! Necessario informar o nome da pasta de saida!\n");
        return 0;
    }
    strcpy(caminho_pasta, argv[1]);
    //considerando esse codigo, a entrada deve ser ./trab1 nome da pasta de saida < arquivo de entrada

    //printf("os arquivos serão criados no diretorio %s\n", caminho_pasta);

    criaPastas(caminho_pasta);
    

    

    //criar pastas de saida
    // system("mkdir ./saida");
    // system("mkdir ./saida/buscas");
    // system("mkdir ./saida/logs");
    // system("mkdir ./saida/relatorio");
    
    
    while (1){
        ImprimeMenu();        
        scanf("%c", &opcao);
        limparBuffer();
        if((opcao == 'F')||(opcao=='f')){
            //printf("Finalizando o programa...\n");

            sprintf(nome_arquivo, "%s/resumo",caminho_pasta);

                FILE *arquivo = fopen(nome_arquivo, "w");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo de relatorio.\n");
                    return 1; // Encerrar o programa
                }

            paciente_geraResumo(bd_pacientes,qtdPacientes,arquivo);
            fclose(arquivo);

            break;
        }
        else if((opcao == 'P')||(opcao=='p')){    
            bd_pacientes=paciente_preCadastro(bd_pacientes, qtdPacientes);            
            qtdPacientes++;
        }
        else if((opcao == 'A')||(opcao=='a')){   
            scanf("%[^\n]", temp_cartaoSus);
            limparBuffer();

            //verifica se o cartao do sus é valido para incrementar a quantidade de atendimentos
            if(paciente_verificaCadastro(bd_pacientes, temp_cartaoSus, qtdPacientes)){
                s_qtdAtendimentos++;               
                bd_pacientes=paciente_realizaConsulta(argv[1],bd_pacientes, qtdPacientes, temp_cartaoSus, s_qtdAtendimentos);
           
            }else{
                printf("Paciente nao cadastrado!\n");
            }            
        }
        else if((opcao == 'B')||(opcao=='b')){
            scanf("%[^\n]", temp_cartaoSus);
            limparBuffer();
            if(paciente_verificaCadastro(bd_pacientes, temp_cartaoSus, qtdPacientes)){
                //paciente_geraArquivoBusca(bd_pacientes, temp_cartaoSus);                
                printf("Paciente encontrado e foi gerado um arquivo de resultado da busca\n");
                sprintf(nome_arquivo, "%s/buscas/busca_%s.txt",caminho_pasta, temp_cartaoSus);

                FILE *arquivo = fopen(nome_arquivo, "w");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo de busca.\n");
                    return 1; // Encerrar o programa
                }
                //imprimir dados do paciente
                paciente_geraArquivoBusca(bd_pacientes, temp_cartaoSus, qtdPacientes, arquivo);
                fclose(arquivo);                
            }
            else{

                printf("Paciente nao cadastrado!\n");
            }
            
        }
        else if((opcao == 'R')||(opcao=='r')){
            //gerar relatorio
            sprintf(nome_arquivo, "%s/relatorio/relatorio_final.txt",caminho_pasta);

                FILE *arquivo = fopen(nome_arquivo, "w");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo de relatorio.\n");
                    return 1; // Encerrar o programa
                }
            printf("Relatório final gerado!\n");
            paciente_geraRelatorio(bd_pacientes, qtdPacientes, arquivo);
            fclose(arquivo);
        }
        else{
            printf("Opcao invalida!\n");
        }
        
    }   
    paciente_LiberaPacientes(bd_pacientes, qtdPacientes);
    
    
    return 0;
}