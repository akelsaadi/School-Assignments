//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
	int value;
	Node* next;
public:
	Node();
	Node(const Node& object);
	virtual ~Node();
	bool hasNext();
	Node* getNext();
	void setNext(Node* newNext);
	int getValue();
	void setValue(int val);
};
