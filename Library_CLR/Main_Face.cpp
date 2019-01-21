#include "Main_Face.h"
#include "Login.h"
#include "Menu_logged.h"
#include "Search.h"
#include "CSV_reader.h"
#include "Constant_definitions.h"
#include "No_file_exception.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace LibraryCLR;

[STAThreadAttribute]
int main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LibraryCLR::Main_Face form;
	if (!form.IsDisposed)
	{
		Application::Run(%form);
	}
}

System::Void Main_Face::Login_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		std::vector<User*>* users = CSV_reader::Read_users(logins_path);
		if (users->size() > 0)
		{
			auto login_window = gcnew Login(users);
			login_window->ShowDialog();
			if (login_window->Is_logged)
			{
				//Logowanie powiod³o siê
				auto logged_menu = gcnew Menu_logged(books, *(login_window->Logged_user_name));
				this->Hide();
				logged_menu->ShowDialog();

				this->Show();
			}

			while (users->size())
			{
				delete users->back();
				users->pop_back();
			}
		}
		else
		{
			auto msg_resp = MessageBox::Show(this, "Error: users list is EMPTY.\nLogging in unavailable.", "No-users error",
				MessageBoxButtons::OK, MessageBoxIcon::Error, MessageBoxDefaultButton::Button1);
		}
		delete users;
	}
	catch (No_file_exception& ex)
	{
		std::string c_msg = "Error trying to load users list:\n";
		c_msg += ex.what();
		c_msg += ".\n\nLogging in unavailable.";
		String^ msg = gcnew String(c_msg.c_str());

		auto msg_resp = MessageBox::Show(this, msg, "Loading fail",
			MessageBoxButtons::OK, MessageBoxIcon::Error, MessageBoxDefaultButton::Button1);
	}
}

System::Void LibraryCLR::Main_Face::OtherUser_button_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	auto search = gcnew Search(books);
	this->Hide();
	search->ShowDialog();

	this->Show();
}