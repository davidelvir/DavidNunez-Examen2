#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona{

public:

	Persona();
	Persona(string,int,string);
	string nombre;
	int edad;
	string id;

	void setNombre(string);
	void setEdad(int);
	void setID(string);

	string getNombre();
	int getEdad();
	string getID();

	virtual void poli();

};
#endif