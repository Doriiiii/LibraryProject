#pragma once
#include "Book.h"
class Romance_book :
	public Book
{
public:
	Romance_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Romance_book();

	std::string Get_genre();
};
