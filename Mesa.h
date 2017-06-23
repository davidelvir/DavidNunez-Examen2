#include "Jugador.h"
#include "Repartidor.h"
#include "Persona.h"
#include <string>
#ifndef MESA_H
#define MESA_H

using namespace std;

class Mesa{
public:

	int numero;
	Persona* repartidor;
	Persona* jugador;

	Mesa();
	int getNumero();
	Mesa(int,Persona*,Persona*);
};

#endif