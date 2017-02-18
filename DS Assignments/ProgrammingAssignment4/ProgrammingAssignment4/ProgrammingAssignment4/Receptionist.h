#include <iostream>
#include "Adminstrator.h"
#pragma once

using namespace std;

class Receptionist: Adminstrator{
private:
	bool answering;
public:
	Receptionist();
	Receptionist(string empName, int empNumber, string dept, bool ans);
	void setIsAnswering(bool isA);
	bool getIsAnswering();
	string toString();
};
