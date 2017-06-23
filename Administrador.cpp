#include "Administrador.h"

Administrador::Administrador(){}

Administrador::Administrador(string nombre,int edad,int id,int experiencia,string rango,double sueldo){

	this->nombre = nombre;
	this->edad = edad;
	this->id = id;
	this->experiencia = experiencia;
	this->rango = rango;
	this->sueldo = sueldo;
}