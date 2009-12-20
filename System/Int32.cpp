#include "Int32.h"
#include "String.h"
#include "DivideByZeroException.h"
#include "FormatException.h"
using namespace System;
#include <sstream>

const Int32 Int32::MaxValue(0x7FFFFFFF);
const Int32 Int32::MinValue(0x80000000);

Int32 Int32::Parse(const String& value)
{
	int integer;
	std::istringstream stream((std::string)value);
	if((stream >> integer).fail() || !stream.eof())
		throw FormatException("Input string was not in the correct format");
	return integer;
}

Int32::Int32(int value) : _value(value)
{
}

Int32::operator int() const
{
	return _value;
}

/////////////////////////
//Operators

Int32 Int32::operator +(const int& val) { return (_value + val); }
Int32 Int32::operator -(const int& val) { return (_value - val); }
Int32 Int32::operator *(const int& val) { return (_value * val); }
Int32 Int32::operator /(const int& val) { if(!val) throw DivideByZeroException(); return (_value / val); }

const Int32& Int32::operator +=(const int& val) { _value += val; return *this; }
const Int32& Int32::operator -=(const int& val) { _value -= val; return *this; }
const Int32& Int32::operator *=(const int& val) { _value *= val; return *this; }
const Int32& Int32::operator /=(const int& val) { _value /= val; return *this; }

bool Int32::operator>(int val) const { return _value > val; }
bool Int32::operator<(int val) const { return _value < val; }

bool Int32::operator>=(int val) const { return _value >= val; }
bool Int32::operator<=(int val) const { return _value <= val; }

bool Int32::operator==(int val) const { return _value == val; }
bool Int32::operator!=(int val) const { return _value != val; }

const Int32& Int32::operator ++ () { ++_value; return *this; }
const Int32& Int32::operator -- () { --_value; return *this; }

Int32 Int32::operator ++ (int) { return _value++; }
Int32 Int32::operator -- (int) { return _value--; }

/////////////////////////

const String Int32::ToString() const
{
	std::ostringstream stream;
	stream << _value;
	return stream.str().c_str();
}
