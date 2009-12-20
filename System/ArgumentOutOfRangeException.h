#pragma once
#include "Exception.h"

namespace System
{
	class ArgumentOutOfRangeException : public Exception
	{
		public:
			ArgumentOutOfRangeException(String paramName, String message);
			const String ToString() const;
			const String ParamName;
	};
}
