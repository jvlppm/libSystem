#pragma once
#include "Exception.h"

namespace System
{
	class InvalidOperationException : public Exception
	{
		public:
			InvalidOperationException(String message = "Operation is not valid due to the current state of the object");
			const String ToString() const;
	};
}
