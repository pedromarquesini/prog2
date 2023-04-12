#ifndef _LIVRO_H
#define _LIVRO_H

typedef struct {
    char titulo[50];
    char autor[30];
    int ano_publicacao;
    int disponibilidade; // 0 - emprestado; 1 - disponível
    int id;
}tLivro;

tLivro CriarLivro(int id);
tLivro RemoverLivro(tBiblioteca b);
void BuscarImprimirId(tLivro b[1000]);
void BuscarImprimirTitulo(tLivro b[1000]);
tLivro ImprimirLivro(tLivro livro)
tLivro EmprestarLivro(tLivro livro);
tLivro DevolverLivro(tLivro livro);
int BuscaPosicaoID(int id, tBiblioteca b);
int BuscaPosicaoTitulo(char titulo[50], tBiblioteca b);



#endif