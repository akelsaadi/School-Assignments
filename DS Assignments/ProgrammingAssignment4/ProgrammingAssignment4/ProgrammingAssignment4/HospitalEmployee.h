#include <iostream>
#include <string>
#include <sstream>
#pragma once

using namespace std;

class HospitalEmployee{
private:
	string name;
	int number;

public:
	HospitalEmployee();
	HospitalEmployee(string empName, int empNumber);
	void setName(string empName);
	void setNumber(int empNumber);
	string getName();
	int getNumber();
	string toString();
};