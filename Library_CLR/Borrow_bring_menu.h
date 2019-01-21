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
	/// Summary for Borrow_bring_menu
	/// </summary>
	public ref class Borrow_bring_menu : public System::Windows::Forms::Form
	{
	public:
		Borrow_bring_menu(std::vector<Book*>* b, std::vector<Client_user*>* c)
		{
			InitializeComponent();

			books_all = b;
			clients_all = c;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Borrow_bring_menu()
		{
			if (components)
			{
				delete components;
			}

			if (books_borrowed != nullptr)
			{
				delete books_borrowed; //only this vector of pointers
				books_borrowed = nullptr;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_user_id;

	private: System::Windows::Forms::Button^  button_search;
	private: System::Windows::Forms::Button^  button_borrow;
	private: System::Windows::Forms::Button^  button_bring;
	private: System::Windows::Forms::ListView^  listView;
	private: System::Windows::Forms::ColumnHeader^  Id_column;
	private: System::Windows::Forms::ColumnHeader^  Title_column;
	private: System::Windows::Forms::ColumnHeader^  Name_column;
	private: System::Windows::Forms::ColumnHeader^  Surname_column;
	private: System::Windows::Forms::ColumnHeader^  Genre_column;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		std::vector<Book*>* books_all;
		std::vector<Client_user*>* clients_all;

		std::vector<Book*>* books_borrowed = nullptr;
		Client_user* selected_client = nullptr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_user_id = (gcnew System::Windows::Forms::TextBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->button_borrow = (gcnew System::Windows::Forms::Button());
			this->button_bring = (gcnew System::Windows::Forms::Button());
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Id_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Title_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Name_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Surname_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Genre_column = (gcnew System::Windows::Forms::ColumnHeader());
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
			// textBox_user_id
			// 
			this->textBox_user_id->AcceptsReturn = true;
			this->textBox_user_id->Location = System::Drawing::Point(64, 11);
			this->textBox_user_id->Name = L"textBox_user_id";
			this->textBox_user_id->Size = System::Drawing::Size(100, 20);
			this->textBox_user_id->TabIndex = 1;
			this->textBox_user_id->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Borrow_bring_menu::textBox_user_id_KeyPress);
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(181, 9);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(75, 23);
			this->button_search->TabIndex = 2;
			this->button_search->Text = L"Search";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &Borrow_bring_menu::button_search_Click);
			// 
			// button_borrow
			// 
			this->button_borrow->Location = System::Drawing::Point(8, 238);
			this->button_borrow->Name = L"button_borrow";
			this->button_borrow->Size = System::Drawing::Size(75, 23);
			this->button_borrow->TabIndex = 4;
			this->button_borrow->Text = L"Borrow";
			this->button_borrow->UseVisualStyleBackColor = true;
			this->button_borrow->Click += gcnew System::EventHandler(this, &Borrow_bring_menu::button_borrow_Click);
			// 
			// button_bring
			// 
			this->button_bring->Location = System::Drawing::Point(432, 238);
			this->button_bring->Name = L"button_bring";
			this->button_bring->Size = System::Drawing::Size(75, 23);
			this->button_bring->TabIndex = 5;
			this->button_bring->Text = L"Bring out";
			this->button_bring->UseVisualStyleBackColor = true;
			this->button_bring->Click += gcnew System::EventHandler(this, &Borrow_bring_menu::button_bring_Click);
			// 
			// listView
			// 
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5)
			{
				this->Id_column, this->Title_column,
					this->Name_column, this->Surname_column, this->Genre_column
			});
			this->listView->FullRowSelect = true;
			this->listView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView->Location = System::Drawing::Point(8, 38);
			this->listView->MultiSelect = false;
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(499, 194);
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
			// Borrow_bring_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(517, 271);
			this->Controls->Add(this->button_bring);
			this->Controls->Add(this->button_borrow);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->textBox_user_id);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView);
			this->MaximizeBox = false;
			this->Name = L"Borrow_bring_menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Dori\'s Library - Borrow/Bring menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_borrow_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_bring_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textBox_user_id_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
			 void Update_list_view_items();
	};
}
