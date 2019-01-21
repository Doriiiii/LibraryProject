#pragma once
#include "Book.h"
class Document_book :
	public Book
{
public:
	Document_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string> *tags, bool was_borrowed);
	~Document_book();

	std::string Get_genre();
};
