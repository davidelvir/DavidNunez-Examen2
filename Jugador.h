#include "Persona.h"

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador : public Persona{

public:
	string lugar;
	string apodo;
	double dinero;

	Jugador();
	Jugador(string,int,string,string,string,double);

};

#endif