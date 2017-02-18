#include "event.h"

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
