#pragma once

namespace System
{
	class String;
	class Object
	{
		public:
			virtual const String ToString() const = 0;
	};
}
