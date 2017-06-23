#include "Baraja.h"
#include <algorithm>

using namespace std;

int Baraja::getSize(){return cartas.size();}

Baraja::Baraja(){

	string valor;
	string simbolo;
	string color;

	for (int i = 0; i < 2; i++){
		if(i==0){
			color="Rojo";
			for(int j=0;j<2;j++){
				
				if(j==0){
					simbolo = "♥";
				}
				if(j==1){
					simbolo = "♦";
				}
				for (int i = 1; i < 14; i++){
					if(i==1){
						valor = "A";
					}
					if(i==2){
						valor = "2";
					}
					if(i==3){
						valor = "3";
					}
					if(i==4){
						valor = "4";
					}
					if(i==5){
						valor = "5";
					}
					if(i==6){
						valor = "6";
					}
					if(i==7){
						valor = "7";
					}
					if(i==8){
						valor = "8";
					}
					if(i==9){
						valor = "9";
					}
					if(i==10){
						valor = "10";
					}
					if(i==11){
						valor = "J";
					}
					if(i==12){
						valor = "Q";
					}
					if(i==13){
						valor = "K";
					}
					Carta* carta = new Carta(valor,simbolo,color);
					cartas.push_back(carta);
				}
			}

		}
		if(i==1){
			color = "Negro";
			for(int j=0;j<2;j++){
				if(j==0){
					simbolo = "♠";
				}
				
				if(j==1){
					simbolo = "♣";
				}
				for (int i = 1; i < 14; i++){
					if(i==1){
						valor = "A";
					}
					if(i==2){
						valor = "2";
					}
					if(i==3){
						valor = "3";
					}
					if(i==4){
						valor = "4";
					}
					if(i==5){
						valor = "5";
					}
					if(i==6){
						valor = "6";
					}
					if(i==7){
						valor = "7";
					}
					if(i==8){
						valor = "8";
					}
					if(i==9){
						valor = "9";
					}
					if(i==10){
						valor = "10";
					}
					if(i==11){
						valor = "J";
					}
					if(i==12){
						valor = "Q";
					}
					if(i==13){
						valor = "K";
					}
					Carta* carta = new Carta(valor,simbolo,color);
					cartas.push_back(carta);
				}

			}
		}

	}
	random_shuffle(cartas.begin(), cartas.end() );
}

Carta* Baraja::getCarta(int num){
	return cartas[num];
}
void Baraja::setCarta(Carta* carta){
	cartas.push_back(carta);
}

void Baraja::shuffle(){
	random_shuffle(cartas.begin(), cartas.end() );
}

vector<Carta*>& Baraja::getCartas(){
	return cartas;
}