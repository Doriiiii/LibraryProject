#include "Add_book.h"
#include <msclr\marshal_cppstd.h>
#include "Logger.h"
#include "Reported_event.h"
#include "Constant_definitions.h"

System::Void LibraryCLR::Add_book::button_cancel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}

System::Void LibraryCLR::Add_book::button_accept_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (!String::IsNullOrEmpty(textBox_name->Text) && !String::IsNullOrWhiteSpace(textBox_surname->Text)
		&& !String::IsNullOrWhiteSpace(textBox_title->Text))
	{
		std::vector<std::string> *tags = new std::vector<std::string>();
		tags->push_back(msclr::interop::marshal_as<std::string>((String^)(comboBox_genre->SelectedItem)));
		int id = books->size() > 0 ? books->back()->Get_id() : 0;
		books->push_back(factory->Create_book(
			id + 1,
			msclr::interop::marshal_as<std::string>(textBox_name->Text),//https://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring
			msclr::interop::marshal_as<std::string>(textBox_surname->Text),
			msclr::interop::marshal_as<std::string>(textBox_title->Text),
			tags, false));

		auto msg_resp = MessageBox::Show(this, "Book added successfully", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1);

		Logger::Add_event(new Reported_event(code_add_book, id + 1,
			msclr::interop::marshal_as<std::string>(textBox_title->Text), text_add_book));

		this->Close();
	}
	else
	{
		auto msg_resp = MessageBox::Show(this, "Fill all fields!", "Unspecified book",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);

	}
}
