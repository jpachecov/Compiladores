/*
*	Clase que implementa una lista ligada
*/
#include "node.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
template <typename Obj>
class linked_list{
private:
	Node<Obj>* head;
	int numElems;
public:

	linked_list(){
		create();
	}
	/**
     *Inicializa las variables head y numElems
     */
	void create(){
		numElems=0;
		head=0;
	}
	 /**
     *Metodo que devuelve un valor logico si la lista esta vacia o no.
     *@return true si esta vacia, false de lo contrario.
     */
	bool isEmpty(){
		return (numElems==0);
	}
	/**
     *Devuelve el tamanio de la lista.
     *@return el numero de elementos
     */
	int size(){
    	return numElems;
    }
    
    /**
     *Metodo que remueve todos los elementos de la lista.
     */
    void removeAll(){
        numElems=0;
        head=0;
    }               
    
    // devuelve el nodo en la posicion i
    Node<Obj>* find(int i){
        Node<Obj>* actual = head;
        int paso=1;
        while(paso<i){
            actual=actual->daSiguiente();
            paso++;
        }
        return actual;
    }
    
    /*
     *Metodo que devuelve el objeto en alguna posicion i de la lista.
     */
    Obj get(int i){
        if(numElems==0)
           throw "Out of range";         
        if(i>=1 && i<=numElems){
            Node<Obj>* actual=find(i);
            return actual->daElemento();            
        }
        else{
        	throw "Indice invalido";
        }
    }    
    
    /**
     *Metodo que agrega un objet en alguna posicion dada.
     */
   	void add(int i,Obj obj){
        if(i>=1 && i<=this->numElems+1){
            if(i==1){
                Node<Obj>* nuevo = new Node<Obj>(obj,head);
	        	head=nuevo;
            }
            else{
				Node<Obj>* previo= find(i-1);
				Node<Obj>* nuevo = new Node<Obj>(obj,previo->daSiguiente());
				previo->cambiaSiguiente(nuevo);
            }
            numElems++;
        }
        else{
            throw "Indice invalido";
        }	
    }
    
    /*
     *Metodo que remueve algun objeto en la posicion i dada.
     */
    void remove(int i){
        if(numElems==0)
            throw "Indice invalido. Lista vacia";                
        if(i>=1 && i<=numElems){
            if(i==1){
                head=head->daSiguiente();
	    }
	    else{
                Node<Obj>*  previo=find(i-1);
                Node<Obj>*  actual=previo->daSiguiente();
				previo->cambiaSiguiente(actual->daSiguiente());
	    }
	   	 	numElems--;
        }
        else{
	    	throw "Indice invalido";
        }
    }
    /**
    *imprime los elementos de la lista
    */
    void toString(){
		for(int i=1; i<=size();i++){
		  cout << "in_stack: "<<get(i)->toString()<< endl;
		}
    }

};
/*
int main(int argc, char const *argv[]){
	linked_list<int> lista;
	lista.add(1,5);
	lista.add(2,7);
	lista.add(3,8);
	lista.add(4,9);
	lista.add(5,10);
	lista.add(6,11);
	lista.toString();
	return 0;
}*/
