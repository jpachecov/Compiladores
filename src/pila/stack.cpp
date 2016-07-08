/*
*	Clase que implementa una pila con listas ligadas
*/
#include <iostream>
#include "linked_list.cpp"
using namespace std;
template <typename Obj>

class stack{
private: 
	linked_list<Obj>* elems;
public:
	stack(){
		create();
	}
	/**
     *Construye una pila sin elementos.
     */    
     void create(){
     	elems= new linked_list<Obj>();
     }
     
    /**
     *Devuelve el tamaño actual de la pila.
     *@return int con el tamaño de la pila.
     */
     int size(){
     	return elems->size();
     }
     
    /**
     *Devuelve el valor logico que indica tiene o no elementos
     *@return true si esta vacia.
     */
     bool isEmpty(){
     	return elems->isEmpty();
     }
     
    /**
     *Insterta un objeto en el tope de la pila
     *@param el objeto que se insertara.
     */
     void push(Obj obj){
     	elems->add(1,obj);
     }

    /**
     *Devuelve el objeto que se enuentra en el tope de la pila.
     *@return objeto al inicio de la pila.
     */
     Obj peek(){
     	if(elems->isEmpty())
     		throw "Pila Vacia";
     	return elems->get(1);
     }

    /**
     *Devuelve y elimina el objeto o elemento que se encuentra en el 
     *top de la pila.  
     *@return el objeto que se elimina
     */
     Obj pop(){
     	if(elems->isEmpty()){
     		throw "Pila Vacia";
     	}
     	Obj temp = elems->get(1);
     	elems->remove(1);
     	return temp;
     }
     
    /**
     *Elimina todos los elementos existentes en la pila.
     */
     void popAll(){
     	elems->removeAll();
     }

     void printStack(){
     	elems->toString();
     } 
   };
