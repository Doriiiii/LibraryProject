#pragma once
#include <ctime>
#include <string>
//#include <chrono>

class Reported_event
{
private:
	int event_code;
	int element_id;
	std::string element_name;
	std::string event_name;
	std::time_t time_stamp;

public:
	Reported_event(int e_code, int element_id, std::string element_name_or_title, std::string e_name);
	~Reported_event();

	friend std::ostream& operator<<(std::ostream&, const Reported_event&);
};

