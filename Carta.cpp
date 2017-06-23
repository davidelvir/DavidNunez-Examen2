#include "Carta.h"

Carta::Carta(){}

Carta::Carta(string valor,string simbolo,string color){

	this->valor = valor;
	this->simbolo = simbolo;
	this->color = color;
}

int Carta::getValor(){
	int retVal;
	if(valor.compare("A")==0){
		retVal = 1;
	}
	if(valor.compare("1")==0){
		retVal = 1;
	}
	if(valor.compare("2")==0){
		retVal = 2;
	}
	if(valor.compare("3")==0){
		retVal = 3;
	}
	if(valor.compare("4")==0){
		retVal = 4;
	}
	if(valor.compare("5")==0){
		retVal = 5;
	}
	if(valor.compare("6")==0){
		retVal = 6;
	}
	if(valor.compare("7")==0){
		retVal = 7;
	}
	if(valor.compare("8")==0){
		retVal = 8;
	}
	if(valor.compare("9")==0){
		retVal = 9;
	}
	if(valor.compare("10")==0){
		retVal = 10;
	}
	if(valor.compare("J")==0){
		retVal = 11;
	}
	if(valor.compare("Q")==0){
		retVal = 12;
	}
	if(valor.compare("K")==0){
		retVal = 13;
	}

	return retVal;
}

string Carta::getValor2(){
	return valor;
}
string Carta::getSimbolo(){
	return simbolo;
}
string Carta::getColor(){
	return color;
}