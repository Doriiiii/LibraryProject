#pragma once
#include <vector>
#include "Constant_definitions.h"
#include "CSV_reader.h"
#include "CSV_writer.h"
#include "Client_user.h"
#include "Book.h"
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
	/// Summary for Menu_logged
	/// </summary>
	public ref class Menu_logged : public System::Windows::Forms::Form
	{
	public:
		Menu_logged(std::vector<Book*>* b, std::string user_name)
		{
			InitializeComponent();

			books = b;

			try
			{
				clients = CSV_reader::Read_clients(path_users);
			}
			catch (No_file_exception& ex)
			{
				std::string c_msg = "Error trying to load users list:\n";
				c_msg += ex.what();
				c_msg += ".\n\nUsers management and borrowing books are unavailable.";
				String^ msg = gcnew String(c_msg.c_str());

				auto msg_resp = MessageBox::Show(this, msg, "Loading fail",
					MessageBoxButtons::OK, MessageBoxIcon::Error, MessageBoxDefaultButton::Button1);

				borrow_button->Enabled = false;
				person_button->Enabled = false;
			}
			user_name_label->Text = gcnew System::String(user_name.c_str());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Menu_logged()
		{
			if (components)
			{
				delete components;
			}

			if (clients != NULL)
			{
				CSV_writer::Write_clients(clients, path_users);

				while (clients->size())
				{
					delete clients->back();
					clients->pop_back();
				}
				delete clients;
				clients = NULL;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  book_button;
	private: System::Windows::Forms::Button^  person_button;
	private: System::Windows::Forms::Button^  borrow_button;
	private: System::Windows::Forms::Label^  user_name_label;
	private: System::Windows::Forms::Label^  label2;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		std::vector<Client_user*>* clients;
		std::vector<Book*>* books;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->book_button = (gcnew System::Windows::Forms::Button());
			this->person_button = (gcnew System::Windows::Forms::Button());
			this->borrow_button = (gcnew System::Windows::Forms::Button());
			this->user_name_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your account:";
			// 
			// book_button
			// 
			this->book_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->book_button->Location = System::Drawing::Point(16, 106);
			this->book_button->Name = L"book_button";
			this->book_button->Size = System::Drawing::Size(121, 52);
			this->book_button->TabIndex = 2;
			this->book_button->Text = L"Add/Delete\r\nBook";
			this->book_button->UseVisualStyleBackColor = true;
			this->book_button->Click += gcnew System::EventHandler(this, &Menu_logged::book_button_Click);
			// 
			// person_button
			// 
			this->person_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->person_button->Location = System::Drawing::Point(149, 106);
			this->person_button->Name = L"person_button";
			this->person_button->Size = System::Drawing::Size(123, 52);
			this->person_button->TabIndex = 3;
			this->person_button->Text = L"Add/Delete\r\nPerson";
			this->person_button->UseVisualStyleBackColor = true;
			this->person_button->Click += gcnew System::EventHandler(this, &Menu_logged::person_button_Click);
			// 
			// borrow_button
			// 
			this->borrow_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->borrow_button->Location = System::Drawing::Point(76, 176);
			this->borrow_button->Name = L"borrow_button";
			this->borrow_button->Size = System::Drawing::Size(133, 52);
			this->borrow_button->TabIndex = 4;
			this->borrow_button->Text = L"Borrow/Bring out";
			this->borrow_button->UseVisualStyleBackColor = true;
			this->borrow_button->Click += gcnew System::EventHandler(this, &Menu_logged::borrow_button_Click);
			// 
			// user_name_label
			// 
			this->user_name_label->AutoSize = true;
			this->user_name_label->Location = System::Drawing::Point(93, 13);
			this->user_name_label->Name = L"user_name_label";
			this->user_name_label->Size = System::Drawing::Size(0, 13);
			this->user_name_label->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(81, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Select action:";
			// 
			// Menu_logged
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 253);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->user_name_label);
			this->Controls->Add(this->borrow_button);
			this->Controls->Add(this->person_button);
			this->Controls->Add(this->book_button);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Menu_logged";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Dori\'s Library - Menu";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Menu_logged::Menu_logged_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void book_button_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void person_button_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void borrow_button_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Menu_logged_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	};
}
