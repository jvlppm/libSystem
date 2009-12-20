#pragma once
#include "Exception.h"

namespace System
{
	class IndexOutOfRangeException : public Exception
	{
		public:
			IndexOutOfRangeException(String message = "Array index is out of range");
			const String ToString() const;
	};
}
