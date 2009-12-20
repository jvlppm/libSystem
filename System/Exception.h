#pragma once
#include "String.h"
#include "Object.h"

namespace System
{
	class Exception : public Object
	{
		public:
			Exception(String message = "");
			const String ToString() const;
			String Message;
	};
}
