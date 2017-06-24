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

int sumarMano(vector<Carta*>&);
void menuAdmin(vector<Persona*>&,vector<Persona*>&, vector<Mesa*>&);
void Jugar(Mesa*);
void imprimirMano(vector<Carta*>&);

int main(){
	

	vector<Persona*>jugadores;
	vector<Persona*>jugadoresTem;

	vector<Persona*>administradores;
	
	vector<Persona*>repartidores;
	vector<Persona*>repartidoresTem;
	
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
		cin>>op;
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
						cout<<"Ingrese el ID(4 numeros): ";
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

						Persona* tem = new Administrador(nombre,edad,id,experiencia,rango,sueldo);
						administradores.push_back(tem);
						break;
					}
					case 2:{
						string nombre;
						int edad;
						int id;
						string lugar;
						string apodo;
						double dinero;
						cout<<"Ingrese el nombre: ";
						cin>>nombre;
						cout<<"Ingrese la edad: ";
						cin>>edad;
						cout<<"Ingrese el ID(4 numeros): ";
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
						jugadoresTem.push_back(tem);
						break;

					}
					case 3:{
						string nombre;
						int edad;
						int id;
						string dificultad;
						double dinero;
						cout<<"Ingrese el nombre: ";
						cin>>nombre;
						cout<<"Ingrese la edad: ";
						cin>>edad;
						cout<<"Ingrese el ID(4 numeros): ";
						cin>>id;
						while(id>9999 || id<1000){
							cout<<"El id solo puede contener 4 numeros, ingrese uno nuevo: ";
							cin>>id;
						}
						cout<<"Ingrese la dificultad del repartidor: ";
						cin>>dificultad;
						cout<<"Ingrese el dinero: ";
						cin>>dinero;
						Persona* tem = new Repartidor(nombre,edad,id,dificultad,dinero);
						repartidores.push_back(tem);
						repartidoresTem.push_back(tem);
						break;
					}
				}
				break;
			}
			case 2:{
				int login;
				cout<<"1. Login como administrador"<<endl;
				cout<<"2. Login como jugador"<<endl;
				cin>>login;

				switch(login){
					case 1:{
						string nombreTem;
						int idTem;

						cout<<"Ingrese el nombre: ";
						cin>>nombreTem;

						cout<<"Ingrese el id: ";
						cin>>idTem;

						Persona* raiz;
						for (int i = 0; i < administradores.size(); i++)
						{
							if(administradores[i]->getNombre().compare(nombreTem)==0 && administradores[i]->getID()==idTem){
								menuAdmin(jugadores,repartidores,mesas);
								break;
							}
						}
						break;

					}
					case 2:{
						string nombreTem;
						int idTem;

						cout<<"Ingrese el nombre: ";
						cin>>nombreTem;

						cout<<"Ingrese el id: ";
						cin>>idTem;

						Persona* raiz;

						for (int i = 0; i < jugadores.size(); i++){
							if(jugadores[i]->getNombre().compare(nombreTem)==0 && jugadores[i]->getID()==idTem){
								bool vivo = true;
								int opJugador;
								while(vivo){
									cout<<"------Menu Jugador------"<<endl;
									cout<<"1. Jugar"<<endl;
									cout<<"2. Salir"<<endl;
									cin>>opJugador;
									
									switch(opJugador){
										case 1:{
											if(mesas.size()!=0){
												Mesa* mesaParaJugar;
												for(int i=0; i<mesas.size();i++){
													if(mesas[i]->getJugador()->getID() == jugadores[i]->getID()){
														mesaParaJugar = mesas[i];
														break;
													}
												}
												if(mesaParaJugar == NULL){
													cout<<"No está en ninguna mesa !!"<<endl;
												}else{
													Jugar(mesaParaJugar);
												}
											}else{
												cout<<"NO hay mesas!!"<<endl;
											}

											break;
										}
										case 2:{
											vivo = false;
											break;
										}
									}

									

								}
								break;
							}
						}
						break;
					}

				}
				break;	

			}
			case 3:{
				cout<<"Ha salido !!"<<endl;
				on = false;
				break;
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
					cout<<"Elija la mesa que quiere eliminar:"<<endl;
					for (int i = 0; i < mesas.size(); i++)
					{
						cout<<"Mesa: "<<mesas[i]->getNumero()<<endl;;
					}
					cin>>mesaElegida;
					mesas.erase(mesas.begin()+mesaElegida);
					cout<<"Mesa eliminada !!"<<endl;

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

void Jugar(Mesa* mesa){


	vector<Carta*>manoJugador;
	vector<Carta*>manoCasa;


	int numJugador = 0;
	int numCasa = 0;
	bool jugando = true;

	Jugador* jugador = dynamic_cast<Jugador*>(mesa->getJugador());
	Repartidor* repartidor = dynamic_cast<Repartidor*>(mesa->getRepartidor());

	repartidor->getDeck()->shuffle();

	vector<Carta*>baraja = repartidor->getBaraja();

	/*Carta* retVal = baraja->getCartas().back();
	baraja->getCartas().pop_back();*/

	Carta* carta1 = baraja.back();
	baraja.pop_back();
	Carta* carta2 = baraja.back();
	baraja.pop_back();

	Carta* carta3 = baraja.back();
	baraja.pop_back();
	Carta* carta4 = baraja.back();
	baraja.pop_back();

	manoJugador.push_back(carta1);
	manoJugador.push_back(carta2);

	manoCasa.push_back(carta3);
	manoCasa.push_back(carta4);

	/*cout<<sumarMano(manoJugador)<<endl;;
	cout<<sumarMano(manoCasa)<<endl;*/
	cout<<"Dinero del jugador: "<<endl;
	cout<<jugador->getDinero()<<endl;
	cout<<"Dinero de la casa: "<<endl;
	cout<<repartidor->getDinero()<<endl;
	
	int turno = 1;
	while(jugando){

		if(numJugador > 21 || numCasa > 21){
			jugando = false;
		}else{
			cout<<"Mano del jugador: "<<endl;
			imprimirMano(manoJugador);
			cout<<"-------------------"<<endl;
			cout<<"Mano de la casa: "<<endl;
			cout<<manoCasa[0]->getValor2()<<" "<<manoCasa[0]->getSimbolo()<<endl;
			cout<<"-------------------"<<endl;
			int apuesta;
			if(turno == 1){
				cout<<"Ingrese su apuesta: ";
				cin>>apuesta;
				while(apuesta>jugador->getDinero() || apuesta>repartidor->getDinero()){
					cout<<"La apuesta es demasiado alta, ingrese otra apuesta: ";
					cin>>apuesta;
				}
				int jalar=0;
				while(jalar!=2){
					cout<<"Jugador, desea tomar otra carta? "<<endl;
					cout<<"1. Si"<<endl;
					cout<<"2. No"<<endl;
					cin>>jalar;
					if(jalar == 1){
						Carta* tem = baraja.back();
						baraja.pop_back();
						manoJugador.push_back(tem);
						cout<<"Nueva mano: "<<endl;
						imprimirMano(manoJugador);
						cout<<"------------------"<<endl;
						numJugador = sumarMano(manoJugador);
						if(numJugador > 21 || numCasa > 21){
							cout<<"Se ha pasado de 21!! Perdió el juego!!"<<endl;
							jugador->setDinero(apuesta);
							repartidor->Ganar(apuesta);
							jugando = false;
							jalar = 2;
						}
					}else{
						jalar = 2;
						numJugador = sumarMano(manoJugador);
					}
				}
				turno++;

			}else{
				int casaJala;
				cout<<"Desea la casa tomar otra carta ?"<<endl;
				cout<<"1. Si"<<endl;
				cout<<"2. NO"<<endl;
				cin>>casaJala;
				if(casaJala==1){
					cout<<"Carta tomada por la casa: "<<endl;
					cout<<baraja.back()->getValor2()<<" "<<baraja.back()->getSimbolo()<<endl;
					Carta* tem = baraja.back();
					baraja.pop_back();
					manoCasa.push_back(tem);
				}
				numCasa = sumarMano(manoCasa);
				if(numCasa > 21){
					cout<<"Perdió la casa !!"<<endl;
					jugador->Ganar(apuesta*2);
					repartidor->Perder(apuesta);
					jugando = false;
				}else if(numCasa > numJugador){
					cout<<"Perdió el jugador!!"<<endl;
					jugador->setDinero(apuesta);
					repartidor->Ganar(apuesta);
					jugando = false;
				}else{
					cout<<"Perdió la casa !!"<<endl;
					jugador->Ganar(apuesta*2);
					repartidor->Perder(apuesta);
					jugando = false;
				}
				turno = 1;
			}
		}

		cout<<"Dinero del jugador: "<<endl;
		cout<<jugador->getDinero()<<endl;
		cout<<"Dinero de la casa: "<<endl;
		cout<<repartidor->getDinero()<<endl;


	}


}

int sumarMano(vector<Carta*>& mano){

	int ret = 0;

	for(int i=0; i<mano.size();i++){
		ret += mano[i]->getValor();
	}

	return ret;

}

void imprimirMano(vector<Carta*>& mano){
	for (int i = 0; i < mano.size(); i++){
		cout<<mano[i]->getValor2()<<" "<<mano[i]->getSimbolo()<<endl;
	}
}

