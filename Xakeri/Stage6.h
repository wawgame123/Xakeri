#pragma once
#include "Settings.h" 
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
using namespace System::IO;
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
				"С - сверить данные из книжки\r\n"
				"1-5 - просмотр результатов с прошлых уровней\r\n"
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
	private: System::ComponentModel::IContainer^ components;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private:
		int inputStart;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage6::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 58.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(-4, 1);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(709, 838);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage6::textBox1_TextChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(584, 1);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(88, 31);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->axWindowsMediaPlayer1);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(701, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(725, 838);
			this->panel1->TabIndex = 10;
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(850, 815);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(75, 23);
			this->axWindowsMediaPlayer1->TabIndex = 1;
			this->axWindowsMediaPlayer1->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox1->Location = System::Drawing::Point(175, 135);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(363, 423);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Записная книжка";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Location = System::Drawing::Point(21, 350);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 27);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Имя";
			this->label5->Click += gcnew System::EventHandler(this, &Stage6::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Location = System::Drawing::Point(21, 280);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 27);
			this->label4->TabIndex = 8;
			this->label4->Text = L"ServerKey";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Location = System::Drawing::Point(21, 202);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 27);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Пароль";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Location = System::Drawing::Point(21, 129);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 27);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Логин";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(21, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 27);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ip";
			this->label1->Click += gcnew System::EventHandler(this, &Stage6::label1_Click);
			// 
			// textBox6
			// 
			this->textBox6->ForeColor = System::Drawing::SystemColors::InfoText;
			this->textBox6->Location = System::Drawing::Point(183, 347);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(152, 31);
			this->textBox6->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->ForeColor = System::Drawing::SystemColors::InfoText;
			this->textBox5->Location = System::Drawing::Point(183, 274);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(152, 31);
			this->textBox5->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->ForeColor = System::Drawing::SystemColors::InfoText;
			this->textBox4->Location = System::Drawing::Point(183, 202);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(152, 31);
			this->textBox4->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->ForeColor = System::Drawing::SystemColors::InfoText;
			this->textBox3->Location = System::Drawing::Point(183, 129);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(152, 31);
			this->textBox3->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->textBox2->Location = System::Drawing::Point(183, 61);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(152, 31);
			this->textBox2->TabIndex = 0;
			// 
			// Stage6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1426, 839);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Stage6";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Финал";
			this->Load += gcnew System::EventHandler(this, &Stage6::Stage6_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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
		   String^ dir = Path::Combine(Application::StartupPath, "stages");
		   String^ path = Path::Combine(dir, "Results.txt");
		   String^ fileIp = "";
		   String^ fileLogin = "";
		   String^ filePassword = "";
		   String^ fileServerKey = "";
		   String^ NameHak = "Бобс";
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
		else if (cmd == "с" || cmd == "сверить") {
			String^ Ip = textBox2->Text;
			String^ Login = textBox3->Text;
			String^ Password = textBox4->Text;
			String^ ServerKey = textBox5->Text;
			String^ Bobs = textBox6->Text;
			if (Ip == fileIp && Login == fileLogin && Password == filePassword && ServerKey == fileServerKey && Bobs == NameHak) {
				textBox1->Text = 
					"Терминал\r\n" +
					"> Настройки - Н, Выход - В\r\n" +
					"> Запрос: журнал доступа — последние 24 часа\r\n" +
					"> Ответ:\r\n" +
					"> [12:03:17] USER: admin\r\n" +
					"> [12:03:18] IP: 192.168.0.14\r\n" +
					"> [12:03:18] Команда: decrypt /log/backup.enc\r\n" +
					"> [12:03:19] Статус: Успешно\r\n" +
					"\r\n" +
					"> Запрос: сравнение хэшей /log/backup.enc и /log/main.log\r\n" +
					"> Ответ:\r\n" +
					"> [12:04:02] Несовпадение: 7 строк изменены вручную\r\n" +
					"\r\n" +
					"> Запрос: кто редактировал /log/main.log\r\n" +
					"> Ответ:\r\n" +
					"> [12:04:17] USER: guest\r\n" +
					"> [12:04:17] IP: 10.0.0.7\r\n" +
					"> [12:04:18] Команда: nano /log/main.log\r\n" +
					"> [12:04:19] Статус: Сохранено\r\n" +
					"\r\n" +
					"> Запрос: кто такой guest\r\n" +
					"> Ответ:\r\n" +
					"> [12:05:01] USER: guest\r\n" +
					"> [12:05:01] MAC: 00:1A:7D:DA:71:13\r\n" +
					"> [12:05:02] Устройство: Raspberry Pi 3B\r\n" +
					"> [12:05:02] Последняя активность: 12:03:19\r\n" +
					"\r\n" +
					"> Запрос: трассировка MAC\r\n" +
					"> Ответ:\r\n" +
					"> [12:05:30] Местоположение: офис 3, серверная\r\n" +
					"\r\n" +
					"> Вывод:\r\n" +
					"> [12:06:00] Хакер найден. Устройство изолировано. Отличная работа!\r\n" +
					"\r\n" +
					"> Выход - В\r\n";
			}
		}
		else if (cmd == "н" || cmd == "настройки")
		{
			Application::OpenForms["Settings"]->Show();
		}
		else if (cmd == "в" || cmd == "выход")
		{
			// Запрос подтверждения выхода
			textBox1->AppendText("\r\nВы уверены? (y/n)");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			waitingForExitConfirmation = true;
		}
		else if (cmd == "1"){
			textBox1->AppendText("\r\nIp хакера:" + fileIp);
			
		}
		else if (cmd == "2") {
			textBox1->AppendText("\r\nЛогин хакера:" + fileLogin);
			
		}
		else if (cmd == "3") {
			textBox1->AppendText("\r\nПароль хакера:" + filePassword);
		
		}
		else if (cmd == "4") {
			textBox1->AppendText("\r\nServerKey хакера:" + fileServerKey);
			
		}
		else if (cmd == "5") {
			textBox1->AppendText("\r\nИмя хакера:" + NameHak);
			
		}
		else
		{
			textBox1->AppendText("\r\nНеизвестная команда");
		}
	}
	private: System::Void Stage6_Load(System::Object^ sender, System::EventArgs^ e) {
		
	
		if (File::Exists(path)) {
			// Читаем все строки из файла
			array<String^>^ lines = File::ReadAllLines(path);

			for each(String ^ line in lines) {
				// Пропускаем пустые строки
				if (String::IsNullOrWhiteSpace(line)) continue;

				// Разделяем строку по первому двоеточию
				array<String^>^ parts = line->Split(gcnew array<Char>{':'}, 2);

				if (parts->Length == 2) {
					String^ key = parts[0]->Trim()->ToLower(); // Ключ 
					String^ value = parts[1]->Trim();          // Значение 

					// Записываем в нужную переменную
					if (key == "ip") fileIp = value;
					else if (key == "login") fileLogin = value;
					else if (key == "password") filePassword = value;
					else if (key == "serverkey") fileServerKey = value;
				}
			}

			// Пример вывода для проверки:
			// MessageBox::Show("Загружен ключ: " + fileServerKey);
		}
		else {
			MessageBox::Show("Ошибка: Файл Results.txt не найден по пути " + path);
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
