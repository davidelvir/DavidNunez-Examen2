#include "Persona.h"
#include <string>
#include "Baraja.h"

#ifndef REPARTIDOR_H
#define REPARTIDOR_H

using namespace std;

class Repartidor : public Persona{

public:
	string dificultad;
	double dinero;
	Baraja* baraja;

	Repartidor();
	Repartidor(string,int,string,string,double,Baraja*);

};

#endif;