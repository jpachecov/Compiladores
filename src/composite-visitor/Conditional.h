class StmtListNode: public lNode{
public:
        StmtListNode(){};
        void show(){
        cout << "StmtListNode ";
        lNode::show();
        };
        void Accept(NodeVisitor* v){
        v->visit(this);
        };
};

class ExprNode:public lNode{

public:
        ExprNode(){};
        void show(){
        cout << "expr";
        lNode::show();
        };
        void Accept(NodeVisitor* v){
        v->visit(this);
        };
};

// if bool : x else: y
class IFNode : public lNode{
public:
	IFNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

IFNode::IFNode(){
}

void IFNode::show(){
	cout<<"if";
	lNode::show();
}

//while x :
class WHILENode : public lNode{
public:
	WHILENode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

WHILENode::WHILENode(){

}

void WHILENode::show(){
	cout<<"while";
	lNode::show();
}

class PrintNode: public lNode{
public:
        string t;
	PrintNode(){t = "print";};
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}

};
void PrintNode::show(){
	cout<<"print";
	lNode::show();
}

// for x in y:
class FORNode : public lNode{

public:
	FORNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

FORNode::FORNode(){
}

void FORNode::show(){
	cout<<"for";
	lNode::show();
}

//def indentifier()
class FunctionNode : public lNode{
public:
	FunctionNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

FunctionNode::FunctionNode(){
}

void FunctionNode::show(){
	cout<<"def";
	lNode::show(); 
}

