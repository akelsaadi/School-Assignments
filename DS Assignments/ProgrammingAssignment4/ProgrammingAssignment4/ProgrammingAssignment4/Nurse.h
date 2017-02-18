#include <iostream>
#include "HospitalEmployee.h"
#include <string>
#include <sstream>
#pragma once

using namespace std;

class Nurse: HospitalEmployee{
private:
	int numPatients;
public:
	Nurse();
	Nurse(string empName, int empNumber, int numPatients);
	void setNumPatients(int pat);
	int getNumPatients();
	string toString();
};
