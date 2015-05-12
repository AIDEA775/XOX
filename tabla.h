#ifndef _TABLA_H
#define _TABLA_H

#include <stdio.h>
#include <stdbool.h>

#define ESC "\033["

typedef FILE *tTabla;

void encabezado(void);

tTabla abrirTabla(void);

tTabla escribirTabla(tTabla tabla,int record,int tiempo);

void comandos(tTabla tabla,char comando);

tTabla cerrarTabla(tTabla tabla);

#endif
