#ifndef _JUGADOR_H
#define _JUGADOR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

#define ARR 65    /*Arriba*/
#define ABA 66    /*Abajo*/
#define DER 67    /*Derecha*/
#define IZQ 68  /*Izquierda*/


typedef direc tJugador;


direc verJugador(tJugador jugador);

bool moverJugador(char moviento, tJugador jugador);

tJugador crearJugador(void);

tJugador destruirJugador(tJugador jugador);

#endif
