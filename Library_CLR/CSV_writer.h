#pragma once
#include <vector>
#include "Book.h"
#include "Client_user.h"
#include "History_event.h"
#include "Reported_event.h"

class CSV_writer
{
public:
	CSV_writer();
	~CSV_writer();

	static void Write_books(std::vector<Book*>* books, std::string path);
	static void Write_clients(std::vector<Client_user*>* clients, std::string path);
	static void Write_events(std::vector<Reported_event*>* events);
	static void Write_history(History_event& story);
};

