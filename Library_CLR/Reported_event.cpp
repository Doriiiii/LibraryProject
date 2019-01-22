#include "Reported_event.h"
#include "Constant_definitions.h"
#include <chrono>


Reported_event::Reported_event(int e_code, int element_id, std::string element_name_or_title, std::string e_name)
{
	event_code = e_code;
	this->element_id = element_id;
	element_name = element_name_or_title;
	event_name = e_name;
	time_stamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

Reported_event::~Reported_event()
{
}

std::ostream & operator<<(std::ostream &os, const Reported_event &e)
{
	tm *ltm = localtime(&e.time_stamp);
	char date[16];
	sprintf(date, date_format, (ltm->tm_year + 1900), (ltm->tm_mon + 1), ltm->tm_mday, ltm->tm_hour, ltm->tm_min);

	os << date << ";" << e.event_code << ";" << e.event_name << ";" << e.element_id << ";" << e.element_name << ";" << std::endl;
	return os;
}
