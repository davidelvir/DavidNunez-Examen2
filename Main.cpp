#include "Baraja.h"
#include "Carta.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 
#include <vector>

using namespace std;

int main(){
	srand ( unsigned ( std::time(0) ) );

	Baraja* baraja = new Baraja();

	int num = baraja->getSize();

	baraja->shuffle();

	for(int i = 0;i< num;i++){

		cout<<baraja->getCarta(i)->getValor2()<<"  "<<baraja->getCarta(i)->getColor()<<"  "<<baraja->getCarta(i)->getSimbolo()<<endl;
	}

}