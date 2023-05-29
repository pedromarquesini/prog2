#include "paciente.h"
#include "lesoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    Paciente **bd_pacientes = paciente_InicializaSistema();
    char opcao;
    int qtdPacientes=0;
    char temp_cartaoSus[20];

    ImprimeMenu();
    while (1){
        scanf("%c", &opcao);
        if((opcao == 'F')||(opcao=='f')){
            printf("Finalizando o programa...\n");
            break;
        }
        else if((opcao == 'P')||(opcao=='p')){    
            paciente_preCadastro(bd_pacientes, qtdPacientes);            
            qtdPacientes++;
        }
        else if((opcao == 'A')||(opcao=='a')){   
            scanf("%s", temp_cartaoSus);
            paciente_realizaConsulta(bd_pacientes, qtdPacientes, temp_cartaoSus);
            
        }
        else if((opcao == 'B')||(opcao=='b')){
            scanf("%s", temp_cartaoSus);
            if(paciente_verificaCadastro(bd_pacientes, temp_cartaoSus, qtdPacientes)){
                //paciente_geraArquivoBusca(bd_pacientes, temp_cartaoSus);
                printf("Paciente encontrado e gerado um arquivo de resultado da busca\n");
            }
            else{
                printf("Paciente nao cadastrado!\n");
            }

            //buscar um paciente
                //gerar arquivo "busca_cartaosus.txt"
                //imprimir dados do paciente
                //imprimir dados clinicos
                //imprimir dados das lesoes
        }
        else if((opcao == 'R')||(opcao=='r')){
            //gerar relatorio
        }
        else{
            printf("Opcao invalida!\n");
        }
        ImprimeMenu();
        scanf("%c", &opcao);
    }
    paciente_LiberaPacientes(bd_pacientes, qtdPacientes);
    

    return 0;
}