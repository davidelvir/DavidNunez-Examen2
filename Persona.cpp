#include "Persona.h"
#include <string>

using namespace std;

Persona::Persona(){}

Persona::Persona(string nombre,int edad,int id){

	this->nombre = nombre;
	this->edad = edad;
	this->id = id;
}

void Persona::setNombre(string pNombre){
	nombre = pNombre;
}
void Persona::setEdad(int pEdad){
	edad = pEdad;
}
void Persona::setID(int pID){
	id = pID;
}

string Persona::getNombre(){
	return nombre;
}
int Persona::getEdad(){
	return edad;
}
int Persona::getID(){
	return id;
}
void Persona::poli(){

}