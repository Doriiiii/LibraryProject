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
	/// Summary for Add_person
	/// </summary>
	public ref class Add_person : public System::Windows::Forms::Form
	{
	public:
		Add_person(std::vector<Client_user*>* c)
		{
			InitializeComponent();
			
			clients = c;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_person()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_cancel;
	private: System::Windows::Forms::TextBox^  textBox_name;
	private: System::Windows::Forms::TextBox^  textBox_surname;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button_accept;

	public: bool Was_added = false;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		std::vector<Client_user*>* clients;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_surname = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_accept = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_cancel
			// 
			this->button_cancel->Location = System::Drawing::Point(159, 139);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(75, 23);
			this->button_cancel->TabIndex = 4;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			this->button_cancel->Click += gcnew System::EventHandler(this, &Add_person::button_cancel_Click);
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(76, 43);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(158, 20);
			this->textBox_name->TabIndex = 1;
			// 
			// textBox_surname
			// 
			this->textBox_surname->Location = System::Drawing::Point(76, 69);
			this->textBox_surname->Name = L"textBox_surname";
			this->textBox_surname->Size = System::Drawing::Size(158, 20);
			this->textBox_surname->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Surname";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 47);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Name";
			// 
			// button_accept
			// 
			this->button_accept->Location = System::Drawing::Point(76, 139);
			this->button_accept->Name = L"button_accept";
			this->button_accept->Size = System::Drawing::Size(75, 23);
			this->button_accept->TabIndex = 3;
			this->button_accept->Text = L"Accept";
			this->button_accept->UseVisualStyleBackColor = true;
			this->button_accept->Click += gcnew System::EventHandler(this, &Add_person::button_accept_Click);
			// 
			// Add_person
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(281, 181);
			this->Controls->Add(this->button_accept);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->textBox_name);
			this->Controls->Add(this->textBox_surname);
			this->MaximizeBox = false;
			this->Name = L"Add_person";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Add person";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_accept_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_cancel_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
