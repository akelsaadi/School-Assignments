#include <iostream>
using namespace std;
#include "HospitalEmployee.h"
#include <string.h>
#pragma once



class Adminstrator: public HospitalEmployee{
private:
	string department;
public:
	Adminstrator();
	Adminstrator(string empName, int empNumber, string dept);
	void setDepartment(string dept);
	string getDepartment();
	string toString();
};