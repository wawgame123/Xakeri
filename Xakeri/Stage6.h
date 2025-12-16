#pragma once

#include "Settings.h" 
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"

namespace Xakeri {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Stage6 : public System::Windows::Forms::Form
	{
	public:
		Stage6(void)
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
			textBox1->KeyDown += gcnew KeyEventHandler(this, &Stage6::textBox1_KeyDown);
		}
	protected:
		~Stage6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private:
		int inputStart;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage6::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage6::textBox1_TextChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(779, 1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(118, 38);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// Stage6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Stage6";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stage6";
			this->Load += gcnew System::EventHandler(this, &Stage6::Stage6_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
	private: System::Void Stage6_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
