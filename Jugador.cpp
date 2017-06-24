#include "Jugador.h"

Jugador::Jugador(){}
Jugador::Jugador(string nombre,int edad,int id,string lugar,string apodo,double dinero){

	this->nombre = nombre;
	this->edad = edad;
	this->id = id;
	this->lugar = lugar;
	this->dinero = dinero;
	this->apodo = apodo;

}
void Jugador::poli(){
	
}

void Jugador::setDinero(double pDinero){
	dinero -= pDinero;
}

void Jugador::Ganar(double pDinero){
	dinero+=pDinero;
}