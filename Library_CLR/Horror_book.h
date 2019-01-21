#pragma once
#include "Book.h"
class Horror_book :
	public Book
{
public:
	Horror_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Horror_book();

	std::string Get_genre();
};
