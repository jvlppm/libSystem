#pragma once
#include "TextWriter.h"
#include <fstream>

namespace System
{
	namespace IO
	{
		class StreamWriter : public TextWriter
		{
			public:
				StreamWriter(String path);
				const String ToString() const;
				
				void Close();
				void Flush();
			private:
				std::ofstream _file;
				
				void write(const String&);
				void writeLine(const String&);
		};
	}
}