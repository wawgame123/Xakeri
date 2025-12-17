#include "loading.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Xakeri;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew loading());
    return 0;
}
