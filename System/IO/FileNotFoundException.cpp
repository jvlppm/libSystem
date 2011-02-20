#include "FileNotFoundException.h"
using namespace System;
using namespace System::IO;

FileNotFoundException::FileNotFoundException(String fileName)
 : Exception(String("Could not find file \"") + fileName + "\"."), FileName(fileName)
{
}

const String FileNotFoundException::ToString() const
{
	if(!Message.Length)
		return "System::IO::FileNotFoundException";
	return (String) "System::IO::FileNotFoundException: " + Message;
}
