// project created on 10/31/2009 at 12:37 PM
#include "System.h"
using namespace System;
using namespace System::Collections::Generic;

int Main()
{
	try
	{
		Array<string> novo = ((string) "12;3;4;56").Split(';');
		
		for(int i = 0; i < novo.Length; i++)
			Console::WriteLine(novo[i]);
			
		Console::WriteLine(novo.Length);
	}
	catch(Exception& ex)
	{
		Console::WriteLine(ex);
	}
	//Console.ReadKey();
}
