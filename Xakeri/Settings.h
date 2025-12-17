#pragma once


namespace Xakeri {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Settings : public System::Windows::Forms::Form
    {
    public:
        Settings(void)
        {
            InitializeComponent();
            textBox1->BackColor = Color::Black;
            textBox1->ForeColor = Color::Lime;
            textBox1->Font = gcnew Drawing::Font("Consolas", 22);
            textBox1->ReadOnly = false; 
            textBox1->Text = "Настройки\r\n> C - Скрыть\r\n> ";
            textBox1->SelectionStart = textBox1->Text->Length;
        }

    protected:
        ~Settings()
        {
            if (components)
                delete components;
        }
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::PictureBox^ pictureBox2;

    private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::CheckBox^ checkBox1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ label3;

    protected:

    protected:


    private:


        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
            this->label3 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::Black;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 58.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->textBox1->Location = System::Drawing::Point(1, 0);
            this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBox1->Size = System::Drawing::Size(666, 600);
            this->textBox1->TabIndex = 1;
            this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Settings::textBox1_KeyDown);
            // 
            // pictureBox2
            // 
            this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
            this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pictureBox2->Location = System::Drawing::Point(525, 0);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(117, 38);
            this->pictureBox2->TabIndex = 10;
            this->pictureBox2->TabStop = false;
            // 
            // comboBox1
            // 
            this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->comboBox1->ForeColor = System::Drawing::Color::Transparent;
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(19) {
                L"5%", L"10%", L"15%", L"20%", L"25%", L"30%",
                    L"35%", L"40%", L"45%", L"50%", L"55%", L"65%", L"70%", L"75%", L"80%", L"85%", L"90%", L"95%", L"100%"
            });
            this->comboBox1->Location = System::Drawing::Point(1019, 217);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(185, 44);
            this->comboBox1->TabIndex = 13;
            this->comboBox1->Text = L"10%";
            this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::comboBox1_SelectedIndexChanged);
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->BackColor = System::Drawing::Color::White;
            this->checkBox1->Checked = true;
            this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
            this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->checkBox1->ForeColor = System::Drawing::SystemColors::Control;
            this->checkBox1->Location = System::Drawing::Point(1052, 274);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(152, 41);
            this->checkBox1->TabIndex = 14;
            this->checkBox1->TabStop = false;
            this->checkBox1->Text = L"||||||||||||||";
            this->checkBox1->UseVisualStyleBackColor = false;
            this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox1_CheckedChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(795, 220);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(174, 36);
            this->label1->TabIndex = 15;
            this->label1->Text = L"Громкость";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(945, 137);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(82, 36);
            this->label2->TabIndex = 16;
            this->label2->Text = L"Звук";
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pictureBox1->Location = System::Drawing::Point(662, -10);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(623, 610);
            this->pictureBox1->TabIndex = 11;
            this->pictureBox1->TabStop = false;
            // 
            // axWindowsMediaPlayer1
            // 
            this->axWindowsMediaPlayer1->Enabled = true;
            this->axWindowsMediaPlayer1->Location = System::Drawing::Point(682, 8);
            this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
            this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
            this->axWindowsMediaPlayer1->Size = System::Drawing::Size(75, 23);
            this->axWindowsMediaPlayer1->TabIndex = 12;
            this->axWindowsMediaPlayer1->Visible = false;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label3->ForeColor = System::Drawing::Color::White;
            this->label3->Location = System::Drawing::Point(1066, 277);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(125, 36);
            this->label3->TabIndex = 17;
            this->label3->Text = L"Музыка";
            this->label3->Click += gcnew System::EventHandler(this, &Settings::label3_Click);
            // 
            // Settings
            // 
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1284, 601);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->axWindowsMediaPlayer1);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->pictureBox2);
            this->Controls->Add(this->textBox1);
            this->DoubleBuffered = true;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Settings";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Настройки";
            this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void Settings_Load(System::Object^ sender, System::EventArgs^ e) {
            axWindowsMediaPlayer1->URL = Application::StartupPath + "\\music\\music.mp3";
            axWindowsMediaPlayer1->settings->setMode("loop", true);
            axWindowsMediaPlayer1->settings->volume = 10;
            axWindowsMediaPlayer1->Ctlcontrols->play();
        }
        System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            int currentLineIndex = textBox1->GetLineFromCharIndex(textBox1->SelectionStart);
            int lineStart = textBox1->GetFirstCharIndexFromLine(currentLineIndex);

            if (e->KeyCode == Keys::Enter) {
                String^ lastLine = textBox1->Lines[textBox1->Lines->Length - 1]->Replace(">", "")->Trim();

                if (lastLine->Equals("C", StringComparison::OrdinalIgnoreCase) ||
                    lastLine->Equals("С", StringComparison::OrdinalIgnoreCase)) {
                    this->Hide();
                }
                e->SuppressKeyPress = true; 
                textBox1->AppendText(Environment::NewLine + "> ");
            }
            if (e->KeyCode == Keys::Back) {
                if (textBox1->SelectionStart <= lineStart + 2) {
                    e->SuppressKeyPress = true;
                }
            }
        }
        System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (comboBox1->SelectedItem != nullptr) {
                String^ val = comboBox1->SelectedItem->ToString()->Replace("%", "");
                axWindowsMediaPlayer1->settings->volume = Convert::ToInt32(val);
            }
        }
        System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
            if (this->checkBox1->Checked) axWindowsMediaPlayer1->Ctlcontrols->play();
            else axWindowsMediaPlayer1->Ctlcontrols->pause();
        }
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
