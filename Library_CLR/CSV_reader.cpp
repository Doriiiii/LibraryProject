#include "CSV_reader.h"
#include "No_file_exception.h"
#include "String_tokenizer.h"
#include "Book_factory.h"
#include <fstream>
#include <stdexcept>

using namespace std;

CSV_reader::CSV_reader()
{
}


CSV_reader::~CSV_reader()
{
}

vector<User*>* CSV_reader::Read_users(string path)
{
	vector<User*> *users = new vector<User*>();
	fstream file;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		string read_row;
		while (getline(file, read_row))
		{
			User* u = new User();
			int position = read_row.find(';');
			u->Set_user_name(read_row.substr(0, position));
			u->Set_password(read_row.substr(position + 1, read_row.length() - position - 1));
			users->push_back(u);
		}

		file.close();
	}
	else
	{
		throw No_file_exception("Missing file: " + path);
	}

	return users;
}

vector<Book*>* CSV_reader::Read_books(string path)
{
	vector<Book*> *books = new vector<Book*>();
	fstream file;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		Book_factory factory;
		string read_row;
		while (getline(file, read_row))
		{
			std::vector<std::string>* vals = String_tokenizer::split(read_row.c_str(), ';');
			std::vector<std::string>* tags = new std::vector<std::string>();
			for (int i = 5; i < vals->size(); ++i)
			{
				tags->push_back((*vals)[i]);
			}

			books->push_back(factory.Create_book(std::stoi((*vals)[0]), (*vals)[1], (*vals)[2], (*vals)[3], tags,
				((*vals)[4] == "1")));
		}

		file.close();
	}
	else
	{
		throw No_file_exception("Missing file: " + path);
	}

	return books;
}

vector<Client_user*>* CSV_reader::Read_clients(string path)
{
	vector<Client_user*> *clients = new vector<Client_user*>();
	fstream file;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		string read_row;
		while (getline(file, read_row))
		{
			std::vector<std::string>* vals = String_tokenizer::split(read_row.c_str(), ';');
			if (vals->size() > 3)
			{
				clients->push_back(new Client_user(std::stoi((*vals)[0]), (*vals)[1], (*vals)[2], new std::vector<std::string>(vals->begin() + 3, vals->end())));
			}
			else
			{
				clients->push_back(new Client_user(std::stoi((*vals)[0]), (*vals)[1], (*vals)[2], new std::vector<std::string>()));
			}
		}

		file.close();
	}
	else
	{
		throw No_file_exception("Missing file: " + path);
	}

	return clients;
}

std::vector<History_event*>* CSV_reader::Read_history(std::string path, int user_id, std::string user_name, std::string user_surname)
{
	vector<History_event*> *histories = new vector<History_event*>();
	fstream file;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		string read_row;
		while (getline(file, read_row))
		{
			std::vector<std::string>* vals = String_tokenizer::split(read_row.c_str(), ';');
			if (std::stoi((*vals)[0]) == user_id)
			{
				if ((*vals)[1] == user_name && (*vals)[2] == user_surname)
				{
					histories->push_back(new History_event(std::stoi((*vals)[0]), (*vals)[1], (*vals)[2], std::stoi((*vals)[3]),
						(*vals)[4], (*vals)[5], (*vals)[6], (*vals)[7], (*vals)[8]));
				}
			}
		}

		file.close();
	}
	else
	{
		throw No_file_exception("Missing file: " + path);
	}

	return histories;
}
