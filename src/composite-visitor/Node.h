using namespace std;
class Nodo {
protected:
	string name;
public:
        string tipo;
        vector<Nodo*> lista;
	Nodo();
	Nodo(string n);
	virtual void setFirstChild(Nodo*){};
	virtual void setLastChild(Nodo*){};
	virtual void makeSiblings(Nodo*){};
	virtual void addRightChild(Nodo*){};
        virtual void addLeftChild(Nodo*){};
	virtual void add(Nodo*) {}
	virtual void remove(Nodo*) {}
	virtual void show() {}
	virtual Nodo* getFather(){};
	virtual vector<Nodo*> getList(){}
	virtual void Accept(NodeVisitor*){};
        vector <Nodo*> daLista(){};
        string nombre(){return name;}
};
Nodo::Nodo() {}
Nodo::Nodo(string n) : name(n) {}
        
