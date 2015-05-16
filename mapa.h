#ifndef _MAPA_H
#define _MAPA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "mensaje.h"


typedef struct dirMapa *direc;
typedef char elemento;
typedef struct tipoMapa *tMapa;


tMapa crearMapa (void);
/*
 * crea el mapa inicializado con la posicion inicial del 'jugador' y un elemento tipo 'SUMA'
 * destruirlo cuando termine la partida
 */

direc crearDir(void);
/*
 * crea una direccion que apunta a un lugar en el mapa
 * por ahora no se necesita destruir esto porque se destruye junto con 'jugador'
 */

tMapa cambiarDificultad(tMapa mapa, int dificultad);
/*
 * asigna un nivel de dificultad al mapa a partir de un entero
 */

tMapa dibujarMapa(tMapa mapa, direc dir, elemento dibujo, bool limpiar);
/*
 * dibuja en el 'mapa' en la direccion de 'dir' el elemento 'dibujo' si 'limpiar' es 'false'
 * dibuja 'LIMPIADOR' si 'limpiar' es 'true'
 */

tMapa randomMapa(tMapa mapa, elemento dibujo);
/*
 * dibuja en el mapa el elemento 'dibujo' en una posicion al azar
 */

void imprimirMapa(tMapa mapa, tMensaje mensaje);
/*
 * imprime o refresca el mapa con el mensaje 
 */

elemento verMapa(tMapa mapa, direc dir);
/*
 * devuelve el elemento del 'mapa' en la posicion 'dir'
 */

bool dirValida(direc dir);
/*
 * devuelve si la direccion 'dir' esta dentro o no del mapa
 */

direc dirCero(direc dir);
/*
 * asigna en la direccion 'dir' la direccion inicial y la devuelve
 */

direc arrDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de arriba y la devuelve
 */

direc abaDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de abajo y la devuelve
 */

direc izqDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de la izquierda y la devuelve
 */

direc derDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de la derecha y la devuelve
 */

tMapa destruirMapa(tMapa mapa);
/*
 * destruye el mapa y asigna este a NULL
 */

#endif