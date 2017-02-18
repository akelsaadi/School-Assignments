//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#include "Node.h"

Node::Node()
{}
Node::~Node()
{}
void Node::setNext(Node* newNext)
{
	if(newNext==NULL)
		next = NULL;
	else
	next=newNext;
}
Node::Node(const Node& object)
{
	next = object.next;
	value = object.value;
}
bool Node::hasNext()
{
	if(next != NULL)
		return true;
	else 
		return false;
}

Node* Node::getNext()
{
	return next;
}
int Node::getValue()
{
	return value;
}
void Node::setValue(int val)
{
	value = val;
}