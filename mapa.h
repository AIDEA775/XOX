#ifndef _MAPA_H
#define _MAPA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mensaje.h"

#define VACIO ' '      /*Espacio vacio en el mapa*/
#define ESTRELLA '*'   /*Layout del jugador*/
#define LIMP '+'     /*Layout del limpiador*/
#define SUMA 'O'      /*Layout de lo que suma puntos*/
#define MUCH '0'      /*Layout de lo que suma doble*/
#define REST 'X'      /*Layout de lo que resta puntos*/

#define RAND "\033[1;"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

#define F 25
#define C 25


typedef struct dirMapa *direc;
typedef char elemento;
typedef struct tipoMapa *tMapa;


tMapa crearMapa (void);

direc crearDir(void);

tMapa cambiarDificultad(tMapa mapa, int dificultad);

tMapa dibujarMapa(tMapa mapa, direc dir, elemento dibujo, bool limpiar);

tMapa randomMapa(tMapa mapa, elemento dibujo);

void imprimirMapa(tMapa mapa, tMensaje mensaje);

elemento verMapa(tMapa mapa, direc dir);

bool dirValida(direc dir);

direc dirCero(direc dir);

direc arrDir(direc dir);

direc abaDir(direc dir);

direc izqDir(direc dir);

direc derDir(direc dir);

tMapa destruirMapa(tMapa mapa);

#endif