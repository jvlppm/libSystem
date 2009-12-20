#include "String.h"
using namespace System;
#include "ArgumentOutOfRangeException.h"
#include "IndexOutOfRangeException.h"
#include <string.h>
#include <iostream>
#include "Collections/Generic/Array.h"

String String::Format(const String& format, const Object& obj0)
{
	String Format = format;
	Format = Format.Replace("{0}", obj0.ToString());
	return Format;
}
String String::Format(const String& format, const Object& obj0, const Object& obj1)
{
	String Format = format;
	Format = Format.Replace("{0}", obj0.ToString());
	Format = Format.Replace("{1}", obj1.ToString());
	return Format;
}
String String::Format(const String& format, const Object& obj0, const Object& obj1, const Object& obj2)
{
	String Format = format;
	Format = Format.Replace("{0}", obj0.ToString());
	Format = Format.Replace("{1}", obj1.ToString());
	Format = Format.Replace("{2}", obj2.ToString());
	return Format;
}
String String::Format(const String& format, const Object& obj0, const Object& obj1, const Object& obj2, const Object& obj3)
{
	String Format = format;
	Format = Format.Replace("{0}", obj0.ToString());
	Format = Format.Replace("{1}", obj1.ToString());
	Format = Format.Replace("{2}", obj2.ToString());
	Format = Format.Replace("{3}", obj3.ToString());
	return Format;
}

String::String() : Length(0), _text(new char[1]) { ((char*)_text)[0] = '\0'; }
String::String(const String& original) : Length(original.Length)
{
	if(Length >= 0)
	{
		_text = new char[Length+1];
		for(int i = 0; i < Length; i++)
			((char*)_text)[i] = original._text[i];
		((char*)_text)[Length] = '\0';
	}
}

String::String(const char* text) : _text(0x0), Length(text? strlen(text) : 0)
{
	if(Length >= 0)
	{
		_text = new char[Length+1];
		for(int i = 0; i < Length; i++)
			((char*)_text)[i] = text[i];
		((char*)_text)[Length] = '\0';
	}
}

String::operator const char* () const
{
	return _text;
}


Boolean String::Contains(const String& str) const
{
	return strstr(_text, str._text) != 0x0;
}

String String::Replace(const String& oldStr, const String& newStr) const
{
	std::string myText = _text;
	for(int i = 0; i < myText.length(); i++)
	{
		int j;
		for(j = 0; j < oldStr.Length && oldStr._text[j] != '\0' && oldStr._text[j] == myText[i+j]; j++);
		if(oldStr._text[j] == '\0')
		{
			myText = myText.replace(i, j, newStr._text);
			i += newStr.Length - 1;
		}
	}
	return myText.c_str();
}

Boolean String::StartsWith(const String &str) const
{
	int i = 0;
	for(; i < Length && i < str.Length && str._text[i] == _text[i]; i++);
	return i >= str.Length;
}

Boolean String::EndsWith(const String &str) const
{
	int i = Length - 1, j = str.Length - 1;
	for(; i >= 0 && j >= 0 && str._text[j] == _text[i]; i--,j--);
	return j < 0;
}

Int32 String::IndexOf(char ch) const
{
	int i;
	for(i = 0; i < Length && _text[i] != ch; i++);
	return i >= Length? -1 : i;
}
Int32 String::IndexOf(const String& str) const
{
	const char* pos = strstr(_text, str._text);
	return pos && ((pos - _text) + str.Length) <= Length? pos - _text: -1;
}

String String::Substring(Int32 startIndex) const
{
	if(startIndex > Length || startIndex < 0)
		throw ArgumentOutOfRangeException("startIndex", "Index must refer to a location within the string");
	return _text + startIndex;
}

String String::Substring(Int32 startIndex, Int32 length) const
{
	if(startIndex > Length || startIndex < 0)
		throw ArgumentOutOfRangeException("startIndex", "Index must refer to a location within the string");
	
	if(startIndex + length > Length || length < 0)
		throw ArgumentOutOfRangeException("length", "Index and length must refer to a location within the string");	
		
	char substr[(int)(length+1)];
	for(int i = 0; i < length; i++)
		substr[i] = _text[startIndex+i];
		
	substr[length] = '\0';
		
	return substr;
}

String String::ToUpper() const
{
	char upper[Length + 1];
	for(int i = 0; i < Length + 1; i++)
	{
		if(_text[i] >= 'a' && _text[i] <= 'z')
			upper[i] = _text[i] - 'a' + 'A';
		else
			upper[i] = _text[i];
	}
	return upper;
}

String String::ToLower() const
{
	char upper[Length + 1];
	for(int i = 0; i < Length + 1; i++)
	{
		if(_text[i] >= 'A' && _text[i] <= 'Z')
			upper[i] = _text[i] - 'A' + 'a';
		else
			upper[i] = _text[i];
	}
	return upper;
}

String String::TrimStart(char ch) const
{
	int i;
	for(i = 0; i < Length && _text[i] == ch; i++);
	return _text + i;
}

String String::TrimEnd(char ch) const
{
	int i;
	for(i = Length - 1; i >= 0 && _text[i] == ch; i--);
	return Substring(0, i+1);
}

String String::Trim(char ch) const
{
	return TrimStart(ch).TrimEnd(ch);
}

Collections::Generic::Array<String> String::Split(char ch) const
{
	std::string text = _text;
	int found = 0, i;
	for(i = 0; i < Length; i++)
		found += _text[i] == ch;
	
	Collections::Generic::Array<String> result(found + 1);
	
	i = 0;
	int lastPos = 0, currentItem = 0;
	
	do
	{
		for(i = 0; i + lastPos < Length && _text[i + lastPos] != ch; i++);
		result[currentItem++] = (String)text.substr(lastPos, i).c_str();
		lastPos += i + 1;
	}while(found-- > 0);
	
	return result;
}

const String& String::operator=(const String& a)
{
	delete _text;
	*((Int32*)(&Length)) = a.Length;
	_text = new char[a.Length];
	strcpy(((char*)_text), a._text);
	return a;
}

String String::operator+(const String& b) const
{
	char newStr[Length + b.Length];
	strcpy(newStr, _text);
	strcat(newStr, b._text);
	return newStr;
}

const String& String::operator+=(const String& b)
{
	return *this = *this + b;
}

String String::operator+(const Char& b) const
{
	return operator+(b.ToString());
}

const String& String::operator+=(const Char& b)
{
	return operator+=(b.ToString());
}

Boolean String::operator==(const String& str) const
{
	return str.Length == Length && !strcmp(_text, str._text);
}

Boolean String::operator==(const char* text) const
{
	return !strcmp(_text, text);
}

Boolean String::operator!=(const String& str) const
{
	return str.Length != Length || strcmp(_text, str._text);
}

Boolean String::operator!=(const char* text) const
{
	return strcmp(_text, text);
}

Char String::operator[](int i) const
{
	return operator[]((Int32)i);
}

Char String::operator[](Int32 i) const
{
	if(i >= Length)
		throw IndexOutOfRangeException();
	return _text[i];
}

const String String::ToString() const
{
	return *this;
}
