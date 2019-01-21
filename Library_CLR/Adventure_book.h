#pragma once
#include "Book.h"
class Adventure_book :
	public Book
{
public:
	Adventure_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string>* tags, bool was_borrowed);
	~Adventure_book();

	std::string Get_genre();
};

