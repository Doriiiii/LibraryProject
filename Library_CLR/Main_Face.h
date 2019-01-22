#pragma once
#include <vector>
#include "CSV_reader.h"
#include "CSV_writer.h"
#include "Book.h"
#include "Client_user.h"
#include "No_file_exception.h"
#include "Logger.h"
#include "Constant_definitions.h"


namespace LibraryCLR
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o window
	/// </summary>
	public ref class Main_Face : public System::Windows::Forms::Form
	{
	public:
		Main_Face(void)
		{
			InitializeComponent();

			try
			{
				books = CSV_reader::Read_books(path_books);
			}
			catch (No_file_exception& ex)
			{
				std::string c_msg = "Error trying to load books list:\n";
				c_msg += ex.what();
				c_msg += ".\n\nLibrary in unavailable. App is closing...";
				String^ msg = gcnew String(c_msg.c_str());

				auto msg_resp = MessageBox::Show(this, msg, "Loading fail",
					MessageBoxButtons::OK, MessageBoxIcon::Error, MessageBoxDefaultButton::Button1);

				this->Close();
			}
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Main_Face()
		{
			if (components)
			{
				delete components;
			}

			if (books != NULL)
			{
				CSV_writer::Write_books(books, path_books);

				while (books->size())
				{
					delete books->back();
					books->pop_back();
				}
				delete books;
				books = NULL;
			}

			if (!was_log_saved)
			{
				CSV_writer::Write_events(Logger::Get_events());
				was_log_saved = true;
			}
		}
	private: System::Windows::Forms::Label^  WelcomeText;
	private: System::Windows::Forms::Button^  Login_button;
	private: System::Windows::Forms::Button^  OtherUser_button;


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

		std::vector<Book*>* books;
		bool was_log_saved = false;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_Face::typeid));
			this->WelcomeText = (gcnew System::Windows::Forms::Label());
			this->Login_button = (gcnew System::Windows::Forms::Button());
			this->OtherUser_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// WelcomeText
			// 
			this->WelcomeText->AutoSize = true;
			this->WelcomeText->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->WelcomeText->Font = (gcnew System::Drawing::Font(L"Mistral", 48, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->WelcomeText->Location = System::Drawing::Point(60, 44);
			this->WelcomeText->Name = L"WelcomeText";
			this->WelcomeText->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->WelcomeText->Size = System::Drawing::Size(517, 76);
			this->WelcomeText->TabIndex = 0;
			this->WelcomeText->Text = L"Dori\'s Library Welcome";
			this->WelcomeText->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Login_button
			// 
			this->Login_button->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->Login_button->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_button->Location = System::Drawing::Point(60, 179);
			this->Login_button->Name = L"Login_button";
			this->Login_button->Size = System::Drawing::Size(217, 77);
			this->Login_button->TabIndex = 1;
			this->Login_button->Text = L"Log In";
			this->Login_button->UseVisualStyleBackColor = false;
			this->Login_button->Click += gcnew System::EventHandler(this, &Main_Face::Login_Click);
			// 
			// OtherUser_button
			// 
			this->OtherUser_button->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->OtherUser_button->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->OtherUser_button->Location = System::Drawing::Point(370, 179);
			this->OtherUser_button->Name = L"OtherUser_button";
			this->OtherUser_button->Size = System::Drawing::Size(207, 77);
			this->OtherUser_button->TabIndex = 2;
			this->OtherUser_button->Text = L"Continue without logging in";
			this->OtherUser_button->UseVisualStyleBackColor = false;
			this->OtherUser_button->Click += gcnew System::EventHandler(this, &Main_Face::OtherUser_button_Click);
			// 
			// Main_Face
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(639, 328);
			this->Controls->Add(this->OtherUser_button);
			this->Controls->Add(this->Login_button);
			this->Controls->Add(this->WelcomeText);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Main_Face";
			this->Text = L"Dori\'s Library";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void Login_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void OtherUser_button_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
