#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "conio.h"
#include "def.h"
#include "jugador.h"
#include "mapa.h"
#include "mensaje.h"
#include "puntos.h"
#include "tabla.h"


int main (void) {
    tMapa mapa;
    tJugador jugador;
    tMensaje mensaje;
    tPuntos puntos;
    tTabla tabla;
    char reintentar;
    char movimiento;
    bool refrescar;
    int tiempo;

    /*necesario para el rand, semilla en cero*/
    srand(time(NULL));

    system("clear");
    printf(RED);
    encabezado();
    printf ("\n\n\n\n\n\t"
            "             Hey!!\n\n\t"
            "       Quieres probarme?\n\n\n\t"
            "     Para saber como jugar\n\t"
            "          Presiona A\n\n\t"
            "     Para empezar a jugar\n\t"
            "        Presiona Enter! \n");
    printf(ESC"%dB\t", 12);
    printf ("       c := Mi Creador\n\t"
            "      b := Respalar Tabla\n\t"
            "     v := Restaurar Tabla\n");
    printf(ESC"%dA"ESC"%dC", 16, 31);

    do {
        reintentar = getch();
    } while (reintentar != 10 && reintentar != 'a' && reintentar != 'c' && reintentar != 'b' && reintentar != 'v');

    printf(ESC"%dB", 20);
    tabla = abrirTabla();
    comandos(tabla, reintentar);
    tabla = cerrarTabla(tabla);

    do {
        mapa = crearMapa();
        jugador = crearJugador();
        puntos = crearPuntos();
        mensaje = crearMensaje();
        tiempo = 1;
        reintentar = 'f';
        refrescar = true;

        encabezado();
        printf ("\n\n\n\t"
                "       A que dificultad\n\t"
                "        Quieres jugar?\n\n\t"
           GREEN"            Facil\n\n\t"RED
                "           Dificil\n\n\t"
                "          Imposible");
        do {
        movimiento = getch();
        if (movimiento == 27) {
            getch();
            movimiento = getch();
            switch (movimiento) {
                case ARR:
                    switch (reintentar) {
                        case 'd':
                            printf (ESC"4A"ESC"23D"ESC"0J\t");
                            printf (GREEN"            Facil\n\n\t"RED
                                         "           Dificil\n\n\t"
                                         "          Imposible");
                            reintentar = 'f';
                            break;
                        case 'i':
                            printf (ESC"4A"ESC"23D"ESC"0J\t");
                            printf (    "            Facil\n\n\t"
                                    CYAN"           Dificil\n\n\t"RED
                                        "          Imposible");
                            reintentar = 'd';
                            break;
                    }
                    break;
                case ABA:
                    switch (reintentar) {
                        case 'f':
                            printf (ESC"4A"ESC"23D"ESC"0J\t");
                            printf (    "            Facil\n\n\t"
                                    CYAN"           Dificil\n\n\t"RED
                                        "          Imposible");
                            reintentar = 'd';
                            break;
                        case 'd':
                            printf (ESC"4A"ESC"23D"ESC"0J\t");
                            printf (      "            Facil\n\n\t"
                                          "           Dificil\n\n\t"
                                    YELLOW"          Imposible"RED);
                            reintentar = 'i';
                            break;
                    }
                    break;
                }
            }
        }
        while (movimiento != 10);

        switch (reintentar) {
            case 'f':
                cambiarDificultad(mapa, 1);
                break;
            case 'd':
                cambiarDificultad(mapa, 2);
                break;
            case 'i':
                cambiarDificultad(mapa, 3);
                break;
        }

        encabezado();
        printf(ESC"10B\t\t    Listo?\n");
        for (int i = 0; i < 180000000; i++);
        printf (ESC"1A\t\t    Bien! \n");
        for (int i = 0; i < 130000000; i++);

        do {
            encabezado();
            printf ("\t  Puntos: %d        Mov: %d\n", verPuntos(puntos), tiempo);
            actualizarMensaje(mensaje, esLimpiador(puntos), verPuntos(puntos));
            imprimirMapa(mapa, mensaje);

            movimiento = getch();
            if (movimiento == 27){
                getch();
                movimiento = getch();
                switch (movimiento) {
                    case ABA:
                    case IZQ:
                    case DER:
                    case ARR:
                        dibujarMapa(mapa, verJugador(jugador), VACIO, false);
                        refrescar = moverJugador(movimiento, jugador);
                        if (refrescar) {
                            srPuntos(puntos, mapa, verJugador(jugador));
                            dibujarMapa(mapa, verJugador(jugador), ESTRELLA, esLimpiador(puntos));
                        }
                        break;
                }
            /*para terminar partida*/
            } else if (movimiento == 'q') {
                refrescar = false;                
            }

            /*gestion de elementos*/
            randomMapa(mapa, REST);
            randomMapa(mapa, REST);
            randomMapa(mapa, REST);
            randomMapa(mapa, REST);
            randomMapa(mapa, REST);
            if (tiempo%(STIME) == 0) {
                randomMapa(mapa, SUMA);
            }
            if (tiempo%(LTIME) == 0) {
                randomMapa(mapa, MUCH);
            }
            tiempo++;

        } while (refrescar && 0 <= verPuntos(puntos) && verPuntos(puntos) < 999);

        tabla = abrirTabla();
        tabla = escribirTabla(tabla, verPuntoMax(puntos), tiempo);

        mensaje = destruirMensaje(mensaje);
        tabla = cerrarTabla(tabla);
        mapa = destruirMapa(mapa);
        puntos = destruirPuntos(puntos);
        jugador = destruirJugador(jugador);

        printf ("\n\n\t"
                "      Gracias por jugar!\n\n\n\t"
                "     Quieres Reprobarme?\n\n\n\t"
                "       Presiona Enter! ");
        
        
        reintentar = getche();
        
    } while (reintentar == 10);
    
    /*reiniciar colores*/
    printf (ESC"0m\n\n\n\n\n\n");
    return 0;
}