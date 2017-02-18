#include <iostream>
using namespace std;
#include "Employee.h"
#pragma once
class Controller {
public:

	Controller();
	Employee emp;
	void UCLoadData();
	void UCDisplayDepth();
	void UCDisplayBreath();
	void UCDisplayLevel();
	void UCSearchRole();
	void UCSearchName();
	void UCAdd();
	void UCRemove();
	void UCSave();
	void UCQuit();
};