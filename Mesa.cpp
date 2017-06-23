#include "Mesa.h"

int numero;
Repartidor* repartidor;
Jugador* jugador;

Mesa::Mesa(){}
Mesa::Mesa(int numero,Repartidor* repartidor,Jugador* jugador){

	this->numero = numero;
	this->repartidor = repartidor;
	this->jugador = jugador;
}

int Mesa::getNumero(){
	return numero;
}