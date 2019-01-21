#include "Borrow_bring_menu.h"
#include "Borrow.h"
#include "Reported_event.h"
#include "Logger.h"
#include "Constant_definitions.h"

System::Void LibraryCLR::Borrow_bring_menu::button_search_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Update_list_view_items();
}

System::Void LibraryCLR::Borrow_bring_menu::button_borrow_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (selected_client != nullptr)
	{
		auto borrow = gcnew Borrow(books_all, selected_client);
		borrow->ShowDialog();

		if (borrow->Was_borrowed)
		{
			Update_list_view_items();
		}
	}
	else
	{
		auto msg_resp = MessageBox::Show(this, "No user selected!\n\nSearch user ID first and try again.", "Empty ID",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
	}
}

System::Void LibraryCLR::Borrow_bring_menu::button_bring_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (listView->SelectedItems->Count > 0)
	{
		int id = -1;
		System::Int32::TryParse(listView->SelectedItems[0]->Text, id);
		for (std::vector<Book*>::iterator it = (*books_borrowed).begin(); it != (*books_borrowed).end(); ++it)
		{
			if ((*it)->Get_id() == id)
			{
				(*it)->Set_borrowed_status(false);
				Logger::Add_event(new Reported_event(code_bring_book, id, (*it)->Get_title(), text_bring_book));
				break;
			}
		}
		selected_client->Return_book(id);

		std::string c_msg = "Book (ID: ";
		c_msg += std::to_string(id);
		c_msg += ") returned successfully.";
		String^ msg = gcnew String(c_msg.c_str());
		auto msg_resp = MessageBox::Show(this, msg, "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1);

		Update_list_view_items();
	}
	else
	{
		auto msg_resp = MessageBox::Show(this, "Select Book first!", "No book selected",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
	}
}

System::Void LibraryCLR::Borrow_bring_menu::textBox_user_id_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (e->KeyChar == (wchar_t)Keys::Return)
	{
		Update_list_view_items();
	}
}

void LibraryCLR::Borrow_bring_menu::Update_list_view_items()
{
	if (System::String::IsNullOrWhiteSpace(textBox_user_id->Text))
	{
		auto msg_resp = MessageBox::Show(this, "No user ID selected!\n\nWrite user ID and try again.", "Empty ID",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
	}
	else
	{
		int id = -1;
		if (System::Int32::TryParse(textBox_user_id->Text, id))
		{
			listView->BeginUpdate();
			listView->Items->Clear();

			for each (Client_user* c in *clients_all)
			{
				if (c->Get_id() == id) //this User
				{

					selected_client = c;
					books_borrowed = new std::vector<Book*>();
					for each (int i in c->Get_owned_books_ids()) //his/her books
					{
						for (std::vector<Book*>::iterator b = (*books_all).begin(); b != (*books_all).end(); ++b)
						{
							if ((*b)->Get_id() == i)
							{
								books_borrowed->push_back(*b);

								ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(i).c_str()));
								item->SubItems->Add(gcnew System::String((*b)->Get_title().c_str()));
								item->SubItems->Add(gcnew System::String((*b)->Get_author_name().c_str()));
								item->SubItems->Add(gcnew System::String((*b)->Get_author_surname().c_str()));
								item->SubItems->Add(gcnew System::String((*b)->Get_genre().c_str()));

								listView->Items->Add(item);
								break;
							}
						}
					}
					// Allow the ListBox to repaint and display the new items.
					listView->EndUpdate();

					return;
				}
			}
			//else
			// Allow the ListBox to repaint and display the new items.
			listView->EndUpdate();

			std::string c_msg = "User with ID: ";
			c_msg += std::to_string(id);
			c_msg += " not found.\n\nWrite other ID and try again.";
			String^ msg = gcnew String(c_msg.c_str());
			auto msg_resp = MessageBox::Show(this, msg, "Unknown ID",
				MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
		}
		else
		{
			auto msg_resp = MessageBox::Show(this, "Value is not an integer!\n\nWrite proper user ID and try again.", "Invalid ID",
				MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
		}
	}
}
