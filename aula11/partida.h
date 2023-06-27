#ifndef _PARTIDA_H_
#define _PARTIDA_H_


typedef struct partida Partida;

Partida* partida_construir();
void partida_ler(Partida *p);
int partida_jogou(Partida *p, int aux);
int partida_vencedor(Partida *p);
void partida_destruir(Partida *p);

#endif