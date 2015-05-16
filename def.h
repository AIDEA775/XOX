#ifndef _DEF_H
#define _DEF_H

#define ARR 65    /*Arriba*/
#define ABA 66    /*Abajo*/
#define DER 67    /*Derecha*/
#define IZQ 68  /*Izquierda*/

#define VACIO ' '      /*Espacio vacio en el mapa*/
#define ESTRELLA '*'   /*Layout del jugador*/
#define LIMP '+'     /*Layout del limpiador*/
#define SUMA 'O'      /*Layout de lo que suma puntos*/
#define MUCH '0'      /*Layout de lo que suma doble*/
#define REST 'X'      /*Layout de lo que resta puntos*/

#define RAND "\033[1;"  /* un numero (rand()%6)+31 seguido de la letra "m" */
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define ESC "\033["

#define F 25
#define C 25

#define STIME 12
#define LTIME 208

#endif
