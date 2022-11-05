#include "SquigglesInterface.h"
#include <iostream>


using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]


void main(array <String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	SquigglesApplication::SquigglesInterface form;

	Application::Run(% form);
}
