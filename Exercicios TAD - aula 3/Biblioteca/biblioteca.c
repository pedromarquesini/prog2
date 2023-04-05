#include <stdio.h>
#include "biblioteca.h"

int ImprimirMenu(){
  int opcao=0;
  printf("\n------ BIBLIOTECA ------\n");
  printf("Escolha uma opcao:\n");
  printf("1 - Cadastrar livro\n");
  printf("2 - Remover livros\n");
  printf("3 - Buscar e imprimir livro\n");
  printf("4 - Emprestar livro\n");
  printf("5 - Devolver livro\n");  
  printf("6- Imprimir todos os Livros\n");
  printf("0 - Sair\n");
  scanf("%d",&opcao);

  return opcao;
}
