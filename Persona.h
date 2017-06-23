#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona{

public:

	Persona();
	Persona(string,int,int);
	string nombre;
	int edad;
	int id;

	void setNombre(string);
	void setEdad(int);
	void setID(int);

	string getNombre();
	int getEdad();
	int getID();

	virtual void poli();

};
#endif