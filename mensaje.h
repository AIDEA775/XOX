#ifndef _MENSAJE_H
#define _MENSAJE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tipoMensaje *tMensaje;

tMensaje crearMensaje(void);

void imprimirMensaje(tMensaje mensaje,int color);

tMensaje actualizarMensaje(tMensaje mensaje,bool eslimpiador,int puntos);

tMensaje destruirMensaje(tMensaje mensaje);

#endif
