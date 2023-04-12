#ifndef _BIBLIOTECA_H
#define _BIBLIOTECA_H

#include "livro.h"

#define MAX_LIVROS 1000

typedef struct Biblioteca{
  tLivro livros[MAX_LIVROS];
  int qtdLivros;
}tBiblioteca;

int ImprimirMenu();
tBiblioteca AumentarTamanho(tBiblioteca biblioteca);
tBiblioteca InicializarBiblioteca(tBiblioteca biblioteca);
tBiblioteca ImprimirBiblioteca();

#endif