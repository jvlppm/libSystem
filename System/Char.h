#pragma once
#include "Object.h"

namespace System
{
	class Char : public Object
	{
		public:
			static const Char MaxValue;
			static const Char MinValue;
		
			Char(char = '\0');
			operator char() const;
			const String ToString() const;
		private:
			char _value;
	};
}
