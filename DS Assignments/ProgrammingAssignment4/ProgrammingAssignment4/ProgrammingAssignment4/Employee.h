#include <iostream>
#include <fstream>
using namespace std;
#include <cstdlib>
#pragma once


class Employee {

public:

	Employee();
	void loadData();
	void displayDepth();
	void displayBreath();
	void displayLevel();
	void searchRole();
	void searchName();
	void addEmployee();
	void removeEmployee();
	void save();
};