#include "Jugador.h"
#include "Repartidor.h"
#include <string>
#ifndef MESA_H
#define MESA_H

using namespace std;

class Mesa{

	int numero;
	Repartidor* repartidor;
	Jugador* jugador;

	Mesa();
	int getNumero();
	Mesa(int,Repartidor*,Jugador*);
};

#endif