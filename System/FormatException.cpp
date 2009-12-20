#include "FormatException.h"
using namespace System;

FormatException::FormatException(String message) : Exception(message)
{
}

const String FormatException::ToString() const
{
	if(!Message.Length)
		return "System::FormatException";
	return (String) "System::FormatException: " + Message;
}
