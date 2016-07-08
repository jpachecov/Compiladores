
class LeafNode : public Nodo{
public:
	LeafNode();
        //string tipo;
	LeafNode (string);
	virtual void show();
	void Accept(NodeVisitor* v){
        v->visit(this);
                
        };
};
LeafNode::LeafNode(){}
LeafNode::LeafNode(string n) { 
	name = n; 
}


void LeafNode::show(){
	cout  << name<<" ";
}
 
