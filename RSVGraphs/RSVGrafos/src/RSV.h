/*
 * Alumno: Sergio Orgaz Bravo
 * Correo: sorgazbr@alumnos.unex.es
 * Fecha: 13/05/2022
 * Descripción: Definición de la clase RSV, esta clase contiene un atributo Graph y los
 *              algoritmos necesarios para realizar las operaciones que nos pide el
 *              usuario desde el menú principal.
 */
#ifndef RSV_H_
#define RSV_H_


#include "listapi.h"
#include "graph.h"

#include <iostream>
using namespace std;

class RSV {
   
private:
	Graph<string> *mapaViajes;

	/*
	 * PRE={Que el fichero de texto se haya abierto correctamente}
	 * POST={Se encarga de cargar todo el fichero de texto a la clase principal}
	 * COMPL: O(n)
	 * DESC: Se encarga de leer toda la información de las ciudades y dejarla a disposición del usuario.
	 */
	void cargarCiudades();

	/*
	 * PRE={Que el fichero de texto se haya abierto correctamente}
	 * POST={Se encarga de cargar todo el fichero de texto a la clase principal}
	 * COMPL: O(n)
	 * DESC: Se encarga de leer toda la información de los viajes y dejarla a disposición del usuario.
	 */
	void cargarViajes();

	/*
	 * PRE={Que la lista no esté vacia}
	 * POST={Devuelve true si la ciudad se encuentra en la lista y false en caso contrario}
	 * COMPL: O(n)
	 * DESC: Realiza un recorrido por la lista en busca de la ciudad indicada
	 */
	bool pertenece(ListaPI<string> *listaCiudades, string ciudad);

	/*
	 * PRE={Que la lista no esté vacia}
	 * POST={Recorre en profundidad la lista}
	 * COMPL: O(n)
	 * DESC: Realiza un recorrido en profundidad de la lista que le pasamos por parametros.
	 */
	void recorridoProfundidad(string c, ListaPI<string> *visitados);

	/*
	 * PRE={Que la lista de ciudades no esté vacia}
	 * POST={Devuelve true si la lista de ciudades y false en caso contrario}
	 * COMPL: O(1)
	 * DESC: Nos dice si la ciudad que le pasamos por parámetros está en la lista de ciudades.
	 */
	bool existeCiudad(string ciudad);

public:

	/*
	 * CONSTRUCTOR POR DEFECTO:
	 * PRE={}
	 * POST={mapaViajes= new Graph<string>}
	 * COMPL: O(1)
	 * DESC: Carga las ciudades y viajes de los ficheros de texto.
	 */
	RSV        ();

    /*
     * PRE={Que la ciudad no esté en la lista de ciudades}
     * POST={Inserta una nueva ciudad en la lista de ciudades}
     * COMPL: O(1)
     * DESC: Inserta una nueva ciudad solo si esa ciudad no existe en la lista de ciudades.
     */
	void  insertarCiudad     (string ciudad);

    /*
     * PRE={Que el viaje entre las dos ciudades no exista en la lista}
     * POST={Inserta un nuevo viaje en la lista}
     * COMPL: O(1)
     * DESC: Inserta un nuevo viaje solo si ese viaje no existia previamente.
     */
	void  insertarViaje      (string cOrigen, string cDestino);

    /*
     * PRE={Que la lista de ciudades no esté vacia}
     * POST={Muestra por pantalla todas las ciudades que hay en la lista}
     * COMPL: O(n)
     * DESC: Muestra por pantalla toda la lista de ciudades.
     */
	void mostrarCiudad();

    /*
     * PRE={Que las listas no esten vacias}
     * POST={Devuelve el grado de las ciudades}
     * COMPL: O(n²)
     * DESC: Calcula el grado de cada uno de los vertices(ciudades) del grafo.
     */
	void grado();

    /*
     * PRE={Que la lista de ciudades no esté vacia}
     * POST={Devuelve true si las dos ciudades son adyacentes y false en caso contrario}
     * COMPL: O(1)
     * DESC: Nos dice si las dos ciudades que le pasamos por parametros son adyacentes o no.
     */
	bool adyacentes(string ciudad1, string ciudad2);

    /*
     * PRE={Que las listas de ciudades y adyacentes no estén vacías}
     * POST={Muestra por pantalla toda la información de la RSV}
     * COMPL: O(n²)
     * DESC: Muestra por pantalla toda la información de la RSV.
     */
	void mostrarTodo();

    /*
     * PRE={Que la ciudad exista y se haya realizado el recorrido en profundidad correctamente}
     * POST={Muestra por pantalla todos los destinos accesibles desde la ciudad que le indicamos}
     * COMPL: O(1)
     * DESC:Muestra por pantalla todos los destinos accesibles desde la ciudad que le indicamos
     */
	void destino();

    /*
     * DESTRUCTOR.
     * PRE={}
     * POST={Libera la memoria}
     * COMPL: O(1)
     * DESC:Libera la memoria
     */
	~RSV        ();
};


#endif /* RSV_H_ */
