class AndNode : public BinNode{
public:
	AndNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

AndNode::AndNode(){
}

void AndNode::show(){
	cout<<"&";
	BinNode::show();
}


class OrNode : public BinNode{
public:
	OrNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

OrNode::OrNode(){
}

void OrNode::show(){
	cout<<"|";
	BinNode::show();
}


class XorNode : public BinNode{
public:
	XorNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

XorNode::XorNode(){
}


void XorNode::show(){
	cout<<"^";
	BinNode::show();
}



class EqualNode : public BinNode{
public:
	EqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

EqualNode::EqualNode(){
}

void EqualNode::show(){
	cout<<"=";
	BinNode::show();
}

class LessNode : public BinNode{
public:
	LessNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

LessNode::LessNode(){
}

void LessNode::show(){
	cout<<"<";
	BinNode::show();
}

class MoreNode : public BinNode{
public:
	MoreNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

MoreNode::MoreNode(){
}

void MoreNode::show(){
	cout<<">";
	BinNode::show();
}


class Equal2Node : public BinNode{
public:
	Equal2Node();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

Equal2Node::Equal2Node(){
}

void Equal2Node::show(){
	cout<<"==";
	BinNode::show();
}


class LessEqualNode : public BinNode{
public:
	LessEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

LessEqualNode::LessEqualNode(){
}

void LessEqualNode::show(){
	cout<<"<=";
	BinNode::show();

}

class MoreEqualNode : public BinNode{
public:
	MoreEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

MoreEqualNode::MoreEqualNode(){
}

void MoreEqualNode::show(){
	cout<<">=";
	BinNode::show();
}


class NotEqualNode : public BinNode{
public:
	NotEqualNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

NotEqualNode::NotEqualNode(){}

void NotEqualNode::show(){
	cout<<"!=";
	BinNode::show();
}



class DifNode : public BinNode{
public:
	DifNode();
	void show();
	void Accept(NodeVisitor* v){
  	v->visit(this); 
	}
};

DifNode::DifNode(){}

void DifNode::show(){
	cout<<"<>";
	BinNode::show();
}
