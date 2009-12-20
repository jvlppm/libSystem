#pragma once
#include "../../Object.h"
#include "../../IndexOutOfRangeException.h"
#include <vector>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <class ContentType>
			class Array : public Object
			{
				public:
					Array(Int32 length) : Length(length), _items(length) {}
					
					const Int32 Length;
					ContentType& operator [] (Int32 index)
					{
						if(index >= Length || index < 0) throw IndexOutOfRangeException();
						return _items[index];
					}
					
					const String ToString() const { return "System::Collections::Generic::Array"; }
				private:
					std::vector<ContentType> _items;
			};
		}
	}
}