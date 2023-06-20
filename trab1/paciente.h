#ifndef _PACIENTE_H_
#define _PACIENTE_H_

#include <stdio.h>
#include <string.h>
#include "lesoes.h"
#include <stdlib.h>
#include <math.h>

typedef struct paciente Paciente;

//funções do sistema
void ImprimeMenu();
void limparBuffer();

//funções externas
Paciente** paciente_InicializaSistema();
int paciente_verificaCadastro(Paciente** bd_pacientes, char cartaoSus[20],int qtdPacientes);
Paciente** paciente_realizaConsulta(char* caminho_pasta, Paciente **bd_pacientes, int qtdPacientes, char cartaoSus[20],int qtdAtendimentos);
Paciente** paciente_preCadastro(Paciente **bd_pacientes, int qtdPacientes);
void paciente_LiberaPacientes(Paciente **bd_paciente, int qtdPaciente);
void paciente_imprimePaciente(Paciente **bd_pacientes,char cartaoSus[20], int qtdPacientes);
void paciente_geraArquivoBusca(Paciente **bd_pacientes, char cartaoSus[20], int qtdPacientes, FILE *arquivo);
void paciente_imprimeIDlesoes(Paciente **bd_pacientes, char cartaoSus[20], int qtdPacientes, FILE *arquivo);
void paciente_geraRelatorio(Paciente **bd_pacientes, int qtdPacientes, FILE *arquivo);
void paciente_geraResumo(Paciente **bd_pacientes, int qtdPacientes, FILE *arquivo);

#endif