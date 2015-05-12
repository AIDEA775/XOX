#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "mapa.h"


tJugador crearJugador(void){
    tJugador jugador=NULL;
    jugador=crearDir();
    jugador=dirCero(jugador);
    return jugador;
}


direc verJugador(tJugador jugador){
    return jugador;
}


bool moverJugador(char moviento,tJugador jugador){
    switch (moviento){
        case ARR:
            jugador=arrDir(jugador);
            break;
        case ABA:
            jugador=abaDir(jugador);
            break;
        case IZQ:
            jugador=izqDir(jugador);
            break;
        case DER:
            jugador=derDir(jugador);
            break;
    }
    return(dirValida(jugador));
}

tJugador destruirJugador(tJugador jugador){
    free(jugador);
    jugador=NULL;
    return jugador;
}