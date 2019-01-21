#pragma once
#include "Book.h"
class Drama_book :
	public Book
{
public:
	Drama_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string>* tags, bool was_borrowed);
	~Drama_book();

	std::string Get_genre();
};

