//Definition for Event class.
#ifndef EVENT_H
#define EVENT_H
#include <string>
using namespace std;

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