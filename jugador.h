#ifndef _JUGADOR_H
#define _JUGADOR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "mapa.h"


typedef direc tJugador;


tJugador crearJugador(void);
/*
 * crea un jugador con una direccion inicial
 * destruirlo cuando termine la partida
 */

direc verJugador(tJugador jugador);
/*
 * devuelve la direccion en el mapa de jugador
 */

bool moverJugador(char moviento, tJugador jugador);
/*
 * cambia la direccion del jugador de acuerdo a movimiento
 * retorna un bool de acuerdo si la nueva direccion es valida o no
 */

tJugador destruirJugador(tJugador jugador);
/*
 * destruye el jugador y asigna el puntero a NULL
 */

#endif
