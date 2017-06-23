#include "Repartidor.h"

Repartidor::Repartidor(){}

Repartidor::Repartidor(string nombre,int edad,string id,string dificultad,double dinero,Baraja* baraja){

	this->nombre = nombre;
	this->edad = edad;
	this->id = id;
	this->dificultad = dificultad;
	this->dinero = dinero;
	this->baraja = baraja;
}

double Repartidor::getDinero(){
	return dinero;
}

void Repartidor::poli(){
	
}