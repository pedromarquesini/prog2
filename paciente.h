#ifndef _PACIENTE_H_
#define _PACIENTE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct paciente Paciente;

//funções do sistema
void ImprimeMenu();

//funções externas
Paciente** paciente_InicializaSistema();
void paciente_geraArquivoBusca(Paciente **bd_pacientes, char cartaoSus[20]);
int paciente_verificaCadastro(Paciente** bd_pacientes, char cartaoSus[20],int qtdPacientes);
void paciente_realizaConsulta(Paciente **bd_pacientes, int qtdPacientes, char cartaoSus[20]);
void paciente_preCadastro(Paciente **bd_pacientes, int qtdPacientes);
void paciente_LiberaPacientes(Paciente **bd_paciente, int qtdPaciente);


#endif