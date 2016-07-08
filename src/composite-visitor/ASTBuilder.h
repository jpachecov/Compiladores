class ASTBuilder{
public:
	virtual void makeSiblings(Nodo*n,Nodo*ns)=0;
	
	virtual Nodo* bPlusNode()=0;
	virtual Nodo* bMinusNode()=0;
	virtual Nodo* bTimesNode()=0;
	virtual Nodo* bDivNode()=0;
	virtual Nodo* bPowNode()=0;
	virtual Nodo* bModNode()=0;
	virtual Nodo* bPlusEqualNode()=0;
	virtual Nodo* bMinusEqualNode()=0;
	virtual Nodo* bTimesEqualNode()=0;
	virtual Nodo* bDivEqualNode()=0;
	virtual Nodo* bPowEqualNode()=0;
	virtual Nodo* bModEqualNode()=0;
	
	virtual Nodo* bAndNode()=0;
	virtual Nodo* bOrNode()=0;
	virtual Nodo* bXorNode()=0;
	virtual Nodo* bEqualNode()=0;
	virtual Nodo* bLessNode()=0;
	virtual Nodo* bMoreNode()=0;
	virtual Nodo* bEqual2Node()=0;
	virtual Nodo* bLessEqualNode()=0;
	virtual Nodo* bMoreEqualNode()=0;
	virtual Nodo* bNotEqualNode()=0;
	virtual Nodo* bDifNode()=0;
	
	virtual Nodo* bIFNode()=0;
	virtual Nodo* bWHILENode()=0;
	virtual Nodo* bFORNode()=0;
	virtual Nodo* bFunctionNode()=0;
	virtual Nodo* bIntNode(int)=0;
	virtual Nodo* bLongNode(long)=0;
	virtual Nodo* bFloatNode(float)=0;
	virtual Nodo* bBoolNode(string)=0;
	virtual Nodo* bStrNode(string)=0;
	virtual Nodo* bIDENTNode(string)=0;
	virtual Nodo* bRETURNNode(string)=0;
};
