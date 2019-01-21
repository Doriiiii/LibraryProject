#pragma once
#include <vector>
#include "Book.h"
#include "Client_user.h"

namespace LibraryCLR
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Borrow
	/// </summary>
	public ref class Borrow : public System::Windows::Forms::Form
	{
	public:
		Borrow(std::vector<Book*>* b, Client_user* c)
		{
			InitializeComponent();
			
			books = b;
			user = c;

			Update_list_view_items();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Borrow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_search;
	private: System::Windows::Forms::Button^  button_borrow;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Button^  button_search;

	public:
		bool Was_borrowed = false;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		std::vector<Book*>* books;
	private: System::Windows::Forms::ListView^  listView;
	private: System::Windows::Forms::ColumnHeader^  Id_column;
	private: System::Windows::Forms::ColumnHeader^  Title_column;
	private: System::Windows::Forms::ColumnHeader^  Name_column;
	private: System::Windows::Forms::ColumnHeader^  Surname_column;
	private: System::Windows::Forms::ColumnHeader^  Genre_column;
	private: System::Windows::Forms::ColumnHeader^  Status_column;
			 Client_user* user;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_search = (gcnew System::Windows::Forms::TextBox());
			this->button_borrow = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Id_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Title_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Name_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Surname_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Genre_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Status_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(88, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Author / Title";
			// 
			// textBox_search
			// 
			this->textBox_search->AcceptsReturn = true;
			this->textBox_search->Location = System::Drawing::Point(91, 48);
			this->textBox_search->Name = L"textBox_search";
			this->textBox_search->Size = System::Drawing::Size(306, 20);
			this->textBox_search->TabIndex = 1;
			this->textBox_search->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Borrow::textBox_search_KeyPress);
			// 
			// button_borrow
			// 
			this->button_borrow->Location = System::Drawing::Point(287, 276);
			this->button_borrow->Name = L"button_borrow";
			this->button_borrow->Size = System::Drawing::Size(75, 34);
			this->button_borrow->TabIndex = 4;
			this->button_borrow->Text = L"Borrow";
			this->button_borrow->UseVisualStyleBackColor = true;
			this->button_borrow->Click += gcnew System::EventHandler(this, &Borrow::button_borrow_Click);
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(16, 75);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(346, 178);
			this->listView1->TabIndex = 6;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(416, 32);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(75, 36);
			this->button_search->TabIndex = 2;
			this->button_search->Text = L"Search";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &Borrow::button_search_Click);
			// 
			// listView
			// 
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6)
			{
				this->Id_column, this->Title_column,
					this->Name_column, this->Surname_column, this->Genre_column, this->Status_column
			});
			this->listView->FullRowSelect = true;
			this->listView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView->Location = System::Drawing::Point(16, 75);
			this->listView->MultiSelect = false;
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(570, 195);
			this->listView->TabIndex = 3;
			this->listView->UseCompatibleStateImageBehavior = false;
			this->listView->View = System::Windows::Forms::View::Details;
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
			this->Name_column->Width = 100;
			// 
			// Surname_column
			// 
			this->Surname_column->Text = L"Surname";
			this->Surname_column->Width = 100;
			// 
			// Genre_column
			// 
			this->Genre_column->Text = L"Genre";
			this->Genre_column->Width = 80;
			// 
			// Status_column
			// 
			this->Status_column->Text = L"Status";
			this->Status_column->Width = 70;
			// 
			// Borrow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(602, 330);
			this->Controls->Add(this->listView);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button_borrow);
			this->Controls->Add(this->textBox_search);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"Borrow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Dori\'s Library - Borrow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_borrow_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textBox_search_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
			 void Update_list_view_items();
};
}
