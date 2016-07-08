#include "tabla.cpp"

class SemanticVisitor : public NodeVisitor{

public:
        tablaSimbolos *ts = new tablaSimbolos();
	//Terminales

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
	//Expresion
        SemanticVisitor();

};

SemanticVisitor::SemanticVisitor(){
ts->openScope();
}


void SemanticVisitor::visit(StrNode* n){}
void SemanticVisitor::visit(FloatNode* n){}


//Aritmeticas
void SemanticVisitor::visit(AsignacionNode* n){ 
        vector <Nodo*> lista = n->lista;

        //lado izquierdo
        const char* nombre;
        const char* type;
        void* valor;
     
        if(((LeafNode*)lista[0])->tipo.compare("var") == 0){
        nombre = ((LeafNode*)lista[0])->nombre().c_str();

        } else {
                cout << " No puedes asignar un valor a un número" << endl;  
                exit(1); 
        }
        

        //lado derecho
        if(((LeafNode*)lista[1])->tipo.compare("error") == 0){
        cout << "Error de tipos. EL valor no esta definido" << endl;
        exit(0);
        }
        if(((LeafNode*)lista[1])->tipo.compare("int") == 0){
        type = ((LeafNode*)lista[1])->tipo.c_str();
        valor = (void*)&(((IntNode*)lista[1])->valor);
        }
        
        if(((LeafNode*)lista[1])->tipo.compare("float") == 0){
        type = ((LeafNode*)lista[1])->tipo.c_str();
        valor = (void*)&(((FloatNode*)lista[1])->valor);
        }
        if(((LeafNode*)lista[1])->tipo.compare("string") == 0){
        type = ((LeafNode*)lista[1])->tipo.c_str();
        valor = (void*)&(((StrNode*)lista[1])->valor);
        }

        if(((LeafNode*)lista[1])->tipo.compare("var") == 0){
                if( !ts->declaredLocally( ((LeafNode*)lista[1])->nombre().c_str() ) ){
                        cout << "La variable \"" <<((LeafNode*)lista[1])->nombre() << "\" no ha sido declarada" << endl;
                        exit(1);
                }
                cout << " La variable derecha fue declarada  anteriormente" << endl;
                Record* rr = ts->lookUp(((LeafNode*)lista[1])->nombre().c_str());
                Simbolo *ss = rr->s;
                type = ss->daTipo();
                cout << " su tipo es " << type << endl;
                valor = ss->daValor();
                

        }
        if(((BinNode*)lista[1])->tipo.compare("varop") == 0){
        vector<Nodo*> lis = ((BinNode*)lista[1])->lista;
        (lis[0])->Accept(this);
        (lis[1])->Accept(this);
        
        if(lis[0]->tipo.compare("var") == 0){

                Record *r = ts->lookUp(lis[0]->nombre().c_str());
                Simbolo *k = r->s;
                const char* tip = k->daTipo();
                const char* tip2 = lis[1]->tipo.c_str();
                        if(strcmp(tip,"int") == 0) {
                                if(strcmp(tip2,"string") == 0 || strcmp(tip2,"error") == 0) {
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1); 
                                }

                                if(strcmp(tip2,"int") == 0) lista[1]->tipo="int";
                        }
                        if(strcmp(tip,"float") == 0) {
                                if(strcmp(tip2,"string") == 0|| strcmp(tip2,"error") == 0) {
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1);
                                }
                                lista[1]->tipo = "float";
                
                        }
                        if(strcmp(tip,"string") == 0){
                                if(strcmp(tip2,"string") != 0) {
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1);
                                }
                        }
                        if(strcmp(tip,"error") == 0){
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1);
                        }
                

        } else { 
        if(lis[1]->tipo.compare("var") == 0){
        
                Record *r = ts->lookUp(lis[1]->nombre().c_str());
                Simbolo *k = r->s;
                const char* tip = k->daTipo();
                const char* tip2 = lis[0]->tipo.c_str();
                        if(strcmp(tip,"int") == 0) {
                                if(strcmp(tip2,"string") == 0 || strcmp(tip2,"error") == 0) {
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1); 
                                }
                                if(strcmp(tip2,"int") == 0) lista[1]->tipo="int";
                        }
                        if(strcmp(tip,"float") == 0) {
                                if(strcmp(tip2,"string") == 0|| strcmp(tip2,"error") == 0) {
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1);
                                }
                                lista[1]->tipo = "float";
                
                        }
                        if(strcmp(tip,"string") == 0){
                                if(strcmp(tip2,"string") != 0) {
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1);
                                }
                        }
                        if(strcmp(tip,"error") == 0){
                                lista[1]->tipo = "error";
                                cout << "Error de tipos, tipo indefinido" << endl; exit(1);
                        }
        }
        }
                
                n->Accept(this);
        }



        //Checamos que se mantenga el tipo de la variable de lado izquierdo
        
        if(ts->declaredLocally(nombre)) {
                Record *r = ts->lookUp(nombre);
                Simbolo *si = r->s;
                if(strcmp(si->daTipo(),type) == 0){
                cout << "tipos iguales" << endl;
                } else {
                cout << "tipos distintos" << endl;
                cout << "Error de tipos. Valor de tipo \""<<type << "\" a variable \"" << si->daNombre() << "\" de tipo \"" << si->daTipo() <<  "\"" << endl;
                exit(0); 

                }

        } else {
        Simbolo *s  = new Simbolo(nombre,type,valor);
        ts->insert(s);
        }
}
void SemanticVisitor::visit(IDENTNode* n){ 
        string id = n->nombre();   
        if(!ts->declaredLocally(id.c_str())) {
        cerr << "La variable \"" << id << "\" no ha sido declarada" << endl;     
        exit(1);
        }
	
}
void SemanticVisitor::visit(IntNode* n){
}

void SemanticVisitor::visit(PlusNode* n){
	vector <Nodo*> lista = n->lista;
        
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(MinusNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(TimesNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(DivNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(PowNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(ModNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(PlusEqualNode* n){
	vector <Nodo*> lista = n->lista;
        if(lista[0]->tipo.compare("var")!= 0 ) {

        cout << " Error. El lado izquierdo de la asignacion no es una variable" << endl;
        exit(1);
        }
        lista[0]->Accept(this);
        Record* r = ts->lookUp(lista[0]->nombre().c_str());
        Simbolo* si = r->s;
        
        if(((LeafNode*)lista[1])->tipo.compare("error") == 0){
        cout << "Error de tipos. EL valor no esta definido" << endl;
        exit(1);
        }
        if(((LeafNode*)lista[1])->tipo.compare("int") == 0){
                if(strcmp(si->daTipo(),"int") != 0) {
                cerr << "Error de tipos. valor de tipo \"int\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        
        if(((LeafNode*)lista[1])->tipo.compare("float") == 0){
                if(strcmp(si->daTipo(),"float") != 0) {
                cerr << "Error de tipos. valor de tipo \"float\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        if(((LeafNode*)lista[1])->tipo.compare("string") == 0){
                if(strcmp(si->daTipo(),"string") != 0) {
                cerr << "Error de tipos. valor de tipo \"string\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }

        if(((LeafNode*)lista[1])->tipo.compare("var") == 0){ 
                Record* r = ts->lookUp(lista[1]->nombre().c_str());
                if(r == NULL){
                cerr << "No puedo resolver el tipo del lado derechooo" << endl;
                exit(1);
                }
                Simbolo* k = r->s;
                if(strcmp(k->daTipo(),si->daTipo()) != 0) {
                cerr << "Error de tipos. Valor de tipo \"" << k->daTipo() << "\" a variable \""<<si->daNombre() << "\" de tipo \"" << si->daTipo() << "\"" << endl;
                exit(1);
        
                }
        } else {
                cerr << "Error.  No puedo resolver el tipo del lado dereeeecho" << endl;
                exit(1);
        }

}
void SemanticVisitor::visit(MinusEqualNode* n){
	vector <Nodo*> lista = n->lista;
        if(lista[0]->tipo.compare("var")!= 0 ) {

        cout << " Error. El lado izquierdo de la asignacion no es una variable" << endl;
        exit(1);
        }
        lista[0]->Accept(this);
        Record* r = ts->lookUp(lista[0]->nombre().c_str());
        Simbolo* si = r->s;
        
        if(((LeafNode*)lista[1])->tipo.compare("error") == 0){
        cout << "Error de tipos. EL valor no esta definido" << endl;
        exit(1);
        }
        if(((LeafNode*)lista[1])->tipo.compare("int") == 0){
                if(strcmp(si->daTipo(),"int") != 0) {
                cerr << "Error de tipos. valor de tipo \"int\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        
        if(((LeafNode*)lista[1])->tipo.compare("float") == 0){
                if(strcmp(si->daTipo(),"float") != 0) {
                cerr << "Error de tipos. valor de tipo \"float\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        if(((LeafNode*)lista[1])->tipo.compare("string") == 0){
                if(strcmp(si->daTipo(),"string") != 0) {
                cerr << "Error de tipos. valor de tipo \"string\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }

        if(((LeafNode*)lista[1])->tipo.compare("var") == 0){
                Record* r = ts->lookUp(lista[1]->nombre().c_str());
                if(r == NULL){
                cerr << "No puedo resolver el tipo del lado derecho" << endl;
                exit(1);
                }
                Simbolo* k = r->s;
                if(strcmp(k->daTipo(),si->daTipo()) != 0) {
                cerr << "Error de tipos. Valor de tipo \"" << k->daTipo() << "\" a variable \""<<si->daNombre() << "\" de tipo \"" << si->daTipo() << "\"" << endl;
                exit(1);
        
                }
        } else {
                cerr << "Error.  No puedo resolver el tipo del lado derecho" << endl;
                exit(1);
        }

}
void SemanticVisitor::visit(TimesEqualNode* n){
	vector <Nodo*> lista = n->lista;
        if(lista[0]->tipo.compare("var")!= 0 ) {

        cout << " Error. El lado izquierdo de la asignacion no es una variable" << endl;
        exit(1);
        }
        lista[0]->Accept(this);
        Record* r = ts->lookUp(lista[0]->nombre().c_str());
        Simbolo* si = r->s;
        
        if(((LeafNode*)lista[1])->tipo.compare("error") == 0){
        cout << "Error de tipos. EL valor no esta definido" << endl;
        exit(1);
        }
        if(((LeafNode*)lista[1])->tipo.compare("int") == 0){
                if(strcmp(si->daTipo(),"int") != 0) {
                cerr << "Error de tipos. valor de tipo \"int\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        
        if(((LeafNode*)lista[1])->tipo.compare("float") == 0){
                if(strcmp(si->daTipo(),"float") != 0) {
                cerr << "Error de tipos. valor de tipo \"float\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        if(((LeafNode*)lista[1])->tipo.compare("string") == 0){
                if(strcmp(si->daTipo(),"string") != 0) {
                cerr << "Error de tipos. valor de tipo \"string\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }

        if(((LeafNode*)lista[1])->tipo.compare("var") == 0){ 
                Record* r = ts->lookUp(lista[1]->nombre().c_str());
                if(r == NULL){
                cerr << "No puedo resolver el tipo del lado derechooo" << endl;
                exit(1);
                }
                Simbolo* k = r->s;
                if(strcmp(k->daTipo(),si->daTipo()) != 0) {
                cerr << "Error de tipos. Valor de tipo \"" << k->daTipo() << "\" a variable \""<<si->daNombre() << "\" de tipo \"" << si->daTipo() << "\"" << endl;
                exit(1);
        
                }
        } else {
                cerr << "Error.  No puedo resolver el tipo del lado dereeeecho" << endl;
                exit(1);
        }

}
void SemanticVisitor::visit(DivEqualNode* n){
	vector <Nodo*> lista = n->lista;
        if(lista[0]->tipo.compare("var")!= 0 ) {

        cout << " Error. El lado izquierdo de la asignacion no es una variable" << endl;
        exit(1);
        }
        lista[0]->Accept(this);
        Record* r = ts->lookUp(lista[0]->nombre().c_str());
        Simbolo* si = r->s;
        
        if(((LeafNode*)lista[1])->tipo.compare("error") == 0){
        cout << "Error de tipos. EL valor no esta definido" << endl;
        exit(1);
        }
        if(((LeafNode*)lista[1])->tipo.compare("int") == 0){
                if(strcmp(si->daTipo(),"int") != 0) {
                cerr << "Error de tipos. valor de tipo \"int\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        
        if(((LeafNode*)lista[1])->tipo.compare("float") == 0){
                if(strcmp(si->daTipo(),"float") != 0) {
                cerr << "Error de tipos. valor de tipo \"float\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }
        if(((LeafNode*)lista[1])->tipo.compare("string") == 0){
                if(strcmp(si->daTipo(),"string") != 0) {
                cerr << "Error de tipos. valor de tipo \"string\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
                return;
        }

        if(((LeafNode*)lista[1])->tipo.compare("var") == 0){
                Record* r = ts->lookUp(lista[1]->nombre().c_str());
                if(r == NULL){
                cerr << "No puedo resolver el tipo del lado derechooo" << endl;
                exit(1);
                }
                Simbolo* k = r->s;
                if(strcmp(k->daTipo(),si->daTipo()) != 0) {
                cerr << "Error de tipos. Valor de tipo \"" << k->daTipo() << "\" a variable \""<<si->daNombre() << "\" de tipo \"" << si->daTipo() << "\"" << endl;
                exit(1);
        
                }
        } else {
                cerr << "Error.  No puedo resolver el tipo del lado dereeeecho" << endl;
                exit(1);
        }

}

void SemanticVisitor::visit(StmtListNode* n){ 
	vector <Nodo*> lista = n->lista;
        
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	} 
}

void SemanticVisitor::visit(PowEqualNode* n){
	vector <Nodo*> lista = n->lista;
        if(lista[0]->tipo.compare("var")!= 0 ) {

        cout << " Error. El lado izquierdo de la asignacion no es una variable" << endl;
        exit(1);
        }
        lista[0]->Accept(this);
        Record* r = ts->lookUp(lista[0]->nombre().c_str());
        Simbolo* si = r->s;
        
        if(((LeafNode*)lista[1])->tipo.compare("error") == 0){
        cout << "Error de tipos. EL valor no esta definido" << endl;
        exit(1);
        }
        if(((LeafNode*)lista[1])->tipo.compare("int") == 0){
                if(strcmp(si->daTipo(),"int") != 0) {
                cerr << "Error de tipos. valor de tipo \"int\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
        }
        
        if(((LeafNode*)lista[1])->tipo.compare("float") == 0){
                if(strcmp(si->daTipo(),"float") != 0) {
                cerr << "Error de tipos. valor de tipo \"float\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
        }
        if(((LeafNode*)lista[1])->tipo.compare("string") == 0){
                if(strcmp(si->daTipo(),"string") != 0) {
                cerr << "Error de tipos. valor de tipo \"string\" a varible \"" << si->daNombre() << "\" de tipo \""<< si->daTipo() << "\""<<endl;
                exit(1);
                }
        }

        if(((LeafNode*)lista[1])->tipo.compare("var") == 0){ cout << "lado derecho es var" << endl;
                Record* r = ts->lookUp(lista[1]->nombre().c_str());
                if(r == NULL){
                cerr << "No puedo resolver el tipo del lado derecho" << endl;
                exit(1);
                }
                Simbolo* k = r->s;
                if(strcmp(k->daTipo(),si->daTipo()) != 0) {
                cerr << "Error de tipos. Valor de tipo \"" << k->daTipo() << "\" a variable \""<<si->daNombre() << "\" de tipo \"" << si->daTipo() << "\"" << endl;
                exit(1);
        
                }
        } else {
                cerr << "Error.  No puedo resolver el tipo del lado derecho" << endl;
                exit(1);
        }

}
void SemanticVisitor::visit(ModEqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(DifNode* n){
	vector <Nodo*> lista = n->lista;
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
//Booleanas
void SemanticVisitor::visit(AndNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(OrNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(XorNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(EqualNode* n){
	vector <Nodo*> lista = n->lista;
	
        for(vector<Nodo*>::const_iterator iter = lista.begin(); iter != lista.end(); ++iter){
		(*iter)->Accept(this);
	}
}
void SemanticVisitor::visit(LessNode* n){
	vector <Nodo*> lista = n->lista;

        // Alguna es cadena

                if(lista[0]->tipo.compare("string") == 0 || lista[1]->tipo.compare("string") == 0){

                cerr << "Error de tipos. Las cadenas no son comparables." << endl;
                     exit(1); 

                }
        // Alguno tiene tipo error
                if(lista[0]->tipo.compare("error") == 0 || lista[1]->tipo.compare("error") == 0){

                cerr << "Error de tipos. Valores no definidos." << endl;
                     exit(1); 
                }


        // Ambas son vars
                if(lista[0]->tipo.compare("var") == 0 && lista[1]->tipo.compare("var") == 0){
                lista[0]->Accept(this);
                lista[1]->Accept(this);
                Record* r1 = ts->lookUp(lista[0]->nombre().c_str());
                Record* r2 = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* s1 = r1->s;
                Simbolo* s2 = r2->s;
                if(strcmp(s1->daTipo(),"string") == 0 || strcmp(s2->daTipo(),"string") == 0){
                        cerr << "Error de tipos. Las cadenas no son comparables" << endl;
                        exit(0);
                  }
                }
 

}       
void SemanticVisitor::visit(MoreNode* n){
	vector <Nodo*> lista = n->lista;

        // Alguna es cadena

                if(lista[0]->tipo.compare("string") == 0 || lista[1]->tipo.compare("string") == 0){

                cerr << "Error de tipos. Las cadenas no son comparables." << endl;
                     exit(1); 

                }
        // Alguno tiene tipo error
                if(lista[0]->tipo.compare("error") == 0 || lista[1]->tipo.compare("error") == 0){

                cerr << "Error de tipos. Valores no definidos." << endl;
                     exit(1); 
                }


        // Ambas son vars
                if(lista[0]->tipo.compare("var") == 0 && lista[1]->tipo.compare("var") == 0){
                lista[0]->Accept(this);
                lista[1]->Accept(this);
                Record* r1 = ts->lookUp(lista[0]->nombre().c_str());
                Record* r2 = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* s1 = r1->s;
                Simbolo* s2 = r2->s;
                if(strcmp(s1->daTipo(),"string") == 0 || strcmp(s2->daTipo(),"string") == 0){
                        cerr << "Error de tipos. Las cadenas no son comparables" << endl;
                        exit(0);
                  }
                }
}
void SemanticVisitor::visit(LessEqualNode* n){
	vector <Nodo*> lista = n->lista;

        // Alguna es cadena

                if(lista[0]->tipo.compare("string") == 0 || lista[1]->tipo.compare("string") == 0){

                cerr << "Error de tipos. Las cadenas no son comparables." << endl;
                     exit(1); 

                }
        // Alguno tiene tipo error
                if(lista[0]->tipo.compare("error") == 0 || lista[1]->tipo.compare("error") == 0){

                cerr << "Error de tipos. Valores no definidos." << endl;
                     exit(1); 
                }


        // Ambas son vars
                if(lista[0]->tipo.compare("var") == 0 && lista[1]->tipo.compare("var") == 0){
                lista[0]->Accept(this);
                lista[1]->Accept(this);
                Record* r1 = ts->lookUp(lista[0]->nombre().c_str());
                Record* r2 = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* s1 = r1->s;
                Simbolo* s2 = r2->s;
                if(strcmp(s1->daTipo(),"string") == 0 || strcmp(s2->daTipo(),"string") == 0){
                        cerr << "Error de tipos. Las cadenas no son comparables" << endl;
                        exit(0);
                  }
                }
}
void SemanticVisitor::visit(MoreEqualNode* n){ 
	vector <Nodo*> lista = n->lista;

        // Alguna es cadena

                if(lista[0]->tipo.compare("string") == 0 || lista[1]->tipo.compare("string") == 0){

                cerr << "Error de tipos. Las cadenas no son comparables." << endl;
                     exit(1); 

                }
        // Alguno tiene tipo error
                if(lista[0]->tipo.compare("error") == 0 || lista[1]->tipo.compare("error") == 0){

                cerr << "Error de tipos. Valores no definidos." << endl;
                     exit(1); 
                }


        // Ambas son vars
                if(lista[0]->tipo.compare("var") == 0 && lista[1]->tipo.compare("var") == 0){
                lista[0]->Accept(this);
                lista[1]->Accept(this);
                Record* r1 = ts->lookUp(lista[0]->nombre().c_str());
                Record* r2 = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* s1 = r1->s;
                Simbolo* s2 = r2->s;
                if(strcmp(s1->daTipo(),"string") == 0 || strcmp(s2->daTipo(),"string") == 0){
                        cerr << "Error de tipos. Las cadenas no son comparables" << endl;
                        exit(0);
                  }
                }
}
void SemanticVisitor::visit(Equal2Node* n){
	vector <Nodo*> lista = n->lista;

        // Alguna es cadena

                if(lista[0]->tipo.compare("string") == 0 || lista[1]->tipo.compare("string") == 0){

                cerr << "Error de tipos. Las cadenas no son comparables." << endl;
                     exit(1); 

                }
        // Alguno tiene tipo error
                if(lista[0]->tipo.compare("error") == 0 || lista[1]->tipo.compare("error") == 0){

                cerr << "Error de tipos. Valores no definidos." << endl;
                     exit(1); 
                }


        // Ambas son vars
                if(lista[0]->tipo.compare("var") == 0 && lista[1]->tipo.compare("var") == 0){
                lista[0]->Accept(this);
                lista[1]->Accept(this);
                Record* r1 = ts->lookUp(lista[0]->nombre().c_str());
                Record* r2 = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* s1 = r1->s;
                Simbolo* s2 = r2->s;
                if(strcmp(s1->daTipo(),"string") == 0 || strcmp(s2->daTipo(),"string") == 0){
                        cerr << "Error de tipos. Las cadenas no son comparables" << endl;
                        exit(0);
                  }
                }
}
void SemanticVisitor::visit(NotEqualNode* n){
	vector <Nodo*> lista = n->lista;

        // Alguna es cadena

                if(lista[0]->tipo.compare("string") == 0 || lista[1]->tipo.compare("string") == 0){

                cerr << "Error de tipos. Las cadenas no son comparables." << endl;
                     exit(1); 

                }
        // Alguno tiene tipo error
                if(lista[0]->tipo.compare("error") == 0 || lista[1]->tipo.compare("error") == 0){

                cerr << "Error de tipos. Valores no definidos." << endl;
                     exit(1); 
                }


        // Ambas son vars
                if(lista[0]->tipo.compare("var") == 0 && lista[1]->tipo.compare("var") == 0){
                lista[0]->Accept(this);
                lista[1]->Accept(this);
                Record* r1 = ts->lookUp(lista[0]->nombre().c_str());
                Record* r2 = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* s1 = r1->s;
                Simbolo* s2 = r2->s;
                if(strcmp(s1->daTipo(),"string") == 0 || strcmp(s2->daTipo(),"string") == 0){
                        cerr << "Error de tipos. Las cadenas no son comparables" << endl;
                        exit(0);
                  }
                }
}

void SemanticVisitor::visit(IFNode* n){
	vector <Nodo*> lista = n->lista; 
        lista[0]->Accept(this); 
        lista[1]->Accept(this);
        if(lista[2] != NULL) {
        lista[2]->Accept(this); 
        }
}

void SemanticVisitor::visit(WHILENode* n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);
        lista[1]->Accept(this);
}
void SemanticVisitor::visit(PrintNode * n){
	vector <Nodo*> lista = n->lista;
        lista[0]->Accept(this);

}
void SemanticVisitor::visit(FORNode* n){ 
        vector<Nodo*> lista = n->lista;

        if(lista[0]->tipo.compare("var") != 0 ){
                cerr << "Error. Cerca de for, \""<<lista[0]->nombre() <<"\" no es una variable." << endl;
                exit(1);
        }
        if(lista[1]->tipo.compare("var") == 0){
                lista[1]->Accept(this);
                Record* r = ts->lookUp(lista[1]->nombre().c_str());
                Simbolo* ss = r->s;
                if(strcmp(ss->daTipo(),"string") != 0){cout << "EREET" << endl;
                cerr << "Error. Cerca de for, operación sobre tipo de dato no soportado." << endl;
                exit(1);
                }
        return;
        }
        
        if(lista[1]->tipo.compare("string") != 0){
                cerr << "Error. Cerca de for, operación sobre tipo de dato no soportado." << endl;
                exit(1);
        }
        Simbolo s (lista[0]->nombre().c_str(),"string",(void*)"algo");
        ts->insert(&s);

        lista[2]->Accept(this);


}

