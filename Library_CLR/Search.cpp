#include "Search.h"
#include <typeinfo>

System::Void LibraryCLR::Search::search_button_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Update_list_view_items();
}

void LibraryCLR::Search::Update_list_view_items()
{
	listView->BeginUpdate();
	listView->Items->Clear();

	if (System::String::IsNullOrWhiteSpace(search_textBox->Text))
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
		if (search_comboBox->SelectedItem == "Title")
		{
			for each (Book* b in *books)
			{
				System::String^ s = gcnew System::String(b->Get_title().c_str());
				if (s->ToLower()->Contains(search_textBox->Text->ToLower()))
				{
					ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(b->Get_id()).c_str()));
					item->SubItems->Add(s);
					item->SubItems->Add(gcnew System::String(b->Get_author_name().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_author_surname().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_genre().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

					listView->Items->Add(item);
				}
			}
		}
		else if (search_comboBox->SelectedItem == "Author Name")
		{
			for each (Book* b in *books)
			{
				System::String^ s = gcnew System::String(b->Get_author_name().c_str());
				if (s->ToLower()->Contains(search_textBox->Text->ToLower()))
				{
					ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(b->Get_id()).c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_title().c_str()));
					item->SubItems->Add(s);
					item->SubItems->Add(gcnew System::String(b->Get_author_surname().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_genre().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

					listView->Items->Add(item);
				}
			}
		}
		else if (search_comboBox->SelectedItem == "Author Surname")
		{
			for each (Book* b in *books)
			{
				System::String^ s = gcnew System::String(b->Get_author_surname().c_str());
				if (s->ToLower()->Contains(search_textBox->Text->ToLower()))
				{
					ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(b->Get_id()).c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_title().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_author_name().c_str()));
					item->SubItems->Add(s);
					item->SubItems->Add(gcnew System::String(b->Get_genre().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

					listView->Items->Add(item);
				}
			}
		}
		else if (search_comboBox->SelectedItem == "Genre")
		{
			for each (Book* b in *books)
			{
				System::String^ s = gcnew System::String(b->Get_genre().c_str());
				if (s->ToLower()->Contains(search_textBox->Text->ToLower()))
				{
					ListViewItem^ item = gcnew ListViewItem(gcnew System::String(std::to_string(b->Get_id()).c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_title().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_author_name().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_author_surname().c_str()));
					item->SubItems->Add(s);
					item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

					listView->Items->Add(item);
				}
			}
		}
		else if (search_comboBox->SelectedItem == "Id")
		{
			for each (Book* b in *books)
			{
				System::String^ s = gcnew System::String(std::to_string(b->Get_id()).c_str());
				if (s->ToLower()->Contains(search_textBox->Text->ToLower()))
				{
					ListViewItem^ item = gcnew ListViewItem(s);
					item->SubItems->Add(gcnew System::String(b->Get_title().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_author_name().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_author_surname().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_genre().c_str()));
					item->SubItems->Add(gcnew System::String(b->Get_borrowed_status() ? "Borrowed" : "Available"));

					listView->Items->Add(item);
				}
			}
		}
	}

	// Allow the ListBox to repaint and display the new items.
	listView->EndUpdate();
}

System::Void LibraryCLR::Search::search_textBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (e->KeyChar == (wchar_t)Keys::Return)
	{
		Update_list_view_items();
	}
}
