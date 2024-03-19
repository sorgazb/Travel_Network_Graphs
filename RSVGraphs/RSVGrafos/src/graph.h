/*
 * graph.h
 *
 *  Created on: Mar. 2021
 *      Author: Juan A. Rico (jarico@unex.es)
 */

#ifndef GRAPH_H_
#define GRAPH_H_

/*
 * Graph
 *
 * Undirected Graph Data structure.
 * Implemented with templates.
 * Implemented as an adjacency list.
 *
 */

#include "listapi.h"
#include <iostream>
#include <string>
using namespace std;


///////////////////////////////////////////////
////    CLass  Graph
///////////////////////////////////////////////

template<class TNODE>
class Graph {
   
private:
   
   class Node {
      
   private:
      
      TNODE         node;
      int           numAdj;
      ListaPI<TNODE> *adj;
      
   public:
      
      friend class Graph;
      
      Node () {
      }
      
      Node (TNODE v) {
         this->adj    = new ListaPI<TNODE> ();
         this->node   = v;
         this->numAdj = 0;
      }
            
      ListaPI<TNODE> *getAdj () {
         return this->adj;
      }
      
   };
   
   // Attributes
   ListaPI<Node>  *lnodes;
   unsigned int    nNodes;
   
   
public:
   
         Graph       ();
        ~Graph       ();
   
   bool  empty       ();
   int   numNodes    ();
   
   void  insertNode  (TNODE v);
   void  insertEdge  (TNODE v, TNODE w);
   
   void  removeNode  (TNODE v);
   void  removeEdge  (TNODE v, TNODE w);
   
   void  nodes       (ListaPI<TNODE> *& n);
   void  adjacents   (TNODE v, ListaPI<TNODE> *&adj);
};



/*
 CLASS Graph:

   Graph            ();
  ~Graph            ();

  // Descr.: return true if graph has no vertices (hence no edges)
  // Complexity: O(1)
  bool  empty       ();

  // Descr.: return the number of vertices in graph
  // Complexity: O(1)
  int   numNodes    ();

  // Descr.: insert a new node
  // Pre  = { v not in V }
  // Post = { numNodes() == OLD.numNodes() + 1, not empty() }
  // Complexity: O(1)
  void  insertNode  (TNODE v);

  // Descr.: insert a new edge
  // Pre  = { v, w in V && (v,w) not in E }
  // Post = { (v,w) in E, w in adjacents(v) && v in adjacents(w) }
  // Complexity: O(n), n == number of nodes
  void  insertEdge  (TNODE v, TNODE w);

  // Descr.: remove a node, and all the edges from/to the node
  // Pre  = { v in V }
  // Post = { numNodes() == OLD.numNodes() - 1, forall w: (v,w) and (w,v) not in E }
  // Complexity: O(n^2), n == number of vertices
  void  removeNode  (TNODE v);

  // Descr.: remove an edge
  // Pre  = { v, w in V}
  // Post = { (v,w) not in E, w not in adjacent(v) && v not in adjacents(w) }
  // Complexity: O(n^2), n == number of nodes
  void  removeEdge  (TNODE v, TNODE w);

  // Descr.: return (a copy of) the list of nodes
  // Pre  = { }
  // Post = { }
  // Complexity: O(n)
  void  nodes       (ListaPI<TNODE> *& n);

  // Descr.: return (a copy of) the list of adjacents of a node
  // Pre  = { v in V }
  // Post = { forall w: if (v,w) in E, w in adjacents(v) }
  // Complexity: O(n^2)
  void  adjacents   (TNODE v, ListaPI<TNODE> *&adj);

*/

//   Implementation

template<class TNODE>
Graph<TNODE>::Graph () {
   this->lnodes = new ListaPI<Node> ();
   this->nNodes = 0;
}


template<class TNODE>
Graph<TNODE>::~Graph () {
         
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) { // Nos movemos por la lista de nodos
            
      Node& x = this->lnodes->consultar(); // conseguimos un nodod
      
      ListaPI<TNODE> *a = x.getAdj(); // conseguimos su lista de adyacencia
      
      a->moverInicio(); // Vamos al inicio de la lusta de adyacencia
      while (! a->enFin()) {
            a->borrar(); // borramos, elemento a elemento, la lista de adyacencia
      }
      delete a; // borramos la lista de adyacencia
   
      this->lnodes->borrar(); // borramos la lista de nodos
   }
   
   delete this->lnodes; // borramos la lista de nodos
}


template<class TNODE>
bool Graph<TNODE>::empty () {
   return (this->nNodes == 0);
}


template<class TNODE>
int Graph<TNODE>::numNodes () {
   return this->nNodes;
}


template<class TNODE>
void Graph<TNODE>::insertNode (TNODE v) {
   
   Node node(v); // Creamos un nuevo nodo para insertar final de la lista de nodos
   
   this->lnodes->moverUltimo(); // nos vamos al final... apuntamos al último
   this->lnodes->avanzar(); // avanzamos
   this->lnodes->insertar(node); //insertamos el nodo
   
   this->nNodes++;
}


template<class TNODE>
void Graph<TNODE>::insertEdge (TNODE v, TNODE w) { // insertamos un arco entre dos vértices
      
   int count = 0;
   
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) {
      
      Node& x = this->lnodes->consultar();
      
      if (x.node == v) {
         
         x.adj->moverUltimo();
         x.adj->avanzar();
         x.adj->insertar(w);
         
         x.numAdj++;
         
         count++;
         
      } else if (x.node == w) {
         
         x.adj->moverUltimo();
         x.adj->avanzar();
         x.adj->insertar(v);
         
         x.numAdj++;
         
         count++;
      }
      
      if (count == 2) {
         break;
      }
      
      this->lnodes->avanzar();
   }
}


template<class TNODE>
void Graph<TNODE>::removeNode (TNODE v) {
         
   // First remove all edges to the node
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) {
      
      Node& x = this->lnodes->consultar(); //obtengo un nodo
            
      ListaPI<TNODE> *a = x.getAdj(); //obtengo su lista de adyacentes
      
      a->moverInicio(); // voy al inicio
      while (! a->enFin()) { 
         
         TNODE& i = a->consultar();
         
         if (i == v) { // encontré el adyacente a borrar y lo borro
            a->borrar();
            x.numAdj--;
            
         } else {
            a->avanzar();
         }
      }
      
      this->lnodes->avanzar();
   }
   
   // Second, remove the adyacents to the node v
   bool found = false;
   
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) {
      
      Node& x = this->lnodes->consultar();
      
      if (x.node == v) {
         
         found = true;
                  
         ListaPI<TNODE> *a = x.getAdj();
         
         a->moverInicio();
         while (! a->empty()) {
            a->borrar();
            x.numAdj--;
         }
         delete a;
         break;
      }
      
      this->lnodes->avanzar();
   }
   
   // Finally, remove node v
   if (found) {
   	this->lnodes->borrar();
   	this->nNodes--;
   }
}


template<class TNODE>
void Graph<TNODE>::removeEdge (TNODE v, TNODE w) {
         
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) {
      
      Node& x = this->lnodes->consultar();
      
      if ((x.node == v) || (x.node == w)) {
         
         ListaPI<TNODE> *a = x.getAdj();
         
         a->moverInicio();
         while (! a->enFin()) {
            
            TNODE& i = a->consultar();
            
            if ((i == w) || (i == v)) {
               a->borrar();
               x.numAdj--;
               break;
            }
            
            a->avanzar();
            
         }
      }
      
      this->lnodes->avanzar();
   }
    
}


template<class TNODE>
void Graph<TNODE>::nodes (ListaPI<TNODE> *& n) {
      
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) {
      
      Node& x = this->lnodes->consultar();
      
      n->moverUltimo();
      n->avanzar();
      n->insertar(x.node);
      
      this->lnodes->avanzar();
      
   }
   
}


template<class TNODE>
void Graph<TNODE>::adjacents (TNODE v, ListaPI<TNODE> *&adj) {
   
   this->lnodes->moverInicio();
   while (! this->lnodes->enFin()) {
      
      Node& x = this->lnodes->consultar();
      
      if (x.node == v) {
         
         ListaPI<TNODE> *a = x.getAdj();
         
         a->moverInicio();
         while (! a->enFin()) {
            
            TNODE& n = a->consultar();
            
            adj->moverUltimo();
            adj->avanzar();
            adj->insertar(n);
            
            a->avanzar();
            
         }
         
         break;
      }
      
      this->lnodes->avanzar();
   }
   
}


#endif /* GRAPH_H_ */
