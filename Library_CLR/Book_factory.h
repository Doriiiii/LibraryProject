#pragma once
#include <string>
#include "Book.h"

class Book_factory
{
public:
	Book_factory();
	~Book_factory();

	Book* Create_book(int id, std::string author_name, std::string author_surname, std::string title, std::vector<std::string>* tags, bool was_borrowed);
};

