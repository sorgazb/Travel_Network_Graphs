/*
 * Alumno: Sergio Orgaz Bravo
 * Correo: sorgazbr@alumnos.unex.es
 * Fecha: 13/05/2022
 * Descripción: Implementación de la clase RSV.
 */
#include "graph.h"
#include "RSV.h"
#include <fstream>
#include <iostream>
using namespace std;


void RSV::cargarCiudades() {
	ifstream flujoCiudades;
	string ciudad;
	flujoCiudades.open("ciudades.csv");
	if(flujoCiudades.is_open()){
		while(!flujoCiudades.eof()){
			getline(flujoCiudades,ciudad);
			if(!flujoCiudades.eof()){
				mapaViajes->insertNode(ciudad);
			}
		}
		flujoCiudades.close();
	}
}

void RSV::cargarViajes() {
	ifstream flujoViajes;
	string ciudadOrigen;
	string ciudadDestino;
	flujoViajes.open("viajes.csv");
	if(flujoViajes.is_open()){
		while(!flujoViajes.eof()){
			getline(flujoViajes, ciudadOrigen, ';');
			if(!flujoViajes.eof()){
				getline(flujoViajes, ciudadDestino);
				mapaViajes->insertEdge(ciudadOrigen, ciudadDestino);
			}
		}
		flujoViajes.close();
	}
}

bool RSV::pertenece(ListaPI<string> *listaCiudades, string ciudad) {
	bool enc=false;
	string aux;
	listaCiudades->moverInicio();
	while(!listaCiudades->enFin() && !enc){
		listaCiudades->consultar(aux);
		if(aux==ciudad){
			enc=true;
		}
		else{
			listaCiudades->avanzar();
		}
	}
	return enc;
}

void RSV::recorridoProfundidad(string c, ListaPI<string> *visitados) {
	ListaPI<string> *listaAdyacentes= new ListaPI<string>;
	string cAux;
	visitados->moverUltimo();
	visitados->avanzar();
	visitados->insertar(c);
	mapaViajes->adjacents(c, listaAdyacentes);
	listaAdyacentes->moverInicio();
	while(!listaAdyacentes->enFin()){
		listaAdyacentes->consultar(cAux);
		if(!pertenece(visitados, cAux)){
			recorridoProfundidad(cAux, visitados);
		}
		listaAdyacentes->avanzar();
	}
	delete listaAdyacentes;
}

bool RSV::existeCiudad(string ciudad) {
	bool enc=false;
	ListaPI<string> *listaCiudades= new ListaPI<string>;
	mapaViajes->nodes(listaCiudades);
	if(pertenece(listaCiudades, ciudad)){
		enc=true;
	}
	delete listaCiudades;
	return enc;
}

RSV::RSV() {
	mapaViajes= new Graph<string>;
	cargarCiudades();
	cargarViajes();
}

// opción 1
void RSV::insertarCiudad(string ciudad) {
	if(existeCiudad(ciudad)==false){
		mapaViajes->insertNode(ciudad);
		cout<<"La ciudad "<<ciudad<<" ha sido insertada en la lista de ciudades correctamente. "<<endl;
	}
	else{
		cout<<"Error.Esa ciudad YA existe."<<endl;
	}
}

// opción 2
void RSV::insertarViaje(string cOrigen, string cDestino) {
	if(adyacentes(cOrigen, cDestino)==false){
		mapaViajes->insertEdge(cOrigen, cDestino);
		cout<<"El viaje de "<<cOrigen<<" a "<<cDestino<<" ha sido insertado en la lista de viajes correctamente. "<<endl;
	}
	else{
		cout<<"Error.Ese viaje YA existe."<<endl;
	}
}

void RSV::mostrarCiudad() {
	ListaPI<string> *listaCiudades= new ListaPI<string>;
	string ciudad;
	mapaViajes->nodes(listaCiudades);
	listaCiudades->moverInicio();
	while(!listaCiudades->enFin()){
		listaCiudades->consultar(ciudad);
		cout<<"Ciudad: "<<ciudad<<endl;
		listaCiudades->avanzar();
	}
	delete listaCiudades;
}

void RSV::grado() {
	string ciudadAux;
	int cont;
	ListaPI<string> *listaCiudades= new ListaPI<string>;
	ListaPI<string> *listaAdyacentes= new ListaPI<string>;
	mapaViajes->nodes(listaCiudades);
	listaCiudades->moverInicio();
	while(!listaCiudades->enFin()){
		listaCiudades->consultar(ciudadAux);
		mapaViajes->adjacents(ciudadAux, listaAdyacentes);
		cont=0;
		listaAdyacentes->moverInicio();
		while(!listaAdyacentes->vacia()){
			cont++;
			listaAdyacentes->borrar();

		}
		cout<<ciudadAux<<"-Grado:"<<cont<<endl;
		listaCiudades->avanzar();
	}
	delete listaCiudades;
	delete listaAdyacentes;
}

bool RSV::adyacentes(string ciudad1, string ciudad2) {
	bool enc=false;
	ListaPI<string> *listaCiudades= new ListaPI<string>;
	mapaViajes->adjacents(ciudad1, listaCiudades);
	if(pertenece(listaCiudades, ciudad2)){
		enc=true;
	}
	delete listaCiudades;
	return enc;
}

void RSV::mostrarTodo() {
	string ciudadAux;
	string adyacenteAux;
	ListaPI<string> *listaCiudades= new ListaPI<string>;
	ListaPI<string> *listaAdyacentes= new ListaPI<string>;
	mapaViajes->nodes(listaCiudades);
	listaCiudades->moverInicio();
	while(!listaCiudades->enFin()){
		cout<<"---------------------"<<endl;
		listaCiudades->consultar(ciudadAux);
		mapaViajes->adjacents(ciudadAux, listaAdyacentes);
		cout<<"-Ciudad: "<<ciudadAux<<endl;
		cout<<"-Ciudades Adyacentes: "<<endl;
		listaAdyacentes->moverInicio();
		while(!listaAdyacentes->enFin()){
			listaAdyacentes->consultar(adyacenteAux);
			cout<<" "<<adyacenteAux<<"\n";
			listaAdyacentes->borrar();
		}
		listaCiudades->avanzar();
	}
	delete listaCiudades;
	delete listaAdyacentes;
}

void RSV::destino() {
	string ciudad;
	cout<<"Introduce el nombre de la ciudad la cual quieres mostrar sus destinos. "<<endl;
	getline(cin,ciudad);
	ListaPI<string> *listaCiudades= new ListaPI<string>;
	string ciudadAux;
	recorridoProfundidad(ciudad, listaCiudades);
	cout<<"Las ciudades destino desde "<<ciudad<<" son: "<<endl;
	listaCiudades->moverInicio();
	while(!listaCiudades->enFin()){
		listaCiudades->consultar(ciudadAux);
		if(ciudad!=ciudadAux){
			cout<<ciudadAux<<" ";
		}
		listaCiudades->avanzar();
	}
	delete listaCiudades;
}

RSV::~RSV() {
	delete mapaViajes;
}

