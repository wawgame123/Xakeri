#pragma once

#include "Settings.h" 
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
namespace Xakeri {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			InitializeComponent();

			// Настройка TextBox
			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font("Consolas", 33);
			textBox1->Multiline = true;
			textBox1->ScrollBars = ScrollBars::Vertical;

			// Начальный текст терминала
			textBox1->Text =
				"Терминал\r\n"
				"> Настройки - Н, Выход - В\r\n"
				"> ";

			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;


			textBox1->KeyDown += gcnew KeyEventHandler(this, &MyForm::textBox1_KeyDown);
		}
		

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;


	private:
		int inputStart;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 58.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(-5, 1);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(945, 1031);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1002, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(461, 75);
			this->button1->TabIndex = 1;
			this->button1->Text = L" Этап 1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button2->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(1002, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(461, 75);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Этап 2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button3->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(1002, 243);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(461, 75);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Этап 3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button4->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(1002, 346);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(461, 75);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Этап 4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button5->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(1002, 453);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(461, 75);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Этап 5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button6->FlatAppearance->BorderColor = System::Drawing::SystemColors::AppWorkspace;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(1002, 552);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(461, 75);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Этап 6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		// Запрет удаления прошлого текста
		if (textBox1->SelectionStart < inputStart &&
			(e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete))
		{
			e->SuppressKeyPress = true;
			return;
		}

		// Обработка Enter
		if (e->KeyCode == Keys::Enter)
		{
			e->SuppressKeyPress = true;

			String^ command = textBox1->Text->Substring(inputStart)->Trim();
			ExecuteCommand(command);

			textBox1->AppendText("\r\n>");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
		}
	}
private: bool waitingForExitConfirmation = false; // новое поле

private: void ExecuteCommand(String^ cmd)
{
	cmd = cmd->ToLower();

	if (waitingForExitConfirmation)
	{
		// Ждем ответ на подтверждение выхода
		if (cmd == "y")
		{
			Application::Exit();
		}
		else if (cmd == "n")
		{
			// Отмена выхода — возвращаем прошлый текст
			textBox1->Text =
				"Терминал\r\n"
				"> Настройки - Н, Выход - В\r\n"
				"> ";
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
		}
		else
		{
			textBox1->AppendText("\r\nНеизвестная команда");
		}

		waitingForExitConfirmation = false; // сброс состояния
	}
	else if (cmd == "н" || cmd == "настройки")
	{
		Settings^ settingsForm = gcnew Settings();
		settingsForm->Show();
	}
	else if (cmd == "в" || cmd == "выход")
	{
		// Запрос подтверждения выхода
		textBox1->AppendText("\r\nВы уверены? (y/n)");
		inputStart = textBox1->Text->Length;
		textBox1->SelectionStart = inputStart;
		waitingForExitConfirmation = true;
	}
	else
	{
		textBox1->AppendText("\r\nНеизвестная команда");
	}
}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		Stage6^ stage1Form = gcnew Stage6();
		stage1Form->Show();
		this->Hide();
		button6->Enabled=false;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stage1^ stage1Form = gcnew Stage1();
		stage1Form->Show();  
		this->Hide();
		button1->Enabled = false;
	}
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Stage2^ stage1Form = gcnew Stage2();
	stage1Form->Show();   
	this->Hide();
	button2->Enabled = false;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Stage3^ stage1Form = gcnew Stage3();
	stage1Form->Show();
	this->Hide();
	button3->Enabled = false;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Stage4^ stage1Form = gcnew Stage4();
	stage1Form->Show();
	this->Hide();
	button4->Enabled = false;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Stage5^ stage1Form = gcnew Stage5();
	stage1Form->Show();
	this->Hide();
	button5->Enabled = false;
}
};
}
