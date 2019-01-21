#include "Add_person.h"
#include <msclr\marshal_cppstd.h>
#include "Reported_event.h"
#include "Logger.h"
#include "Constant_definitions.h"

System::Void LibraryCLR::Add_person::button_accept_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (!System::String::IsNullOrEmpty(textBox_name->Text) && !System::String::IsNullOrEmpty(textBox_surname->Text))
	{
		int id = clients->size() > 0 ? clients->back()->Get_id() : 0;
		clients->push_back(new Client_user(
			id + 1,
			msclr::interop::marshal_as<std::string>(textBox_name->Text),//https://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring
			msclr::interop::marshal_as<std::string>(textBox_surname->Text),
			new std::vector<std::string>()));

		auto msg_resp = MessageBox::Show(this, "User added successfully", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1);
		
		Logger::Add_event(new Reported_event(code_add_person, id + 1,
			msclr::interop::marshal_as<std::string>(textBox_name->Text) + " " 
			+ msclr::interop::marshal_as<std::string>(textBox_surname->Text), text_add_person));

		Was_added = true;
		this->Close();
	}
	else
	{
		auto msg_resp = MessageBox::Show(this, "Enter Name and Surname!", "Missing data",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
		
		return;
	}
}

System::Void LibraryCLR::Add_person::button_cancel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}
