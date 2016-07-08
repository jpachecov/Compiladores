#ifndef YYTOKENTYPE
#define YYTOKENTYPE
#include <iomanip>
#include <locale>
#include <iostream>
#include <vector>
#include <string>	
#include <sstream> 
#include <algorithm>
#include "NodeVisitor.h"
#include "Node.h"
#include "LeafNode.h"
#include "lNode.h"
#include "BinNode.h"
#include "Terminals.h"
#include "Arithmetics.h"
#include "Booleans.h"
#include "Conditional.h"
#include "ASTBuilder.h"
#include "PrintVisitor.h"
#include "SemanticVisitor.h"
#include "CodeVisitor.h"

class MASTBuilder: public ASTBuilder{
public:
		//MASTBuilder (){}
	void makeSiblings(Nodo* n1,Nodo* n2){
		n1->makeSiblings(n2);
	}
        Nodo* bStmtListNode(){
                return new StmtListNode();
        }
        Nodo* bPrintNode(){
                return new PrintNode();
        }
        Nodo* bAsignacionNode(){
                return new AsignacionNode();
        }
        Nodo* bCorrimIzqNode(){
                return new CorrimIzq();
        }
        Nodo* bCorrimDerNode(){
                return new CorrimDer();
        }
        Nodo* bAndIgualNode(){
                return new AndIgual();
        }
        Nodo* bOrIgualNode(){
                return new OrIgual();
        }
        Nodo* bXorIgualNode(){
                return new XorIgual();
        }
        Nodo* bCorIzqIgualNode(){
                return new CorIzqIgual();
        }
        Nodo* bCorDerIgualNode(){
                return new CorDerIgual();
        }
        Nodo* bPowIgualNode(){
                return new PowIgual();
        }
        Nodo* bDiventIgualNode(){
                return new DivEntIgual();
        }

	Nodo* bPlusNode(){
		return new PlusNode;
	}
	Nodo* bMinusNode(){
		return new MinusNode;
	}
	Nodo* bTimesNode(){
		return new TimesNode;
	}
	Nodo* bDivNode(){
		return new DivNode;
	}
	Nodo* bPowNode(){
		return new PowNode;
	}
	Nodo* bModNode(){
		return new ModNode;
	}
	Nodo* bPlusEqualNode(){
		return new PlusEqualNode;
	}
	Nodo* bMinusEqualNode(){
		return new MinusEqualNode;
	}
	Nodo* bTimesEqualNode(){
		return new TimesEqualNode;
	}
	Nodo* bDivEqualNode(){
		return new DivEqualNode;
	}
	Nodo* bPowEqualNode(){
		return new PowEqualNode;
	}
	Nodo* bModEqualNode(){
		return new ModEqualNode;
	}

	Nodo* bAndNode(){
		return new AndNode;
	}
	Nodo* bOrNode(){
		return new OrNode;
	}
	Nodo* bXorNode(){
		return new XorNode;
	}
	Nodo* bEqualNode(){
		return new EqualNode;
	}
	Nodo* bLessNode(){
		return new LessNode;
	}
	Nodo* bMoreNode(){
		return new MoreNode;
	}
	Nodo* bEqual2Node(){
		return new Equal2Node;
	}
	Nodo* bLessEqualNode(){
		return new LessEqualNode;
	}
	Nodo* bMoreEqualNode(){
		return new MoreEqualNode;
	}
	Nodo* bNotEqualNode(){
		return new NotEqualNode;
	}
	Nodo* bDifNode(){
		return new DifNode;
	}
	
	Nodo* bIFNode(){
		return new IFNode;
	}
	Nodo* bWHILENode(){
		return new WHILENode;
	}
	Nodo* bFORNode(){
		return new FORNode;
	}
	Nodo* bFunctionNode(){
		return new FunctionNode;
	}
	Nodo* bIntNode(int n){
		return new IntNode(n);
	}
	Nodo* bLongNode(long n){
		return new LongNode(n);
	}
	Nodo* bFloatNode(float n){
		return new FloatNode(n);
	}
	Nodo* bBoolNode(string s){
		return new BoolNode(s);
	}
	Nodo* bStrNode(string s){
		return new StrNode(s);
	}
	Nodo* bIDENTNode(string s){
		return new IDENTNode(s);
	}
	Nodo* bRETURNNode(string s){
		return new RETURNNode(s);
	}

};

#endif	
