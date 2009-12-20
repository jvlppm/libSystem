#include "InvalidOperationException.h"
using namespace System;

InvalidOperationException::InvalidOperationException(String message) : Exception(message)
{
}

const String InvalidOperationException::ToString() const
{
	if(!Message.Length)
		return "System::InvalidOperationException";
	return (String) "System::InvalidOperationException: " + Message;
}
