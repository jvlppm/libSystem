// project created on 10/31/2009 at 12:37 PM
#include "System.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

int Main()
{
	try
	{
		StreamWriter newFile("new.txt");
		
		string example = "12;3;4;56";
		
		Console::WriteLine("Original string: \"{0}\"", example);
		newFile.WriteLine("Original string: \"{0}\"", example);
		
		Array<string> novo = example.Split(';');
		
		Console::WriteLine("string splitted on \';\'");
		newFile.WriteLine("string splitted on \';\'");
		
		for(int i = 0; i < novo.Length; i++)
		{
			Console::WriteLine(novo[i]);
			newFile.WriteLine(novo[i]);
		}
			
		Console::WriteLine("Length of splitted array: {0}", novo.Length);
		newFile.WriteLine("Length of splitted array: {0}", novo.Length);
	}
	catch(Exception& ex)
	{
		Console::WriteLine(ex);
	}
	//Console.ReadKey();
}
