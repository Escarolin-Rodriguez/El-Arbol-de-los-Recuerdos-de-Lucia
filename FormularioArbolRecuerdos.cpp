#include "FormularioArbolRecuerdos.h"
#include "FormBienvenida.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Aquí usamos el nombre exacto que aparece en tu línea 3:
    ArbolRecuerdos::FormBienvenida form;

    Application::Run(% form);
    return 0;
}