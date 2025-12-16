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
        }

    protected:
        ~Settings()
        {
            if (components)
                delete components;
        }
    private: System::Windows::Forms::ComboBox^ comboBox1;
    protected:
    private: System::Windows::Forms::ComboBox^ comboBox2;

    private:


        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"Blue", L"Red", L"Green", L"White", L"Orange",
                    L"Black"
            });
            this->comboBox1->Location = System::Drawing::Point(126, 57);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 24);
            this->comboBox1->TabIndex = 0;
            // 
            // comboBox2
            // 
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"Blue", L"Red", L"Green", L"White", L"Orange",
                    L"Black"
            });
            this->comboBox2->Location = System::Drawing::Point(126, 114);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(121, 24);
            this->comboBox2->TabIndex = 1;
            // 
            // Settings
            // 
            this->ClientSize = System::Drawing::Size(282, 253);
            this->Controls->Add(this->comboBox2);
            this->Controls->Add(this->comboBox1);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Settings";
            this->Text = L"Settings";
            this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
    private: System::Void Settings_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
