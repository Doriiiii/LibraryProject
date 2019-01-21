#pragma once
#include <vector>
#include "Book.h"
#include "Book_factory.h"

namespace LibraryCLR
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Add_book
	/// </summary>
	public ref class Add_book : public System::Windows::Forms::Form
	{
	public:
		Add_book(std::vector<Book*>* b)
		{
			InitializeComponent();

			books = b;
			comboBox_genre->SelectedIndex = 0;
			factory = new Book_factory();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_book()
		{
			if (components)
			{
				delete components;
			}

			if (factory != nullptr)
			{
				delete factory;
				factory = nullptr;
			}
		}
	private: System::Windows::Forms::Button^  button_cancel;
	private: System::Windows::Forms::TextBox^  textBox_name;
	protected:

	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox_surname;

	private: System::Windows::Forms::TextBox^  textBox_title;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button_accept;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBox_genre;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		std::vector<Book*>* books;
		Book_factory* factory;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_surname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_title = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_accept = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox_genre = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button_cancel
			// 
			this->button_cancel->Location = System::Drawing::Point(159, 161);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(75, 23);
			this->button_cancel->TabIndex = 5;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			this->button_cancel->Click += gcnew System::EventHandler(this, &Add_book::button_cancel_Click);
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(76, 43);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(158, 20);
			this->textBox_name->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Title";
			// 
			// textBox_surname
			// 
			this->textBox_surname->Location = System::Drawing::Point(76, 69);
			this->textBox_surname->Name = L"textBox_surname";
			this->textBox_surname->Size = System::Drawing::Size(158, 20);
			this->textBox_surname->TabIndex = 1;
			// 
			// textBox_title
			// 
			this->textBox_title->Location = System::Drawing::Point(76, 95);
			this->textBox_title->Name = L"textBox_title";
			this->textBox_title->Size = System::Drawing::Size(158, 20);
			this->textBox_title->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Author";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Surname";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 47);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Name";
			// 
			// button_accept
			// 
			this->button_accept->Location = System::Drawing::Point(76, 161);
			this->button_accept->Name = L"button_accept";
			this->button_accept->Size = System::Drawing::Size(75, 23);
			this->button_accept->TabIndex = 4;
			this->button_accept->Text = L"Accept";
			this->button_accept->UseVisualStyleBackColor = true;
			this->button_accept->Click += gcnew System::EventHandler(this, &Add_book::button_accept_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Genre";
			// 
			// comboBox_genre
			// 
			this->comboBox_genre->FormattingEnabled = true;
			this->comboBox_genre->Items->AddRange(gcnew cli::array< System::Object^  >(8)
			{
				L"Adventure", L"Criminal", L"Document", L"Drama",
					L"Fantasy", L"Horror", L"Romance", L"Young adult"
			});
			this->comboBox_genre->Location = System::Drawing::Point(76, 122);
			this->comboBox_genre->Name = L"comboBox_genre";
			this->comboBox_genre->Size = System::Drawing::Size(158, 21);
			this->comboBox_genre->TabIndex = 3;
			// 
			// Add_book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(281, 204);
			this->Controls->Add(this->comboBox_genre);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button_accept);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->textBox_name);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_surname);
			this->Controls->Add(this->textBox_title);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"Add_book";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Add book";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_cancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_accept_Click(System::Object^  sender, System::EventArgs^  e);
};
}
