#include "Node.h"


Node::Node()
{}
Node::~Node()
{}
Node::Node(const Node& object)
{
	right = object.right;
	left = object.left;
	value = object.value;
}
void Node::setValue(int val)
{
	value = val;
}
void Node::setLeft(Node* newLeft)
{
	left = newLeft;
}
void Node::setRight(Node* newRight)
{
	right = newRight;
}
int Node::getValue()
{
	return value;
}
Node* Node::getLeft()
{
	return left;
}
Node* Node::getRight()
{
	return right;
}