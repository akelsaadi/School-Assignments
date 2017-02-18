//Cosc 2320 Summer 2015
//Ali Elsaadi
//Programming Assignment 2
//This is my own work; I will not post

#include "Simulator.h"


	Simulator::Simulator()
	{
		sw = new Switch(bucketSize, frameReleaseRate);
	}
	void Simulator::loadData()
	{
			ifstream inFile("Programming Assignment 2 Data.txt");

			inFile >> bucketSize;
			inFile >> frameReleaseRate;
			inFile >> frameBurstProbability;
			inFile >> frameBurstSize;
			inFile >> simulationLength;

			sw = new Switch(bucketSize, frameReleaseRate);

			inFile.close();


	
	}
	void Simulator::displayData()
	{
			cout << "Bucket Size: " << bucketSize <<endl;
			cout << "Frame release rate: "<< frameReleaseRate <<endl;
			cout << "Simulation length: " << simulationLength <<endl;
			cout << "Probability of frame burst: " << frameBurstProbability <<endl;
			cout << "Size of frame burst: " << frameBurstSize;
	}

	void Simulator::runSimulator()
	{
		for (int currentTime=0; currentTime<=simulationLength; currentTime++)
		{
			double randomProbability=  ( rand()%101 ) / 100.0;
			if (randomProbability <= frameBurstProbability)
			{
				for (int i=0; i<frameBurstSize; i++)
				{
					sw->addFrame (currentTime); // just add the frame "time"
				}
			}

			sw->releaseFrames(currentTime);
		}

		saveData();
	}

	void Simulator::displayResults()
	{
		displayData();
		cout << " Number of frames Received: " << sw->getNumberFramesReceived() << endl;
		cout << " Number of frames Released: " << sw->getNumberFramesReleased() << endl;
		cout << " Number of frames Dropped: " << sw->getNumberFramesDropped() << endl;
		cout << " Average Wait Time: " << sw->getAverageWaitTime() << endl;


	}

	void Simulator::saveData()
	{
		ofstream out ("Programming Assignment 2 Data Output.txt", ios::app);

		out << sw->getNumberFramesReceived() << endl;
		out << sw->getNumberFramesReleased() << endl;
		out << sw->getNumberFramesDropped() << endl;
		out << sw->getAverageWaitTime() << endl;



		out.close();
	}
