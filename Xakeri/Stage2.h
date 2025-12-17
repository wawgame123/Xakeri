#pragma once

#include "Settings.h" 

#include "Stage1.h"
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
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Collections::Generic;

	public ref class Stage2 : public System::Windows::Forms::Form
	{
	public:
		Stage2(void)
		{

			InitializeComponent();


			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font("Consolas", 33);
			textBox1->Multiline = true;
			textBox1->ScrollBars = ScrollBars::Vertical;


			textBox1->Text =
				"Терминал\r\n"
				"> Настройки - Н, Выход - В, Проверка - П\r\n"
				"> ";

			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			textBox1->KeyDown += gcnew KeyEventHandler(this, &Stage2::textBox1_KeyDown);


			rnd = gcnew Random();
			currentFileNumber = -1;
			currentEmail = String::Empty;

			loginGiven = false;
		}
	protected:
		~Stage2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox2;


	private:
		int inputStart;
		int currentFileNumber;
		Random^ rnd;
	private: System::Windows::Forms::Label^ label1;
		   String^ currentEmail;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		 
		   bool loginGiven;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage2::typeid));
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::Black;
			   this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 58.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox1->Location = System::Drawing::Point(-11, -4);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(945, 1031);
			   this->textBox1->TabIndex = 0;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage2::textBox1_TextChanged);
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->checkBox1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->checkBox1->Location = System::Drawing::Point(17, 26);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(390, 42);
			   this->checkBox1->TabIndex = 3;
			   this->checkBox1->Text = L"Подозрительная почта";
			   this->checkBox1->UseVisualStyleBackColor = true;
			   this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Stage2::checkBox1_CheckedChanged);
			   // 
			   // checkBox2
			   // 
			   this->checkBox2->AutoSize = true;
			   this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->checkBox2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->checkBox2->Location = System::Drawing::Point(17, 74);
			   this->checkBox2->Name = L"checkBox2";
			   this->checkBox2->Size = System::Drawing::Size(488, 42);
			   this->checkBox2->TabIndex = 4;
			   this->checkBox2->Text = L"Подозрительное содержание";
			   this->checkBox2->UseVisualStyleBackColor = true;
			   this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Stage2::checkBox2_CheckedChanged);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			   this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panel1->Controls->Add(this->checkBox1);
			   this->panel1->Controls->Add(this->checkBox2);
			   this->panel1->Location = System::Drawing::Point(1115, 395);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(533, 150);
			   this->panel1->TabIndex = 5;
			   // 
			   // textBox2
			   // 
			   this->textBox2->BackColor = System::Drawing::Color::RoyalBlue;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox2->ForeColor = System::Drawing::Color::White;
			   this->textBox2->Location = System::Drawing::Point(1099, 62);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->ReadOnly = true;
			   this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->textBox2->Size = System::Drawing::Size(576, 327);
			   this->textBox2->TabIndex = 6;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			   this->label1->Location = System::Drawing::Point(1125, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(467, 38);
			   this->label1->TabIndex = 7;
			   this->label1->Text = L"Выберите признаки фишинга";
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			   this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox2->Location = System::Drawing::Point(788, 5);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(118, 38);
			   this->pictureBox2->TabIndex = 9;
			   this->pictureBox2->TabStop = false;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox1->Location = System::Drawing::Point(930, -4);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(970, 1031);
			   this->pictureBox1->TabIndex = 10;
			   this->pictureBox1->TabStop = false;
			   // 
			   // Stage2
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->ClientSize = System::Drawing::Size(1902, 1033);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->textBox1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"Stage2";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Рыбак рыбака...";
			   this->Load += gcnew System::EventHandler(this, &Stage2::Stage2_Load);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: void LoadRandomFile()
	{
		int newNum = currentFileNumber;
		while (newNum == currentFileNumber)
		{
			newNum = rnd->Next(1, 6);
		}
		LoadFile(newNum);
	}

	private: void LoadFile(int fileNumber)
	{
		currentFileNumber = fileNumber;
		
		String^ path = Application::StartupPath + "\\fish\\" + fileNumber.ToString() + ".txt";



		checkBox1->Checked = false;
		checkBox2->Checked = false;
		checkBox1->Enabled = true;
		checkBox2->Enabled = true;
		try
		{
			if (!File::Exists(path))
			{
				textBox2->Text = "Файл не найден: " + path;
				currentEmail = String::Empty;
				return;
			}

			array<String^>^ lines = File::ReadAllLines(path, Encoding::UTF8);

			if (lines->Length >= 1 && lines[0]->StartsWith("Почта:"))
			{
				currentEmail = lines[0]->Substring(7)->Trim();
			}
			else if (lines->Length >= 1)
			{
				currentEmail = lines[0]->Trim();
			}
			else
			{
				currentEmail = String::Empty;
			}
			StringBuilder^ sb = gcnew StringBuilder();
			if (!String::IsNullOrEmpty(currentEmail))
			{
				sb->AppendLine(currentEmail);
			}

			sb->AppendLine("----------------");
			for (int i = 1; i < lines->Length; i++)
			{
				String^ line = lines[i];
				if (line->StartsWith("Текст:"))
				{
					line = line->Substring(6)->Trim();
				}
				sb->AppendLine(line);
			}

			textBox2->Text = sb->ToString()->Trim();
		}
		catch (Exception^ ex)
		{
			textBox2->Text = "Ошибка чтения файла: " + ex->Message;
			currentEmail = String::Empty;
		}
	}

	private: void ShowMainMenu()
	{
		textBox1->Text =
			"Меню\r\n"
			"> Настройки - Н, Выход - В, Проверка - П\r\n"
			"> ";
		inputStart = textBox1->Text->Length;
		textBox1->SelectionStart = inputStart;
	}

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

			textBox1->AppendText("\r\n>");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
		}
	}
	private: bool waitingForExitConfirmation = false;

	private: void ExecuteCommand(String^ cmd)
	{
		cmd = cmd->ToLower();

		// 1. Команда: Настройки
		if (cmd == "н" || cmd == "n")
		{
			Form^ setForm = Application::OpenForms["Settings"];
			if (setForm != nullptr)
			{
				setForm->Show();
				setForm->BringToFront();
			}
			else
			{
				Xakeri::Settings^ newSettings = gcnew Xakeri::Settings();
				newSettings->Show();
			}
			return;
		}

	
		if (cmd == "в" || cmd == "d")
		{
			Application::Exit();
			return;
		}

	
		if (cmd == "м" || cmd == "m")
		{
			if (!loginGiven)
			{
				textBox1->AppendText("\r\n[СИСТЕМА]: ОШИБКА. Сначала получите данные (П)");
				return;
			}

			if (Application::OpenForms["MyForm"] != nullptr)
			{
				Application::OpenForms["MyForm"]->Show();
			}
			this->Hide();
			return;
		}

		
		if (cmd == "п" || cmd == "g")
		{
			if (loginGiven)
			{
				textBox1->AppendText("\r\n[СИСТЕМА]: Данные уже получены. Используйте 'М'");
				return;
			}

	
			bool correct = false;
			switch (currentFileNumber)
			{
			case 1: correct = (checkBox1->Checked && checkBox2->Checked); break;
			case 2: case 3: correct = (checkBox1->Checked && !checkBox2->Checked); break;
			case 4: case 5: correct = (!checkBox1->Checked && checkBox2->Checked); break;
			}

			if (correct)
			{
			
				int len = rnd->Next(5, 8);
				StringBuilder^ sb = gcnew StringBuilder();
				for (int i = 0; i < len; i++) sb->Append((wchar_t)('a' + rnd->Next(0, 26)));
				String^ login = sb->ToString();

				textBox1->AppendText("\r\n[УСПЕХ]: Данные расшифрованы.\r\nLOGIN: " + login);
				loginGiven = true;

				try
				{
					String^ stagesDir = Path::Combine(Application::StartupPath, "stages");
					if (!Directory::Exists(stagesDir)) Directory::CreateDirectory(stagesDir);

					String^ filePath = Path::Combine(stagesDir, "Results.txt");

				
					List<String^>^ lines = gcnew List<String^>();
					if (File::Exists(filePath))
					{
						lines->AddRange(File::ReadAllLines(filePath, Encoding::UTF8));
					}

				
					while (lines->Count < 2)
					{
						if (lines->Count == 0) lines->Add("Ip: ");
						else lines->Add("Login: ");
					}

				
					lines[1] = "Login: " + login;

				
					File::WriteAllLines(filePath, lines->ToArray(), Encoding::UTF8);
				}
				catch (Exception^ ex)
				{
					textBox1->AppendText("\r\n[ОШИБКА ФАЙЛА]: " + ex->Message);
				}
			

				textBox1->AppendText("\r\nВведите 'М' для перехода в систему");
			}
			else
			{
				textBox1->AppendText("\r\n[ОШИБКА]: Признаки неверны. Генерация нового файла...");
				LoadRandomFile();
			}
			return;
		}

		
		textBox1->AppendText("\r\n[СИСТЕМА]: Команда '" + cmd + "' не распознана.");
	}
	private: System::Void Stage2_Load(System::Object^ sender, System::EventArgs^ e)
	{
		pictureBox1->SendToBack();
		try
		{
			String^ stagesDir = Path::Combine(Application::StartupPath, "stages");
			Directory::CreateDirectory(stagesDir);

			String^ filePath = Path::Combine(stagesDir, "Results.txt");

			List<String^>^ lines = gcnew List<String^>();

			if (File::Exists(filePath))
			{
				lines->AddRange(File::ReadAllLines(filePath, Encoding::UTF8));
			}

			if (lines->Count == 0)
			{
				lines->Add("Ip: ");
				lines->Add("Login: ");
			}
			else if (lines->Count == 1)
			{
				if (lines[0]->StartsWith("Ip:"))
				{
					lines->Add("Login: ");
				}
				else
				{
					lines->Insert(0, "Ip: ");
					lines->Insert(1, "Login: ");
				}
			}
			else
			{

				lines[1] = "Login: ";
			}

			File::WriteAllLines(filePath, lines->ToArray(), Encoding::UTF8);
		}
		catch (...)
		{

		}

		currentFileNumber = -1;
		int startNum = rnd->Next(1, 6);
		LoadFile(startNum);
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
