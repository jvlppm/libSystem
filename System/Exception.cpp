#include "Exception.h"
using namespace System;

Exception::Exception(String message) : Message(message)
{
}

const String Exception::ToString() const
{
	if(!Message.Length)
		return "System::Exception";
	return (String)"System::Exception: " + Message;
}