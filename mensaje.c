#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mensaje.h"

#define RAND "\033[1;"
#define ESC "\033["
#define RED "\033[1;31m"
#define F 25
#define C 25


struct tipoMensaje{
    int descenso;
    char letra[F];
};


tMensaje copiarMensaje (tMensaje mensaje,char letras[F]){
    int i=0;
    while (letras[i]!='\0'){
        mensaje->letra[F-(i+1)]=letras[i];
        i++;
    }
    return mensaje;
}


tMensaje borrarLetras(tMensaje mensaje){
    for (int i=0; i<F; i++ ){
        mensaje->letra[i]=' ';
    }
    return mensaje;
}


tMensaje crearMensaje(void){
    tMensaje mensaje=NULL;
    mensaje=calloc(1,sizeof(struct tipoMensaje));
    mensaje=borrarLetras(mensaje);
    mensaje->descenso=0;
    return mensaje;
}


void imprimirMensaje(tMensaje mensaje,int color){
    for (int i=0; i<F; i++){
        printf(ESC"A%s%dm%c%s",RAND,color,mensaje->letra[(i+mensaje->descenso)%F],RED);
        printf(ESC"D");
    }
    printf(ESC"%dB",F);
}


tMensaje actualizarMensaje(tMensaje mensaje,bool eslimpiador,int puntos){
    char mensajeLimp[F]="LIMPIADOOR!!";
    char mensaje0[F]="MUEVETE CON FLECHAS DIR";
    char mensaje1[F]="VAMOS DESPACIO";
    char mensaje2[F]="OKEY EMPEZAMOS BIEN";
    char mensaje3[F]="OKEY AHORA SI";
    char mensaje4[F]="VAMOS SIGUE!";
    char mensaje5[F]="BIEN CONTINUA";
    char mensaje6[F]="FACIL?";
    char mensaje7[F]="AHORA SE PONE DIVERTIDO";
    mensaje->descenso++;
    mensaje=borrarLetras(mensaje);
        if (eslimpiador){
            mensaje=copiarMensaje(mensaje,mensajeLimp);
        } else {
            switch (puntos){
                case 1:
                    mensaje=copiarMensaje(mensaje,mensaje0);
                    break;
                case 2:
                    
                    mensaje=copiarMensaje(mensaje,mensaje1); 
                    break;
                case 3:
                    
                    mensaje=copiarMensaje(mensaje,mensaje2); 
                    break;
                case 4:
                    
                    mensaje=copiarMensaje(mensaje,mensaje3); 
                    break;
                case 5:
                    
                    mensaje=copiarMensaje(mensaje,mensaje4); 
                    break;
                case 10:
                case 11:
                    
                    mensaje=copiarMensaje(mensaje,mensaje5); 
                    break;
                case 30:
                case 31:
                    
                    mensaje=copiarMensaje(mensaje,mensaje6); 
                    break;
                case 40:
                case 41:
                    
                    mensaje=copiarMensaje(mensaje,mensaje7); 
                    break;
                default :
                    break;
            }
        }
    
    return mensaje;
}


tMensaje destruirMensaje(tMensaje mensaje){
    free (mensaje);
    mensaje=NULL;
    return mensaje;
}