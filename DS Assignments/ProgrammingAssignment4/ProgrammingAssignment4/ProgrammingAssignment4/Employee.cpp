#include "Employee.h"
#include "Surgeon.h"
#include "Nurse.h"
#include "Janitor.h"
#include "Receptionist.h"
Employee::Employee()
{
}

void Employee::loadData()
{
	HospitalEmployee hospemp;
	Doctor doc;
	ifstream inFile("Programming Assignment 4 Data.txt");
	string currentPhrase;
	string key;
	int num;
	inFile >> currentPhrase;
	inFile >> key;
	inFile >> num;
	if (currentPhrase == "h")
	{
		
		hospemp.setName(key);
		hospemp.setNumber(num);
	}
	else if (currentPhrase == "d")
	{


}
void Employee::addEmployee()
{
}
void Employee::removeEmployee()
{
}
void Employee::displayBreath()
{
}
void Employee::displayDepth()
{
}
void Employee::displayLevel()
{
}
void Employee::searchName()
{
}
void Employee::searchRole()
{
}
void Employee::save()
{
}