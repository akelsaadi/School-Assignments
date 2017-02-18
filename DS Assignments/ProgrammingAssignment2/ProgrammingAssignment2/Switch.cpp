//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post


#include "Switch.h"

Switch::Switch(int bucketSize, int releaseRate)
	{
		frameReleaseRate = releaseRate;

		// generate "bucketSize" number of nodes on the bucket(queue)
		bucket = new AELinkedQueue;
		bucket->setMaxSize(bucketSize);

		numberFramesReleased = 0;
		numberFramesDropped = 0;
		numberFramesReceived = 0;
		totalWaitTime = 0;
	}

void Switch::addFrame(int currTime)
	{
		//f.setArrivalTime(currTime);
		numberFramesReceived++;

		if(! bucket->AEisFull())
		{
			bucket->AEenqueue(currTime);
		}
		else
		{
			numberFramesDropped++;
		}
	}

void Switch::releaseFrames (int currTime)
	{
		int i;
		for (i=0; i<frameReleaseRate && !bucket->AEisEmpty(); i++)
		{
			int frameTime = bucket->AEdequeue();
			totalWaitTime = totalWaitTime + currTime - frameTime;
		}
		numberFramesReleased += i;
	}
int Switch:: getTotalWaitTime()
{
	return totalWaitTime;
}
int Switch::getNumberFramesReleased()
{
	return numberFramesReleased;
}
int Switch::getNumberFramesReceived()
{
	return numberFramesReceived;
}
int Switch::getNumberFramesDropped()
{
	return numberFramesDropped;
}
double Switch::getAverageWaitTime()
{
	return totalWaitTime/numberFramesReleased;
}