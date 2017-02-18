//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

typedef int QueueItemType;
#include "Node.h"
#include "AELinkedQueueInterface.h"
#pragma once
class AELinkedQueue : public AELinkedQueueInterface
{
public :
	AELinkedQueue();
	~AELinkedQueue();
	bool AEisEmpty();
	bool AEisFull();
	void AEenqueue(QueueItemType newType);
	bool AEdequeue();
	bool AEdequeue(QueueItemType& queueFront);
	Node* AEgetFront();

	void setMaxSize(int size);
private:
	Node *backPtr;
	Node *frontPtr;
	int nodeCount;
	int maxSize;
};