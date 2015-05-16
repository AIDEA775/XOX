#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"
#include "puntos.h"


struct tipoPuntos {
	int puntoActual;
	int puntoMax;
    int limpiar;
    int limpiarTiempo;
};


tPuntos crearPuntos (void) {
	tPuntos puntos = NULL;
	puntos = calloc(1, sizeof(struct tipoPuntos));
	puntos->puntoActual = 1;
	puntos->puntoMax = 1;
    puntos->limpiar = 0;
    puntos->limpiarTiempo = 0;
	return puntos;
}


void srPuntos(tPuntos puntos, tMapa mapa, direc jugador) {
    direc dir=NULL;

    if (puntos->limpiar == 0) {
        switch (verMapa(mapa, jugador)) {
            case SUMA:
            	puntos->puntoActual += 2;
                break;
            case REST:
                puntos->puntoActual--;
                break;
            case MUCH:
                puntos->puntoActual += 10;
                puntos->limpiar = rand()%5+1;
                switch (puntos->limpiar) {
                    case 1:
                        puntos->limpiarTiempo = C;
                        break;

                    case 2:
                        puntos->limpiar = 0;
                        dir = copiarDir(jugador);
                        arrDir(dir);
                        izqDir(dir);
                        for (int f = 0; f<3; f++) {
                            for (int c = 0; c<3; c++) {
                                dibujarMapa(mapa, dir, SUMA, false);
                                derDir(dir);
                            }
                            for (int t = 0; t<3; t++) {
                                izqDir(dir);
                            }
                            abaDir(dir);
                        }
                        dir = destruirDir(dir);
                        break;

                    case 3:
                        puntos->limpiar = 0;

                        dir = copiarDir(jugador);
                        arrDirFinal(dir);
                        while (dirValida(dir)){
                            dibujarMapa(mapa, dir, VACIO, false);
                            abaDir(dir);
                        }
                        dir = destruirDir(dir);

                        dir = copiarDir(jugador);
                        izqDirFinal(dir);
                        while (dirValida(dir)){
                            dibujarMapa(mapa, dir, VACIO, false);
                            derDir(dir);
                        }
                        dir = destruirDir(dir);
                        break;

                    case 4:
                        puntos->limpiar = 0;
                        dir = copiarDir(jugador);
                        arrDir(dir);
                        arrDir(dir);
                        izqDir(dir);
                        izqDir(dir);
                        for (int f = 0; f<5; f++) {
                            for (int c = 0; c<5; c++) {
                                dibujarMapa(mapa, dir, VACIO, false);
                                derDir(dir);
                            }
                            for (int t = 0; t<5; t++) {
                                izqDir(dir);
                            }
                            abaDir(dir);
                        }
                        dir = destruirDir(dir);
                        break;

                    case 5:
                        puntos->limpiar = 0;
                        dir = copiarDir(jugador);
                        arrDir(dir);
                        for (int i = 0;i < 3;i++) {
                            izqDirFinal(dir);
                            while(dirValida(dir)){
                                dibujarMapa(mapa, dir, VACIO, false);
                                derDir(dir);
                            }
                            abaDir(dir);
                        }
                        dir = destruirDir(dir);
                        break;

                }
                break;
        }
    } else if (puntos->limpiarTiempo > 0) {
        puntos->limpiarTiempo--;
    } else {
        puntos->limpiarTiempo = 0;
        puntos->limpiar = 0;
   }

    /*guardar puntaje maximo*/
    if (puntos->puntoMax < puntos->puntoActual) {
        puntos->puntoMax = puntos->puntoActual;
    }

    /*en caso de superar los 999 puntos*/
    if (puntos->puntoMax > 999) {
        puntos->puntoMax = 999;
    }
}


int verPuntoMax(tPuntos puntos) {
	return (puntos->puntoMax);
}


int verPuntos(tPuntos puntos) {
	return (puntos->puntoActual);
}

bool esLimpiador(tPuntos puntos) {
    return (puntos->limpiar != 0);
}


tPuntos destruirPuntos(tPuntos puntos) {
	free(puntos);
	puntos = NULL;
	return puntos;
}