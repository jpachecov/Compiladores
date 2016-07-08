class lNode : public Nodo{
protected:
  lNode* father;
  int tamano;
public:

  vector<Nodo*> lista;
  lNode();
  void add(Nodo*);
  virtual void setFirstChild(Nodo*){};
  virtual void setLastChild(Nodo*){};
  void addRightChild(Nodo*);
  void addLeftChild(Nodo*);
  Nodo* getFather();
  void makeSiblings(Nodo*);
  void remove(Nodo*);
  void show();
  vector <Nodo*> daLista(){return lista;}
  virtual void Accept(NodeVisitor*){};
};
lNode::lNode(){
        tamano=0;
        }

void lNode::makeSiblings(Nodo* n2){
  father = new lNode();
  father->addLeftChild(this);
  father->addRightChild(n2);
}

Nodo* lNode::getFather(){
  return father;
}

void lNode::add(Nodo* Node){
	lista.push_back(Node);
        tamano+=1;
}

void lNode::addLeftChild(Nodo* n){
  vector<Nodo*>::iterator it;
  it = lista.begin();
  lista.insert(it,n);
        tamano+=1;      
}

void lNode::addRightChild(Nodo* n){
  vector<Nodo*>::iterator it;
  it = lista.end();
  lista.insert(it,n);
tamano+=1;
}

void lNode::remove(Nodo* Node){
	lista.erase(std::remove(lista.begin(), lista.end(), Node), lista.end());
}


void lNode::show(){

        for (int i = 0 ; i < lista.size() ; i+=1) {
        lista[i]->show();

        }


}
