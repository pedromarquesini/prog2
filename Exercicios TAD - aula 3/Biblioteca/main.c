#include <stdio.h>
#include "biblioteca.h"
#include "livro.h"

int main(void) {
  tLivro biblioteca[1000];
  int id=1, opcao=0,pos=0;

  opcao=ImprimirMenu();

  while ((opcao>0) && (opcao<7)){
    switch(opcao){
      case 1:
        //CRIAR LIVRO
        biblioteca[pos]=CriarLivro(id);
        id++;
        pos++;
      break;
      case 2:
        //EXIBIR LIVROS
        
      break;
      case 3:
        //BUSCAR LIVRO
        printf("Como deseja buscar?\n1-Id\n2-Titulo\n");
        int temp;
        scanf("%d",&temp);
          if(temp==1){
            //busca pelo id
            BuscarImprimirId(biblioteca);
          }else if(temp==2){
            //busca pelo titulo
            BuscarImprimirTitulo(biblioteca);
          }else{
            printf("Opção Inválida, operação cancelada! ");
          } break;
      break;
      case 4:
        //EMPRESTAR LIVRO
        
      break;
      case 5:
        //DEVOLVER LIVRO
        
      break;
      case 6:
        //IMPRIMIR TODOS OS LIVROS

      break;      
      default:
        //SAIR
      break;
    }
    
  }  
  
  return 0;
}