#pragma once
#include "Exception.h"

namespace System
{
	class FormatException : public Exception
	{
		public:
			FormatException(String message = "Invalid format");
			const String ToString() const;
	};
}
