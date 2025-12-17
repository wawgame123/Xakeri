#pragma once
#include "MyForm.h"
#include "Settings.h"

namespace Xakeri {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class loading : public System::Windows::Forms::Form
	{
	private:
		String^ phrase1 = "> Загрузка.....";
		String^ phrase2 = "> Терминал\r\n> Нажмите любую кнопку чтобы продолжить";
		int charIndex = 0;
		int state = 0;

	public:
		loading(void)
		{
			InitializeComponent();
			textBox1->BackColor = Color::Black;
			textBox1->ForeColor = Color::Lime;
			textBox1->Font = gcnew Drawing::Font("Consolas", 22);
			timer1->Interval = 100;
			timer1->Start();
		}

	protected:
		~loading()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(loading::typeid));
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::Black;
			   this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->textBox1->Location = System::Drawing::Point(-2, -2);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->ReadOnly = true;
			   this->textBox1->Size = System::Drawing::Size(889, 1205);
			   this->textBox1->TabIndex = 1;
			   this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &loading::loading_KeyDown);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox1->Location = System::Drawing::Point(893, -2);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(1009, 1031);
			   this->pictureBox1->TabIndex = 11;
			   this->pictureBox1->TabStop = false;
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &loading::timer1_Tick);
			   // 
			   // loading
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1902, 1033);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->textBox1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Name = L"loading";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Загрузка";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &loading::loading_KeyDown);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }
#pragma endregion

	private:
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (state == 0) {
				if (charIndex < phrase1->Length) {
					textBox1->AppendText(phrase1[charIndex].ToString());
					charIndex++;
				}
				else {
					state = 1;
					timer1->Interval = 1000;
				}
			}
			else if (state == 1) {
				timer1->Interval = 30;
				if (textBox1->Text->Length > 0) {
					textBox1->Text = textBox1->Text->Substring(0, textBox1->Text->Length - 1);
				}
				else {
					state = 2;
					charIndex = 0;
				}
			}
			else if (state == 2) {
				timer1->Interval = 70;
				if (charIndex < phrase2->Length) {
					textBox1->AppendText(phrase2[charIndex].ToString());
					charIndex++;
				}
				else {
					state = 3;
					timer1->Stop();
				}
			}
		}

		System::Void loading_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (state == 3) {
				MyForm^ mainForm = gcnew MyForm();
				Xakeri::Settings^ settingsForm = gcnew Xakeri::Settings();
				mainForm->Show();
				this->Hide();
				Settings^ newf = gcnew Settings();
				this->Hide();
				newf->Show();
				newf->Hide();
			}
		}
	};
}