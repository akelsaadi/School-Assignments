#include "HospitalEmployee.h"

HospitalEmployee::HospitalEmployee()
{
	name = "";
	number = 0;
}
HospitalEmployee::HospitalEmployee(string empName, int empNumber)
{
	name = empName;
	number = empNumber;
}
void HospitalEmployee::setName (string empName)
{
	name = empName;
}
void HospitalEmployee::setNumber(int empNumber)
{
	number = empNumber;
}
string HospitalEmployee::getName()
{
	return name;
}

int HospitalEmployee::getNumber()
{
	return number;
}

string HospitalEmployee::toString()
{
	string nb;
	stringstream ss;
	ss << number;
	nb = ss.str();
	return "Name:" + name + " " + "Number:" + " " + nb + " " ;
}
