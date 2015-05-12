#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"
#include "puntos.h"

struct tipoPuntos {
	int puntoActual;
	int puntoMax;
    bool limpiar;
    int limpiarTiempo;
};

tPuntos crearPuntos (void) {
	tPuntos puntos = NULL;
	puntos = calloc(1, sizeof(struct tipoPuntos));
	puntos->puntoActual = 1;
	puntos->puntoMax = 1;
    puntos->limpiar = false;
    puntos->limpiarTiempo = C;
	return puntos;
}


tPuntos srPuntos(tPuntos puntos,elemento dibujo) {
    if (!puntos->limpiar) {
        switch (dibujo) {
            case SUMA:
            	puntos->puntoActual += 2;
                break;
            case REST:
                puntos->puntoActual--;
                break;
            case MUCH:
                puntos->puntoActual += 10;
                puntos->limpiar = true;
                break;
        }
    } else if (puntos->limpiarTiempo > 0) {
        puntos->limpiarTiempo--;
    } else {
        puntos->limpiarTiempo = C;
        puntos->limpiar = false;
   }

    /*guardar puntaje maximo*/
    if (puntos->puntoMax < puntos->puntoActual) {
        puntos->puntoMax = puntos->puntoActual;
    }

    /*en caso de superar los 999 puntos*/
    if (puntos->puntoMax > 999) {
        puntos->puntoMax = 999;
    }
    return puntos;
}


int verPuntoMax(tPuntos puntos) {
	return (puntos->puntoMax);
}


int verPuntos(tPuntos puntos) {
	return (puntos->puntoActual);
}

bool esLimpiador(tPuntos puntos) {
    return (puntos->limpiar);
}


tPuntos destruirPuntos(tPuntos puntos) {
	free(puntos);
	puntos = NULL;
	return puntos;
}