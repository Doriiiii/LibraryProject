#include "Logger.h"
#include <fstream>
#include <string>
#include <ctime>


std::vector<Reported_event*> Logger::events;

Logger::Logger()
{
}

Logger::~Logger()
{
	while (events.size())
	{
		delete events.back();
		events.pop_back();
	}
}

void Logger::Add_event(Reported_event * e)
{
	events.push_back(e);
}

std::vector<Reported_event*>* Logger::Get_events()
{
	std::vector<Reported_event*>* ptr = &events;
	return ptr;
}