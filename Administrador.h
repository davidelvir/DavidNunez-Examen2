#include "Persona.h"
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador : public Persona{

public:
	int experiencia;
	string rango;
	double sueldo;

	Administrador();

	Administrador(string,int,int,int,string,double);
};

#endif