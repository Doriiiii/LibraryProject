#include "Client_user.h"
#include <string>

Client_user::Client_user(int id, std::string name, std::string surname, std::vector<std::string>* book_ids)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
	for each (std::string s in *book_ids)
	{
		owned_books.insert(std::stoi(s));
	}
}

Client_user::~Client_user()
{
}

int Client_user::Get_id()
{
	return id;
}

std::string Client_user::Get_name()
{
	return name;
}

std::string Client_user::Get_surname()
{
	return surname;
}

std::set<int> Client_user::Get_owned_books_ids()
{
	return owned_books;
}

void Client_user::Borrow_book(int id)
{
	owned_books.insert(id);
}

void Client_user::Return_book(int id)
{
	owned_books.erase(owned_books.find(id));
}

std::ostream & operator<<(std::ostream &os, const Client_user &client)
{
	os << client.id << ";" << client.name << ";" << client.surname << ";";
	for each (int i in client.owned_books)
	{
		os << i << ";";
	}
	os << std::endl;
	return os;
}
