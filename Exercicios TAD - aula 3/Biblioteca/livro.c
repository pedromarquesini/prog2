#include"livro.h"
#include"biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

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
  livro.disponibilidade=1;
  
  
  return livro;  
}
tLivro RemoverLivro();
void BuscarImprimirId(tLivro b[1000]){
  //ler o numero do ID
  //buscar o id
  //imprimir livro
}
void BuscarImprimirTitulo(tLivro b[1000]){
  //ler o titulo
  //rodar o array comparando o titulo lido com o do livro
  //imprimir livro
}
tLivro ImprimirLivro(tLivro livro){ 
  printf("\nTitulo: %s",livro.titulo);
  printf("\nAutor: %s",livro.autor);
  printf("\nAno de publicação: %d",livro.ano_publicacao);
  printf("\nDisponibilidade: %d",livro.disponibilidade);
  printf("\nId: %d",livro.id);
  return livro;

}
tLivro EmprestarLivro(tLivro livro){
  if(livro.disponibilidade==1){
    livro.disponibilidade=0;
    printf("Livro emprestado com sucesso!");
  }else{
    printf("Livro indisponível para empréstimo!");
  }
  return livro;
}
tLivro DevolverLivro(){

}






