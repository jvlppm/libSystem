#include "DivideByZeroException.h"
using namespace System;

DivideByZeroException::DivideByZeroException(String message) : Exception(message)
{
}

const String DivideByZeroException::ToString() const
{
	if(!Message.Length)
		return "System::DivideByZeroException";
	return (String) "System::DivideByZeroException: " + Message;
}
