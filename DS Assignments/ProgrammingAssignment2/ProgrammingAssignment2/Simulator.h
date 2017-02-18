//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post
#pragma once
#include <cstdlib>
#include <string>
#include <fstream>
#include "Switch.h"
using namespace std;
class Simulator
{
private:
	int bucketSize;
	int frameReleaseRate;
	double frameBurstProbability;
	int frameBurstSize;
	int simulationLength;

	Switch* sw;
public:

	Simulator();
	void displayData();
	void runSimulator();
	void displayResults();
	void saveData();
	void loadData();
};