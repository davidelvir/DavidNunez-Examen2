#include "Persona.h"

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador : public Persona{

public:
	string lugar;
	string apodo;
	double dinero;

	Jugador();
	Jugador(string,int,int,string,string,double);

	string getApodo(){return apodo;}
	double getDinero(){return dinero;}
	virtual void poli();

};

#endif