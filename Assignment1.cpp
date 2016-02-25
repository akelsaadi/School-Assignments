

//Definition for Instruction class.
#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>

class Instruction
{
	private:
		std::string instrucType;
		int instrucRunTime;
		int sequenceNum;
		int startTime;
	public:
		Instruction();
		Instruction(std::string type, int instrucTime, int seqNum, int time);
		~Instruction();
		std::string getInstrucType();
		void setInstrucType(std::string type);
		int getInstrucRunTime();
		void setInstrucRunTime(int instrucTime);
		int getSequenceNum();
		void setSequenceNum(int seqNum);
		int getInstrucStartTime();
		void setInstrucStartTime(int sTime);
};
#endif

//Implementation for Instruction class.
#include <string>
using namespace std;

Instruction::Instruction()
{
	instrucRunTime = 0;
	instrucType = "";
}

Instruction::Instruction(string type, int instrucTime, int seqNum, int time)
{
	instrucType = type;
	instrucRunTime = instrucTime;
	sequenceNum = seqNum;
	startTime = time;
}

Instruction::~Instruction(){
}

string Instruction::getInstrucType()
{
	return instrucType;
}

void Instruction::setInstrucType(string type)
{
	instrucType = type;
}

int Instruction::getInstrucRunTime()
{
	return instrucRunTime;
}
void Instruction::setInstrucRunTime(int instrucTime)
{
	instrucRunTime = instrucTime;
}

int Instruction::getSequenceNum()
{
	return sequenceNum;
}

void Instruction::setSequenceNum(int seqNum)
{
	sequenceNum = seqNum;
}

int Instruction::getInstrucStartTime()
{
	return startTime;
}

void Instruction::setInstrucStartTime(int sTime)
{
	startTime = sTime;
}

//Definition for Process class.
#ifndef PROCESS_H
#define PROCESS_H
#include <queue>
#include <string>

class Process
{
	private:
		int processNum;
		int processStartTime;
	public:
		Process();
		Process(int processNumber, int processSTime, double processTTime);
		~Process();
		double processTotalTime;
		int getProcessNum();
		void setProcessNum(int pNum);
		int getProcessStartTime();
		void setProcessStartTime(int processSTime);
		int getProcessSequenceNum();
		int getProcessInstrucStartTime();
		std::string getProcessInstrucType();
		int getProcessInstrucRunTime();
		int getTotalInstruc();
		Instruction createProcessInstruc(std::string type, int instrucTime, int seqNum, int time);
		void insertInstrucToQueue(Instruction instruc);
		void clearQueue();
		void printQueue();
		std::queue<Instruction> instrucQueue;
		int coreTime;
};
#endif

//Implementation for Process class.
#include <string>
#include <queue>
#include <iostream>

using namespace std;

Process::Process()
{
	processNum = 0;
	processStartTime = -1;
	processTotalTime = 0;
	coreTime = 0;
}

Process::Process(int processNumber, int processSTime,double processTTime)
{
	processNum = processNumber;
	processStartTime = processSTime;
	processTotalTime = processTTime;
}

Process::~Process()
{

}
int Process::getProcessNum()
{
	return processNum;
}

void Process::setProcessNum(int pNum)
{
	processNum = pNum;
}

int Process::getProcessStartTime()
{
	return processStartTime;
}

void Process::setProcessStartTime(int processSTime)
{
	processStartTime = processSTime;
}

int Process::getProcessSequenceNum()
{
	Instruction temp = instrucQueue.front();
	return temp.getSequenceNum();
}

int Process::getProcessInstrucStartTime()
{
	Instruction temp = instrucQueue.front();
	return temp.getInstrucStartTime();
}

string Process::getProcessInstrucType()
{
	Instruction temp = instrucQueue.front();
	return temp.getInstrucType();
}

int Process::getProcessInstrucRunTime()
{
	Instruction temp = instrucQueue.front();
	return temp.getInstrucRunTime();
}

int Process::getTotalInstruc()
{
	return instrucQueue.size();
}

Instruction Process::createProcessInstruc(string type, int instrucTime, int seqNum, int time)
{
	Instruction processInstruc(type,instrucTime, seqNum, time);
	return processInstruc;
}

void Process::insertInstrucToQueue(Instruction instruc)
{
	Instruction processInstruc = instruc;
	instrucQueue.push(processInstruc);
}

void Process::clearQueue()
{
	while(!instrucQueue.empty())
	{
		instrucQueue.pop();
	}
}

void Process::printQueue()
{
	if(instrucQueue.empty())
	{
		cout << "There is nothing in the process queue." << endl;
	}
	else
	{
		while(!instrucQueue.empty())
		{
			cout << getProcessInstrucType() <<
			" " << getProcessInstrucRunTime() <<
			" " << getProcessSequenceNum() <<
			" " << getProcessInstrucStartTime() << endl;
			instrucQueue.pop();
		}
	}
}

//Definition for QueueEntry class.
#ifndef QUEUEENTRY_H
#define QUEUEENTRY_H
class QueueEntry
{
	public:
		int processID;
		int requestDuration;
};
#endif

//Definition for Computer Status class.
#ifndef COMPUTERSTATUS_H
#define COMPUTERSTATUS_H
#include <string>
#include <queue>

class ComputerStatus
{
	public:
		ComputerStatus();
		int clock;
		double coreClock;
		int coreOneStatus;
		int coreTwoStatus;

		int diskStatus;
		int inputStatus;
		int previousInputTime;
		int previousDiskTime;
		int previousCore1Time;
		int previousCore2Time;

		std::queue<QueueEntry> readyQueue;
		std::queue<QueueEntry> diskQueue;
		std::queue<QueueEntry> inputQueue;
};
#endif

//Implementation for ComputerStatus.
using namespace std;

ComputerStatus::ComputerStatus()
{
	clock = 0;
	coreClock = 0;
	coreOneStatus = 0;
	coreTwoStatus = 0;

	diskStatus = 0;
	inputStatus = 0;
	previousCore1Time = 0;
	previousCore2Time = 0;

}

//Definition for Event class.
#ifndef EVENT_H
#define EVENT_H
#include <string>

class Event
{
	private:
		int eventTime;
		string eventType;
		int processID;
	public:
		Event();
		Event(int eTime, string evType, int pID);
		int getEventTime();
		void setEventTime(int eTime);
		string getEventType();
		void setEventType(string evType);
		int getProcessID();
		void setProcessID(int pID);
};
#endif

//Implementation for Event class.
using namespace std;

Event::Event()
{
	eventTime = 0;
	eventType = "";
	processID = 0;
}

Event::Event(int eTime, string evType, int pID)
{
	eventTime = eTime;
	eventType = evType;
	processID = pID;
}

int Event::getEventTime()
{
	return eventTime;
}

void Event::setEventTime(int eTime)
{
	eventTime = eTime;
}

string Event::getEventType()
{
	return eventType;
}

void Event::setEventType(string evType)
{
	eventType = evType;
}

int Event::getProcessID()
{
	return processID;
}
void Event::setProcessID(int pID)
{
	processID = pID;
}

//Definition for ProcessStatus class.
#ifndef PROCESSSTATUS_H
#define PROCESSSTATUS_H
#include <string>

class ProcessStatus
{
	public:
		ProcessStatus();
		int processID;
		string processStatus;
};
#endif

//Implementation for ProcessStatus class.
using namespace std;
ProcessStatus::ProcessStatus()
{
	processID = 0;
	processStatus = "";
}

//Driver.
#include <iomanip>
#include <iostream>
#include <queue>
#include <deque>
#include <list>

using namespace std;

void initialize(deque<Process*> &, list<Event> &);
void arrival(deque<Process*> &, ComputerStatus &, int pid, list<Event> &);
void core_request(deque<Process*> &,int pid, int runTime, ComputerStatus &, list<Event> &);
void core_completion(deque<Process*> &, ComputerStatus &, int pid, list<Event> &);
void disk_request(deque<Process*> &,int pid, int runTime, ComputerStatus &, list<Event> &);
void disk_completion(deque<Process*> &, ComputerStatus &, int pid, list<Event> &);
void input_request(deque<Process*> &,int pid, int runTime, ComputerStatus &, list<Event> &);
void input_completion(deque<Process*> &, ComputerStatus &, int pid, list<Event> &);
void next_request(deque<Process*> &,int pid, ComputerStatus &, list<Event> &);
deque<ProcessStatus> processTable;

//Structure that allows me to sort the event list.
struct CompareTime
{
	bool operator()(Event lhs,Event rhs){
	return lhs.getEventTime() < rhs.getEventTime();}
};

int main()
{
	deque<Process*> processQueue;
	ComputerStatus computer;
	list<Event> eventList;
	initialize(processQueue,eventList);
	Event tempEvent = eventList.front();

	int queueSize = processQueue.size();
	int processNumbers[queueSize];
	int arrayNum;

	for(int i = 0; i < queueSize; i++)
	{
		processNumbers[i] = processQueue[i]->getProcessNum();
	}

	while(!eventList.empty())
	{
		eventList.sort(CompareTime());
		Event tempEvent = eventList.front();

		for(int j = 0; j < queueSize; j++)
		{
			if(tempEvent.getProcessID() == processNumbers[j])
			{
				arrayNum = j;
			}
		}

	//	cout << "Now processing: ";
	//	cout << tempEvent.getEventType() << " ";
	//	cout << tempEvent.getEventTime() << " ";
	//	cout << tempEvent.getProcessID() << endl;

		computer.clock = tempEvent.getEventTime();

		if(tempEvent.getEventType() == "START")
		{
			arrival(processQueue,computer, arrayNum,eventList);
		}
		else if(tempEvent.getEventType() == "CORE")
		{
			core_completion(processQueue,computer, arrayNum,eventList);
		}
		else if(tempEvent.getEventType() == "DISK")
		{
			disk_completion(processQueue,computer, arrayNum,eventList);
		}
		else if(tempEvent.getEventType() == "I/O")
		{
			input_completion(processQueue,computer, arrayNum,eventList);
		}
		eventList.pop_front();
	}


	return 0;
}

//Function that adds to ready queue.

void initialize(deque<Process*> & processQueue, list<Event> & eventList)
{
	string input;
	int sequenceNumber;
	int parameterNumber;
	int startTime;
	int procNum = 0;
	Process *process;
	while(cin >> input)
	{
		if(input == "START")
		{
			process = new Process;
			cin >> parameterNumber;
			process->setProcessNum(procNum);

			ProcessStatus tempStatus;
			tempStatus.processID = procNum;
			tempStatus.processStatus = "";
			processTable.push_back(tempStatus);

			sequenceNumber = 0;

			Event firstEvent;
			firstEvent.setEventTime(parameterNumber);
			firstEvent.setEventType(input);
			firstEvent.setProcessID(procNum);
			eventList.push_back(firstEvent);
			process->setProcessStartTime(parameterNumber);
			processQueue.push_back(process);
			startTime = parameterNumber;
			process->processTotalTime = parameterNumber;
			procNum++;
		}
		else if(input == "END")
		{


		}
		else
		{
			cin >> parameterNumber;
			process -> insertInstrucToQueue(process->createProcessInstruc(input,parameterNumber,sequenceNumber,startTime));
			sequenceNumber++;
			startTime += parameterNumber;
		}
	}
}

//Arrival function that reads the first START
void arrival(deque<Process*> &processQueue, ComputerStatus &computer, int pid, list<Event> &eventList)
{
	Instruction temp = processQueue[pid]->instrucQueue.front();
	processQueue[pid]->instrucQueue.pop();
	if(temp.getInstrucType() == "CORE")
	{
		core_request(processQueue,pid,temp.getInstrucRunTime(),computer,eventList);
	}
	else
	{
		cout << "Panic!" << endl;
	}
}

//Function that calls for a core request. Creates core completion event.
void core_request(deque<Process*> &processQueue,int pid, int runTime, ComputerStatus &computer,list<Event> &eventList)
{
	processQueue[pid]->processTotalTime = processQueue[pid]->processTotalTime + runTime;
	if(computer.coreOneStatus == 0)
	{
		computer.coreOneStatus = 1;
		processTable[pid].processStatus = "RUNNING";
		computer.coreClock = computer.coreClock + runTime;
		processQueue[pid]->coreTime = processQueue[pid]->coreTime + runTime;
		Event newEvent(processQueue[pid]->processTotalTime,"CORE",pid);
		eventList.push_back(newEvent);
	}

	else if(computer.coreTwoStatus == 0)
	{
		computer.coreTwoStatus = 1;
		processTable[pid].processStatus = "RUNNING";
		computer.coreClock = computer.coreClock + runTime;
		processQueue[pid]->coreTime = processQueue[pid]->coreTime + runTime;
		Event newEvent(processQueue[pid]->processTotalTime,"CORE",pid);
		eventList.push_back(newEvent);
	}
	else
	{
		processTable[pid].processStatus = "READY";
		QueueEntry queueInfo;
		queueInfo.processID = pid;
		queueInfo.requestDuration = runTime;
		computer.readyQueue.push(queueInfo);
	}
}

//Core completion event function, frees up cores or ready queue.
void core_completion(deque<Process*> &processQueue, ComputerStatus &computer, int pid, list<Event> &eventList)
{
	if(computer.readyQueue.empty())
	{
		if(computer.coreOneStatus == 1)
		{
			computer.coreOneStatus = 0;
		}

		else if(computer.coreTwoStatus == 1)
		{
			computer.coreTwoStatus = 0;
		}
	}
	else
	{
		processTable[pid].processStatus = "RUNNING";
		QueueEntry tempEntry = computer.readyQueue.front();
		int tempPID = tempEntry.processID;
		int tempDuration = tempEntry.requestDuration;
		computer.readyQueue.pop();
		int tempTime = processQueue[tempPID]->processTotalTime + tempDuration;
		Event newEvent(tempTime,"CORE",tempPID);
		eventList.push_back(newEvent);
		computer.coreClock = computer.coreClock + tempTime;
		processQueue[pid]->coreTime = processQueue[pid]->coreTime + tempTime;
	}
	next_request(processQueue,pid,computer,eventList);
}

//Disk request function. Creates disk completion event or adds to disk queue.
void disk_request(deque<Process*> &processQueue,int pid, int runTime, ComputerStatus &computer, list<Event> &eventList)
{
	processQueue[pid]->processTotalTime = processQueue[pid]->processTotalTime + runTime;
	if(computer.diskStatus == 0)
	{
		computer.diskStatus = 1;
		processTable[pid].processStatus = "RUNNING";
		computer.previousDiskTime = processQueue[pid]->processTotalTime;
		Event newEvent(processQueue[pid]->processTotalTime,"DISK",pid);
		eventList.push_back(newEvent);
	}
	else
	{
		processTable[pid].processStatus = "WAITING";
		QueueEntry queueInfo;
		queueInfo.processID = pid;
		queueInfo.requestDuration = runTime;
		computer.diskQueue.push(queueInfo);
	}
}

//Disk completion event function. Frees up disk or adds from disk queue.
void disk_completion(deque<Process*> &processQueue, ComputerStatus &computer, int pid, list<Event> &eventList)
{
	if(computer.diskQueue.empty())
	{
		if(computer.diskStatus == 1)
		{
			computer.diskStatus = 0;
		}
	}
	else
	{
		processTable[pid].processStatus = "WAITING";
		QueueEntry tempEntry = computer.diskQueue.front();
		int tempPID = tempEntry.processID;
		int tempDuration = tempEntry.requestDuration;
		computer.diskQueue.pop();
		int tempTime = computer.previousDiskTime + tempDuration;
		computer.previousDiskTime = tempTime;
		processQueue[tempPID]->processTotalTime = tempTime;
		Event newEvent(tempTime,"DISK",tempPID);
		eventList.push_back(newEvent);
	}
	next_request(processQueue,pid,computer,eventList);
}

//Input request function. Creates input completion event or adds to input queue.
void input_request(deque<Process*> &processQueue,int pid, int runTime, ComputerStatus &computer, list<Event> &eventList)
{
	processQueue[pid]->processTotalTime = processQueue[pid]->processTotalTime + runTime;
	if(computer.inputStatus == 0)
	{
		processTable[pid].processStatus = "RUNNING";
		computer.inputStatus = 1;
		computer.previousInputTime = processQueue[pid]->processTotalTime;
		Event newEvent(processQueue[pid]->processTotalTime,"I/O",pid);
		eventList.push_back(newEvent);
	}
	else
	{
		processTable[pid].processStatus = "WAITING";
		QueueEntry queueInfo;
		queueInfo.processID = pid;
		queueInfo.requestDuration = runTime;
		computer.inputQueue.push(queueInfo);
	}
}

//Input completion event function. Frees up input or adds from input queue.
void input_completion(deque<Process*> &processQueue, ComputerStatus &computer, int pid, list<Event> &eventList)
{
	if(computer.inputQueue.empty())
	{
		if(computer.inputStatus == 1)
		{
			computer.inputStatus = 0;
		}
		processTable[pid].processStatus = "RUNNING";
	}
	else
	{
		processTable[pid].processStatus = "WAITING";
		QueueEntry tempEntry = computer.inputQueue.front();
		int tempPID = tempEntry.processID;
		int tempDuration = tempEntry.requestDuration;
		computer.inputQueue.pop();
		int tempTime = computer.previousInputTime + tempDuration;
		computer.previousInputTime = tempTime;
		processQueue[tempPID]->processTotalTime = tempTime;
		Event newEvent(tempTime,"I/O",tempPID);
		eventList.push_back(newEvent);
	}
	next_request(processQueue,pid,computer,eventList);
}

//Function that prints status when a process terminates, but also gets the next instruction for use.
void next_request(deque<Process*> &processQueue,int pid, ComputerStatus &computer, list<Event> &eventList)
{
	if(processQueue[pid]->instrucQueue.empty())
	{
		cout << endl;
		processTable[pid].processStatus = "TERMINATED";
		double COREUtilization = computer.coreClock/processQueue[pid]->processTotalTime;
		cout << "Process " << pid << " terminates at t = " << processQueue[pid]->processTotalTime << endl;
		if(computer.coreOneStatus == 0)
		{
			cout << "Core 1 is IDLE" << endl;
		}
		else
		{
			cout << "Core 1 is BUSY" << endl;
		}
		if(computer.coreTwoStatus == 0)
		{
			cout << "Core 2 is IDLE" << endl;
		}
		else
		{
			cout << "Core 2 is BUSY" << endl;
		}
		cout << "Average number of busy cores: " << COREUtilization << endl;

		if(!computer.readyQueue.empty())
		{
			QueueEntry temp = computer.readyQueue.front();
			cout << "Ready queue contains: " << "process " << temp.processID << endl;
		}
		else
		{
			cout << "Ready queue contains: " << "---" << endl;
		}

		if(!computer.diskQueue.empty())
		{
			QueueEntry temp = computer.diskQueue.front();
			cout << "Disk queue contains: " << "process " << temp.processID << endl;
		}
		else
		{
			cout << "Disk queue contains: " << "---" << endl;
		}
		int size = processQueue.size();
		for(int x = 0; x < size; x++)
		{
			cout << endl;
			cout << "Process ID: " << processQueue[x]->getProcessNum() << endl;
			cout << "Start time: " << processQueue[x]->getProcessStartTime() << endl;
			cout << "CORE time: " << processQueue[x]->coreTime << endl;
			cout << "Status: " << processTable[x].processStatus << endl;
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		Instruction temp = processQueue[pid]->instrucQueue.front();

		processQueue[pid]->instrucQueue.pop();
		if(temp.getInstrucType() == "CORE")
		{
			core_request(processQueue,pid,temp.getInstrucRunTime(),computer,eventList);
		}
		else if(temp.getInstrucType() == "DISK")
		{
			disk_request(processQueue,pid,temp.getInstrucRunTime(),computer,eventList);
		}
		else if(temp.getInstrucType() == "I/O")
		{
			input_request(processQueue,pid,temp.getInstrucRunTime(),computer,eventList);
		}
		else
		{
			cout << "???" << endl;
		}
	}
}
