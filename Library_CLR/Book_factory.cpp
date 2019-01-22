#include "Book_factory.h"
#include "Adventure_book.h"
#include "Criminal_book.h"
#include "Document_book.h"
#include "Drama_book.h"
#include "Fantasy_book.h"
#include "Horror_book.h"
#include "Romance_book.h"
#include "Young_adult_book.h"


Book_factory::Book_factory()
{
}

Book_factory::~Book_factory()
{
}

Book * Book_factory::Create_book(int id, std::string author_name, std::string author_surname, std::string title, std::vector<std::string>* tags, bool was_borrowed)
{
	Book* book_ptr = NULL;
	for each (std::string s in *tags)
	{
		if (s.find("przygodowa") != std::string::npos || s.find("przygoda") != std::string::npos || s.find("Adventure") != std::string::npos)
		{
			Adventure_book* a = new Adventure_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = a;
			break;
		}
		else if (s.find("krymina³") != std::string::npos || s.find("Criminal") != std::string::npos)
		{
			Criminal_book* c = new Criminal_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = c;
			break;
		}
		else if (s.find("dokument") != std::string::npos || s.find("Document") != std::string::npos)
		{
			Document_book* d = new Document_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = d;
			break;
		}
		else if (s.find("dramat") != std::string::npos || s.find("Drama") != std::string::npos)
		{
			Drama_book* d = new Drama_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = d;
			break;
		}
		else if (s.find("fantastyka") != std::string::npos || s.find("Fantasy") != std::string::npos)
		{
			Fantasy_book* f = new Fantasy_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = f;
			break;
		}
		else if (s.find("horror") != std::string::npos || s.find("Horror") != std::string::npos)
		{
			Horror_book* h = new Horror_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = h;
			break;
		}
		else if (s.find("romans") != std::string::npos || s.find("Romance") != std::string::npos)
		{
			Romance_book* r = new Romance_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = r;
			break;
		}
		else if (s.find("young adult") != std::string::npos || s.find("Young adult") != std::string::npos)
		{
			Young_adult_book* y = new Young_adult_book(id, author_name, author_surname, title, tags, was_borrowed);
			book_ptr = y;
			break;
		}
	}
	//else
	//{
	//	//book_ptr = new Book(id, author_name, author_surname, title, tags, was_borrowed);
	//}
	return book_ptr;
}
