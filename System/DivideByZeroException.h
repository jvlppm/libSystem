#pragma once
#include "Exception.h"

namespace System
{
	class DivideByZeroException : public Exception
	{
		public:
			DivideByZeroException(String message = "Attempted to divide by zero");
			const String ToString() const;
	};
}
