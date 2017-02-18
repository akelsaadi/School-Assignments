//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post


#include "AELinkedQueue.h"
class Switch
{
private:
	
	int frameReleaseRate;
	int numberFramesReleased;
	int numberFramesReceived;
	int numberFramesDropped;
	int totalWaitTime;
	AELinkedQueue* bucket;

public:
	Switch(int bucketSize, int releaseRate);

	void addFrame(int currTime);
	void releaseFrames (int currTime);
	int getTotalWaitTime();
	int getNumberFramesReleased();
	int getNumberFramesReceived();
	int getNumberFramesDropped();
	double getAverageWaitTime();

};