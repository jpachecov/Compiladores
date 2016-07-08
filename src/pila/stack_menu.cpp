/*
*	Menu para interactuar con las operaciones del stacks
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctype.h>
#include "stack.cpp"
#include <stdlib.h>
#include <stdio.h> 

using namespace std;

int main(){
	stack<int> s;
	char *ord;
	char car; 
	int out=0;
	cout <<"Introduzca caracteres o numeros y pulse Enter"<<endl;
	cout <<"numero: push en la pila."<<endl;
	cout <<"+: suma los dos ultimos elementos de la pila."<<endl;
	cout <<"d: muestra los elementos de la pila, sin borrarlos."<<endl;
	cout <<"x: Salir del programa."<<endl;
	cout <<"-------------------"<<endl;
	cout <<""<<endl;
	do{
		try{
		string in;
		cin>> in;
		ord=strdup(in.c_str());
		car=ord[0];
		if(isdigit(car)){
			int number=atoi(ord);
			s.push(number);
		}else{
			switch(car) {
				case 'x': 
					exit(0);
				break;
				case '+': 
					if(s.size()>1){
						int a=s.pop();	
						int b=s.pop();
						s.push(a+b);
					}else{ 
						cout <<"Necesita mas operadores para realizar esta operacion"<<endl;
					}
				break;
				case 'd': 
					s.printStack();
				break;
				default: puts("Error");
				}
		}
	}catch(std::exception caught){ // not quite sure the syntax is ok here...
    
 	 }
	}while(out==0);

	return 0;
}