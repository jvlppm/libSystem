#pragma once
#include "../Object.h"
#include "../Int32.h"
#include "../Boolean.h"
#include <fstream>

namespace System
{
	namespace IO
	{
		class StreamReader : public Object
		{
			public:
				StreamReader(String path);
				const String ToString() const;
				
				void Close();
				Int32 Read();
				String ReadLine();
				Int32 Peek();
				const Boolean EndOfStream;
				
			private:
				std::ifstream _file;
		};
	}
}