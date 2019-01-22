#include "Menu_logged.h"
#include "Book_management.h"
#include "Person_management.h"
#include "Borrow_bring_menu.h"

System::Void LibraryCLR::Menu_logged::book_button_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	auto book = gcnew Book_management(books);
	this->Hide();
	book->ShowDialog();

	this->Show();
}

System::Void LibraryCLR::Menu_logged::person_button_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	auto person = gcnew Person_management(clients);
	this->Hide();
	person->ShowDialog();

	this->Show();
}

System::Void LibraryCLR::Menu_logged::borrow_button_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	auto borrow = gcnew Borrow_bring_menu(books, clients);
	this->Hide();
	borrow->ShowDialog();

	this->Show();
}

System::Void LibraryCLR::Menu_logged::Menu_logged_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	if (clients != NULL)
	{
		CSV_writer::Write_clients(clients, path_users);

		while (clients->size())
		{
			delete clients->back();
			clients->pop_back();
		}
		delete clients;
		clients = NULL;
	}
}
