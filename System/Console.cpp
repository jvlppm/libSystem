#include "Console.h"
using namespace System;
#include <stdarg.h>
#include "Int32.h"

#include <iostream>

void Console::Write(const Object& obj)
{
	std::cout << obj.ToString();
}

void Console::Write(const String& format, const Object& arg1)
{
	Write(String::Format(format, arg1));
}

void Console::Write(const String& format, const Object& arg1, const Object& arg2)
{
	Write(String::Format(format, arg1, arg2));
}

void Console::Write(const String& format, const Object& arg1, const Object& arg2, const Object& arg3)
{
	Write(String::Format(format, arg1, arg2, arg3));
}

void Console::Write(const String& format, const Object& arg1, const Object& arg2, const Object& arg3, const Object& arg4)
{
	Write(String::Format(format, arg1, arg2, arg3, arg4));
}

void Console::WriteLine()
{
	std::cout << std::endl;
}

void Console::WriteLine(const Object& obj)
{
	std::cout << obj.ToString() << std::endl;
}

void Console::WriteLine(const String& format, const Object& arg1)
{
	WriteLine(String::Format(format, arg1));
}

void Console::WriteLine(const String& format, const Object& arg1, const Object& arg2)
{
	WriteLine(String::Format(format, arg1, arg2));
}

void Console::WriteLine(const String& format, const Object& arg1, const Object& arg2, const Object& arg3)
{
	WriteLine(String::Format(format, arg1, arg2, arg3));
}

void Console::WriteLine(const String& format, const Object& arg1, const Object& arg2, const Object& arg3, const Object& arg4)
{
	WriteLine(String::Format(format, arg1, arg2, arg3, arg4));
}