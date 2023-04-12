#include <stdio.h>
#include "livro.h"
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

tBiblioteca ImprimirBiblioteca(tBiblioteca biblioteca){
  //imprimir a quantidade de livros com id maiores que 0
  int i;
  for(i=0;i<MAX_LIVROS;i++){
    if(biblioteca.livros[i].id>0){
      //imprimir livro
      ImprimirLivro(biblioteca.livros[i]);
    }
  } 
  
}

tBiblioteca InicializarBiblioteca(tBiblioteca biblioteca){
  biblioteca.tamanho=0;
  return biblioteca;
}

tBiblioteca AumentarTamanho(tBiblioteca biblioteca){
  biblioteca.tamanho++;
  return biblioteca;
}
