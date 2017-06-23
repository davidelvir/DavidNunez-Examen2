#include <string>

#ifndef CARTA_H
#define CARTA_H

using namespace std;

class Carta{
public:
	Carta();
	Carta(string,string,string);
	string valor;
	string simbolo;
	string color;
	
	string getValor();


};

#endif