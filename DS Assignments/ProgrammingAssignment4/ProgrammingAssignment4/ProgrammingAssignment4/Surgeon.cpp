#include "Surgeon.h"

Surgeon::Surgeon()
{
	Surgeon::Doctor( " ", 0, " ");
	operating = false;
}
Surgeon::Surgeon(string empName, int empNumber, string special, bool isOp)
{
	Surgeon::Doctor(empName, empNumber, special);
	operating = isOp;
}
bool Surgeon::getIsOperating()
{
	return operating;
}
void Surgeon::setIsOperating(bool isO)
{
	operating = isO;
}
string Surgeon::toString()
{
	char OP = 'N';
	if (operating)
		OP='y';
	return Surgeon::Doctor::toString() + "Operating: "+ OP;
}
