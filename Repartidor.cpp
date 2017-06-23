#include "Repartidor.h"

Repartidor::Repartidor(){}

Repartidor::Repartidor(string nombre,int edad,int id,string dificultad,double dinero){

	this->nombre = nombre;
	this->edad = edad;
	this->id = id;
	this->dificultad = dificultad;
	this->dinero = dinero;
	baraja = new Baraja();
}

double Repartidor::getDinero(){
	return dinero;
}

void Repartidor::poli(){
	
}