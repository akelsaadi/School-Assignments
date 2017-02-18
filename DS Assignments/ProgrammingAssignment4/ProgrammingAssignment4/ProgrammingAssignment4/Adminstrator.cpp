#include "Adminstrator.h"

Adminstrator::Adminstrator()
{
	Adminstrator::HospitalEmployee(" ",0);
	department = " ";

}
Adminstrator::Adminstrator(string empName, int empNumber, string dept)
{
	Adminstrator::HospitalEmployee(empName, empNumber);
	department = dept;
}
void Adminstrator::setDepartment(string dept)
{
	department = dept;
}
string Adminstrator::getDepartment()
{
	return department;
}
string Adminstrator::toString()
{
	return Adminstrator::HospitalEmployee::toString() + "Department: " + department + " ";
}