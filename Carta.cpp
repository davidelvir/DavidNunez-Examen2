#include "Carta.h"

Carta::Carta(){}

Carta::Carta(string valor,string simbolo,string color){

	this->valor = valor;
	this->simbolo = simbolo;
	this->color = color;
}

string Carta::getValor(){
	return valor;
}