#pragma once
#include <vector>
#include "Constant_definitions.h"
#include "Book.h"
#include "Client_user.h"
#include "User.h"

//using namespace std;

class CSV_reader
{
public:
	CSV_reader();
	~CSV_reader();

	static std::vector<User*>* Read_users(std::string path);
	static std::vector<Book*>* Read_books(std::string path);
	static std::vector<Client_user*>* Read_clients(std::string path);
};

