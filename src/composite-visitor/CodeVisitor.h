#include <iostream>
#include <fstream>
using namespace std;

class CodeVisitor : public NodeVisitor{
        
public:
        tablaSimbolos* s;
	//Terminales
          int contador;
          void visit(IDENTNode*);
          void visit(IntNode*);
          void visit(StrNode*);
          void visit(FloatNode*);
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
          void visit(PrintNode*);
          
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
          void escribe(string);
	//Expresion
        CodeVisitor(tablaSimbolos*);

};


void CodeVisitor:: escribe(string cadena){
        ofstream archivo;
        archivo.open ("archivo.c",std::ofstream::app);
        archivo << cadena;
        archivo.close();
}
CodeVisitor::CodeVisitor(tablaSimbolos* t){
        s = t;
        contador = 0;
        escribe("#include <stdio.h>\n");
        escribe("#include <stdlib.h>\n");
        escribe("#include <string.h>\n");
        escribe("int main() { \n");
}


void CodeVisitor::visit(StrNode* n){
        escribe(n->nombre());
 
}
void CodeVisitor::visit(FloatNode* n){
        escribe(n->nombre());
        escribe("f");
}
        
void CodeVisitor::visit(IntNode* n){
        escribe(n->nombre());
}
//Aritmeticas
void CodeVisitor::visit(AsignacionNode* n){
      vector <Nodo*> lista = n->lista;
        if(((LeafNode*)lista[0])->tipo.compare("var") == 0){
        string n =  lista[0]->nombre();
                if(lista[1]->tipo.compare("int") == 0){        
                escribe("int ");escribe(n);escribe("=");
                lista[1]->Accept(this);
                escribe(";\n");
                }
                if(lista[1]->tipo.compare("float") == 0){        
                escribe("float ");escribe(n);escribe("=");
                lista[1]->Accept(this);
                escribe(";\n");
                }
                if(lista[1]->tipo.compare("string") == 0){        
                escribe("char* ");escribe(n);escribe("=");
                lista[1]->Accept(this);
                escribe(";\n");
                }
        }
     
}
void CodeVisitor::visit(IDENTNode* n){ 
       escribe(n->nombre());
	
}

void CodeVisitor::visit(PlusNode* n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        escribe("+");
        lista[1]->Accept(this);
        //escribe(";\n");
        
}
void CodeVisitor::visit(MinusNode* n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        escribe("-");
        lista[1]->Accept(this);
        //escribe(";\n");
}
void CodeVisitor::visit(TimesNode* n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        escribe("*");
        lista[1]->Accept(this);
        //escribe(";\n");
}
void CodeVisitor::visit(DivNode* n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        escribe("/");
        lista[1]->Accept(this);
        //escribe(";\n");
}
void CodeVisitor::visit(PowNode* n){
	
}
void CodeVisitor::visit(ModNode* n){
	
}
void CodeVisitor::visit(PlusEqualNode* n){cout << "  +=  ";
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        escribe("=");
        lista[0]->Accept(this);
        escribe("+");
        lista[1]->Accept(this);
        escribe(";\n");
}
void CodeVisitor::visit(MinusEqualNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe("=");
        lista[0]->Accept(this);
        escribe("-");
        lista[1]->Accept(this);
        escribe(";\n");
}
void CodeVisitor::visit(TimesEqualNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe("=");
        lista[0]->Accept(this);
        escribe("*");
        lista[1]->Accept(this);
        escribe(";\n");
}
void CodeVisitor::visit(DivEqualNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe("=");
        lista[0]->Accept(this);
        escribe("/");
        lista[1]->Accept(this);
        escribe(";\n");
}

void CodeVisitor::visit(StmtListNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}

void CodeVisitor::visit(PowEqualNode* n){
	
}
void CodeVisitor::visit(ModEqualNode* n){
	
}
void CodeVisitor::visit(DifNode* n){
	
}
//Booleanas
void CodeVisitor::visit(AndNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void CodeVisitor::visit(OrNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void CodeVisitor::visit(XorNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void CodeVisitor::visit(EqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void CodeVisitor::visit(LessNode* n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        escribe("<");
        lista[1]->Accept(this);
}
void CodeVisitor::visit(MoreNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe(">");
        lista[1]->Accept(this);
}
void CodeVisitor::visit(LessEqualNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe("<=");
        lista[1]->Accept(this);
}
void CodeVisitor::visit(MoreEqualNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe(">=");
        lista[1]->Accept(this);
}
void CodeVisitor::visit(Equal2Node* n){
	vector <Nodo*> lista = n->lista;
	
        lista[0]->Accept(this);
        escribe("==");
        lista[1]->Accept(this);
}
void CodeVisitor::visit(NotEqualNode* n){
	vector <Nodo*> lista = n->lista;
	lista[0]->Accept(this);
        escribe("!=");
        lista[1]->Accept(this);
}

void CodeVisitor::visit(IFNode* n){
        vector<Nodo*> lista = n->lista;	
        escribe("if(");
        lista[0]->Accept(this);
        escribe(") {\n");
        lista[1]->Accept(this);
        escribe("}\n");
        if(lista[2] != NULL){
        escribe(" else {\n");
        lista[2]->Accept(this);
        escribe("}\n");
        }	
}

void CodeVisitor::visit(WHILENode* n){
        vector<Nodo*> lista = n->lista;	
        escribe("while(");
        lista[0]->Accept(this);
        escribe(") {\n");
        lista[1]->Accept(this);
        escribe("}\n");
       
}
void CodeVisitor::visit(PrintNode * n){
        contador +=1;
	vector<Nodo*> lista = n->lista;
        if(lista[0]->tipo.compare("int") == 0){
        escribe("int g");
        escribe(std::to_string(contador));
        escribe(" = ");
        lista[0]->Accept(this);
        escribe(";\n");
        escribe("printf( \"%d\", g");
        escribe(std::to_string(contador));
        escribe(");\n");
        }

        if(lista[0]->tipo.compare("float") == 0){
        escribe("float g");
        escribe(std::to_string(contador));
        escribe(" = ");
        lista[0]->Accept(this);
        escribe(";\n");
        escribe("printf( \"%f\", g");
        escribe(std::to_string(contador));
        escribe(");\n");
        }
        if(lista[0]->tipo.compare("string") == 0){
        escribe("char* g");
        escribe(std::to_string(contador));
        escribe(" = ");
        lista[0]->Accept(this);
        escribe(";\n");
        escribe("printf( \"%s\", g");
        escribe(std::to_string(contador));
        escribe(");\n");        
        }
        
        if(lista[0]->tipo.compare("var") == 0){
                Record* r = s->lookUp(lista[0]->nombre().c_str());
                Simbolo* ss = r->s;
                if(strcmp(ss->daTipo(),"string") == 0){
                        //string
                        escribe("printf( \"%s\",");
                        escribe(ss->daNombre());
                        escribe(");\n");
                }
                if(strcmp(ss->daTipo(),"int") == 0){
                        escribe("printf( \"%d\",");
                                escribe(ss->daNombre());
                                escribe(");\n");
        
                }
                if(strcmp(ss->daTipo(),"float") == 0){
                                escribe("printf( \"%f\",");
                                escribe(ss->daNombre());
                                escribe(");\n");
                
                }
        }
}               
void CodeVisitor::visit(FORNode* n){
        vector<Nodo*> lista = n->lista;        
        escribe("int i");
        escribe(std::to_string(contador));
        escribe(";\n");
        escribe("char* c");
        escribe(std::to_string(contador));        
        escribe("=");
        lista[1]->Accept(this);
        escribe(";\n");
        escribe("for(i");escribe(std::to_string(contador));escribe("=0;");
        escribe("i");escribe(std::to_string(contador));escribe("<");
        escribe("strlen(");escribe("c");escribe(std::to_string(contador));
        escribe("); ");
        escribe("i");escribe(std::to_string(contador));escribe("++) {\n");
        contador+=1;
        escribe("char c");
        escribe(std::to_string(contador));
        escribe(" = ");            
        escribe("c");escribe(std::to_string(contador-1));escribe("[i");escribe(std::to_string(contador-1));escribe("];\n");
        escribe("printf(\"%c\",");escribe("c");escribe(std::to_string(contador));escribe(");\n");
        
        escribe("}\n");
}

