#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pila/stack.cpp"
#define TAM_MAX 128
#define C 0.156489763561
using namespace std;

/**
 * Clase Simbolo que contiene los campos requeridos, tales como
 * nombre, tipo y valor.
 */
class Simbolo {
public:
  const char* nombre;
  const char* tipo;
  void* valor;
  Simbolo(const char*,const char*, void*);
  const char* daNombre(){ return nombre;}
  const char* daTipo(){return tipo;}
  void* daValor(){return valor;}
};

/* Constructor */
Simbolo::Simbolo(const char* nom, const char* tip, void* val){
  nombre = nom;
  tipo = tip;
  valor = val;
}

/**
 * Clase Record que sera con la que trabaje directamente
 * la tabla de simbolos.
 * Contiene un apuntador a un objeto de tipo Simbolo,
 * un entero que representa el nivel lexico en 
 * donde esta declarado el simbolo y  un apuntador
 * al siguiente Record. 
 */
class Record {
public:
  Simbolo *s;
  int nivelLexico;
  Record *siguiente;
  Record(Simbolo*, int);
  const char* daNombre(){return s->daNombre();}
  int daNivel(){return nivelLexico;}
  char* toString();
};

/*Constructor*/
  Record::Record(Simbolo *sim, int nivel){
    s = sim;
    nivelLexico = nivel;
    siguiente = NULL;
  }

/**
 * Devuelve la representacion en cadena de un Record
 * con el siguiente formato:
 * nombre nivel nombreRecordSiguiente nivelRecordSiguiente
 * Por ejemplo:   x 3 c 2
 * Es decir, el Record tiene una simbolo de nombre "x", en el nivel Lexico 3,
 * y tiene un apuntador al Record siguiente que tiene un simbolo  de nombre "c"
 * en el nivel lexico 2.
 */
char* Record::toString(){
  char *resp;
  resp= new char;
  strcpy(resp,s->daNombre());
  std::string num = std::to_string(nivelLexico);
  const char* nuum = num.c_str();
  strncat(resp," ",1);
  strncat(resp,nuum, strlen(nuum));
  
  if(siguiente == NULL){
    strncat(resp," null ",strlen(" null "));
  } else {
    strncat(resp," ",1);
    strncat(resp, siguiente->daNombre(), strlen(siguiente->daNombre()));
    std::string num = std::to_string(siguiente->daNivel());
    const char* nuum = num.c_str();
    strncat(resp," ",1);
    strncat(resp,nuum, strlen(nuum));
  } 

  return resp;
}

/**
 * Clase tablaSimbolos que representa a la tabla de simbolos
 * Usa una pila de apuntadores a objetos de tipo Record, 
 * para almacenar los Records.
 * Su funcionamiento es tal y como se describe 
 * en el Apendice B del libro de Cooper, paginas 758-759
 */
class tablaSimbolos {
public:
  int nivelActual;
  Record* tablahash [TAM_MAX];
  stack<Record*> pila;
  tablaSimbolos ();
  Record* lookUp(const char*);
  void insert(Simbolo*);
  void openScope();
  void closeScope();
  bool declaredLocally(const char*);
  int aplicaHash(const char*);
  int obtenRepresentacion(const char*);
};

/*Constructor*/
tablaSimbolos::tablaSimbolos() {
  nivelActual = -1;
  int i;
  for(i = 0; i < TAM_MAX; i+=1){
    tablahash[i] = NULL;
  }
}

/**
 * Metodo que regresa un apuntador (pueder ser nulo) 
 * a una estrauctura de tipo Record si es que el nombre
 * que recibe de parametro esta declarado.
 */
Record* tablaSimbolos::lookUp(const char* nombre){

  Record *r = NULL;
  r = tablahash[aplicaHash(nombre)];
  
  if(r == NULL) return NULL;
  while(r != NULL) {

    if(strcmp((r->s)->daNombre(),nombre) == 0){
      return r;    

    }
    r = r->siguiente;
  }
  return NULL;
}

/**
 * Metodo que inserta un nuevo Record a la
 * tabla de simbolos. Esto incluye, meterlo al
 * stack y actualizar la referencia al siguiente si
 * es que es necesario.
 */
void tablaSimbolos::insert(Simbolo* s){
  Record *r = new Record(s,nivelActual);

  Record *re = tablahash[aplicaHash(s->daNombre())];
  if(re == NULL) {

    tablahash[aplicaHash(s->daNombre())] = r;
    pila.push(r);
   
  } else {
    r->siguiente = re;
    tablahash[aplicaHash(s->daNombre())] = r;
    pila.push(r);
  }

}

/**
 * Metodo que abre un nuevo alcance.
 * Por nuestra implementacion, el metodo
 * es muy simple y solo aumenta en 1 la variable
 * que indica el nivel lexico actual.
 */
void tablaSimbolos::openScope(){
  nivelActual+=1;
}

/**
 * MEtodo que cierra el alcance actual.
 * Hace pop sobre el stack y actuliza 
 * referencias si es necesario.
 */
void tablaSimbolos::closeScope(){
  if(pila.isEmpty()) return;
  Record *r = NULL;
  r = pila.peek();

  while(r->daNivel() == nivelActual && pila.size()!=0 ){
    tablahash[aplicaHash(r->daNombre())] = r->siguiente;
    r->siguiente = NULL;
    //Desalojar a r o  mantenerlo en otro lugar
    delete r;
    pila.pop();
    r = pila.peek();
  }
  nivelActual+=-1;
}

/**
 * Metodo que regresa true si es que nombre
 * esta declarada dentro del alcance actual.
 * Regresa false en cualquier otro caso.
 */
bool tablaSimbolos::declaredLocally(const char* nombre){

  if(tablahash[aplicaHash(nombre)] == NULL) return false;
  return tablahash[aplicaHash(nombre)]->daNivel() == nivelActual;
  
}

/**
 * Metodo que obtiene una representacion de la cadena
 * nombre como entero.
 */
int tablaSimbolos::obtenRepresentacion(const char *nombre){
  int valor = 0;
  int i;
  for (i = 0; i < strlen(nombre); i+=1){
    valor+=(int)nombre[i]*((strlen(nombre)-i)^2);
  }
  return valor;
}

/**
 * Funcion hash
 */
int tablaSimbolos::aplicaHash(const char* nombre){
  int i = obtenRepresentacion(nombre);
  return (int)floor(TAM_MAX*((i*C)-floor(i*C)));
}

/* main */
/*
int main(){
  
  Simbolo w ("w","int",(void*)"algo");
  Simbolo x ("x","int",(void*)"algo");
  Simbolo exm ("exm","int",(void*)"algo");
  Simbolo a ("a","int",(void*)"algo");
  Simbolo b ("b","int",(void*)"algo");
  Simbolo c ("c","int",(void*)"algo");
  Simbolo b1 ("b","int",(void*)"algo");
  Simbolo z ("z","int",(void*)"algo");
  Simbolo a1 ("a","int",(void*)"algo");
  Simbolo x1 ("x","int",(void*)"algo");
  Simbolo c1 ("c","int",(void*)"algo");
  Simbolo x2 ("x","int",(void*)"algo");

  tablaSimbolos t;
  t.openScope();
  t.insert(&w);
  t.insert(&x);
  t.pila.printStack();
  t.insert(&exm);
  t.openScope();
  t.insert(&a);
  t.insert(&b);
  t.pila.printStack();
  t.insert(&c);
  t.openScope();
  t.insert(&b1);
  t.insert(&z);
  t.closeScope();
  t.openScope();
  t.insert(&a1);
  t.insert(&x1);
  t.openScope();
  t.insert(&c1);
  t.insert(&x2);
  
  t.pila.printStack();
}
*/
