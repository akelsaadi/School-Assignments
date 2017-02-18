#include <iostream>
#include <string>
#pragma once


using namespace std;

class Node
{
private:
	int value;
	Node* left;
	Node* right;
public:
	Node();
	Node(const Node& object);
	virtual ~Node();
	void setValue(int val);
	void setLeft(Node* newLeft);
	void setRight(Node* newRight);
	int getValue();
	Node* getLeft();
	Node* getRight();
};