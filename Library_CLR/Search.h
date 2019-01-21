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
	/// Podsumowanie informacji o Search
	/// </summary>
	public ref class Search : public System::Windows::Forms::Form
	{
	public:
		Search(std::vector<Book*>* b)
		{
			InitializeComponent();

			books = b;
			Update_list_view_items();
			search_comboBox->SelectedIndex = 0;
			//search_textBox->Focus();
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Search()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  search_by;
	private: System::Windows::Forms::ComboBox^  search_comboBox;
	private: System::Windows::Forms::RichTextBox^  search_textBox;
	private: System::Windows::Forms::Button^  search_button;
	private: System::Windows::Forms::ListView^  listView;
	private: System::Windows::Forms::ColumnHeader^  Name_column;
	private: System::Windows::Forms::ColumnHeader^  Surname_column;


	private: System::Windows::Forms::ColumnHeader^  Title_column;
	private: System::Windows::Forms::ColumnHeader^  Genre_column;




	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ColumnHeader^  Id_column;
	private: System::Windows::Forms::ColumnHeader^  Status_column;


			 std::vector<Book*>* books;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
			 /// jej zawartoœci w edytorze kodu.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->search_by = (gcnew System::Windows::Forms::Label());
				 this->search_comboBox = (gcnew System::Windows::Forms::ComboBox());
				 this->search_textBox = (gcnew System::Windows::Forms::RichTextBox());
				 this->search_button = (gcnew System::Windows::Forms::Button());
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
				 this->label1->Font = (gcnew System::Drawing::Font(L"Mistral", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label1->Location = System::Drawing::Point(5, 4);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(134, 19);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"Dori\'s library Welcome!";
				 // 
				 // search_by
				 // 
				 this->search_by->AutoSize = true;
				 this->search_by->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->search_by->Location = System::Drawing::Point(23, 40);
				 this->search_by->Name = L"search_by";
				 this->search_by->Size = System::Drawing::Size(116, 33);
				 this->search_by->TabIndex = 5;
				 this->search_by->Text = L"Search by:";
				 // 
				 // search_comboBox
				 // 
				 this->search_comboBox->FormattingEnabled = true;
				 this->search_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5)
				 {
					 L"Title", L"Author Name", L"Author Surname",
						 L"Genre", L"Id"
				 });
				 this->search_comboBox->Location = System::Drawing::Point(29, 85);
				 this->search_comboBox->Name = L"search_comboBox";
				 this->search_comboBox->Size = System::Drawing::Size(148, 21);
				 this->search_comboBox->TabIndex = 4;
				 // 
				 // search_textBox
				 // 
				 this->search_textBox->DetectUrls = false;
				 this->search_textBox->Location = System::Drawing::Point(225, 85);
				 this->search_textBox->Multiline = false;
				 this->search_textBox->Name = L"search_textBox";
				 this->search_textBox->Size = System::Drawing::Size(372, 21);
				 this->search_textBox->TabIndex = 1;
				 this->search_textBox->Text = L"";
				 this->search_textBox->WordWrap = false;
				 this->search_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Search::search_textBox_KeyPress);
				 // 
				 // search_button
				 // 
				 this->search_button->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->search_button->Location = System::Drawing::Point(466, 30);
				 this->search_button->Name = L"search_button";
				 this->search_button->Size = System::Drawing::Size(131, 43);
				 this->search_button->TabIndex = 2;
				 this->search_button->Text = L"Search";
				 this->search_button->UseVisualStyleBackColor = true;
				 this->search_button->Click += gcnew System::EventHandler(this, &Search::search_button_Click);
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
				 this->listView->Location = System::Drawing::Point(29, 125);
				 this->listView->MultiSelect = false;
				 this->listView->Name = L"listView";
				 this->listView->Size = System::Drawing::Size(568, 195);
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
				 // Search
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(631, 348);
				 this->Controls->Add(this->search_button);
				 this->Controls->Add(this->search_textBox);
				 this->Controls->Add(this->search_comboBox);
				 this->Controls->Add(this->search_by);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->listView);
				 this->MaximizeBox = false;
				 this->Name = L"Search";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				 this->Text = L"Dori\'s Library - Search";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void search_button_Click(System::Object^  sender, System::EventArgs^  e);
			 void Update_list_view_items();

	private: System::Void search_textBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	};
}
