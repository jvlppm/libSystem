#include "Boolean.h"
#include "String.h"
using namespace System;

Boolean::Boolean(bool value) : _value(value)
{
}

Boolean::operator bool() const
{
	return _value;
}

const String Boolean::ToString() const
{
	return _value? "True" : "False";
}