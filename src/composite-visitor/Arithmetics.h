class CorrimIzq: public BinNode{
public:
	CorrimIzq(){};
	void show(){
        cout << "<<";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};
class CorrimDer: public BinNode{
public:       
         CorrimDer(){};
	void show(){
        cout << ">>";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class AndIgual: public BinNode{
public:        
        AndIgual(){};
	void show(){
        cout << "&=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class OrIgual: public BinNode{
public:
        OrIgual(){};
	void show(){
        cout << "|=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class XorIgual: public BinNode{
public:
        XorIgual(){};
	void show(){
        cout << "^=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class CorIzqIgual: public BinNode{
public:
        CorIzqIgual(){};
	void show(){
        cout << "<<=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class CorDerIgual: public BinNode{
public:
        CorDerIgual(){};
	void show(){
        cout << ">>=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class PowIgual: public BinNode{
public:
        PowIgual(){};
	void show(){
        cout << "^=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
class DivEntIgual: public BinNode{
public:
        DivEntIgual(){};
	void show(){
        cout << "//=";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};

class PlusNode : public BinNode{

public:
        //string tipo;
	PlusNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

PlusNode::PlusNode(){
                tipo = "";
}

void PlusNode::show(){
	cout<<"(+ ";
	BinNode::show();
        cout << ")";

}

class MinusNode : public BinNode{
public:
	MinusNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

MinusNode::MinusNode(){}

void MinusNode::show(){
	cout<<"(- ";
	BinNode::show();
        cout << ")";
}
class AsignacionNode: public BinNode{
public:
	AsignacionNode(){};
	void show(){
        cout << "ASIG ";
        BinNode::show();
        };
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};
class TimesNode : public BinNode{

public:
	TimesNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

TimesNode::TimesNode(){
}

void TimesNode::show(){
	cout<<"(* ";
	BinNode::show();
        cout << ")";
}

class DivNode : public BinNode{
public:
	DivNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

DivNode::DivNode(){
}

void DivNode::show(){
	cout<<"/ ";
	BinNode::show();
}


class PowNode : public BinNode{
public:
	PowNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

PowNode::PowNode(){
}

void PowNode::show(){
	cout<<"**"<<endl;
	BinNode::show();
}


class ModNode : public BinNode{
public:
	ModNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

ModNode::ModNode(){
}

void ModNode::show(){
	cout<<"%"<<endl;
	BinNode::show();
}

class PlusEqualNode : public BinNode{
public:
	PlusEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

PlusEqualNode::PlusEqualNode(){
}

void PlusEqualNode::show(){
	cout<<"+="<<endl;
	BinNode::show();
}


class MinusEqualNode : public BinNode{
private:
	lNode* n;
public:
	MinusEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

MinusEqualNode::MinusEqualNode(){
}

void MinusEqualNode::show(){
	cout<<"-= ";
	BinNode::show();
}


class TimesEqualNode : public BinNode{
public:
	TimesEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

TimesEqualNode::TimesEqualNode(){
}

void TimesEqualNode::show(){
	cout<<"*="<<endl;
	BinNode::show();
}


class DivEqualNode : public BinNode{
public:
	DivEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

DivEqualNode::DivEqualNode(){
}

void DivEqualNode::show(){
	cout<<"/="<<endl;
	BinNode::show();
}


class PowEqualNode : public BinNode{
public:
	PowEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

PowEqualNode::PowEqualNode(){
}

void PowEqualNode::show(){
	cout<<"**="<<endl;
	BinNode::show();
}



class ModEqualNode : public BinNode{
public:
	ModEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};

ModEqualNode::ModEqualNode(){
}

void ModEqualNode::show(){
	cout<<"%="<<endl;
	BinNode::show();
}

