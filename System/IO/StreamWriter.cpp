#include "StreamWriter.h"
#include "../String.h"
using namespace System;
using namespace System::IO;

StreamWriter::StreamWriter(String path) : _file(path)
{
}

const String StreamWriter::ToString() const
{
	return "System::IO::StreamWriter";
}

void StreamWriter::write(const String& text)
{
	_file << text;
}

void StreamWriter::writeLine(const String& text)
{
	_file << text << std::endl;
}

void StreamWriter::Close()
{
	_file.close();
}

void StreamWriter::Flush()
{
	_file.flush();
}
