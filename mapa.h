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

void cambiarDificultad(tMapa mapa, int dificultad);
/*
 * asigna un nivel de dificultad al mapa a partir de un entero
 */

void dibujarMapa(tMapa mapa, direc dir, elemento dibujo, bool limpiar);
/*
 * dibuja en el 'mapa' en la direccion de 'dir' el elemento 'dibujo' si 'limpiar' es 'false'
 * dibuja 'LIMPIADOR' si 'limpiar' es 'true'
 */

void randomMapa(tMapa mapa, elemento dibujo);
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

direc copiarDir(direc dir);
/*
 * copia una direccion
 * destruir esto cuando ya no se use
 */

void dirCero(direc dir);
/*
 * asigna en la direccion 'dir' la direccion inicial
 */

void arrDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de arriba
 */

void abaDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de abajo
 */

void izqDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de la izquierda
 */

void derDir(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion de la derecha
 */

 void arrDirFinal(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion tope de arriba
 */

void abaDirFinal(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion tope hacia abajo
 */

void izqDirFinal(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion tope a la izquierda
 */

void derDirFinal(direc dir);
/*
 * asigna en la direccion 'dir' la direccion de la posicion tope a la derecha
 */

direc destruirDir(direc dir);
/*
 * destruye la direccion y la asigna a NULL
 */

tMapa destruirMapa(tMapa mapa);
/*
 * destruye el mapa y asigna este a NULL
 */

#endif