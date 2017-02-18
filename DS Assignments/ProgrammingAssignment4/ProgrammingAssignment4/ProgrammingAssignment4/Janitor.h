#include <iostream>
#include "Adminstrator.h"
#pragma once

using namespace std;

class Janitor: Adminstrator{
private:
	bool sweeping;
public:
	Janitor();
	Janitor(string empName, int empNumber, string dept, bool sw);
	void setIsSweeping(bool isS);
	bool getIsSweeping();
	string toString();
};