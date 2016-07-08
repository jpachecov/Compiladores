#include "MASTBuilder.h"

using namespace std;


int main() {
	MASTBuilder* mast= new MASTBuilder();
	Nodo* plus =mast->bPlusNode();
	Nodo* n1 = mast->bIntNode(5);
	Nodo* n2  =mast->bIntNode(10);
	Nodo* n3 = mast->bIntNode(15);
	
	Nodo* plus2 = mast->bPlusNode();
	plus->setFirstChild(n1);
	plus->setLastChild(plus2);
	plus2->setFirstChild(n2);
	plus2 -> setLastChild(n3);
	
	cout << (((PlusNode*)plus)->lista).size() << endl;
	vector<Nodo*> li = ((PlusNode*)plus)->lista;
	li[1]->show();
	return 0;
}
