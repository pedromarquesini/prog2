#ifndef _LIVRO_H
#define _LIVRO_H

typedef struct {
    char titulo[50];
    char autor[30];
    int ano_publicacao;
    int disponibilidade; // 0 - emprestado; 1 - disponível
    int id;
}tLivro;

tLivro CriarLivro();
tLivro RemoverLivro();
void BuscarImprimirId();
void BuscarImprimirTitulo();
tLivro ImprimirLivro();
tLivro EmprestarLivro();
tLivro DevolverLivro();


#endif