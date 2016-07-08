class PrintVisitor : public NodeVisitor{

public:
	//Terminales
	void visit(LeafNode*);
	//Aritmeticas
	  void visit(PlusNode*);
	  void visit(MinusNode*);
	  void visit(TimesNode*);
	  void visit(DivNode*);
	  void visit(PowNode*);
	  void visit(ModNode*);
	  void visit(PlusEqualNode*);
	  void visit(MinusEqualNode*);
	  void visit(TimesEqualNode*);
	  void visit(DivEqualNode*);
	  void visit(PowEqualNode*);
	  void visit(ModEqualNode*);
          void visit(AsignacionNode*);
          void visit(StmtListNode*);
	//Booleanas
	  void visit(AndNode*);
	  void visit(OrNode*);
	  void visit(XorNode*);
	  void visit(EqualNode*);
	  void visit(LessNode*);
	  void visit(MoreNode*);
	  void visit(LessEqualNode*);
	  void visit(MoreEqualNode*);
	  void visit(Equal2Node*);
	  void visit(NotEqualNode*);
	  void visit(DifNode*);
	  void visit(IFNode*);
	  void visit(WHILENode*);
	  void visit(FORNode*);
	  void visit(FunctionNode*);
	//Expresion
	/*  void visit(ExpressionNode*);
	  void visit(SStmtListNode*);
	  void visit(StmtListNode*);
	*/
	PrintVisitor();

private:
	void printOp(std::string op,Nodo* n);
	void printLeaf(std::string s);
};

PrintVisitor::PrintVisitor(){}
//Terminales


void PrintVisitor::visit(LeafNode* n){
	//cout<<"(";

	n->Accept(this);
       //cout<<")";
}

//Aritmeticas
void PrintVisitor::visit(AsignacionNode* n){
vector <Nodo*> lista = n->lista;
	cout << "ASIG ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}	
}
void PrintVisitor::visit(PlusNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "+ ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(MinusNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "- ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(TimesNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "* ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(DivNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "/ ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(PowNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "** ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(ModNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "% ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(PlusEqualNode* n){
	vector <Nodo*> lista = n->lista;
	cout << "*= ";
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(MinusEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(TimesEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(DivEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(StmtListNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(PowEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(ModEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(DifNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
//Booleanas
void PrintVisitor::visit(AndNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(OrNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(XorNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(EqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(LessNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(MoreNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(LessEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(MoreEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(Equal2Node* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void PrintVisitor::visit(NotEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}

void PrintVisitor::visit(IFNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}

void PrintVisitor::visit(WHILENode* n){
	vector <Nodo*> lista = n->lista;
	cout << "WHILE " ;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}

void PrintVisitor::visit(FORNode* n){
	printOp("for",n);
}

void PrintVisitor::visit(FunctionNode* n){
	printOp("def",n);
}

void PrintVisitor::printOp(string op,Nodo*n){
	cout<< "(" <<op;
        
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
      

}
void PrintVisitor::printLeaf(string s){
	cout<<"("<<s<<")";
}
