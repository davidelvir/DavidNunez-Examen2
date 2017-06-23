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

Carta* Repartidor::darCarta(){

	Carta* retVal = baraja->getCartas().back();
	baraja->getCartas().pop_back();
	return retVal;

}

vector<Carta*>& Repartidor::getBaraja(){
	return baraja->getCartas();
}