#include "gdalForm.h"

using namespace System;
using namespace System ::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	gdalVisual::gdalForm form;
	Application::Run(%form);
}