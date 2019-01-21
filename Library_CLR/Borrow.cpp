#include "Borrow.h"
#include "Reported_event.h"
#include "Logger.h"
#include "Constant_definitions.h"

System::Void LibraryCLR::Borrow::button_search_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Update_list_view_items();
}

System::Void LibraryCLR::Borrow::button_borrow_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (listView->SelectedItems->Count > 0)
	{
		System::String^ borrowed = gcnew System::String("Borrowed");
		for each(auto si in listView->SelectedItems[0]->SubItems)
		{
			if (((ListViewItem::ListViewSubItem^)si)->Text->Contains(borrowed))
			{
				auto msg_resp = MessageBox::Show(this, "Cannot borrow book which is already borrowed!", "Borrow conflict",
					MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
				return;
			}
		}

		int id = -1;
		System::Int32::TryParse(listView->SelectedItems[0]->Text, id);
		for (std::vector<Book*>::iterator it = (*books).begin(); it != (*books).end(); ++it)
		{
			if ((*it)->Get_id() == id)
			{
				(*it)->Set_borrowed_status(true);
				user->Borrow_book(id);
				Was_borrowed = true;
				Logger::Add_event(new Reported_event(code_borrow_book, id, (*it)->Get_title(), text_borrow_book));

				this->Close();
				return;
			}
		}
	}
	else
	{
		auto msg_resp = MessageBox::Show(this, "Select Book first!", "No book selected",
			MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1);
	}
}

System::Void LibraryCLR::Borrow::textBox_search_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (e->KeyChar == (wchar_t)Keys::Return)
	{
		Update_list_view_items();
	}
}

void LibraryCLR::Borrow::Update_list_view_items()
{
	listView->BeginUpdate();
	listView->Items->Clear();

	if (System::String::IsNullOrWhiteSpace(textBox_search->Text))
	{
		for each (Book* b in *books)
		{
			ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(b->Get_id()).c_str()));
			item->SubItems->Add(gcnew System::String(b->Get_title().c_str()));
			item->SubItems->Add(gcnew System::String(b->Get_author_name().c_str()));
			item->SubItems->Add(gcnew System::String(b->Get_author_surname().c_str()));
			item->SubItems->Add(gcnew System::String(b->Get_genre().c_str()));
			item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

			listView->Items->Add(item);
		}
	}
	else
	{
		for each (Book* b in *books)
		{
			System::String^ title = gcnew System::String(b->Get_title().c_str());
			System::String^ author_name = gcnew System::String(b->Get_author_name().c_str());
			System::String^ author_surname = gcnew System::String(b->Get_author_surname().c_str());

			if (title->ToLower()->Contains(textBox_search->Text->ToLower()) ||
				author_name->ToLower()->Contains(textBox_search->Text->ToLower()) ||
				author_surname->ToLower()->Contains(textBox_search->Text->ToLower()))
			{
				ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(b->Get_id()).c_str()));
				item->SubItems->Add(gcnew System::String(b->Get_title().c_str()));
				item->SubItems->Add(gcnew System::String(b->Get_author_name().c_str()));
				item->SubItems->Add(gcnew System::String(b->Get_author_surname().c_str()));
				item->SubItems->Add(gcnew System::String(b->Get_genre().c_str()));
				item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

				listView->Items->Add(item);
			}
		}
	}

	// Allow the ListBox to repaint and display the new items.
	listView->EndUpdate();
}