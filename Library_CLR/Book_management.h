#pragma once
#include <vector>
#include "Book.h"

namespace LibraryCLR
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Book_management
	/// </summary>
	public ref class Book_management : public System::Windows::Forms::Form
	{
	public:
		Book_management(std::vector<Book*>* b)
		{
			InitializeComponent();

			books = b;
			Update_list_view_items();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Book_management()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  search_textBox;

	private: System::Windows::Forms::Button^  button_add;
	private: System::Windows::Forms::Button^  button_delete;
	private: System::Windows::Forms::Button^  button_search;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListView^  listView;
	private: System::Windows::Forms::ColumnHeader^  Id_column;
	private: System::Windows::Forms::ColumnHeader^  Title_column;
	private: System::Windows::Forms::ColumnHeader^  Name_column;
	private: System::Windows::Forms::ColumnHeader^  Surname_column;
	private: System::Windows::Forms::ColumnHeader^  Genre_column;
	private: System::Windows::Forms::ColumnHeader^  Status_column;

			 std::vector<Book*>* books;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->search_textBox = (gcnew System::Windows::Forms::TextBox());
				 this->button_add = (gcnew System::Windows::Forms::Button());
				 this->button_delete = (gcnew System::Windows::Forms::Button());
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
				 this->label1->Location = System::Drawing::Point(12, 25);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(72, 13);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Author / Title:";
				 // 
				 // search_textBox
				 // 
				 this->search_textBox->AcceptsReturn = true;
				 this->search_textBox->Location = System::Drawing::Point(92, 20);
				 this->search_textBox->Name = L"search_textBox";
				 this->search_textBox->Size = System::Drawing::Size(490, 20);
				 this->search_textBox->TabIndex = 2;
				 this->search_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Book_management::search_textBox_KeyPress);
				 // 
				 // button_add
				 // 
				 this->button_add->Location = System::Drawing::Point(600, 133);
				 this->button_add->Name = L"button_add";
				 this->button_add->Size = System::Drawing::Size(75, 23);
				 this->button_add->TabIndex = 3;
				 this->button_add->Text = L"Add";
				 this->button_add->UseVisualStyleBackColor = true;
				 this->button_add->Click += gcnew System::EventHandler(this, &Book_management::button_add_Click);
				 // 
				 // button_delete
				 // 
				 this->button_delete->Location = System::Drawing::Point(600, 180);
				 this->button_delete->Name = L"button_delete";
				 this->button_delete->Size = System::Drawing::Size(75, 23);
				 this->button_delete->TabIndex = 3;
				 this->button_delete->Text = L"Delete";
				 this->button_delete->UseVisualStyleBackColor = true;
				 this->button_delete->Click += gcnew System::EventHandler(this, &Book_management::button_delete_Click);
				 // 
				 // button_search
				 // 
				 this->button_search->Location = System::Drawing::Point(600, 18);
				 this->button_search->Name = L"button_search";
				 this->button_search->Size = System::Drawing::Size(75, 23);
				 this->button_search->TabIndex = 4;
				 this->button_search->Text = L"Search";
				 this->button_search->UseVisualStyleBackColor = true;
				 this->button_search->Click += gcnew System::EventHandler(this, &Book_management::button_search_Click);
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
				 this->listView->Location = System::Drawing::Point(12, 64);
				 this->listView->MultiSelect = false;
				 this->listView->Name = L"listView";
				 this->listView->Size = System::Drawing::Size(570, 195);
				 this->listView->TabIndex = 5;
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
				 // Book_management
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(687, 272);
				 this->Controls->Add(this->button_search);
				 this->Controls->Add(this->button_delete);
				 this->Controls->Add(this->button_add);
				 this->Controls->Add(this->search_textBox);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->listView);
				 this->MaximizeBox = false;
				 this->Name = L"Book_management";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Dori\'s Library - Book management";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_delete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void search_textBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
			 void Update_list_view_items();
	};
}
