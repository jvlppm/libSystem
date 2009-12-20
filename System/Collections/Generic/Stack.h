#pragma once

#include "../../Int32.h"
#include "../../InvalidOperationException.h"
#include "Array.h"
#include "Object.h"
#include <stack>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <class ContentType>
			class Stack : public Object
			{
				public:
					Stack() : Count(0) { }
				
					void Push(const ContentType& item)
					{
						_items.push(item);
						(*((Int32*)&Count))++;
					}
					
					ContentType Peek()
					{
						if(Count <= 0) throw InvalidOperationException();
						return _items.top();
					}
					
					ContentType Pop()
					{
						if(Count <= 0) throw InvalidOperationException();
						
						const ContentType& result = _items.top();
						_items.pop();
						(*((Int32*)&Count))--;
						return result;
					}
					
					Boolean Contains(ContentType item)
					{
						std::stack<ContentType> items = _items;
						while(!items.empty())
						{
							if(items.top() == item)
								return true;
							items.pop();
						}
						return false;
					}
					
					void Clear() { while(Count > 0) Pop(); }
					
					const String ToString() const { "System::Collections::Generic::Stack"; }
					const Int32 Count;
					
					Array<ContentType> ToArray() const
					{
						Array<ContentType> result(Count);
						std::stack<ContentType> items(_items);
						for(int i = 0; i < Count; i++)
						{
							result[i] = items.top();
							items.pop();
						}
						return result;
					}
				private:
					std::stack<ContentType> _items;
			};
		}
	}
}
