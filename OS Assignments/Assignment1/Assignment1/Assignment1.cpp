//Driver.
#include <iomanip>
#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <list>
#include "event.h"

using namespace std;

#define MAX_PROCESSES 100			

//Structure of an entry in the data table
struct dataTableEntry {
	string op;			//operation
	int param;			//parameter

						//Constructor
	dataTableEntry(string o, int p) {
		op = o;
		param = p;
	}
};
enum states { READY, RUNNING, WAITING, TERMINATED };
//Structure of an entry in the process table
struct processTableEntry {
	int sTime;												//Start time of the process
	int fLine;												//First line int the data table
	int lLine;												//Last line in the data table
	int cLine;												//Current line in the data table
	states state;											//State of the process

															//Constructor
	processTableEntry(int s, int f, int l, int c, states st) {
		sTime = s;
		fLine = f;
		lLine = l;
		cLine = c;
		state = st;
	}
	//default constructor, only for pupose of array declaration
	processTableEntry() {
		sTime = -1;
		fLine = -1;
		lLine = -1;
		cLine = -1;
		state = TERMINATED;
	}
};

//Structure of an entry in the device table
struct deviceTableEntry {
	bool busy;			//busy flag
	int pid;			//pid of process if busy
	int cTime;			//completion time

						//default constructor, only for pupose of array declaration
	deviceTableEntry() {
		busy = false;
		pid = 0;
		cTime = 0;
	}
};

//Defining a comparison function for the priority queue of Events
class ComparisonEvents {
public:
	//Return true if b should preceed a
	bool operator() (Event &a, Event &b) {
		return a.getEventTime() > b.getEventTime();
	}
};

priority_queue<Event, vector<Event>, ComparisonEvents> eventList;	//The event list
vector<dataTableEntry> dataTable;									//The data table
deviceTableEntry deviceTable[3];									//The device table
processTableEntry processTable[MAX_PROCESSES];						//Process Table with MAX_PROCESSES rows, you can adjust this value to accomodate more processes if needed
int processPriority[MAX_PROCESSES];									//To hold the process priorities, 0 for low 1 for high
																	//The enum array is indexed by PID, and it is initialized to a value of 0 that corresponds to LOW

deque<int>	high_priority_queue;
deque<int>	low_priority_queue;
deque<int>	disk_queue;

int nCoreBusy;							//Number of busy cores
int coreBusyTimes;						//The core bust time currently
int sumCurBusyTimes;


void readInput();
void initialize();
void core_request(int pid, int time);
void core_complete(int pid, int time);
void disk_request(int pid, int time);
void disk_complete(int pid, int time);
void io_request(int pid, int time);
void io_complete(int pid, int time);
void processCompletion(int pid, int time);

int main() {

	readInput();
	initialize();

	/*DEBUG STATEMENTS
	while(!eventList.empty()){
	Event e = eventList.top();
	eventList.pop();
	cout<<e.getEventType()<<" "<<e.getProcessID()<<" "<<e.getEventTime()<<endl;
	}
	*/

	//Start handling the events till the queue is not empty
	while (!eventList.empty()) {
		Event e = eventList.top();
		eventList.pop();

		//cout<<"Event : "<<e.getEventType()<<" "<<e.getEventTime()<<" "<<e.getProcessID()<<endl;

		if (e.getEventType() == "CORE")
			core_request(e.getProcessID(), e.getEventTime());
		else if (e.getEventType() == "CORE_COMPLETE")
			core_complete(e.getProcessID(), e.getEventTime());
		else if (e.getEventType() == "DISK")
			disk_request(e.getProcessID(), e.getEventTime());
		else if (e.getEventType() == "DISK_COMPLETE")
			disk_complete(e.getProcessID(), e.getEventTime());
		else if (e.getEventType() == "I/O")
			io_request(e.getProcessID(), e.getEventTime());
		else if (e.getEventType() == "IO_COMPLETE")
			io_complete(e.getProcessID(), e.getEventTime());
	}
	//cout<<"Exiting!"<<endl;
	return 0;
}

//Read input and fill the data table
void readInput() {
	string inp;
	int param;

	while (cin >> inp) {
		//Discard if its END
		if (inp == "END") {
			continue;
		}
		else {
			//Read parameter
			cin >> param;
			//Add entry to data table
			dataTable.push_back(dataTableEntry(inp, param));
		}
	}
}

//Initialize the process table and the eventList by reading from the data table
void initialize() {

	memset(processPriority, 0, sizeof(processPriority));	//Initialize to all 0s
	nCoreBusy = 0;
	coreBusyTimes = 0;
	sumCurBusyTimes = 0;

	int pid = -1;		//PID of process with is being currently added

	for (int i = 0; i<dataTable.size(); i++) {
		//If we encounter a start of a new process
		if (dataTable[i].op == "START") {
			//if i!=0 then update details of previous process
			if (i != 0) {
				processTable[pid].lLine = i - 1;				//Set last line
			}
			//Add the details for the new process
			pid++;											//Update pid value
			processTable[pid].sTime = dataTable[i].param;	//Set the start time
			processTable[pid].fLine = i + 1;					//Set first line
			processTable[pid].cLine = i + 1;					//Set current line
			processTable[pid].state = READY;				//Set the state to ready

															//Add event to queue, which is the first operation that the process wants to do
			eventList.push(Event(processTable[pid].sTime, dataTable[i + 1].op, pid));
		}
	}
	//Set last line of last process
	if (pid != -1) {
		processTable[pid].lLine = dataTable.size() - 1;
	}
}

//Handle core request
void core_request(int pid, int time) {
	//Check the process table for current line 
	int curLine = processTable[pid].cLine;
	//Get the current request time from the data table
	int curRequestTime = dataTable[curLine].param;

	//cout<<"Core Request made by "<<pid<<" at "<<time<<" for "<<curRequestTime<<endl;

	//If core 0 is available then allocate process to core
	if (!deviceTable[0].busy) {
		//Mark process state as running
		processTable[pid].state = RUNNING;

		//Mark core as busy
		nCoreBusy++;
		deviceTable[0].busy = true;
		deviceTable[0].cTime = time + curRequestTime;

		coreBusyTimes += curRequestTime;
		sumCurBusyTimes += deviceTable[0].cTime;

		//Add the completion event to eventList
		eventList.push(Event(deviceTable[0].cTime, "CORE_COMPLETE", pid));

		//cout<<"Granted to Core 0! Scheduled to complete at "<<deviceTable[0].cTime<<endl;
	}
	//If core 1 is available then allocate process to core
	else if (!deviceTable[1].busy) {
		//Mark process state as running
		processTable[pid].state = RUNNING;

		//Mark core as busy
		nCoreBusy++;
		deviceTable[1].busy = true;
		deviceTable[1].cTime = time + curRequestTime;

		coreBusyTimes += curRequestTime;
		sumCurBusyTimes += deviceTable[1].cTime;

		//Add the completion event to eventList
		eventList.push(Event(deviceTable[1].cTime, "CORE_COMPLETE", pid));

		//cout<<"Granted to Core 1! Scheduled to complete at "<<deviceTable[1].cTime<<endl;
	}
	else {
		//cout<<"Adding to queue: "<<(processPriority[pid]==0?"low":"high")<<endl;

		//Mark process state as waiting
		processTable[pid].state = READY;

		//add process to queue based on priority
		if (processPriority[pid] == 0)
			low_priority_queue.push_back(pid);
		else
			high_priority_queue.push_back(pid);
	}
}

//Handle core completion
void core_complete(int pid, int time) {
	//Find which core has completed
	int coreNum = deviceTable[0].cTime == time ? 0 : 1;

	//If ready queues are empty
	if (low_priority_queue.empty() && high_priority_queue.empty()) {
		deviceTable[coreNum].busy = false;			//Mark as free
		nCoreBusy--;
	}
	else {
		int nxtPID;

		//get the next element
		if (!high_priority_queue.empty()) {
			nxtPID = high_priority_queue.front();
			high_priority_queue.pop_front();
		}
		else {
			nxtPID = low_priority_queue.front();
			low_priority_queue.pop_front();
		}

		processTable[nxtPID].state = RUNNING;

		//Check the process table for current line 
		int curLine = processTable[nxtPID].cLine;
		//Get the current request time from the data table
		int curRequestTime = dataTable[curLine].param;

		deviceTable[coreNum].cTime = time + curRequestTime;
		coreBusyTimes += curRequestTime;
		sumCurBusyTimes += deviceTable[coreNum].cTime;

		//Add the completion event to eventList
		eventList.push(Event(deviceTable[coreNum].cTime, "CORE_COMPLETE", nxtPID));

		//cout<<nxtPID<<" granted CORE "<<coreNum<<"! Scheduled to complete at "<<deviceTable[coreNum].cTime<<endl;
	}

	//Subtract t for completing process
	sumCurBusyTimes -= time;

	//Process next request for completing process
	//If the process' current line is its last line then call process completion routine
	if (processTable[pid].cLine == processTable[pid].lLine) {
		processTable[pid].state = TERMINATED;
		processCompletion(pid, time);
	}
	else {
		processTable[pid].cLine++;			//Increment the current line
											//Add next event to queue
		eventList.push(Event(time, dataTable[processTable[pid].cLine].op, pid));
		processTable[pid].state = READY;
	}
}

//Handle disk request
void disk_request(int pid, int time) {
	int reqTime = dataTable[processTable[pid].cLine].param;

	//cout<<"Disk Request made by "<<pid<<" at "<<time<<" for "<<reqTime<<endl;

	//If drt == 0
	if (reqTime == 0) {
		//Mark process low priority
		processPriority[pid] = 0;

		//Add event for completion
		eventList.push(Event(time, "DISK_COMPLETE", pid));

		//cout<<"Granted! Scheduled to complete at "<<time<<endl;
	}
	else {
		//Check if disk is free
		if (!deviceTable[2].busy) {
			deviceTable[2].busy = true;				//Mark disk as busy
			deviceTable[2].cTime = time + reqTime;

			//Add event for completion
			eventList.push(Event(deviceTable[2].cTime, "DISK_COMPLETE", pid));

			//Mark process running
			processTable[pid].state = RUNNING;

			//cout<<"Granted! Scheduled to complete at "<<deviceTable[2].cTime<<endl;
		}
		else {
			disk_queue.push_back(pid);		//Push into disk queue
			processTable[pid].state = WAITING;

			//cout<<"Added to queue: disk"<<endl;
		}
	}
}

//Handle disk complete
void disk_complete(int pid, int time) {
	//If disk is empty, mark disk idle
	if (disk_queue.empty())
		deviceTable[2].busy = false;
	else {
		int nxtPID = disk_queue.front();
		disk_queue.pop_front();

		int reqTime = dataTable[processTable[nxtPID].cLine].param;

		//Mark disk busy
		deviceTable[2].cTime = time + reqTime;

		processTable[nxtPID].state = RUNNING;

		//cout<<nxtPID<<" granted Disk! Scheduled to complete at "<<deviceTable[2].cTime<<endl;
	}

	//Mark the completing process low priority
	processPriority[pid] = 0;

	//If the process' current line is its last line then call process completion routine
	if (processTable[pid].cLine == processTable[pid].lLine) {
		processTable[pid].state = TERMINATED;
		processCompletion(pid, time);
	}
	else {
		processTable[pid].cLine++;			//Increment the current line
											//Add next event to queue
		eventList.push(Event(time, dataTable[processTable[pid].cLine].op, pid));

		processTable[pid].state = READY;
	}
}

//Handle I/O request
void io_request(int pid, int time) {
	int reqTime = dataTable[processTable[pid].cLine].param;

	//cout<<"I/O Request made by "<<pid<<" at "<<time<<" for "<<reqTime<<endl;

	//Add completion event
	eventList.push(Event(time + reqTime, "IO_COMPLETE", pid));

	//Mark process running
	processTable[pid].state = WAITING;

	//cout<<"Granted! Scheduled to complete at "<<time+reqTime<<endl;
}

//Handle I/O complete
void io_complete(int pid, int time) {
	processPriority[pid] = 1;		//Mark high priority

									//If the process' current line is its last line then call process completion routine
	if (processTable[pid].cLine == processTable[pid].lLine) {
		processTable[pid].state = TERMINATED;
		processCompletion(pid, time);
	}
	else {
		processTable[pid].cLine++;			//Increment the current line
											//Add next event to queue
		eventList.push(Event(time, dataTable[processTable[pid].cLine].op, pid));

		processTable[pid].state = READY;
	}
}

//Print the Report
void processCompletion(int pid, int time) {
	cout << "CURRENT STATE OF THE SYSTEM AT TIME " << time << endl;

	cout << "Current number of busy cores: " << nCoreBusy << endl;

	//Error correction and average calculation
	double err = sumCurBusyTimes - (time*nCoreBusy);
	double avgBusy = ((coreBusyTimes - err)*1.0) / time;
	cout << "Average number of busy cores: " << avgBusy << endl;

	cout << "HIGH-PRIORITY READY QUEUE:\n";
	if (high_priority_queue.empty())
		cout << "empty" << endl;
	else {
		for (int i = 0; i<high_priority_queue.size(); i++)
			cout << "Process " << high_priority_queue[i] << "  ";
		cout << endl;
	}
	cout << "LOW-PRIORITY READY QUEUE:\n";
	if (low_priority_queue.empty())
		cout << "empty" << endl;
	else {
		for (int i = 0; i<low_priority_queue.size(); i++)
			cout << "Process " << low_priority_queue[i] << "  ";
		cout << endl;
	}

	cout << "DISK QUEUE:\n";
	if (disk_queue.empty())
		cout << "empty" << endl;
	else {
		for (int i = 0; i<disk_queue.size(); i++)
			cout << "Process " << disk_queue[i] << "\t";
		cout << endl;
	}

	//For processes in the main memory
	cout << "PROCESS TABLE:\n";
	for (int pid = 0; pid<MAX_PROCESSES; pid++) {
		//If process is in memory
		if (processTable[pid].sTime >= 0) {
			cout << "Process " << pid << " ";
			cout << "stated at " << processTable[pid].sTime << ", ";
			int coreTime = 0;
			//Iterate over data table range and find CORE requests
			for (int i = processTable[pid].fLine; i <= processTable[pid].cLine; i++) {
				if (dataTable[i].op == "CORE")
					coreTime += dataTable[i].param;
			}
			cout << "got " << coreTime << " ms of CORE time and is ";
			if (processTable[pid].state == READY)
				cout << "READY" << endl;
			else if (processTable[pid].state == WAITING)
				cout << "WAITING" << endl;
			else if (processTable[pid].state == TERMINATED)
				cout << "TERMINATED" << endl;
			else if (processTable[pid].state == RUNNING)
				cout << "RUNNING" << endl;
		}
	}
	cout << "\n\n";

	processTable[pid].sTime = -1;
}