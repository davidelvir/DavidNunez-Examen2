Main: Main.o Persona.o Administrador.o Jugador.o Repartidor.o Baraja.o Carta.o Mesa.o
	g++ Main.o Persona.o Administrador.o Jugador.o Repartidor.o Baraja.o Carta.o Mesa.o -o Main

Main.o: Main.cpp Persona.h Administrador.h Jugador.h Repartidor.h Baraja.h Carta.h Mesa.h
	g++ -c Main.cpp

Persona.o: Persona.cpp Persona.h
	g++ -c Persona.cpp 

Administrador.o:  Administrador.h Administrador.cpp Persona.h
	g++ -c Administrador.cpp 

Jugador.o:  Jugador.h Jugador.cpp Persona.h
	g++ -c Jugador.cpp 

Repartidor.o:  Repartidor.h Repartidor.cpp Persona.h
	g++ -c Repartidor.cpp 

Baraja.o: Baraja.cpp Baraja.h
	g++ -c Baraja.cpp 

Carta.o: Carta.cpp Carta.h
	g++ -c Carta.cpp 

Mesa.o: Mesa.cpp Mesa.h
	g++ -c Mesa.cpp 

clean: 
	rm -f *.0 *.main ~
