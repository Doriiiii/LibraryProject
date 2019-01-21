#include "Person_management.h"
#include <set>
#include <string>
#include "Add_person.h"
#include "Reported_event.h"
#include "Logger.h"
#include "Constant_definitions.h"

System::Void LibraryCLR::Person_management::button_search_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Update_list_view_items();
}

System::Void LibraryCLR::Person_management::button_add_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	auto add = gcnew Add_person(clients);
	add->ShowDialog();

	if (add->Was_added)
	{
		//textBox_search->Text = "";
		Update_list_view_items();
	}
}

System::Void LibraryCLR::Person_management::button_delete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (listView->SelectedItems->Count > 0)
	{
		int id = -1;
		System::Int32::TryParse(listView->SelectedItems[0]->Text, id);
		for (std::vector<Client_user*>::iterator it = (*clients).begin(); it != (*clients).end(); ++it)
		{
			if ((*it)->Get_id() == id)
			{
				if ((*it)->Get_owned_books_ids().size())
				{
					auto msg_resp = MessageBox::Show(this, "Cannot remove user which already own books!", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
					return;
				}

				Logger::Add_event(new Reported_event(code_delete_person, id, (*it)->Get_name() + " " + (*it)->Get_surname(),
					text_delete_person));

				delete *it;
				clients->erase(it);
				break;
			}
		}
		Update_list_view_items();
	}
	else
	{
		auto msg_resp = MessageBox::Show(this, "Select user first!", "No user selected",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
	}
}

System::Void LibraryCLR::Person_management::textBox_search_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (e->KeyChar == (wchar_t)Keys::Return)
	{
		Update_list_view_items();
	}
}

void LibraryCLR::Person_management::Update_list_view_items()
{
	listView->BeginUpdate();
	listView->Items->Clear();

	if (System::String::IsNullOrWhiteSpace(textBox_search->Text))
	{
		for each (Client_user* c in *clients)
		{
			ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(c->Get_id()).c_str()));
			item->SubItems->Add(gcnew System::String(c->Get_name().c_str()));
			item->SubItems->Add(gcnew System::String(c->Get_surname().c_str()));
			item->SubItems->Add(gcnew System::String(std::to_string(c->Get_owned_books_ids().size()).c_str()));

			listView->Items->Add(item);
		}
	}
	else
	{
		for each (Client_user* c in *clients)
		{
			System::String^ id = gcnew System::String(std::to_string(c->Get_id()).c_str());
			System::String^ name = gcnew System::String(c->Get_name().c_str());
			System::String^ surname = gcnew System::String(c->Get_surname().c_str());

			if (name->ToLower()->Contains(textBox_search->Text->ToLower()) ||
				surname->ToLower()->Contains(textBox_search->Text->ToLower()) ||
				id->ToLower()->Contains(textBox_search->Text->ToLower()))
			{
				ListViewItem^ item = gcnew ListViewItem(gcnew System::String(id));
				item->SubItems->Add(gcnew System::String(name));
				item->SubItems->Add(gcnew System::String(surname));
				item->SubItems->Add(gcnew System::String(std::to_string(c->Get_owned_books_ids().size()).c_str()));

				listView->Items->Add(item);
			}
		}
	}

	// Allow the ListBox to repaint and display the new items.
	listView->EndUpdate();
}
