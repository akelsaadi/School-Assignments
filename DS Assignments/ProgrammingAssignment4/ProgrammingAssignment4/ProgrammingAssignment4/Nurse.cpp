#include "Nurse.h"

Nurse::Nurse()
{
	Nurse::HospitalEmployee(" ", 0);
	numPatients = 0;
}
Nurse::Nurse(string empName, int empNumber, int numPat)
{
	Nurse::HospitalEmployee(empName, empNumber);
	numPatients = numPat;
}
void Nurse::setNumPatients(int pat)
{
	numPatients = pat;
}	
int Nurse::getNumPatients()
{
	return numPatients;
}
string Nurse::toString()
{
	string nbp;
	stringstream ss;
	ss << numPatients;
	nbp = ss.str();
	return Nurse::HospitalEmployee::toString() + "Number of patients: " + nbp;
}