#include "Receptionist.h"

Receptionist::Receptionist()
{
	Receptionist::Adminstrator(" ", 0, " ");
	answering = false;
}
Receptionist::Receptionist(string empName, int empNumber, string dept, bool ans)
{
	Receptionist::Adminstrator(empName, empNumber, dept);
	answering = ans;
}
void Receptionist::setIsAnswering(bool isA)
{
	answering = isA;
}
bool Receptionist::getIsAnswering()
{
	return answering;
}
string Receptionist:: toString()
{
	char Ans = 'N';
	if (answering)
		Ans = 'Y';
	return Receptionist::Adminstrator::toString() + "Answering: " + Ans;
}