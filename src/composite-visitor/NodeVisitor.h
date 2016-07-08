class Nodo;
class lNode;
class PlusNode;
class LeafNode;
class MinusNode;
class TimesNode;
class DivNode;
class PowNode;
class ModNode;
class PlusEqualNode;
class MinusEqualNode;
class TimesEqualNode;
class DivEqualNode;
class PowEqualNode;
class ModEqualNode;
class AndNode;
class OrNode;
class XorNode;
class EqualNode;
class LessNode;
class ModNode;
class LessEqualNode;
class ModEqualNode;
class Equal2Node;
class NotEqualNode;
class DifNode;
class MoreNode;
class MoreEqualNode;	
class IFNode;
class WHILENode;
class FORNode;
class FunctionNode;
class AsignacionNode;
class StmtListNode;
class IDENTNode;
class IntNode;
class StrNode;
class FloatNode;
class PrintNode;


class NodeVisitor {
public:
	//Terminales
	virtual void visit(Nodo*){};
        virtual void visit(IntNode*){}
        virtual void visit(IDENTNode*){};
        virtual void visit(StrNode*){};	
        virtual void visit(FloatNode*){};	
        //Aritmeticas
	virtual void visit(PlusNode*){};
	virtual void visit(MinusNode*){};
	virtual void visit(TimesNode*){};
	virtual void visit(DivNode*){};
	virtual void visit(PowNode*){};
	virtual void visit(ModNode*){};
	virtual void visit(PlusEqualNode*){};
	virtual void visit(MinusEqualNode*){};
	virtual void visit(TimesEqualNode*){};
	virtual void visit(DivEqualNode*){};
	virtual void visit(PowEqualNode*){};
	virtual void visit(ModEqualNode*){};
        virtual void visit(AsignacionNode*){};
        virtual void visit(StmtListNode*){};
        virtual void visit(PrintNode*){};
        
	//Booleanas
	virtual void visit(AndNode*){};
	virtual void visit(OrNode*){};
	virtual void visit(XorNode*){};
	virtual void visit(EqualNode*){};
	virtual void visit(LessNode*){};
	virtual void visit(MoreNode*){};
	virtual void visit(LessEqualNode*){};
	virtual void visit(MoreEqualNode*){};
	virtual void visit(Equal2Node*){};
	virtual void visit(NotEqualNode*){};
	virtual void visit(DifNode*){};
	virtual void visit(IFNode*){};
        virtual void visit(FORNode*){};
	virtual void visit(WHILENode*){};

        
protected:
	NodeVisitor(){};
};
