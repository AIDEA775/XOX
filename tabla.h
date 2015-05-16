#ifndef _TABLA_H
#define _TABLA_H

#include <stdbool.h>
#include <stdio.h>

#include "def.h"


typedef FILE *tTabla;


void encabezado(void);
/*
 * imprime el titulo del juego
 * aunque no tenga nada que ver con la tabla, los tads que lo usan importan este tad
 */

tTabla abrirTabla(void);
/*
 * si existe abre la tabla, sino la crea
 */

tTabla escribirTabla(tTabla tabla, int record, int tiempo);
/*
 * si es el caso, pide el nombre al usuario, guarda el nuevo record e imprime la tabla
 * sino, solo imprime la tabla
 */

void comandos(tTabla tabla, char comando);
/*
 * llama a funciones dependiendo de 'comando'
 * 'b' y 'v' son funciones con la tabla, respalda y restaura respectivamente
 * 'a' y 'c' son funciones que imprimen en pantalla, ayuda y acerca de respectivamente
 */

tTabla cerrarTabla(tTabla tabla);
/*
 * cierra el archivo tabla
 */

#endif
