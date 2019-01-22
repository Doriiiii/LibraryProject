#include "CSV_writer.h"
#include <fstream>
#include <iostream>
#include "Constant_definitions.h"

using namespace std;

CSV_writer::CSV_writer()
{
}

CSV_writer::~CSV_writer()
{
}

void CSV_writer::Write_books(std::vector<Book*>* books, std::string path)
{
	ofstream file(path, std::ios::trunc);
	for each (Book* b in *books)
	{
		file << *b;
	}
	file.close();
}

void CSV_writer::Write_clients(std::vector<Client_user*>* clients, std::string path)
{
	ofstream file(path, std::ios::trunc);
	for each (Client_user* c in *clients)
	{
		file << *c;
	}
	file.close();
}

void CSV_writer::Write_events(std::vector<Reported_event*>* events)
{
	if (events->size())
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);

		char file_path[20];
		sprintf(file_path, "%d-%02d-%02d_%02d-%02d.log", (ltm->tm_year + 1900), (ltm->tm_mon + 1), ltm->tm_mday,
			ltm->tm_hour, ltm->tm_min);
		std::ofstream file(file_path, std::ios::out);
		for each (Reported_event* re in *events)
		{
			file << *re;
		}
		file.close();
	}
}

void CSV_writer::Write_history(History_event& story)
{
	try
	{
		std::ofstream file(path_history, std::ios::app);
		file << story;
		file.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}
