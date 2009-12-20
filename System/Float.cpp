#include "Float.h"
#include "String.h"
#include "DivideByZeroException.h"
#include "FormatException.h"
using namespace System;
#include <sstream>
#include <math.h>
#include <limits>

const Float Float::MaxValue(std::numeric_limits<float>::max());
const Float Float::MinValue(std::numeric_limits<float>::min());
const Float Float::NaN(0/(float)0);
const Float Float::NegativeInfinity(-1/(float)0);
const Float Float::PositiveInfinity(+1/(float)0);

Float Float::Parse(const String& text)
{
	float value;
	std::istringstream stream((std::string)text);
	if((stream >> value).fail() || !stream.eof())
		throw FormatException("Input string was not in the correct format");
	return value;
}

Boolean Float::IsNaN(Float value)
{
	return isnan(value);
}

Boolean Float::IsPositiveInfinity(Float value)
{
	return isinf(value) && value > 0;
}

Boolean Float::IsNegativeInfinity(Float value)
{
	return isinf(value) && value < 0;
}

Float::Float(Int32 value) : _value(value) { }
Float::Float(double value) : _value(value) { }
Float::Float(float value) : _value(value) { }
Float::Float(int value) : _value(value) { }

Float::operator float() const
{
	return _value;
}

const Float& Float::operator ++ () // Prefix
{
	++_value;
	return *this;
}

const Float& Float::operator -- () // Prefix
{
	--_value;
	return *this;
}

Float Float::operator ++ (int)   // Postfix
{
	return _value++;
}

Float Float::operator -- (int)   // Postfix
{
	return _value--;
}

const String Float::ToString() const
{
	if(IsNaN(_value))
		return "NaN";
	if(IsPositiveInfinity(_value))
		return "Infinity";
	if(IsNegativeInfinity(_value))
		return "-Infinity";
		
	std::ostringstream stream;
	stream << _value;
	return stream.str().c_str();
}
