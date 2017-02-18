//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#include "View.h"
#include <iostream>
using namespace std;
View::View()
{
}
void View::showMenu()
{
	cout << "1. Load Data" << endl;
	cout << "2. Display Data" << endl;
	cout << "3. Run Simulation" <<endl;
	cout << "4. Display Results"<<endl;
	cout << "5. Exit" << endl;
}