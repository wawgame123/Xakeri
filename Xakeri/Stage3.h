#pragma once

#include "Settings.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"

namespace Xakeri {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Stage3 : public System::Windows::Forms::Form
	{
	public:
		Stage3(void)
		{
			InitializeComponent();
			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font(L"Consolas", 33.0f);
			textBox1->Multiline = true;
			textBox1->ScrollBars = ScrollBars::Vertical;
			textBox1->Text =
				L"Терминал\r\n"
				L"> Настройки - Н, Выход - В\r\n"
				L"> ";
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			textBox1->KeyDown += gcnew KeyEventHandler(this, &Stage3::textBox1_KeyDown);
			rng = gcnew Random();
			InitializeDocuments();
			ShuffleIndices();
			currentIndex = -1;
			consecutiveCorrect = 0;
			passwordObtained = false;
			ShowNextDocument();
		}
	protected:
		~Stage3()
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
	private: System::Windows::Forms::Label^ label1;
	private:
		int inputStart;
		array<String^>^ docNames;
		array<int>^ docOwners;
		array<int>^ indices;
		int currentIndex;
		int consecutiveCorrect;
		bool passwordObtained;
		String^ password;
		Random^ rng;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage3::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(958, 424);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(210, 75);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Преподователь";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Stage3::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1190, 424);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(218, 75);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Директор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Stage3::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(958, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 52);
			this->label1->TabIndex = 3;
			this->label1->Click += gcnew System::EventHandler(this, &Stage3::label1_Click);
			// 
			// Stage3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Stage3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Кто-то сказал: Права администратора\?";
			this->Load += gcnew System::EventHandler(this, &Stage3::Stage3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (textBox1->SelectionStart < inputStart &&
			(e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete))
		{
			e->SuppressKeyPress = true;
			return;
		}
		if (e->KeyCode == Keys::Enter)
		{
			e->SuppressKeyPress = true;
			String^ command = textBox1->Text->Substring(inputStart)->Trim();
			ExecuteCommand(command);
			textBox1->AppendText(L"\r\n>");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
		}
	}
	private: bool waitingForExitConfirmation = false;
	private: void ExecuteCommand(String^ cmd)
	{
		cmd = cmd->ToLower();
		if (waitingForExitConfirmation)
		{
			if (cmd == L"y")
			{
				Application::Exit();
			}
			else if (cmd == L"n")
			{
				textBox1->Text =
					L"Терминал\r\n"
					L"> Настройки - Н, Выход - В\r\n"
					L"> ";
				inputStart = textBox1->Text->Length;
				textBox1->SelectionStart = inputStart;
			}
			else
			{
				textBox1->AppendText(L"\r\nНеизвестная команда");
			}
			waitingForExitConfirmation = false;
		}
		else if (cmd == L"н" || cmd == L"настройки")
		{
			if (!passwordObtained)
			{
				textBox1->AppendText(L"\r\nДоступ к настройкам закрыт до получения пароля");
				return;
			}
			Settings^ settingsForm = gcnew Settings();
			settingsForm->Show();
		}
		else if (cmd == L"в" || cmd == L"выход")
		{
			if (!passwordObtained)
			{
				textBox1->AppendText(L"\r\nНельзя выйти в меню до получения пароля");
				return;
			}
			textBox1->AppendText(L"\r\nВы уверены? (y/n)");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			waitingForExitConfirmation = true;
		}
		else
		{
			textBox1->AppendText(L"\r\nНеизвестная команда");
		}
	}
	private: System::Void Stage3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void InitializeDocuments()
	{
		docNames = gcnew array<String^>(16) {
			L"Приказ о приеме на работу",
				L"Расписание занятий",
				L"Аттестационный лист директора",
				L"Отчет преподавателя по курсу",
				L"Личный файл директора",
				L"Методические указания преподавателя",
				L"Положение о директоре",
				L"Рабочая тетрадь преподавателя",
				L"Протокол собрания директора",
				L"Учебный план преподавателя",
				L"Доклад директора",
				L"Контрольная работа преподавателя",
				L"Служебная записка директора",
				L"План-конспект преподавателя",
				L"Обоснование назначения директора",
				L"Отчет по практике преподавателя"
		};
		docOwners = gcnew array<int>(16) { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };
		indices = gcnew array<int>(docNames->Length);
		for (int i = 0; i < indices->Length; i++) indices[i] = i;
	}
	private: void ShuffleIndices()
	{
		int n = indices->Length;
		for (int i = n - 1; i > 0; i--)
		{
			int j = rng->Next(i + 1);
			int t = indices[i];
			indices[i] = indices[j];
			indices[j] = t;
		}
	}
	private: void ShowNextDocument()
	{
		currentIndex++;
		if (currentIndex >= indices->Length)
		{
			ShuffleIndices();
			currentIndex = 0;
		}
		label1->Text = docNames[indices[currentIndex]];
	}
	private: void GeneratePassword()
	{
		int len = rng->Next(6, 11);
		array<wchar_t>^ buf = gcnew array<wchar_t>(len);
		for (int i = 0; i < len; i++)
		{
			int r = rng->Next(0, 26);
			buf[i] = wchar_t('a' + r);
		}
		password = gcnew String(buf);
		textBox1->AppendText(L"\r\n> Пароль получен: " + password);
		passwordObtained = true;
		for each (Control ^ c in this->Controls)
		{
			Button^ b = dynamic_cast<Button^>(c);
			if (b != nullptr)
			{
				b->Enabled = true;
			}
		}
		button1->Enabled = false;
		button2->Enabled = false;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (currentIndex < 0) return;
		int owner = docOwners[indices[currentIndex]];
		if (owner == 0)
		{
			consecutiveCorrect++;
			textBox1->AppendText(L"\r\n> Правильно");
			if (consecutiveCorrect >= 3 && !passwordObtained)
			{
				GeneratePassword();
			}
			ShowNextDocument();
		}
		else
		{
			consecutiveCorrect = 0;
			textBox1->AppendText(L"\r\nНеправильно");
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (currentIndex < 0) return;
		int owner = docOwners[indices[currentIndex]];
		if (owner == 1)
		{
			consecutiveCorrect++;
			textBox1->AppendText(L"\r\nПравильно");
			if (consecutiveCorrect >= 3 && !passwordObtained)
			{
				GeneratePassword();
			}
			ShowNextDocument();
		}
		else
		{
			consecutiveCorrect = 0;
			textBox1->AppendText(L"\r\nНеправильно");
		}
	}
	};
}
