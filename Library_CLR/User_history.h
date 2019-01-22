#pragma once
#include <vector>
#include "Client_user.h"
#include "Reported_event.h"
#include "CSV_reader.h"
#include "Constant_definitions.h"
#include "No_file_exception.h"

namespace LibraryCLR
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Borrow_bring_menu
	/// </summary>
	public ref class User_history : public System::Windows::Forms::Form
	{
	public:
		User_history(Client_user* c)
		{
			InitializeComponent();

			selected_client = c;
			try
			{
				history = CSV_reader::Read_history(path_history, selected_client->Get_id(), selected_client->Get_name(), selected_client->Get_surname());
			}
			catch (No_file_exception& ex)
			{
				std::string c_msg = "Error trying to load user history:\n";
				c_msg += ex.what();
				c_msg += ".\n\nHistory in unavailable.";
				String^ msg = gcnew String(c_msg.c_str());

				auto msg_resp = MessageBox::Show(this, msg, "Loading fail",
					MessageBoxButtons::OK, MessageBoxIcon::Error, MessageBoxDefaultButton::Button1);

				this->Close();
				return;
			}

			std::string s = std::to_string(selected_client->Get_id()) + " - " + selected_client->Get_name() + " " + selected_client->Get_surname();
			textBox_user_id->Text = gcnew System::String(s.c_str());
			Load_list_view_items();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~User_history()
		{
			if (components)
			{
				delete components;
			}
			if (history != nullptr)
			{
				while (history->size())
				{
					delete history->back();
					history->pop_back();
				}
				delete history;
				history = nullptr;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListView^  listView;
	private: System::Windows::Forms::ColumnHeader^  Id_column;
	private: System::Windows::Forms::ColumnHeader^  Title_column;
	private: System::Windows::Forms::ColumnHeader^  Name_column;
	private: System::Windows::Forms::ColumnHeader^  Surname_column;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ColumnHeader^  Date_column;
	private: System::Windows::Forms::TextBox^  textBox_user_id;
	private: System::Windows::Forms::ColumnHeader^  Action_column;

			 Client_user* selected_client = nullptr;
			 std::vector<History_event*>* history;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->listView = (gcnew System::Windows::Forms::ListView());
				 this->Date_column = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Id_column = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Title_column = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Name_column = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Surname_column = (gcnew System::Windows::Forms::ColumnHeader());
				 this->Action_column = (gcnew System::Windows::Forms::ColumnHeader());
				 this->textBox_user_id = (gcnew System::Windows::Forms::TextBox());
				 this->SuspendLayout();
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(12, 15);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(43, 13);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"User ID";
				 // 
				 // listView
				 // 
				 this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6)
				 {
					 this->Date_column, this->Id_column,
						 this->Title_column, this->Name_column, this->Surname_column, this->Action_column
				 });
				 this->listView->FullRowSelect = true;
				 this->listView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
				 this->listView->Location = System::Drawing::Point(8, 38);
				 this->listView->MultiSelect = false;
				 this->listView->Name = L"listView";
				 this->listView->Size = System::Drawing::Size(571, 221);
				 this->listView->TabIndex = 3;
				 this->listView->UseCompatibleStateImageBehavior = false;
				 this->listView->View = System::Windows::Forms::View::Details;
				 // 
				 // Date_column
				 // 
				 this->Date_column->Text = L"Date";
				 this->Date_column->Width = 120;
				 // 
				 // Id_column
				 // 
				 this->Id_column->Text = L"Id";
				 this->Id_column->Width = 40;
				 // 
				 // Title_column
				 // 
				 this->Title_column->Text = L"Title";
				 this->Title_column->Width = 150;
				 // 
				 // Name_column
				 // 
				 this->Name_column->Text = L"Name";
				 this->Name_column->Width = 80;
				 // 
				 // Surname_column
				 // 
				 this->Surname_column->Text = L"Surname";
				 this->Surname_column->Width = 90;
				 // 
				 // Action_column
				 // 
				 this->Action_column->Text = L"Action";
				 this->Action_column->Width = 80;
				 // 
				 // textBox_user_id
				 // 
				 this->textBox_user_id->AcceptsReturn = true;
				 this->textBox_user_id->Location = System::Drawing::Point(64, 11);
				 this->textBox_user_id->Name = L"textBox_user_id";
				 this->textBox_user_id->ReadOnly = true;
				 this->textBox_user_id->Size = System::Drawing::Size(511, 20);
				 this->textBox_user_id->TabIndex = 1;
				 // 
				 // User_history
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(587, 271);
				 this->Controls->Add(this->textBox_user_id);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->listView);
				 this->MaximizeBox = false;
				 this->Name = L"User_history";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Dori\'s Library - Borrow/Bring menu";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

			 void Load_list_view_items();
	};
}
