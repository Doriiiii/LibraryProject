#include "Book.h"
#include <typeinfo>  


Book::Book(int id, std::string name, std::string surname, std::string title, bool was_borrowed)
{
	this->id = id;
	author_name = name;
	author_surname = surname;
	this->title = title;
	this->tags = new std::set<std::string>();
	is_borrowed = was_borrowed;
}

Book::Book(int id, std::string name, std::string surname, std::string title, std::vector<std::string>* tags, bool was_borrowed)
{
	this->id = id;
	author_name = name;
	author_surname = surname;
	this->title = title;
	this->tags = new std::set<std::string>();
	for each (std::string t in *tags)
	{
		this->tags->insert(t);
	}
	is_borrowed = was_borrowed;
}

Book::~Book()
{
	delete tags;
}

int Book::Get_id()
{
	return id;
}

std::string Book::Get_author_name()
{
	return author_name;
}

std::string Book::Get_author_surname()
{
	return author_surname;
}

std::string Book::Get_title()
{
	return title;
}

//std::string Book::Get_genre()
//{
//	return "None";
//}

bool Book::Get_borrowed_status()
{
	return is_borrowed;
}

void Book::Set_borrowed_status(bool is_borrowed)
{
	this->is_borrowed = is_borrowed;
}

std::ostream & operator<<(std::ostream &os, const Book &book)
{
	os << book.id << ";" << book.author_name << ";" << book.author_surname << ";" << book.title << ";" << book.is_borrowed << ";";
	for each (std::string s in *(book.tags))
	{
		os << s << ";";
	}
	os << std::endl;
	return os;
}
