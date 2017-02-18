#pragma once
#include "Node.h"
#include "Node.cpp"
typedef int ItemType;
class AEBinarySearchTreeInterface
{
public:
	AEBinarySearchTreeInterface() {}
	virtual bool AEAdd(ItemType newType)=0;
	virtual bool AERemove(ItemType newType)=0;
