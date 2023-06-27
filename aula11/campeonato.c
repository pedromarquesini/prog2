#include "campeonato.h"
#include "partida.h"
#include "time.h"

struct campeonato{
    Time *times;
    Partida *partidas;
    
    int n_times;
    int n_times_alocados;

    int n_partidas;
    int n_partidas_alocadas;
    
    
};

Campeonato *campeonato_construir(){

}
void campeonato_ler(Campeonato *c){

}
void campeonato_destruir(Campeonato* c){
    free(c);
}

void campeonato_mostrar_relatorio(Campeonato *c){
    int i=0;
    
}
