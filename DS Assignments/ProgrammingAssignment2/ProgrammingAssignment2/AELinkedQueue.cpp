//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#include "AELinkedQueue.h"
AELinkedQueue::AELinkedQueue()
{
	backPtr = frontPtr = NULL;
	nodeCount = 0;
}
AELinkedQueue::~AELinkedQueue()
{
	while(!AEisEmpty())
	AEdequeue();
}
bool AELinkedQueue::AEisEmpty()
{
	return backPtr==NULL;
}

bool AELinkedQueue::AEisFull()
{
	return nodeCount==maxSize;
}
void AELinkedQueue::AEenqueue(QueueItemType newItem)
{
	Node *newPtr = new Node();
	newPtr->setValue(newItem);
	newPtr->setNext(NULL);

	// newPtr=newItem;

	// enqueue

	if (frontPtr == NULL) // if the linked queue is initially empty
	{
		// this special case will be the ONLY one updating the frontPtr
		frontPtr = newPtr;
		backPtr = newPtr;
	}
	else // for all other cases
	{
		// we just add the new node at the "backPtr" side
		backPtr->setNext(newPtr);
		backPtr = newPtr;
	}

	nodeCount ++;
}

bool AELinkedQueue::AEdequeue()
{
	if (nodeCount == 0)
	{
		return false;
	}
	else if (nodeCount == 1)
	{
		frontPtr = NULL;
		backPtr = NULL;
		nodeCount = 0;
		return true;
	}
	else
	{
		frontPtr = frontPtr->getNext();
		nodeCount--;
		return true;
	}
}

Node* AELinkedQueue::AEgetFront()
{
	return frontPtr;
}

void AELinkedQueue::setMaxSize(int size)
{
	maxSize = size;
}