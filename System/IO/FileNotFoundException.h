#pragma once
#include "../Exception.h"

namespace System
{
	namespace IO
	{
		class FileNotFoundException : public Exception
		{
			public:
				FileNotFoundException(String fileName);
				const String ToString() const;
				String FileName;
		};
	}
}
