#include "Login.h"

using namespace LibraryCLR;

System::Void Login::Accept_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	for each (User* u in *users)
	{
		String^ user_name = gcnew String(u->Get_user_name().c_str());
		if (login_textBox->Text->Equals(user_name))
		{
			String^ user_pass = gcnew String(u->Get_password().c_str());
			if (password_textBox->Text->Equals(user_pass))
			{
				Is_logged = true;
				Logged_user_name = new std::string(u->Get_user_name());
				this->Close();
				return;
			}
		}
	}

	Is_logged = false;
	auto msg_resp = MessageBox::Show(this, "Incorrect Login or Password!\n\nTry again.", "Login fail",
		MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
}

System::Void Login::Cancel_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	Is_logged = false;
	this->Close();
}