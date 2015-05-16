#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "mapa.h"


tJugador crearJugador(void){
    tJugador jugador=NULL;
    jugador=crearDir();
    dirCero(jugador);
    return jugador;
}


direc verJugador(tJugador jugador){
    return jugador;
}


bool moverJugador(char moviento,tJugador jugador){
    switch (moviento){
        case ARR:
            arrDir(jugador);
            break;
        case ABA:
            abaDir(jugador);
            break;
        case IZQ:
            izqDir(jugador);
            break;
        case DER:
            derDir(jugador);
            break;
    }
    return(dirValida(jugador));
}

tJugador destruirJugador(tJugador jugador){
    free(jugador);
    jugador=NULL;
    return jugador;
}