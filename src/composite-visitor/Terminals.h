
class IntNode: public LeafNode{
	public:
                int valor;
		IntNode(int);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
 
};

IntNode::IntNode(int n){
        valor = n;
	ostringstream convert;
	convert << n; 
	name = convert.str();
        tipo = "int";
}

void IntNode::show(){
	cout  <<"("<<name << ")";
}


class  LongNode: public LeafNode{
	public:
		LongNode(long);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
};

LongNode::LongNode(long n){
	stringstream ss (stringstream::in | stringstream::out);
  	ss << n;
	name = ss.str();
}

void LongNode::show(){
	cout  <<"("<<name << ")";
}

class FloatNode: public LeafNode{
	public: 
                float valor;
		FloatNode(float);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
};

FloatNode::FloatNode(float n){
	stringstream ss (stringstream::in | stringstream::out);
  	ss << n;
	name = ss.str();
        tipo = "float";
        valor = n;
}

void FloatNode::show(){
	cout  <<"("<<name << ")";
}

class  BoolNode: public LeafNode{
	public:
                
		BoolNode(string);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
};

BoolNode::BoolNode(string n){
	name = n;
}

void BoolNode::show(){
	cout  <<"("<<name << ")";
}

//Cadenas
class  StrNode: public LeafNode{
	public:
                string valor;
		StrNode(string);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
};

StrNode::StrNode(string n){
	name = n;
        valor = n;
        tipo = "string";
}

void StrNode::show(){
	cout  <<"("<<name << ")";
}

//Identificadores
class  IDENTNode: public LeafNode{
	public:
                //string tipo;
		IDENTNode(string);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
};

IDENTNode::IDENTNode(string n){
	name = n;
        tipo = "var";
}

void IDENTNode::show(){
	cout  <<"("<<name << ")";
}

//return
class  RETURNNode: public LeafNode{
	public:
		RETURNNode(string);
		void show();
                void Accept(NodeVisitor* n){
                n->visit(this);                
                }
};

RETURNNode::RETURNNode(string n){
	name = n;
}

void RETURNNode::show(){
	cout  <<"("<<name << ")";
}
