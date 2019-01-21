#include "CSV_writer.h"
#include <fstream>

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
