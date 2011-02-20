#include "StreamReader.h"
#include "../String.h"
#include "FileNotFoundException.h"
using namespace System;
using namespace System::IO;

StreamReader::StreamReader(String path) : _file(path), EndOfStream(_file.eof())
{
	if(!_file.is_open())
		throw FileNotFoundException(path);
}

const String StreamReader::ToString() const
{
	return "System::IO::StreamReader";
}

Int32 StreamReader::Read()
{
	int data = _file.get();
	_file.get();
	*((Boolean*)&EndOfStream) = _file.eof();
	_file.unget();
	return data;
}

String StreamReader::ReadLine()
{
	std::string result;
	std::getline(_file, result);
	*((Boolean*)&EndOfStream) = _file.eof();
	return result.c_str();
}

Int32 StreamReader::Peek()
{
	int data = _file.peek();
	return data;
}

void StreamReader::Close()
{
	_file.close();
}
