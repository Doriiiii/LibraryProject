#pragma once
#include <vector>
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
	/// Summary for Person_management
	/// </summary>
	public ref class Person_management : public System::Windows::Forms::Form
	{
	public:
		Person_management(std::vector<Client_user*>* c)
		{
			InitializeComponent();
			
			clients = c;
			Update_list_view_items();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Person_management()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_search;

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
	private: System::Windows::Forms::ColumnHeader^  Name_column;
	private: System::Windows::Forms::ColumnHeader^  Surname_column;
	private: System::Windows::Forms::ColumnHeader^  Books_count_column;
			 std::vector<Client_user*>* clients;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_search = (gcnew System::Windows::Forms::TextBox());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Id_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Name_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Surname_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->Books_count_column = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(12, 56);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(295, 193);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID / Name:";
			// 
			// textBox_search
			// 
			this->textBox_search->AcceptsReturn = true;
			this->textBox_search->Location = System::Drawing::Point(78, 21);
			this->textBox_search->Name = L"textBox_search";
			this->textBox_search->Size = System::Drawing::Size(265, 20);
			this->textBox_search->TabIndex = 1;
			this->textBox_search->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Person_management::textBox_search_KeyPress);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(353, 120);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(75, 23);
			this->button_add->TabIndex = 4;
			this->button_add->Text = L"Add";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &Person_management::button_add_Click);
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(353, 167);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(75, 23);
			this->button_delete->TabIndex = 5;
			this->button_delete->Text = L"Delete";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &Person_management::button_delete_Click);
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(353, 20);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(75, 23);
			this->button_search->TabIndex = 2;
			this->button_search->Text = L"Search";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &Person_management::button_search_Click);
			// 
			// listView
			// 
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4)
			{
				this->Id_column, this->Name_column,
					this->Surname_column, this->Books_count_column
			});
			this->listView->FullRowSelect = true;
			this->listView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView->Location = System::Drawing::Point(12, 56);
			this->listView->MultiSelect = false;
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(331, 195);
			this->listView->TabIndex = 3;
			this->listView->UseCompatibleStateImageBehavior = false;
			this->listView->View = System::Windows::Forms::View::Details;
			// 
			// Id_column
			// 
			this->Id_column->Text = L"Id";
			this->Id_column->Width = 40;
			// 
			// Name_column
			// 
			this->Name_column->Text = L"Name";
			this->Name_column->Width = 80;
			// 
			// Surname_column
			// 
			this->Surname_column->Text = L"Surname";
			this->Surname_column->Width = 80;
			// 
			// Books_count_column
			// 
			this->Books_count_column->Text = L"Owned books";
			this->Books_count_column->Width = 85;
			// 
			// Person_management
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 261);
			this->Controls->Add(this->listView);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->textBox_search);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView1);
			this->MaximizeBox = false;
			this->Name = L"Person_management";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Dori\'s Library - Person management";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_delete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textBox_search_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
			 void Update_list_view_items();
};
}
