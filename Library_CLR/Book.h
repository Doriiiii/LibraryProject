#pragma once
#include <string>
#include <vector>
#include <set>


class Book
{
protected:
	int id;
	std::string author_name;
	std::string author_surname;
	std::string title;
	bool is_borrowed;

	std::set<std::string>* tags;
public:
	Book(int id, std::string name, std::string surname, std::string title, bool was_borrowed);
	Book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Book();

	int Get_id();
	std::string Get_author_name();
	std::string Get_author_surname();
	std::string Get_title();
	virtual std::string Get_genre() = 0;
	bool Get_borrowed_status();

	void Set_borrowed_status(bool is_borrowed);

	friend std::ostream& operator<<(std::ostream&, const Book&);
};
