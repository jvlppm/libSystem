#include "ArgumentOutOfRangeException.h"
using namespace System;

ArgumentOutOfRangeException::ArgumentOutOfRangeException(String paramName, String message) : ParamName(paramName), Exception(message)
{
}

const String ArgumentOutOfRangeException::ToString() const
{
	if(!Message.Length)
		return "System::ArgumentOutOfRangeException";
	return (String) "System::ArgumentOutOfRangeException: " + Message;
}
