#include "Controller.h"


Controller::Controller()
{
}
void Controller::UCLoadData()
{
	emp.loadData();
}
	
void Controller::UCDisplayDepth()
{
	emp.displayDepth();
}
void Controller::UCDisplayBreath()
{
	emp.displayBreath();
}
void Controller::UCDisplayLevel()
{
	emp.displayLevel();
}
void Controller::UCSearchRole()
{
	emp.searchRole();
}
void Controller::UCSearchName()
{
	emp.searchName();
}
void Controller::UCAdd()
{
	emp.addEmployee();
}
void Controller::UCRemove()
{
	emp.removeEmployee();
}
void Controller::UCSave()
{
	emp.save();
}
