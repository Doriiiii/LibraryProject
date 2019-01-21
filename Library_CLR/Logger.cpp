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

void Logger::Save_events()
{
	if (events.size())
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);

		char file_path[20];
		sprintf(file_path, "%d-%02d-%02d_%02d-%02d.log", (ltm->tm_year + 1900), (ltm->tm_mon + 1), ltm->tm_mday,
			ltm->tm_hour, ltm->tm_min);
		std::ofstream file(file_path, std::ios::out);
		for each (Reported_event* re in events)
		{
			file << *re;
		}
		file.close();
	}
}
