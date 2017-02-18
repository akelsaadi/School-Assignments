//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#pragma once
#include "Node.h"
typedef int QueueItemType;

class AELinkedQueueInterface
{
public:
	AELinkedQueueInterface(){}

	virtual bool AEisEmpty()=0;
	virtual void AEenqueue(QueueItemType newType)=0;
	virtual bool AEdequeue()=0;
	virtual Node* AEgetFront()=0;

private:
};
