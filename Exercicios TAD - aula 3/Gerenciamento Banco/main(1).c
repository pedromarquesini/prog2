/*
  Programa para gerenciamento de banco
  Autor: Pedro Marquesini
  Data de Inicio: 29/03/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Conta {
  int id;
  char nome[50];
  char cpf[15];
  char dtNascimento[10];
  char adress[100];
  char cel[15];
  char email[50];
  float saldo;
}tConta;

tConta CadastrarCliente(int i){
  tConta conta;
  
  printf("------ Iniciando Cadastro ------");
  conta.id=i;
  printf("\nNome: ");
  fgets(conta.nome,50,stdin);
  printf("\nCpf: ");
  fgets(conta.cpf, 15, stdin);
  printf("\nData de Nascimento: ");
  fgets(conta.dtNascimento, 10, stdin);
  printf("\nEndereço: ");
  fgets(conta.adress, 100, stdin);
  printf("\nCelular: ");
  fgets(conta.cel, 15, stdin);
  printf("\nEmail: ");
  fgets(conta.email, 50, stdin);
  conta.saldo=0.0;  

  return conta;
}
//função para zerar todos os valores do cliente
tConta RemoverCliente(tConta conta){
  
  conta.id=9999;
  /* essa função memset tem como objetivo zerar a string
     e recebe como argumento a string a ser zerada, o valor padrão
     e o tamanho em bytes do bloco de memória, no caso utilizando
     o sizeof para obter o tamanho da string
  */    
  memset(conta.nome,0,sizeof(conta.nome));
  memset(conta.cpf,0,sizeof(conta.cpf));
  memset(conta.dtNascimento,0,sizeof(conta.dtNascimento));
  memset(conta.adress,0,sizeof(conta.adress));
  memset(conta.cel,0,sizeof(conta.cel));
  memset(conta.email,0,sizeof(conta.email));  

  conta.saldo=0.0;
  
  return conta;
}

void ImprimirMenu(){
  printf("\nQual operação deseja realizar?\n 1-Cadastro de Cliente\n2-Depósito\n3-Saque\n4-Excluir Cliente\n5-Sair");
   
}

int ProcuraConta(tConta contas[100],int n){
  int aux=-1;
    for(int j=0;j<100;j++){//vai verificar durante todo o array para ver qual a posição daquele id e passar para variavel auxiliar a posição
      if(contas[j].id==n){
        aux=j;
        break;
      }
    }
  
  return aux;
}

int main(void) {
  tConta clientes[100];
  int i=0,resp=1,n;

  while(resp<5){
    ImprimirMenu();
    scanf("%d",&resp);
      if(resp==1){
        //Cadastro de Cliente
        clientes[i]=CadastrarCliente(i);
        i++;
        
      }else if(resp==2){
        //Deposito
        static float valor=0.0; //variavel interna
        printf("\nQual o id da conta que vc deseja depositar?:");
        scanf("%d",&n);
        n=ProcuraConta(clientes,n);
        printf("\nQual o valor do Depósito?");
        scanf("%f",&valor);
        clientes[n].saldo+=valor;
        
      }else if (resp==3){
        //Saque
        static float valor=0.0;
        printf("\nQual o id da conta que vc deseja depositar?:");
        scanf("%d",&n);
        n=ProcuraConta(clientes,n);
        printf("\nQual o valor do Saque?");
        scanf("%f",&valor);
          if(clientes[n].saldo<valor){//Função de verificação do valor do saque
            printf("\nErro ao realizar o saque, a conta não possui saldo suficiente!");
          }else clientes[n].saldo=-valor;
        
      }else if(resp==4){
        //Remover Cliente
        printf("\nQual o id da conta que vc deseja depositar?:");
        scanf("%d",&n);
        n=ProcuraConta(clientes,n);
        clientes[n]=RemoverCliente(clientes[n]);
        
      }else{
        printf("\n-----Finalizando o Programa-----");
        break;
      }
    
  }
  
  return 0;
}