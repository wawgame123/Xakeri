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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   // Пароль для следующего этапа
		   String^ serverKey = "";
#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage4::typeid));
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage4::textBox1_TextChanged);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label2->Location = System::Drawing::Point(959, 19);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(126, 46);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"label2";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			   this->pictureBox1->Location = System::Drawing::Point(967, 337);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(913, 560);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 3;
			   this->pictureBox1->TabStop = false;
			   // 
			   // Stage4
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->ClientSize = System::Drawing::Size(1902, 1033);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->textBox1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Name = L"Stage4";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Stage4";
			   this->Load += gcnew System::EventHandler(this, &Stage4::Stage4_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
			   return "SERVERKEY_S4_" + random_part.ToString();
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

		//  ждем ответ на вопрос "Вы уверены?"
		if (waitingForExitConfirmation)
		{
			if (cmdLower == "y")
			{
				Application::Exit();
			}
			else if (cmdLower == "n")
			{
				textBox1->Text = "\r\n>";
				inputStart = textBox1->Text->Length;
				textBox1->SelectionStart = inputStart;
			}
			else
			{
				textBox1->AppendText("\r\nВведите 'y' (да) или 'n' (нет)");
			}
			// После любого ответа выключаем режим ожидания
			waitingForExitConfirmation = false;
			return; // выходим из функции, чтобы не проверять остальные команды
		}

		//  Если мы не ждем подтверждения, проверяем остальные команды
		if (isTaskActive)
		{
			// Логика проверки задания
			String^ cleanInput = "";
			for (int i = 0; i < cmd->Length; i++) {
				if (Char::IsLetter(cmd[i])) {
					cleanInput += Char::ToUpper(cmd[i]);
				}
			}

			String^ cleanCorrect = correctDecryptedMessage;
			if (cleanInput == cleanCorrect)
			{
				isTaskActive = false;
				serverKey = generateServerKey();
				this->label2->Text = "[УСПЕХ] Задание выполнено! Ключ получен.";
				textBox1->AppendText("\r\n[Успех!] Сообщение расшифровано верно!");
				textBox1->AppendText("\r\nВаш серверный ключ (SERVERKEY): " + serverKey);
				textBox1->AppendText("\r\nКлюч получен. Нажмите 'В' для выхода, 'Н' для настроек или 'М' для меню");
			}
			else
			{
				textBox1->AppendText("\r\n[Ошибка] Неверное расшифрованное сообщение. Попробуйте снова.");
			}
		}
		else if (cmdLower == "н" || cmdLower == "настройки")
		{
			Settings^ settingsForm = gcnew Settings();
			settingsForm->Show();
		}
		else if (cmdLower == "м" || cmdLower == "меню")
		{
			this->Hide();
			Application::OpenForms["MyForm"]->Show();
		}
		else if (cmdLower == "в" || cmdLower == "выход")
		{
			// задаем вопрос и включаем режим ожидания
			textBox1->AppendText("\r\nВы уверены? (y/n)");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			waitingForExitConfirmation = true;
		}
		else if (!isTaskActive && serverKey != "" && cmdLower == "")
		{
			textBox1->AppendText("\r\nКлюч уже получен. Вы можете выйти, нажав 'В'.");
		}
		else
		{
			textBox1->AppendText("\r\nНеизвестная команда");
		}
	}
	private: System::Void Stage4_Load(System::Object^ sender, System::EventArgs^ e) {
		// Устанавливаем seed для rand
		srand(static_cast<unsigned int>(time(NULL)));
		pictureBox1->Image = System::Drawing::Image::FromFile("..\\images\\alp.png");
		
		// Генерируем случайный ключ (от 1 до 32)
		shiftKey = (rand() % (RUSSIAN_ALPHABET_SIZE - 1)) + 1;
		// Генерируем случайный исходный текст (5 русских букв в верхнем регистре)
		std::string plainTextStd = generateRandomRussianText(5);
		correctDecryptedMessage = gcnew String(plainTextStd.c_str());
		// Шифруем
		std::string encTextStd = caesarEncrypt(plainTextStd, shiftKey);
		encryptedMessage = gcnew String(encTextStd.c_str());
		isTaskActive = true;
		// 4. Формируем текст задания для label2
		String^ russianAlphabetDisplay = gcnew String(RUSSIAN_ALPHABET_UPPER.c_str());
		String^ taskText =
			"Этап 4. Шифр Цезаря\r\n"
			"ЗАДАНИЕ:\r\nРасшифруйте случайное сообщение.\r\n"
			"Зашифровано: \r\n" + encryptedMessage + "\r\n"
			"Сдвиг (Ключ): \r\n" + shiftKey.ToString() + "\r\n"
			"Введите расшифрованный текст";
		this->label2->Text = taskText;
		// Очищаем терминал
		textBox1->Text = "> ";
		inputStart = textBox1->Text->Length;
		textBox1->SelectionStart = inputStart;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}