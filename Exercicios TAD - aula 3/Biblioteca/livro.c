#include"livro.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tLivro CriarLivro(int id){
  tLivro livro;
  
  livro.id=id;
  printf("\nTitulo do Livro: ");
  fflush(stdin);//limpa buffer
  scanf("%s",livro.titulo);
  printf("\nAutor:");
  fflush(stdin);
  scanf("%s",livro.autor);
  printf("\nAno de publicação: ");
  fflush(stdin);
  scanf("%d",&livro.ano_publicacao);
  livro.disponibilidade=1;//1=disponivel 0=emprestado
  
  return livro;  
}

int BuscaPosicaoID(int id, tBiblioteca b){
  int i,pos;
  for(i=0;i<b.qtd_livros;i++){
    if(b.livros[i].id==id){
      return i;//retorna a posicao do livro no array
    }
  }
}

int BuscaPosicaoTitulo(tBiblioteca b,char titulo[50]){
  int i,pos;
  for(i=0;i<b.qtd_livros;i++){
    if(strcmp(b.livros[i].titulo,titulo)==0){
      return i;//retorna a posicao do livro no array
    }
  }
}

tLivro RemoverLivro(tBiblioteca b){
  int i,id,opcao;
  char titulo[50];
  //perguntar se é por titulo ou por id
  printf("\nDeseja remover por titulo ou por id?\n 1-Titulo\n 2-ID: ");
  scanf("%d",&opcao);
  if(opcao==1){
    printf("Qual o titulo do livro que deseja remover? ");
    scanf("%s",&titulo);
  }else{
    printf("Qual o id do livro que deseja remover? ");
    scanf("%d",&id);
  }

  //remover o livro
  for(i=0;i<b.qtd_livros;i++){
    if(b.livros[i].id==id || strcmp(b.livros[i].titulo,titulo)==0){//strcmp compara duas strings e retorna 0 se forem iguais
      b.livros[i].id=0;
      b.livros[i].titulo[0]='\0';
      b.livros[i].autor[0]='\0';
      b.livros[i].ano_publicacao=0;
      b.livros[i].disponibilidade=0;
      b.qtd_livros--;
      break;
    }
  }
  for(i=0;i<b.qtd_livros;i++){
    if(b.livros[i].id==0){
      b.livros[i]=b.livros[i+1];
    }
  }
  return b.livros[1000];
}
void BuscarImprimirId(tLivro b[1000]){
  int i;
  //ler o numero do ID
  printf("Qual o id do livro que deseja buscar? ");
  scanf("%d",&id);
  //buscar o id

  for(i=0;i<1000;i++){
    if(b[i].id==id){
      //imprimir livro
      printf("\nID: %d",b[i].id);
      printf("\nTitulo: %s",b[i].titulo);
      printf("\nAutor: %s",b[i].autor);
      printf("\nAno de publicação: %d",b[i].ano_publicacao);
      printf("\nDisponibilidade: %d",b[i].disponibilidade);
    }
  } 
  
}
void BuscarImprimirTitulo(tLivro b[1000]){
  //ler o titulo
  char titulo[50];
  printf("Qual o titulo do livro que deseja buscar? ");
  scanf("%s",titulo);
  fflush(stdin);//limpar buffer

  //rodar o array comparando o titulo lido com o do livro
  int i;
  for(i=0;i<1000;i++){
    if(strcmp(b[i].titulo,titulo)==0){//essa funcao strcmp compara duas strings
      //imprimir livro
      printf("\nID: %d",b[i].id);
      printf("\nTitulo: %s",b[i].titulo);
      printf("\nAutor: %s",b[i].autor);
      printf("\nAno de publicação: %d",b[i].ano_publicacao);
      printf("\nDisponibilidade: %d",b[i].disponibilidade);
    }
  }
  //imprimir livro
}
tLivro ImprimirLivro(tLivro livro){
  printf("\nID: %d",livro.id);
  printf("\nTitulo: %s",livro.titulo);
  printf("\nAutor: %s",livro.autor);
  printf("\nAno de publicação: %d",livro.ano_publicacao);
  printf("\nDisponibilidade: %d",livro.disponibilidade);
  return livro;
}
tLivro EmprestarLivro(tLivro livro){
  if(livro.disponibilidade==1){
    livro.disponibilidade=0;
    printf("\nLivro emprestado com sucesso!");
  }else{  
    printf("\nLivro indisponível!");
  }
  
  return livro;
}
tLivro DevolverLivro(tLivro livro){
  if(livro.disponibilidade==0){
    livro.disponibilidade=1;
    printf("\nLivro devolvido com sucesso!");
  }else{  
    printf("\nLivro já está disponível");
  }
  
  return livro;
}

