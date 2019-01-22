#include "History_event.h"
#include "Constant_definitions.h"
#include <chrono>
//#include <iomanip>


History_event::History_event(int u_id, std::string u_name, std::string u_surname, int b_id, std::string b_title,
	std::string b_a_name, std::string b_a_surname, std::string a_name)
{
	user_id = u_id;
	user_name = u_name;
	user_surname = u_surname;
	book_id = b_id;
	book_title = b_title;
	book_author_name = b_a_name;
	book_author_surname = b_a_surname;
	action_name = a_name;
	time_stamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

History_event::History_event(int u_id, std::string u_name, std::string u_surname, int b_id, std::string b_title,
	std::string b_a_name, std::string b_a_surname, std::string a_name, std::string timest)
{
	user_id = u_id;
	user_name = u_name;
	user_surname = u_surname;
	book_id = b_id;
	book_title = b_title;
	book_author_name = b_a_name;
	book_author_surname = b_a_surname;
	action_name = a_name;

	time_t rawtime;
	struct tm * timeinfo;
	int year, month, day, hour, minute;
	year = stoi(timest.substr(0, 4));
	month = stoi(timest.substr(5, 2));
	day = stoi(timest.substr(8, 2));
	hour = stoi(timest.substr(11, 2));
	minute = stoi(timest.substr(14, 2));

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	timeinfo->tm_hour = hour;
	timeinfo->tm_min = minute;

	time_stamp = mktime(timeinfo);
}

History_event::~History_event()
{
}

int History_event::Get_user_id()
{
	return user_id;
}

std::string History_event::Get_user_name()
{
	return user_name;
}

std::ostream & operator<<(std::ostream &os, const History_event &e)
{
	tm *ltm = localtime(&e.time_stamp);
	char date[20];
	sprintf(date, date_format, (ltm->tm_year + 1900), (ltm->tm_mon + 1), ltm->tm_mday, ltm->tm_hour, ltm->tm_min);

	os << e.user_id << ";" << e.user_name << ";" << e.user_surname << ";" << e.book_id << ";" << e.book_title << ";"
		<< e.book_author_name << ";" << e.book_author_surname << ";" << e.action_name << ";" << date << ";" << std::endl;
	return os;
}

std::string History_event::Get_user_surname()
{
	return user_surname;
}

int History_event::Get_book_id()
{
	return book_id;
}

std::string History_event::Get_book_title()
{
	return book_title;
}

std::string History_event::Get_book_author_name()
{
	return book_author_name;
}

std::string History_event::Get_book_author_surname()
{
	return book_author_surname;
}

std::string History_event::Get_action_name()
{
	return action_name;
}

std::time_t History_event::Get_time_stamp()
{
	return time_stamp;
}
