#pragma once
#include <vector>
#include "Constant_definitions.h"
#include "Book.h"
#include "Client_user.h"
#include "User.h"
#include "History_event.h"

//using namespace std;

class CSV_reader
{
public:
	CSV_reader();
	~CSV_reader();

	static std::vector<User*>* Read_users(std::string path);
	static std::vector<Book*>* Read_books(std::string path);
	static std::vector<Client_user*>* Read_clients(std::string path);
	static std::vector<History_event*>* Read_history(std::string path, int user_id, std::string user_name, std::string user_surname);
};

