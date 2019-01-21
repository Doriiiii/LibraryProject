#pragma once
#include "Book.h"
class Young_adult_book :
	public Book
{
public:
	Young_adult_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Young_adult_book();

	std::string Get_genre();
};
