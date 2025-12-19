#pragma once
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "Settings.h" 
#include "Stage2.h"
#include "Stage3.h"
#include "Stage5.h"
#include "Stage6.h"
// Константы для русского алфавита (вне класса, но необходимы для функций)
const std::string RUSSIAN_ALPHABET_UPPER = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const std::string RUSSIAN_ALPHABET_LOWER = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const int RUSSIAN_ALPHABET_SIZE = 33;
namespace Xakeri {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class Stage4 : public System::Windows::Forms::Form
	{
	public:
		Stage4(void)
		{
			InitializeComponent();

			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font("Consolas", 33);
			textBox1->Multiline = true;
			textBox1->ScrollBars = ScrollBars::Vertical;

			textBox1->Text =
				"Терминал\r\n"
				"> Настройки - Н, Выход - В, Меню - М\r\n"
				"> ";
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			textBox1->KeyDown += gcnew KeyEventHandler(this, &Stage4::textBox1_KeyDown);

			// очищаем строку serverKey при запуске, как просили
			ClearServerKeyLineAtStartup();

		}
	protected:
		~Stage4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::Container^ components;
	private:
		int inputStart;
		bool waitingForExitConfirmation = false;
		// Новые поля для задания
		String^ encryptedMessage;
		String^ correctDecryptedMessage; // Заглавные, чтобы избежать ошибок регистра при проверке
		int shiftKey; // Ключ, на который было зашифровано
		bool isTaskActive = false; // Флаг активности задания

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
		   // Пароль для следующего этапа
		   String^ serverKey = "";
#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage4::typeid));
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::Black;
			   this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 58.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox1->ForeColor = System::Drawing::SystemColors::MenuBar;
			   this->textBox1->Location = System::Drawing::Point(-4, 1);
			   this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(709, 838);
			   this->textBox1->TabIndex = 0;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage4::textBox1_TextChanged);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			   this->pictureBox1->Location = System::Drawing::Point(736, 379);
			   this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(638, 424);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 3;
			   this->pictureBox1->TabStop = false;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			   this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox2->Location = System::Drawing::Point(585, 1);
			   this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(88, 31);
			   this->pictureBox2->TabIndex = 9;
			   this->pictureBox2->TabStop = false;
			   // 
			   // pictureBox3
			   // 
			   this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			   this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox3->Location = System::Drawing::Point(704, 1);
			   this->pictureBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->pictureBox3->Name = L"pictureBox3";
			   this->pictureBox3->Size = System::Drawing::Size(728, 838);
			   this->pictureBox3->TabIndex = 12;
			   this->pictureBox3->TabStop = false;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->ForeColor = System::Drawing::SystemColors::Control;
			   this->label1->Location = System::Drawing::Point(780, 91);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(86, 31);
			   this->label1->TabIndex = 13;
			   this->label1->Text = L"label1";
			   // 
			   // Stage4
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1426, 839);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->pictureBox3);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->textBox1);
			   this->DoubleBuffered = true;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"Stage4";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"А мне карбонара больше нравится";
			   this->Load += gcnew System::EventHandler(this, &Stage4::Stage4_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   std::string caesarEncrypt(const std::string& text, int k) {
			   std::string result = "";
			   k = k % RUSSIAN_ALPHABET_SIZE;
			   for (char c : text) {
				   size_t index = std::string::npos;
				   // Поиск в верхнем регистре
				   index = RUSSIAN_ALPHABET_UPPER.find(c);
				   if (index != std::string::npos) {
					   char shifted = RUSSIAN_ALPHABET_UPPER[(index + k) % RUSSIAN_ALPHABET_SIZE];
					   result += shifted;
					   continue;
				   }
				   // Поиск в нижнем регистре
				   index = RUSSIAN_ALPHABET_LOWER.find(c);
				   if (index != std::string::npos) {
					   char shifted = RUSSIAN_ALPHABET_LOWER[(index + k) % RUSSIAN_ALPHABET_SIZE];
					   result += shifted;
					   continue;
				   }
				   // Если это не русская буква, оставляем как есть
				   result += c;
			   }
			   return result;
		   }
		   // Генерация случайного русского текста (5 букв в ВЕРХНЕМ регистре)
		   std::string generateRandomRussianText(int length) {
			   std::string randomText = "";
			   for (int i = 0; i < length; ++i) {
				   int charIndex = rand() % RUSSIAN_ALPHABET_SIZE;
				   randomText += RUSSIAN_ALPHABET_UPPER[charIndex];
			   }
			   return randomText;
		   }
		   // Функция для генерации serverkey
		   String^ generateServerKey() {
			   int random_part = rand() % 10000;
			   return "SERVERKEY_S4_" + System::Convert::ToString(random_part);
		   }

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
	private: void ExecuteCommand(String^ cmd)
	{
		String^ cmdLower = cmd->ToLower();

		
		if (waitingForExitConfirmation)
		{
			if (cmdLower == "y" || cmdLower == "д") { Application::Exit(); }
			else {
				textBox1->AppendText("\r\nОтмена выхода.");
				waitingForExitConfirmation = false;
			}
			return;
		}

	
		if (cmdLower == "н" || cmdLower == "настройки")
		{
			if (Application::OpenForms["Settings"] != nullptr)
				Application::OpenForms["Settings"]->Show();
			return;
		}

		if (cmdLower == "в" || cmdLower == "выход")
		{
			textBox1->AppendText("\r\nВы уверены, что хотите выйти? (y/n)");
			waitingForExitConfirmation = true;
			return;
		}


		if (cmdLower == "м" || cmdLower == "меню")
		{
			if (isTaskActive)
			{
				textBox1->AppendText("\r\n[ОШИБКА] Доступ запрещен. Сначала расшифруйте сообщение.");
			}
			else
			{
				this->Hide();
				Form^ f = Application::OpenForms["MyForm"];
				if (f != nullptr) f->Show();
			}
			return;
		}

		
		if (isTaskActive)
		{
			
			String^ cleanInput = "";
			for (int i = 0; i < cmd->Length; i++) {
				if (Char::IsLetter(cmd[i])) cleanInput += Char::ToUpper(cmd[i]);
			}

			if (cleanInput == correctDecryptedMessage)
			{
				isTaskActive = false;
				serverKey = generateServerKey();
				WriteServerKeyToResultsFile(serverKey);

				this->label1->Text = "[УСПЕХ] Задание выполнено!";
				textBox1->AppendText("\r\n[СИСТЕМА] Расшифровка завершена успешно.");
				textBox1->AppendText("\r\nSERVERKEY: " + serverKey);
				textBox1->AppendText("\r\nТеперь вы можете перейти в Меню (М)");
			}
			else
			{
				textBox1->AppendText("\r\n[ОШИБКА] Неверный код расшифровки. Попробуйте еще раз.");
			}
			return;
		}

		textBox1->AppendText("\r\nНеизвестная команда.");
	}
	private: System::Void Stage4_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureBox3->SendToBack();
		// Устанавливаем seed для rand
		srand(static_cast<unsigned int>(time(NULL)));


		// Генерируем случайный ключ (от 1 до 32)
		shiftKey = (rand() % (RUSSIAN_ALPHABET_SIZE - 1)) + 1;
		// Генерируем случайный исходный текст (5 русских букв в верхнем регистре)
		std::string plainTextStd = generateRandomRussianText(5);
		correctDecryptedMessage = gcnew String(plainTextStd.c_str());
		// Шифруем
		std::string encTextStd = caesarEncrypt(plainTextStd, shiftKey);
		encryptedMessage = gcnew String(encTextStd.c_str());
		isTaskActive = true;
		//Формируем текст задания для label2
		String^ russianAlphabetDisplay = gcnew String(RUSSIAN_ALPHABET_UPPER.c_str());
		String^ taskText =
			"Этап 4. Шифр Цезаря\r\n"
			"ЗАДАНИЕ:\r\nРасшифруйте случайное сообщение.\r\n"
			"Зашифровано: \r\n" + encryptedMessage + "\r\n"
			"Сдвиг (Ключ): \r\n" + shiftKey.ToString() + "\r\n"
			"Введите расшифрованный текст";
		this->label1->Text = taskText;
		// Очищаем терминал
		textBox1->Text = "> ";
		inputStart = textBox1->Text->Length;
		textBox1->SelectionStart = inputStart;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   // --- Добавленные функции для работы с файлом Results.txt (4-я строка: serverKey:)
	private: void ClearServerKeyLineAtStartup()
	{
		try
		{
			String^ dir = Path::Combine(Application::StartupPath, "stages");
			String^ path = Path::Combine(dir, "Results.txt");
			if (!Directory::Exists(dir)) Directory::CreateDirectory(dir);

			array<String^>^ lines;
			if (File::Exists(path))
			{
				lines = File::ReadAllLines(path);
			}
			else
			{
				lines = gcnew array<String^>(4);
				for (int i = 0; i < 4; i++) lines[i] = "";
				File::WriteAllLines(path, lines);
			}

			if (lines->Length < 4)
			{
				array<String^>^ newLines = gcnew array<String^>(4);
				for (int i = 0; i < 4; i++)
				{
					if (i < lines->Length) newLines[i] = lines[i];
					else newLines[i] = "";
				}
				lines = newLines;
			}

			lines[3] = "serverKey:";
			File::WriteAllLines(path, lines);
		}
		catch (Exception^)
		{
		}
	}

	private: void WriteServerKeyToResultsFile(String^ sk)
	{
		try
		{
			String^ dir = Path::Combine(Application::StartupPath, "stages");
			String^ path = Path::Combine(dir, "Results.txt");
			if (!Directory::Exists(dir)) Directory::CreateDirectory(dir);

			array<String^>^ lines;
			if (File::Exists(path))
			{
				lines = File::ReadAllLines(path);
			}
			else
			{
				lines = gcnew array<String^>(4);
				for (int i = 0; i < 4; i++) lines[i] = "";
			}

			if (lines->Length < 4)
			{
				array<String^>^ newLines = gcnew array<String^>(4);
				for (int i = 0; i < 4; i++)
				{
					if (i < lines->Length) newLines[i] = lines[i];
					else newLines[i] = "";
				}
				lines = newLines;
			}

			lines[3] = "serverKey: " + sk;
			File::WriteAllLines(path, lines);
		}
		catch (Exception^)
		{
		}
	}
	};
}
