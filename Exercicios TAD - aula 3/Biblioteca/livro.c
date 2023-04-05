#include"livro.h"
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
tLivro ImprimirLivro();
tLivro EmprestarLivro();
tLivro DevolverLivro();






