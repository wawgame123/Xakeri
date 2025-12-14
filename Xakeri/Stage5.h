#pragma once
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "Settings.h" 
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage6.h"

namespace Xakeri {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Stage5 : public System::Windows::Forms::Form
	{
	public:
		Stage5(void)
		{

			InitializeComponent();

			// Настройка TextBox
			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font("Consolas", 22);
			textBox1->Multiline = true;
			textBox1->ScrollBars = ScrollBars::Vertical;

			// Начальный текст терминала
			textBox1->Text =
				"Терминал\r\n"
				"> Настройки - Н, Выход - В\r\n"
				"> ";

			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			textBox1->KeyDown += gcnew KeyEventHandler(this, &Stage5::textBox1_KeyDown);
		}
	protected:
		~Stage5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel1;
	private:
		int inputStart;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage5::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
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
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage5::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkGreen;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(3, 523);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(532, 63);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Защита от фишинга";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &Stage5::label2_Click);
			this->label2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label2_MouseDown);
			this->label2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label2_MouseMove);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DarkGreen;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(136, 885);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(600, 63);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Привязка к устройству";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label3_MouseDown);
			this->label3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label3_MouseMove);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DarkGreen;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label4.Image")));
			this->label4->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label4->Location = System::Drawing::Point(3, 709);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(584, 63);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Минимизация ущерба";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label4_MouseDown);
			this->label4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label4_MouseMove);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DarkGreen;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label5.Image")));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label5->Location = System::Drawing::Point(226, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(439, 126);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Зависимость от \r\nустройства";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label5->Click += gcnew System::EventHandler(this, &Stage5::label5_Click);
			this->label5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label5_MouseDown);
			this->label5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label5_MouseMove);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::DarkGreen;
			this->label6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label6.Image")));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->label6->Location = System::Drawing::Point(112, 319);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(444, 126);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Неудобство при \r\nчастых входах";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label6_MouseDown);
			this->label6->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label6_MouseMove);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::DarkGreen;
			this->label7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label7.Image")));
			this->label7->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label7->Location = System::Drawing::Point(136, 40);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(456, 63);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Риск блокировки";
			this->label7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label7_MouseDown);
			this->label7->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stage5::label7_MouseMove);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Location = System::Drawing::Point(937, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(962, 1038);
			this->panel1->TabIndex = 8;
			// 
			// Stage5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Stage5";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stage5";
			this->Load += gcnew System::EventHandler(this, &Stage5::Stage5_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Point startPoint;
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
		   
		   int rany(int min, int max) {
			   // Инициализация генератора случайных чисел один раз
			   
			   // Генерация случайного числа в пределах [min, max]
			
			   // rand() % (max - min + 1) даёт диапазон от 0 до (max-min)
			   int y = min + rand() % (max - min + 1);
			 
			   return y;
		   }
		   int ranx(int min, int max) {
			   // Инициализация генератора случайных чисел один раз
			   
			   // Генерация случайного числа в пределах [min, max]
			
			   // rand() % (max - min + 1) даёт диапазон от 0 до (max-min)
			   int x = min + rand() % (max - min + 1);
			
			   return x;
		   }
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
	private: System::Void Stage5_Load(System::Object^ sender, System::EventArgs^ e) {
		srand(time(0));
		label2->Location = System::Drawing::Point(ranx(10,600), rany(0, 850));
		label3->Location = System::Drawing::Point(ranx(10, 600), rany(0, 805));
		label4->Location = System::Drawing::Point(ranx(10, 600), rany(0, 805));
		label5->Location = System::Drawing::Point(ranx(10, 600), rany(0, 805));
		label6->Location = System::Drawing::Point(ranx(10, 600), rany(0, 805));
		label7->Location = System::Drawing::Point(ranx(10, 600), rany(0, 805));

	}




	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void label2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	// Запоминаем точку, где нажали мышь
	startPoint = e->Location;
}
private: System::Void label2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		label2->Left += e->X - startPoint.X;
		label2->Top += e->Y - startPoint.Y;
	}
}
	
private: System::Void label3_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	startPoint = e->Location;
}
private: System::Void label3_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		label3->Left += e->X - startPoint.X;
		label3->Top += e->Y - startPoint.Y;
	}
}
private: System::Void label4_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	startPoint = e->Location;
}
private: System::Void label4_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		label4->Left += e->X - startPoint.X;
		label4->Top += e->Y - startPoint.Y;
	}
}
private: System::Void label6_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	startPoint = e->Location;
}
private: System::Void label6_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		label6->Left += e->X - startPoint.X;
		label6->Top += e->Y - startPoint.Y;
	}
}
private: System::Void label5_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	startPoint = e->Location;
}
private: System::Void label5_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		label5->Left += e->X - startPoint.X;
		label5->Top += e->Y - startPoint.Y;
	}
}
private: System::Void label7_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	startPoint = e->Location;
}
private: System::Void label7_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		label7->Left += e->X - startPoint.X;
		label7->Top += e->Y - startPoint.Y;
	}
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
