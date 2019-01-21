#include "Reported_event.h"
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
	os << e.time_stamp << ";" << e.event_code << ";" << e.event_name << ";" << e.element_id << ";" << e.element_name << ";"
		<< std::endl;
	return os;
}
