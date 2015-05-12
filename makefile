#makefile para XOX2
FLAGS = -g -Wall -Wextra -Werror -pedantic -std=c99
OBJETOS = main.o jugador.o mapa.o puntos.o tabla.o mensaje.o conio.o

xox2 : $(OBJETOS)
	gcc $(FLAGS) -o XOX2 $(OBJETOS)

main.o : main.c jugador.h mapa.h puntos.h tabla.h mensaje.h
	gcc $(FLAGS) -c main.c

jugador.o : jugador.c jugador.h mapa.h
	gcc $(FLAGS) -c jugador.c

mapa.o : mapa.c mapa.h mensaje.h
	gcc $(FLAGS) -c mapa.c

puntos.o : puntos.c puntos.h mapa.h
	gcc $(FLAGS) -c puntos.c

tabla.o : tabla.c tabla.h
	gcc $(FLAGS) -c tabla.c

mensaje.o : mensaje.c mensaje.h
	gcc $(FLAGS) -c mensaje.c

conio.o : conio.c conio.h
	gcc $(FLAGS) -c conio.c

clean :
		rm XOX2 $(OBJETOS) tablaXOX.txt
