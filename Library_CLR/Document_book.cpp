#include "Document_book.h"


Document_book::Document_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string>* tags, bool was_borrowed) : Book(id, name, surname, title, was_borrowed)
{
	this->tags = new std::set<std::string>();
	for each (std::string t in *tags)
	{
		this->tags->insert(t);
	}
	this->tags->insert("Document");
}

Document_book::~Document_book()
{
}

std::string Document_book::Get_genre()
{
	std::string genre = typeid(*this).name();
	return genre.substr(6, genre.length() - 5 - 6);
}
