#include "Drama_book.h"

Drama_book::Drama_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string>* tags, bool was_borrowed) : Book(id, name, surname, title, was_borrowed)
{
	this->tags = new std::set<std::string>();
	for each (std::string t in *tags)
	{
		this->tags->insert(t);
	}
	this->tags->insert("Drama");
}

Drama_book::~Drama_book()
{
}


std::string Drama_book::Get_genre()
{
	std::string genre = typeid(*this).name();
	return genre.substr(6, genre.length() - 5 - 6);
}