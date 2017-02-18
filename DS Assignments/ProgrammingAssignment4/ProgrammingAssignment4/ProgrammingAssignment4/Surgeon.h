#include <iostream>
#include "Doctor.h"
#pragma once

using namespace std;

class Surgeon: Doctor{
private:
	bool operating;
public:
	Surgeon();
	Surgeon(string empName, int empNumber, string special, bool isOp);
	bool getIsOperating();
	void setIsOperating(bool isO);
	string toString();
};