//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#include <iostream>
#include "Controller.h"
#include "View.h"
#include <iostream>

using namespace std;
int main(){
	View v;
	Controller c;
	int choice;
	do{
		v.showMenu();
		cin >> choice;
		switch(choice)
		{
			case 1:
				c.UCLoadData();
				break;
			case 2:
				c.UCDisplayData();
				break;
			case 3:
				c.UCRunSimulation();
				break;
			case 4:
				c.UCDisplayResults();
				break;
			case 5:
				system("exit");
				break;
		}
	}while(choice !=5);
	system("pause");
	return 0;
}