#include "Char.h"
#include "String.h"
using namespace System;
#include <sstream>

const Char Char::MaxValue(0xFF);
const Char Char::MinValue(0x00);

Char::Char(char value) : _value(value)
{
}

Char::operator char() const
{
	return _value;
}

const String Char::ToString() const
{
	std::ostringstream stream;
	stream << _value;
	return stream.str().c_str();
}
