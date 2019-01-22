#pragma once
#include <ctime>
#include <string>
//#include <chrono>

class History_event
{
private:
	int user_id;
	std::string user_name;
	std::string user_surname;
	int book_id;
	std::string book_title;
	std::string book_author_name;
	std::string book_author_surname;
	std::string action_name;
	std::time_t time_stamp;

public:
	History_event(int u_id, std::string u_name, std::string u_surname, int b_id, std::string b_title, std::string b_a_name, std::string b_a_surname, std::string a_name);
	History_event(int u_id, std::string u_name, std::string u_surname, int b_id, std::string b_title, std::string b_a_name, std::string b_a_surname, std::string a_name, std::string timest);
	~History_event();

	int Get_user_id();
	std::string Get_user_name();
	std::string Get_user_surname();
	int Get_book_id();
	std::string Get_book_title();
	std::string Get_book_author_name();
	std::string Get_book_author_surname();
	std::string Get_action_name();
	std::time_t Get_time_stamp();

	friend std::ostream& operator<<(std::ostream&, const History_event&);
};

