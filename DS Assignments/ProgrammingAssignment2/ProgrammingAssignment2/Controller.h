//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post


#pragma once
#include "Simulator.h"
class Controller
{
public:
	Controller();
	
	Simulator c;

	void UCLoadData();
	void UCDisplayData();
	void UCDisplayResults();
	void UCRunSimulation();
};