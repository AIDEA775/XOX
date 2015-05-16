#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "conio.h"
#include "tabla.h"


/*imprimir titulo del juego*/
void encabezado (void) {
    /*system("clear");*/
    printf(ESC"1J"ESC"1;1f\n\n\n\t     ");

    /*imprimir barra superior*/
    for (int i = 0; i <= 20; i++) {
        printf("%s%dm×", RAND, (rand()%6)+31);
    }

    /*imprimir nombre*/
    printf("\n\t              XOX*    v2.0\n\t     ");

    /*imprimir barra inferior*/
    for (int i = 0; i <= 20; i++) {
        printf("%s%dm×", RAND, (rand()%6)+31);
    }
    printf("\n%s", RED);
}


/*imprime acerca de*/
void printAbout(void) {
    encabezado();
    printf ("\n\n\n\n\t"
            "     Mi creador es:\n\t"
            "\t%s%dmSilva Alejandro Ismael%s\n\n\t"
            "     Con ayuda e ideas de:\n\t"
            "\t%s%dmSilva Jonathan Ariel\n\t"
            "\t%s%dmNigrelli Alejandro Jose%s\n\n\t"
            "     Tabla de posiciones por:\n\t"
            "\t%s%dmSilva Walter Andre%s\n\n\t"
            "     Gracias por preguntar!"
            "\n", RAND, rand()%6+32, RED, RAND, rand()%6+32, RAND, rand()%6+32, RED, RAND, rand()%6+32, RED);
    getch();
}


/*imprime ayuda*/
void printHelp(void) {
    encabezado();
    printf ("\n\n\n\n\t"
            "     Eres un asterisco...\n\t"
            "     Estas hambriento...\n\t"
            "     Quieres comer %sO%ss...\n\t"
            "     Es tu letra favorita\n\t"
            "     Pero no las %sX%ss...\n\t"
            "     Esa letra no te gusta\n\t"
            "     Y menos las ×s...\n\t"
            "     Esa letra te hace mal\n\n\t"
            "     Puedes encontrar %s0%ss\n\t"
            "     Te ayuda a limpiar\n\t"
            "     Cualquier letra...\n\t"
            "     Pero cuidado!\n\t"
            "     No limpies tus letras favoritas!!\n\n\t"
            "      Ahora si quieres empezar? ", CYAN, RED, YELLOW, RED, GREEN, RED);
    getch();
}


/*restaura la tabla desde un backup existente*/
void setTable (tTabla tabla) {
    char buffer[120];
    FILE *backup;
    backup = fopen("backuptablaXOX.txt", "r");

    /*leer backup y escribir en tabla*/
    fscanf(backup, "%s", buffer);
    fprintf(tabla, "%s", buffer);

    fclose(backup);
}


/*hace un backup de la tabla actual*/
void backupTable (tTabla tabla) {
    char buffer[120];
    FILE *backup;
    backup = fopen("backuptablaXOX.txt", "w");

    /*leer tabla y escribir en backup*/
    fscanf(tabla, "%s", buffer);
    fprintf(backup, "%s", buffer);

    fclose(backup);
}



tTabla abrirTabla(void) {
    tTabla tabla = NULL;
    tabla = fopen("tablaXOX.txt", "r+");
    if (tabla == 0) {
        tabla = fopen("tablaXOX.txt", "w");
        rewind(tabla);

        /*escribir tabla inicial*/
        fprintf(tabla, "%s", "Steve....500"
                             "Tony.....400"
                             "Bruce....300"
                             "Nick.....200"
                             "Logan....100"
                             "Peter.....75"
                             "Natasha...50"
                             "Clint.....40"
                             "Pietro....30"
                             "Wanda.....15");
    }
    return tabla;
}

/*imprimir de tabla de posiciones*/
void imprimirTabla(char buffer[120]) {
    printf("\n\n\n\t     TABLA DE POSICIONES:\n\n");
    int lat = 0;

    /*imprimir desde el buffer*/
    while (lat < 120) {
        printf("\t        ");
        for (int col = 0; col < 12; col++) {
            printf("%c", buffer[lat]);
            lat++;
        }
        printf("\n");
    }
}


tTabla escribirTabla(tTabla tabla, int puntoMax, int tiempo) {
    char buffer[120];
    char nombre[10] = ".........";
    char string1[1];
    char string2[2];
    char string3[3];
    char c;
    int i = 0, l = 0;
    int ubicacion, record;

    /*iniciar buffer*/
    for (int i = 0; i < 120; i++){
        buffer[i] = ' ';
    }

    /*buffer contiene la tabla sin modificar*/
    fscanf (tabla, "%s", buffer);

    /*buscar donde escribir*/
    i = 9;
    do {
        l = 0;
        if (buffer[i] != '.') {
            for (int j = i; j < i+3; j++) {
                string3[l] = buffer[j];
                l++;
            }
            record = atoi(string3);
        } else if (buffer[i+1] != '.') {
            for (int j = i+1; j< i+3; j++) {
                string2[l] = buffer[j];
                l++;
            }
            record = atoi(string2);
        } else if (buffer[i+2] != '.') {
            string1[0] = buffer[i+2];
            record = atoi(string1);
        }
        ubicacion = i-9;
        i += 12;
    } while (i < 120 && record > puntoMax);

    /*si hay que escribir...*/
    if (record <= puntoMax) {
        encabezado();
        printf ("\n\n\n\n\n\t"
                "       Y O U W I N ! !\n\n\t"
                "         PUNTOS: %d\n\t"
                "      MOVIMIENTOS: %d\n", puntoMax, tiempo);  

        /*pedir y guardar un nombre con maximo 7 caracteres*/
        printf("\n\t     Tu nombre: ");
        i = 0;
        do {
            c = getchar();
            if (i < 7 && c != 10) {
                nombre[i] = c;
                i++;
            }
        } while (c != 10);

        /*ubicacion tiene el lugar donde hay que escribir el nuevo record*/
        rewind(tabla);
        fseek(tabla, ubicacion, SEEK_CUR);
    
        /*en caso de escribir a la mitad del archivo*/
        if (buffer[ubicacion] != '\000') {

            /*guardar el resto de records menores*/
            fscanf (tabla, "%s", buffer);

            /*reubicar el puntero*/
            rewind(tabla);
            fseek(tabla, ubicacion, SEEK_CUR);

            /*escribir el nombre y los puntos*/
            fprintf(tabla, "%s", nombre);
            if (puntoMax < 10) {
                fprintf(tabla, "%s", "..");
            } else if (puntoMax < 100) {
                fprintf(tabla, "%s", ".");
            }
            fprintf(tabla, "%d", puntoMax);

            /*escribir el resto de records*/
            fprintf(tabla, "%s", buffer);

        } else {
            /*escribir el nombre y los puntos*/
            fprintf(tabla, "%s", nombre);
            if (puntoMax < 10) {
                fprintf(tabla, "%s", "..");
            } else if (puntoMax < 100) {
                fprintf(tabla, "%s", ".");
            }
            fprintf(tabla, "%d", puntoMax);
        }

        /*cortar el archivo para no superar el buffer*/
        rewind(tabla);
        fseek(tabla, 120, SEEK_CUR);
        fprintf(tabla, "%s", "\n");
    }
    encabezado();

    /*por ultimo (...y si no hay que escribir) leer e imprimir la tabla*/
    rewind(tabla);
    fscanf (tabla, "%s", buffer);
    imprimirTabla(buffer);
    return tabla;
}


void comandos(tTabla tabla, char comando){
    switch (comando) {
        case 'b':
            backupTable(tabla);
            break;
        case 'v':
            setTable(tabla);
            break;
        case 'a':
            printHelp();
            break;
        case 'c':
            printAbout();
            break;
    }
}


tTabla cerrarTabla(tTabla tabla) {
    fclose(tabla);
    return tabla;
}