/*
*   Clase que implementa un nodo
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename Obj>
class Node{
private:
	Node<Obj>* next;
public:
    Obj element;
	Node(Obj e){
        this->element=e;
        this->next=NULL;
    }

    Node(Obj e, Node<Obj>* sig){
        this->element=e;
        this->next=sig;
    }

    Node<Obj>* daSiguiente(){
        return this->next;
    }

    void cambiaSiguiente(Node<Obj>* sig){
        this->next=sig;
    }
    
    void cambiaElemento(Obj nvo){
        this->element=nvo;
    }
    Obj daElemento(){
    return this->element;
    }
};
