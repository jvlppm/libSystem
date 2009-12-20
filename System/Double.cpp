#include "Double.h"
#include "String.h"
#include "DivideByZeroException.h"
#include "FormatException.h"
using namespace System;
#include <sstream>
#include <math.h>
#include <limits>

const Double Double::MaxValue(std::numeric_limits<double>::max());
const Double Double::MinValue(std::numeric_limits<double>::min());
const Double Double::NaN(0/(double)0);
const Double Double::NegativeInfinity(-1/(double)0);
const Double Double::PositiveInfinity(+1/(double)0);

Double Double::Parse(const String& text)
{
	double value;
	std::istringstream stream((std::string)text);
	if((stream >> value).fail() || !stream.eof())
		throw FormatException("Input string was not in the correct format");
	return value;
}

Boolean Double::IsNaN(Double value)
{
	return isnan(value);
}

Boolean Double::IsPositiveInfinity(Double value)
{
	return isinf(value) && value > 0;
}

Boolean Double::IsNegativeInfinity(Double value)
{
	return isinf(value) && value < 0;
}

Double::Double(Float value) : _value(value) { }
Double::Double(Int32 value) : _value(value) { }
Double::Double(double value) : _value(value) { }
Double::Double(float value) : _value(value) { }
Double::Double(int value) : _value(value) { }

Double::operator double() const
{
	return _value;
}

const Double& Double::operator ++ () // Prefix
{
	++_value;
	return *this;
}

const Double& Double::operator -- () // Prefix
{
	--_value;
	return *this;
}

Double Double::operator ++ (int)   // Postfix
{
	return _value++;
}

Double Double::operator -- (int)   // Postfix
{
	return _value--;
}

const String Double::ToString() const
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
