#ifndef _PUNTOS_H
#define _PUNTOS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"


typedef struct tipoPuntos *tPuntos;


tPuntos crearPuntos(void);

tPuntos srPuntos(tPuntos puntos, elemento dibujo);

int verPuntoMax(tPuntos puntos);

int verPuntos(tPuntos puntos);

bool esLimpiador (tPuntos puntos);

tPuntos destruirPuntos(tPuntos puntos);

#endif
