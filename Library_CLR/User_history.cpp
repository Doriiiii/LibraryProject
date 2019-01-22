#include "User_history.h"
#include <string>

void LibraryCLR::User_history::Load_list_view_items()
{
	listView->BeginUpdate();
	listView->Items->Clear();

	for each (History_event* h in *history)
	{
		time_t d = h->Get_time_stamp();
		tm *ltm = localtime(&d);
		char date[16];
		sprintf(date, date_format, (ltm->tm_year + 1900), (ltm->tm_mon + 1), ltm->tm_mday, ltm->tm_hour, ltm->tm_min);

		ListViewItem^ item = gcnew ListViewItem(gcnew System::String(date));
		item->SubItems->Add(gcnew System::String(std::to_string(h->Get_book_id()).c_str()));
		item->SubItems->Add(gcnew System::String(h->Get_book_title().c_str()));
		item->SubItems->Add(gcnew System::String(h->Get_book_author_name().c_str()));
		item->SubItems->Add(gcnew System::String(h->Get_book_author_surname().c_str()));
		item->SubItems->Add(gcnew System::String(h->Get_action_name().c_str()));

		listView->Items->Add(item);
	}

	// Allow the ListBox to repaint and display the new items.
	listView->EndUpdate();
}
