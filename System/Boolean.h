#pragma once
#include "Object.h"

namespace System
{
	class Boolean : public Object
	{
		public:
			Boolean(bool = false);
			operator bool() const;
			const String ToString() const;
		private:
			bool _value;
	};
}