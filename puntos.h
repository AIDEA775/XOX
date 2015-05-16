#ifndef _PUNTOS_H
#define _PUNTOS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"


typedef struct tipoPuntos *tPuntos;


tPuntos crearPuntos(void);
/*
 * crea una estructura con puntos y datos del limpiador
 * destruirlo cuando termine la partida
 */

tPuntos srPuntos(tPuntos puntos, elemento dibujo);
/*
 * suma o resta puntos dependiendo del elemento 'dbujo'
 * ademas actualiza el 'puntoMax'
 */

int verPuntoMax(tPuntos puntos);
/*
 * devuelve el punto maximo que se ha alcanzado
 */

int verPuntos(tPuntos puntos);
/*
 * devuelve el puntaje actual
 */

bool esLimpiador (tPuntos puntos);
/*
 * devuelve si esta activado o no el limpiador
 */

tPuntos destruirPuntos(tPuntos puntos);
/*
 * destruye los puntos y asigna este a NULL
 */

#endif
