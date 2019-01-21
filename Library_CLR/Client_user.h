#pragma once
#include <vector>
#include <set>
//#include "Book.h"

class Client_user
{
private:
	int id;
	std::string name;
	std::string surname;
	std::set<int> owned_books;

public:
	Client_user(int id, std::string name, std::string surname, std::vector<std::string>* book_ids);
	~Client_user();

	int Get_id();
	std::string Get_name();
	std::string Get_surname();
	std::set<int> Get_owned_books_ids();
	void Borrow_book(int id);
	void Return_book(int id);

	friend std::ostream& operator<<(std::ostream&, const Client_user&);
};