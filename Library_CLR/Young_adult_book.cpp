#include "Young_adult_book.h"
#include <algorithm>

Young_adult_book::Young_adult_book(int id, std::string name, std::string surname, std::string title, std::vector<std::string>* tags, bool was_borrowed) : Book(id, name, surname, title, was_borrowed)
{
	this->tags = new std::set<std::string>();
	for each (std::string t in *tags)
	{
		this->tags->insert(t);
	}
	this->tags->insert("Young adult");
}

Young_adult_book::~Young_adult_book()
{
}

std::string Young_adult_book::Get_genre()
{
	std::string genre = typeid(*this).name();
	genre = genre.substr(6, genre.length() - 5 - 6);
	std::replace(genre.begin(), genre.end(), '_', ' ');
	return genre;
}