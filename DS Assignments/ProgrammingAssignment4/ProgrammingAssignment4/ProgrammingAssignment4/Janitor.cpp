#include "Janitor.h"

Janitor::Janitor()
{
	Janitor::Adminstrator( " " , 0 , " " );
	sweeping = false;
}
Janitor::Janitor(string empName, int empNumber, string dept, bool sw)
{
	Janitor::Adminstrator(empName, empNumber, dept);
	sweeping = sw;
}
void Janitor :: setIsSweeping(bool isS)
{
	sweeping = isS;
}
bool Janitor :: getIsSweeping()
{
	return sweeping;
}
string Janitor::toString()
{
	char SW = 'N';
	if (sweeping)
		SW = 'T';
	return Janitor::Adminstrator::toString() + SW;
}