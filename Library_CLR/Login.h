#pragma once
#include <algorithm>
#include <vector>
#include "User.h"


namespace LibraryCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(std::vector<User*>* u)
		{
			InitializeComponent();

			users = u;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  login_textBox;
	private: System::Windows::Forms::TextBox^  password_textBox;

	private: System::Windows::Forms::Label^  Login_label;

	private: System::Windows::Forms::Label^  Pass_label;
	private: System::Windows::Forms::Button^  Accept_button;
	private: System::Windows::Forms::Button^  Cancel_button;

	public: bool Is_logged = false;
			std::string *Logged_user_name = nullptr;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

		std::vector<User*>* users;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->login_textBox = (gcnew System::Windows::Forms::TextBox());
			this->password_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Login_label = (gcnew System::Windows::Forms::Label());
			this->Pass_label = (gcnew System::Windows::Forms::Label());
			this->Accept_button = (gcnew System::Windows::Forms::Button());
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// login_textBox
			// 
			this->login_textBox->Location = System::Drawing::Point(115, 25);
			this->login_textBox->Name = L"login_textBox";
			this->login_textBox->Size = System::Drawing::Size(131, 20);
			this->login_textBox->TabIndex = 1;
			// 
			// password_textBox
			// 
			this->password_textBox->Location = System::Drawing::Point(115, 66);
			this->password_textBox->Name = L"password_textBox";
			this->password_textBox->Size = System::Drawing::Size(131, 20);
			this->password_textBox->TabIndex = 2;
			this->password_textBox->UseSystemPasswordChar = true;
			// 
			// Login_label
			// 
			this->Login_label->AutoSize = true;
			this->Login_label->CausesValidation = false;
			this->Login_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Login_label->Location = System::Drawing::Point(25, 25);
			this->Login_label->Name = L"Login_label";
			this->Login_label->Size = System::Drawing::Size(48, 20);
			this->Login_label->TabIndex = 1;
			this->Login_label->Text = L"Login";
			// 
			// Pass_label
			// 
			this->Pass_label->AutoSize = true;
			this->Pass_label->CausesValidation = false;
			this->Pass_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Pass_label->Location = System::Drawing::Point(25, 66);
			this->Pass_label->Name = L"Pass_label";
			this->Pass_label->Size = System::Drawing::Size(78, 20);
			this->Pass_label->TabIndex = 3;
			this->Pass_label->Text = L"Password";
			// 
			// Accept_button
			// 
			this->Accept_button->Location = System::Drawing::Point(29, 105);
			this->Accept_button->Name = L"Accept_button";
			this->Accept_button->Size = System::Drawing::Size(96, 42);
			this->Accept_button->TabIndex = 4;
			this->Accept_button->Text = L"Accept";
			this->Accept_button->UseVisualStyleBackColor = true;
			this->Accept_button->Click += gcnew System::EventHandler(this, &Login::Accept_button_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancel_button->Location = System::Drawing::Point(150, 105);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(96, 42);
			this->Cancel_button->TabIndex = 5;
			this->Cancel_button->Text = L"Cancel";
			this->Cancel_button->UseVisualStyleBackColor = true;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &Login::Cancel_button_Click);
			// 
			// Login
			// 
			this->AcceptButton = this->Accept_button;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancel_button;
			this->ClientSize = System::Drawing::Size(272, 170);
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->Accept_button);
			this->Controls->Add(this->Pass_label);
			this->Controls->Add(this->Login_label);
			this->Controls->Add(this->password_textBox);
			this->Controls->Add(this->login_textBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Login";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Dori\'s Library - Login";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Accept_button_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void Cancel_button_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
