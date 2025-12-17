#pragma once

#include "Settings.h" 

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
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text; 

	public ref class Stage1 : public System::Windows::Forms::Form
	{
	public:
		Stage1(void)
		{
			InitializeComponent();
			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font("Consolas", 22);
			textBox1->Multiline = true;
			textBox1->ScrollBars = ScrollBars::Vertical;
			textBox1->Text =
				"Терминал\r\n"
				"> Настройки - Н, Выход - В\r\n"
				"> ";

			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
			textBox1->KeyDown += gcnew KeyEventHandler(this, &Stage1::textBox1_KeyDown);

			rnd = gcnew Random();
			buttons = gcnew array<Button^>(4) { this->button1, this->button2, this->button3, this->button4 };
			buttonType = gcnew array<int>(4);
			passwords = gcnew array<String^>(4);
			for (int i = 0; i < buttons->Length; i++)
			{
				buttons[i]->Click += gcnew EventHandler(this, &Stage1::passwordButton_Click);
			}


			state = 0;
			mediumSelectedCount = 0;
			complexPassword = nullptr;
			ip = nullptr;
		}
	protected:
		~Stage1()
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
	private: System::Windows::Forms::Label^ label1;

	private:
		int inputStart;


		array<Button^>^ buttons;
		array<int>^ buttonType;
		array<String^>^ passwords;
		Random^ rnd;
		String^ complexPassword;
		String^ ip;
		int mediumSelectedCount;
		int state;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   const int MAX_TERMINAL_LINES = 200;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage1::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->textBox1->Location = System::Drawing::Point(-8, 2);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(667, 979);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Stage1::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 31.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(850, 154);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(386, 89);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 31.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(850, 254);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(386, 89);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 31.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(850, 357);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(386, 89);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 31.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(850, 460);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(386, 89);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Transparent;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(764, 21);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 44);
			this->label1->TabIndex = 6;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(551, 2);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(88, 31);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(656, 2);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(757, 838);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// Stage1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1407, 841);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Stage1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"Вы самый слабый пароль, прощайте!";
			this->Load += gcnew System::EventHandler(this, &Stage1::Stage1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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

			textBox1->AppendText("\r\n>");
			inputStart = textBox1->Text->Length;
			textBox1->SelectionStart = inputStart;
		}
	}
	private: bool waitingForExitConfirmation = false;
	private: void AppendTerminal(String^ line)
	{
		textBox1->AppendText("\r\n" + line);
		TrimTerminalLines(MAX_TERMINAL_LINES);
		inputStart = textBox1->Text->Length;
		textBox1->SelectionStart = inputStart;
	}
	private: void TrimTerminalLines(int maxLines)
	{
		array<String^>^ lines = textBox1->Lines;
		if (lines == nullptr) return;
		if (lines->Length <= maxLines) return;

		int start = lines->Length - maxLines;
		array<String^>^ keep = gcnew array<String^>(maxLines);
		for (int i = 0; i < maxLines; i++)
		{
			keep[i] = lines[start + i];
		}
		textBox1->Lines = keep;
	}

	private: void ExecuteCommand(String^ cmd)
	{
		cmd = cmd->Trim()->ToLower();


		if (cmd == "м" || cmd == "m" || cmd == "меню")
		{

			if (String::IsNullOrEmpty(ip))
			{
				AppendTerminal("Нельзя открыть меню до получения IP.");
				return;
			}

			auto form = Application::OpenForms["MyForm"];
			if (form != nullptr)
			{
				this->Hide();
				form->Show();
			}
			return;
		}


		if (cmd == "п" || cmd == "проверка")
		{

			return;
		}


		if (waitingForExitConfirmation)
		{
			if (cmd == "y")
			{
				Application::Exit();
			}
			else if (cmd == "n")
			{
				textBox1->Text =
					"Терминал\r\n"
					"> Настройки - Н, Выход - В\r\n"
					"> ";
				inputStart = textBox1->Text->Length;
				textBox1->SelectionStart = inputStart;
			}
			else
			{
				AppendTerminal("Введите y или n");
			}

			waitingForExitConfirmation = false;
			return;
		}


		if (cmd == "н" || cmd == "настройки")
		{
			Settings^ settingsForm = gcnew Settings();
			settingsForm->Show();
		}

		else if (cmd == "в" || cmd == "выход")
		{
			AppendTerminal("Вы уверены? (y/n)");
			waitingForExitConfirmation = true;
		}

		else
		{
			AppendTerminal("Неизвестная команда");
		}
	}
	private: String^ GenLettersOnly(int minLen, int maxLen)
	{
		String^ letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int len = rnd->Next(minLen, maxLen + 1);
		array<wchar_t>^ buf = gcnew array<wchar_t>(len);
		for (int i = 0; i < len; i++)
		{
			int idx = rnd->Next(letters->Length);
			buf[i] = letters[idx];
		}
		return gcnew String(buf);
	}

	private: String^ GenLettersDigits(int minLen, int maxLen)
	{
		String^ letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String^ digits = "0123456789";
		String^ pool = letters + digits;
		int len = rnd->Next(minLen, maxLen + 1);
		array<wchar_t>^ buf = gcnew array<wchar_t>(len);

	
		int digitPos = rnd->Next(len);

		for (int i = 0; i < len; i++)
		{
			if (i == digitPos)
			{
				int dIdx = rnd->Next(digits->Length);
				buf[i] = digits[dIdx];
			}
			else
			{
				int idx = rnd->Next(pool->Length);
				buf[i] = pool[idx];
			}
		}
		return gcnew String(buf);
	}


	private: String^ GenComplex(int minLen, int maxLen)
	{
		String^ letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String^ digits = "0123456789";
		String^ specials = "!@#$%^&*()-_=+[]{};:,.<>?/";
		String^ pool = letters + digits + specials;
		int len = rnd->Next(minLen, maxLen + 1);
		array<wchar_t>^ buf = gcnew array<wchar_t>(len);
		for (int i = 0; i < len; i++)
		{
			int idx = rnd->Next(pool->Length);
			buf[i] = pool[idx];
		}
		return gcnew String(buf);
	}

	private: void ShuffleList(List<KeyValuePair<String^, int>>^ list)
	{
		for (int i = list->Count - 1; i > 0; i--)
		{
			int j = rnd->Next(i + 1);
			auto tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
		}
	}
	private: System::Void passwordButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ b = safe_cast<Button^>(sender);
		int idx = -1;
		for (int i = 0; i < buttons->Length; i++)
		{
			if (buttons[i] == b) { idx = i; break; }
		}
		if (idx == -1) return;
		if (state == 0)
		{
			if (buttonType[idx] == 0)
			{
				b->Enabled = false;
				label1->Text = "Выберите 2 средних пароля";
				state = 1;
				AppendTerminal("Правильно — лёгкий пароль найден.");
			}
			else
			{
				AppendTerminal("Неверный выбор — это не самый лёгкий пароль.");
			}
		}
		else if (state == 1)
		{
			if (buttonType[idx] == 1)
			{
				if (!b->Enabled)
				{
					AppendTerminal("Эта кнопка уже выбрана.");
					return;
				}
				b->Enabled = false;
				mediumSelectedCount++;
				AppendTerminal("Выбран средний пароль (" + mediumSelectedCount.ToString() + "/2).");

				if (mediumSelectedCount >= 2)
				{
					AppendTerminal("Сложный пароль: " + complexPassword);
					System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
					for each (wchar_t c in complexPassword)
					{
						if (Char::IsDigit(c)) sb->Append(c);
					}
					ip = sb->ToString();
					if (String::IsNullOrEmpty(ip))
					{
						int len = rnd->Next(4, 7);
						System::Text::StringBuilder^ sb2 = gcnew System::Text::StringBuilder();
						for (int i = 0; i < len; i++)
						{
							int d = rnd->Next(10);
							sb2->Append(d.ToString());
						}
						ip = sb2->ToString();

					}
					AppendTerminal("> часть ip хакера: " + ip);
					AppendTerminal(">> Настройки - Н, Выход - В, М-Меню\r\n");


					label1->Text = "> Готово";
					state = 2;
					for (int i = 0; i < buttons->Length; i++)
					{
						buttons[i]->Enabled = false;
					}

			
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

						String^ ipLine = "Ip: " + ip;

						if (lines->Count > 0 && lines[0]->StartsWith("Ip:"))
						{
						
							lines[0] = ipLine;
						}
						else
						{
						
							lines->Insert(0, ipLine);
						}


						File::WriteAllLines(filePath, lines->ToArray(), Encoding::UTF8);

						AppendTerminal("> IP успешно записан");
						AppendTerminal("> Путь: " + filePath);
						AppendTerminal(">");
					}
					catch (Exception^ ex)
					{
						AppendTerminal("> Ошибка записи IP: " + ex->Message);
					}
				}
			}
			else
			{
				AppendTerminal("Это не средний пароль — попробуйте ещё раз.");
			}
		}
		else
		{
			AppendTerminal("Вы уже завершили выбор.");
		}
	}
private: System::Void Stage1_Load(System::Object^ sender, System::EventArgs^ e)
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
		}
		else if (lines[0]->StartsWith("Ip:"))
		{
		
			lines[0] = "Ip: ";
		}
		else
		{
			lines->Insert(0, "Ip: ");
		}

		File::WriteAllLines(filePath, lines->ToArray(), Encoding::UTF8);
	}
	catch (...) {}
	String^ easy = GenLettersOnly(6, 10);
	String^ medium1 = GenLettersDigits(6, 10);
	String^ medium2 = GenLettersDigits(6, 10);
	complexPassword = GenComplex(10, 15);

	List<KeyValuePair<String^, int>>^ items = gcnew List<KeyValuePair<String^, int>>();
	items->Add(KeyValuePair<String^, int>(easy, 0));
	items->Add(KeyValuePair<String^, int>(medium1, 1));
	items->Add(KeyValuePair<String^, int>(medium2, 1));
	items->Add(KeyValuePair<String^, int>(complexPassword, 2));

	ShuffleList(items);

	for (int i = 0; i < items->Count && i < buttons->Length; i++)
	{
		passwords[i] = items[i].Key;
		buttonType[i] = items[i].Value;
		buttons[i]->Text = passwords[i];
		buttons[i]->Enabled = true;
	}

	label1->Text = "Выберите самый легкий пароль";
}


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
