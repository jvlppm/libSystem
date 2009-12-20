#include "IndexOutOfRangeException.h"
using namespace System;

IndexOutOfRangeException::IndexOutOfRangeException(String message) : Exception(message)
{
}

const String IndexOutOfRangeException::ToString() const
{
	if(!Message.Length)
		return "System::IndexOutOfRangeException";
	return (String) "System::IndexOutOfRangeException: " + Message;
}
