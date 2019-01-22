#pragma once
#include <vector>
#include <string>
#include "Reported_event.h"

static class Logger
{
private:
	static std::vector<Reported_event*> events;
public:
	Logger();
	~Logger();

	static void Add_event(Reported_event*);
	static std::vector<Reported_event*>* Get_events();
};

