#include "Mesa.h"

int numero;
Repartidor* repartidor;
Jugador* jugador;

Mesa::Mesa(){}
Mesa::Mesa(int numero,Persona* repartidor,Persona* jugador,string tipo){

	this->tipo = tipo;
	this->numero = numero;
	this->repartidor = repartidor;
	this->jugador = jugador;
}

int Mesa::getNumero(){
	return numero;
}