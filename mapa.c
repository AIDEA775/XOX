#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

#define ESC "\033["

struct dirMapa {
    int fila;
    int columna;
};

struct tipoMapa {
    elemento a[F][C];
    int dificultad;
};


tMapa crearMapa(void) {
    tMapa mapa = NULL;
    mapa = calloc(1, sizeof(struct tipoMapa));
    mapa->dificultad = 0;

    /*mapa vacio*/
    for (int fila = 0; fila < F; fila++) {
        for (int columna = 0; columna < C; columna++) {
            mapa->a[fila][columna] = VACIO;
        }
    }
    /*posicion inicial del player*/
    mapa->a[F/2][1] = ESTRELLA;

    /*primer elemento inicial*/
    mapa->a[F/2][C-2] = SUMA;

    /*mapa->a[F/2-1][C/2]=MUCH;*/

    return mapa;
}


tMapa cambiarDificultad(tMapa mapa, int dificultad) {
    mapa->dificultad = dificultad;
    return mapa;
}


direc crearDir(void) {
    direc dir = NULL;
    dir = calloc(1, sizeof(struct dirMapa));
    return dir;
}


tMapa dibujarMapa(tMapa mapa, direc dir, elemento dibujo, bool limpiar) {
    if (dibujo == ESTRELLA && limpiar) {
        mapa->a[dir->fila][dir->columna] = LIMP;
    } else {
        mapa->a[dir->fila][dir->columna] = dibujo;
    }
    return mapa;
}


tMapa randomMapa(tMapa mapa, elemento dibujo) {
    mapa->a[rand()%F][rand()%C] = dibujo;
    return mapa;
}
void doblarMapa(int dificultad) {
    int doblar;
    if (dificultad == 1) {
        doblar = 2;
    } else {
        doblar = rand()%dificultad+1;
    }
    for (int i = 0; i < doblar; i++){
        printf(' ');
    }
}

void imprimirMapa(tMapa mapa, tMensaje mensaje) {
    int colorMensaje = (rand()%6)+31;

    /*imprimir barra Superior*/
    printf("\t");
    doblarMapa(mapa->dificultad);
    for (int columna = 0; columna < C+2; columna++) {
        printf("%s%dm×",RAND, (rand()%6)+31);
    }

    /*imprimir mapa*/
    for (int fila = 0; fila < F; fila++) {
        printf("\n\t");
        doblarMapa(mapa->dificultad);
        printf ("%s%dm×",RAND, (rand()%6)+31);
        for (int columna = 0; columna < C; columna++) {
            switch (mapa->a[fila][columna]) {            /*imprimir cada elemento con su color*/
                case ESTRELLA:
                    printf ("%s%c%s", WHITE, mapa->a[fila][columna], RED);
                    break;
                case REST:
                    printf ("%s%c%s", YELLOW, mapa->a[fila][columna], RED);
                    break;
                case SUMA:
                    printf ("%s%c%s", CYAN, mapa->a[fila][columna], RED);
                    break;
                case MUCH:
                    printf ("%s%c%s", GREEN, mapa->a[fila][columna], RED);
                    break;
                case LIMP:
                    printf ("%s%c%s", RED, mapa->a[fila][columna], RED);
                    break;
                default :
                    printf ("%c", mapa->a[fila][columna]);
                    break;
            }
        }
        printf("%s%dm×", RAND, (rand()%6)+31);
    }
    printf("\n\t");
    imprimirMensaje(mensaje, colorMensaje);
    printf(ESC"%dC", F+5);
    imprimirMensaje(mensaje, colorMensaje);
    printf(ESC"%dD", F+5);

    /*imprimir barra inferior*/
    doblarMapa(mapa->dificultad);
    for (int columna = 0; columna < C+2; columna++) {
        printf("%s%dm×", RAND, (rand()%6)+31);
    }
    printf ("%s\n",RED);
}


elemento verMapa(tMapa mapa, direc dir) {
    return (mapa->a[dir->fila][dir->columna]);
}


bool dirValida(direc dir) {
    return (0 <= dir->fila && dir->fila < F && 0 <= dir->columna && dir->columna < C);
}


direc dirCero(direc dir) {
    dir->fila = F/2;
    dir->columna = 1;
    return dir;
}


direc arrDir(direc dir) {
    dir->fila--;
    return dir;
}


direc abaDir(direc dir) {
    dir->fila++;
    return dir;
}


direc izqDir(direc dir) {
    dir->columna--;
    return dir;
}


direc derDir(direc dir) {
    dir->columna++;
    return dir;
}


tMapa destruirMapa(tMapa mapa) {
    free(mapa);
    mapa = NULL;
    return mapa;
}