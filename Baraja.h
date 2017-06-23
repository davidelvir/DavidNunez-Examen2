#include "Carta.h"
#include <vector>

#ifndef BARAJA_H
#define BARAJA_H

class Baraja{

public:

	vector<Carta*>cartas;

	Baraja();

	int getSize();
	Carta* getCarta(int);
	void setCarta(Carta*);

	void shuffle();

};

#endif