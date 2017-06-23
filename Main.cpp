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
#include <algorithm>

using namespace std;

int main(){
	void menuAdmin(vector<Persona*>&,vector<Persona*>&, vector<Mesa*>&);

	vector<Persona*>jugadores;
	vector<Administrador*>administradores;
	vector<Persona*>repartidores;
	vector<Mesa*>mesas;

	srand ( unsigned ( std::time(0) ) );

	/*Baraja* baraja = new Baraja();

	int num = baraja->getSize();

	baraja->shuffle();

	for(int i = 0;i< num;i++){

		cout<<baraja->getCarta(i)->getValor2()<<"  "<<baraja->getCarta(i)->getColor()<<"  "<<baraja->getCarta(i)->getSimbolo()<<endl;
	}*/
	bool on = true;
	while(on){
		int op;
		cout<<"------Menu principal-----"<<endl;
		cout<<"1. Crear una persona"<<endl;
		cout<<"2. Login"<<endl;
		cout<<"3. Salir"<<endl;

		switch(op){
			case 1:{
				int crear;
				cout<<"1. Crear administrador"<<endl;
				cout<<"2. Crear jugador"<<endl;
				cout<<"3. Crear repartidor"<<endl;
				cin>>crear;

				switch(crear){
					case 1:{
						string nombre;
						int edad;
						int id;
						int experiencia;
						string rango;
						double sueldo;
						cout<<"Ingrese el nombre: ";
						cin>>nombre;
						cout<<"Ingrese la edad: ";
						cin>>edad;
						cout<<"Ingrese el ID(4 numeros)";
						cin>>id;
						while(id>9999){
							cout<<"El id solo puede contener 4 numeros, ingrese uno nuevo: ";
							cin>>id;
						}
						cout<<"Ingrese la experiencia: ";
						cin>>experiencia;
						cout<<"Ingrese el rango en la empresa: ";
						cin>>rango;
						cout<<"Ingrese el sueldo: ";
						cin>>sueldo;

						Administrador* tem = new Administrador(nombre,edad,id,experiencia,rango,sueldo);
						administradores.push_back(tem);
						break;
					}
					case 2:{
						string nombre;
						int edad;
						string id;
						string lugar;
						string apodo;
						double dinero;
						cout<<"Ingrese el nombre: ";
						cin>>nombre;
						cout<<"Ingrese la edad: ";
						cin>>edad;
						cout<<"Ingrese el ID(4 numeros)";
						cin>>id;
						while(id>9999){
							cout<<"El id solo puede contener 4 numeros, ingrese uno nuevo: ";
							cin>>id;
						}
						cout<<"Ingese el lugar de procedencia: ";
						cin>>lugar;
						cout<<"Ingrese el apodo del jugador: ";
						cin>>apodo;
						cout<<"Ingrese el dinero del jugador: ";
						cin>>dinero;

						Persona* tem = new Jugador(nombre,edad,id,lugar,apodo,dinero);
						jugadores.push_back(tem);

					}
					case 3:{
						string nombre;
						int edad;
						string id;
						cout<<"Ingrese el nombre: ";
						cin>>nombre;
						cout<<"Ingrese la edad: ";
						cin>>edad;
						cout<<"Ingrese el ID(4 numeros)";
						cin>>id;
						while(id>9999){
							cout<<"El id solo puede contener 4 numeros, ingrese uno nuevo: ";
							cin>>id;
						}
					}
				}
			}
		}
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
					string tipo;
					int op2;
					cout<<"Elija el tipo de mesa: "<<endl;
					cout<<"1. VIP"<<endl;
					cout<<"2. Clásica"<<endl;
					cout<<"3. Viajera"<<endl;
					cin>>op2;
					if(op2==1){
						tipo = "VIP";
					}
					if(op2 == 2){
						tipo = "Clásica";
					}
					if(op2==3){
						tipo = "Viajera";
					}
					Mesa* mesa = new Mesa(mesas.size(),repartidor,jugador,tipo);
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
					string tipo;
					int op2;
					cout<<"Elija el tipo de mesa: "<<endl;
					cout<<"1. VIP"<<endl;
					cout<<"2. Clásica"<<endl;
					cout<<"3. Viajera"<<endl;
					cin>>op2;
					if(op2==1){
						tipo = "VIP";
					}
					if(op2 == 2){
						tipo = "Clásica";
					}
					if(op2==3){
						tipo = "Viajera";
					}
					Mesa* mesa = new Mesa(mesas.size(),repartidor,jugador,tipo);
					replace (mesas.begin(), mesas.end(), mesas[mesaElegida], mesa);
					cout<<"Mesa cambiada !!"<<endl;
					
				}
				break;
			}
			case 3:{
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
					mesas.erase(mesas.begin()+mesaElegida);

				}
				break;
			}
			case 4:{
				vivo = false;
				cout<<"Ha salido del menu de admin"<<endl;
				break;
			}
		}
	}
}