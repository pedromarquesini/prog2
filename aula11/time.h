#ifndef _TIME_H_
#define _TIME_H_

typedef struct time Time;

Time *time_construir();
void time_ler(Time *t);
void time_mostrar(Time *t);
void time_destruir(Time *t);

#endif