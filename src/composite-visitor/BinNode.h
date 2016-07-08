class BinNode : public lNode{
protected:
//	vector<Nodo*> lista;
        int tamano;
public:
  	vector<Nodo*> lista;

  BinNode();
  void setFirstChild(Nodo*);
  void setLastChild(Nodo*);
  void remove(Nodo*);
  void show();
  vector<Nodo*> daLista(){
        return lista;
        };
        
  virtual void Accept(NodeVisitor*){};
};

BinNode::BinNode(){
        tamano = 0;
        }

void BinNode::setFirstChild(Nodo* n){
  vector<Nodo*>::iterator it;
  it = lista.begin();
  lista.insert(it,n);
  /*if(tamano < 2){
        lista.push_back(n);
        tamano+=1;
        return;        
   }*/
}

void BinNode::setLastChild(Nodo* n){
  vector<Nodo*>::iterator it;
  it = lista.end();
  lista.insert(it,n);
}


void BinNode::remove(Nodo* Node){
	lista.erase(std::remove(lista.begin(), lista.end(), Node), lista.end());
}


void BinNode::show(){
  cout << lista.size() << endl;
   for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
    if(*iter != 0){
      (*iter)->show();
    }
  }
}

