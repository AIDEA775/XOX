#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mensaje.h"


struct tipoMensaje {
    int descenso;
    char letra[F];
};


tMensaje copiarMensaje (tMensaje mensaje, char letras[F]) {
    int i = 0;
    while (letras[i] != '\0') {
        mensaje->letra[F-(i+1)] = letras[i];
        i++;
    }
    return mensaje;
}


tMensaje borrarLetras(tMensaje mensaje) {
    for (int i = 0; i < F; i++ ) {
        mensaje->letra[i] = ' ';
    }
    return mensaje;
}


tMensaje crearMensaje(void) {
    tMensaje mensaje = NULL;
    mensaje = calloc(1, sizeof(struct tipoMensaje));
    mensaje = borrarLetras(mensaje);
    mensaje->descenso = 0;
    return mensaje;
}


void imprimirMensaje(tMensaje mensaje,int color) {
    for (int i = 0; i < F; i++) {
        printf(ESC"A%s%dm%c%s", RAND, color, mensaje->letra[(i+mensaje->descenso)%F], RED);
        printf(ESC"D");
    }
    printf(ESC"%dB", F);
}


tMensaje actualizarMensaje(tMensaje mensaje,bool eslimpiador,int puntos) {
    char mensajeLimp[F] = "LIMPIADOOR!!";
    char mensaje0[F] = "MUEVETE CON FLECHAS DIR";
    char mensaje1[F] = "VAMOS DESPACIO";
    char mensaje2[F] = "OKEY EMPEZAMOS BIEN";
    char mensaje3[F] = "OKEY AHORA SI";
    char mensaje4[F] = "VAMOS SIGUE!";
    char mensaje5[F] = "BIEN CONTINUA";
    char mensaje6[F] = "FACIL?";
    char mensaje7[F] = "AHORA SE PONE DIVERTIDO";
    char mensaje8[F] = "SI CAMBIAS DE ESTRATEGIA";
    char mensaje9[F] = "ERES GENIAL";
    char mensaje10[F] = "GRANDIOSO!";
    char mensaje11[F] = "FANTASTICO!!";
    char mensaje12[F] = "EXCELSIOR";
    char mensaje13[F] = "YA CASI!";
    char mensaje14[F] = "SOLO UN POCO MAS";
    char mensaje15[F] = "LO HAS HECHO MUY BIEN";
    mensaje->descenso++;
    mensaje = borrarLetras(mensaje);
        if (eslimpiador) {
            mensaje = copiarMensaje(mensaje, mensajeLimp);
        } else {
            switch (puntos){
                case 1:
                    mensaje = copiarMensaje(mensaje, mensaje0);
                    break;

                case 2:
                    mensaje = copiarMensaje(mensaje, mensaje1);
                    break;

                case 3:
                    mensaje = copiarMensaje(mensaje, mensaje2);
                    break;

                case 4:
                    mensaje = copiarMensaje(mensaje, mensaje3);
                    break;

                case 5:
                    mensaje = copiarMensaje(mensaje, mensaje4);
                    break;

                case 10:
                case 11:
                    mensaje = copiarMensaje(mensaje, mensaje5);
                    break;

                case 30:
                case 31:
                    mensaje = copiarMensaje(mensaje, mensaje6);
                    break;

                case 40:
                case 41:
                    mensaje = copiarMensaje(mensaje, mensaje7);
                    break;

                case 50:
                case 51:
                    mensaje = copiarMensaje(mensaje, mensaje8);
                    break;

                case 75:
                case 76:
                    mensaje = copiarMensaje(mensaje, mensaje9);
                    break;

                case 100:
                case 101:
                    mensaje = copiarMensaje(mensaje, mensaje10);
                    break;

                case 200:
                case 201:
                    mensaje = copiarMensaje(mensaje, mensaje11);
                    break;

                case 300:
                case 301:
                    mensaje = copiarMensaje(mensaje, mensaje12);
                    break;

                case 400:
                case 401:
                    mensaje = copiarMensaje(mensaje, mensaje13);
                    break;

                case 500:
                case 501:
                    mensaje = copiarMensaje(mensaje, mensaje14);
                    break;

                case 900:
                case 901:
                    mensaje = copiarMensaje(mensaje, mensaje15);
                    break;

                default :
                    break;
            }
        }
    
    return mensaje;
}


tMensaje destruirMensaje(tMensaje mensaje) {
    free (mensaje);
    mensaje = NULL;
    return mensaje;
}