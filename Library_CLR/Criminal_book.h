#pragma once
#include "Book.h"
class Criminal_book :
	public Book
{
public:
	Criminal_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Criminal_book();

	std::string Get_genre();
};

