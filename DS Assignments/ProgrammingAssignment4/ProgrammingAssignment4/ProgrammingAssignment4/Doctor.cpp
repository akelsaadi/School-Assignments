#include "Doctor.h"

Doctor::Doctor()
{
	Doctor::HospitalEmployee(" ", 0);
	specialty = " ";
}
Doctor::Doctor(string empName, int empNumber, string special)
{
	Doctor::HospitalEmployee(empName, empNumber);
	specialty = special;
}
void Doctor::setSpecialty(string special)
{
	specialty = special;
}
string Doctor::getSpecialty()
{
	return specialty;
}
string Doctor::toString()
{
	return Doctor::HospitalEmployee::toString() + "Specialty: " + specialty;
}
