#pragma once
#include "Book.h"
class Fantasy_book :
	public Book
{
public:
	Fantasy_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Fantasy_book();

	std::string Get_genre();
};
