/*
 * Alumno: Sergio Orgaz Bravo
 * Correo: sorgazbr@alumnos.unex.es
 * Fecha: 13/05/2022
 * Descripción: Clase principal, se encarga de ejecutar el menú con las diferentes opciones del programa.
 */
#include <iostream>
#include <string>
#include <cstdlib>

#include "RSV.h"
using namespace std;

// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "______________ MENU PRINCIPAL ______________" << endl << endl;

		cout << "     1. Insertar ciudad                        " << endl;
		cout << "     2. Insertar viaje (crear arco)            " << endl;
		cout << "     3. Mostrar ciudades                       " << endl;
		cout << "     4. Grado de todos los vértices (ciudades) " << endl;
		cout << "     5. Adyacentes                             " << endl;
		cout << "     6. Mostrar todo                           " << endl;
		cout << "     7. Mostrar destinos desde una ciudad      " << endl;

		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 8));

	return opcion;
}
int main() {
	RSV *rsv= new RSV;
	string ciudad;
	string ciudadOrigen;
	string ciudadDestino;
	bool terminar = false;
	int opcion;

	while (!terminar) {
		opcion = menu();

		switch (opcion) {
		case 1:
			cout<<"OPCION 1 -> INSERTAR CIUDAD: "<<endl;
			cout<<"Introduce el nombre de la ciudad a insetar: "<<endl;
			getline(cin,ciudad);
			rsv->insertarCiudad(ciudad);
			break;
		case 2:
			cout<<"OPCION 2 -> INSERTAR VIAJE: "<<endl;
			cout<<"Introduce la Ciudad Origen del viaje: "<<endl;
			getline(cin,ciudadOrigen);
			cout<<"Introduce la Ciudad Destino del viaje: "<<endl;
			getline(cin,ciudadDestino);
			rsv->insertarViaje(ciudadOrigen, ciudadDestino);
			break;
		case 3:
			cout<<"OPCION 3 -> MOSTRAR CIUDADES: "<<endl;
			rsv->mostrarCiudad();
			break;
		case 4:
			cout<<"OPCION 4 -> GRADO DE TODOS LOS VERTICES: "<<endl;
			rsv->grado();
			break;
		case 5:
			cout<<"OPCION 5 -> ADYACENTES: "<<endl;
			cout<<"Introduce el nombre de la primera ciudad: "<<endl;
			getline(cin,ciudadOrigen);
			cout<<"Introduce el nombre de la segunda ciudad: "<<endl;
			getline(cin,ciudadDestino);
			if(rsv->adyacentes(ciudadOrigen, ciudadDestino)){
				cout<<"Son adyacentes. "<<endl;
			}
			else{
				cout<<"No son adyacentes. "<<endl;
			}
			break;
		case 6:
			cout<<"OPCION 6 -> MOSTRAR TODO: "<<endl;
			rsv->mostrarTodo();
			break;
		case 7:
			cout<<"OPCION 7 -> MOSTRAR DESTINOS DESDE UNA CIUDAD: "<<endl;
			rsv->destino();
			break;
		case 0:
			delete rsv;
			terminar = true;
			break;

		default:
			break;

		}
	}


	return 0;
}

