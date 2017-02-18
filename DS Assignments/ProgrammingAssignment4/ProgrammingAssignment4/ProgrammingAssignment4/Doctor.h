#include <iostream>
#include "HospitalEmployee.h"
#pragma once

using namespace std;

class Doctor: HospitalEmployee{
private:
	string specialty;
public:
	Doctor();
	Doctor(string empName, int empNumber, string special);
	void setSpecialty(string special);
	string getSpecialty();
	string toString();
};