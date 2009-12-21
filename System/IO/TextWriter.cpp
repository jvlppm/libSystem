#include "TextWriter.h"
using namespace System;
using namespace System::IO;

void TextWriter::Write(const Object& obj)
{
	write(obj.ToString());
}

void TextWriter::Write(const String& format, const Object& arg1)
{
	Write(String::Format(format, arg1));
}

void TextWriter::Write(const String& format, const Object& arg1, const Object& arg2)
{
	Write(String::Format(format, arg1, arg2));
}

void TextWriter::Write(const String& format, const Object& arg1, const Object& arg2, const Object& arg3)
{
	Write(String::Format(format, arg1, arg2, arg3));
}

void TextWriter::Write(const String& format, const Object& arg1, const Object& arg2, const Object& arg3, const Object& arg4)
{
	Write(String::Format(format, arg1, arg2, arg3, arg4));
}

void TextWriter::WriteLine()
{
	writeLine("");
}

void TextWriter::WriteLine(const Object& obj)
{
	writeLine(obj.ToString());
}

void TextWriter::WriteLine(const String& format, const Object& arg1)
{
	WriteLine(String::Format(format, arg1));
}

void TextWriter::WriteLine(const String& format, const Object& arg1, const Object& arg2)
{
	WriteLine(String::Format(format, arg1, arg2));
}

void TextWriter::WriteLine(const String& format, const Object& arg1, const Object& arg2, const Object& arg3)
{
	WriteLine(String::Format(format, arg1, arg2, arg3));
}

void TextWriter::WriteLine(const String& format, const Object& arg1, const Object& arg2, const Object& arg3, const Object& arg4)
{
	WriteLine(String::Format(format, arg1, arg2, arg3, arg4));
}