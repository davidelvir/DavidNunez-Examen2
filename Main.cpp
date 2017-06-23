#include "Baraja.h"
#include "Carta.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 
#include <vector>
#include "Persona.h"
#include "Jugador.h"
#include "Repartidor.h"
#include "Mesa.h"
#include "Administrador.h"

using namespace std;

int main(){

	vector<Persona*>jugadores;
	vector<Administrador*>administradores;
	vector<Persona*>repartidores;
	vector<Mesa*>mesas;

	srand ( unsigned ( std::time(0) ) );

	Baraja* baraja = new Baraja();

	int num = baraja->getSize();

	baraja->shuffle();

	for(int i = 0;i< num;i++){

		cout<<baraja->getCarta(i)->getValor2()<<"  "<<baraja->getCarta(i)->getColor()<<"  "<<baraja->getCarta(i)->getSimbolo()<<endl;
	}

}

void menuAdmin(vector<Persona*>& jugadores,vector<Persona*>& repartidores, vector<Mesa*>& mesas){
	bool vivo = true;

	while(vivo){
		int op;
		cout<<"------Menu Administrador------"<<endl;
		cout<<"1. Crear mesa de blackjack."<<endl;
		cout<<"2. Modificar mesa de blackjack."<<endl;
		cout<<"3. Eliminar mesa de blackjack."<<endl;
		cout<<"4. Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				if(jugadores.size()>0 && repartidores.size()>0){
					/*string nombre;
					int edad;
					string id;
					string lugar;
					string apodo;
					double dinero;*/
					Persona* jugador;
					Persona* repartidor;
					int jugadorEscogido;
					int repartidoreEscogido;
					cout<<"ELija al jugador: "<<endl;
					for (int i = 0; i < jugadores.size(); i++){
						Jugador* temp = dynamic_cast<Jugador*>(jugadores[i]);
						cout<<i<<": "<<jugadores[i]->getNombre()<<" | "<<temp->getApodo()<<" | "<<temp->getDinero()<<endl;
					}
					cin>>jugadorEscogido;
					Jugador* tem2 = dynamic_cast<Jugador*>(jugadores[jugadorEscogido]);
					if(tem2->getDinero()<=0){
						cout<<"El jugador no tiene dinero para jugar!!"<<endl;
					}else{
						jugador = jugadores[jugadorEscogido];
						cout<<"ELija al repartidor: "<<endl;
						for (int i = 0; i < repartidores.size(); i++){
							Repartidor* tem3 = dynamic_cast<Repartidor*>(repartidores[i]);
							cout<<i<<": "<<repartidores[i]->getNombre()<<" | "<<tem3->getDinero()<<endl;
						}
						cin>>repartidoreEscogido;
						repartidor = repartidores[repartidoreEscogido];
					}
					Mesa* mesa = new Mesa(mesas.size(),repartidor,jugador);
					mesas.push_back(mesa);
					cout<<"Mesa creada !!"<<endl;

				}else{
					cout<<"No hay suficientes jugadores y repartidores para hacer una mesa!!"<<endl;
				}
				break;
			}
			case 2:{
				if(mesas.size()==0){
					cout<<"No hay mesas creadas !!"<<endl;
				}else{
					int mesaElegida;
					cout<<"Elija la mesa que quiere modificar:"<<endl;
					for (int i = 0; i < mesas.size(); i++)
					{
						cout<<"Mesa: "<<mesas[i]->getNumero()<<endl;;
					}
					cin>>mesaElegida;
				}
			}
		}
	}
}