#pragma once

#include "../../Int32.h"
#include "../../InvalidOperationException.h"
#include "Object.h"
#include <queue>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <class ContentType>
			class Queue : public Object
			{
				public:
					Queue() : Count(0) { }
				
					void Enqueue(const ContentType& item)
					{
						_items.push(item);
						(*((Int32*)&Count))++;
					}
					
					ContentType Peek()
					{
						if(Count <= 0) throw InvalidOperationException();
						
						return _items.front();
					}
					
					ContentType Dequeue()
					{
						if(Count <= 0) throw InvalidOperationException();
						
						const ContentType& result = _items.front();
						_items.pop();
						(*((Int32*)&Count))--;
						return result;
					}
					
					Boolean Contains(ContentType item)
					{
						std::queue<ContentType> items = _items;
						while(!items.empty())
						{
							if(items.front() == item)
								return true;
							items.pop();
						}
						return false;
					}
					
					void Clear() { while(Count > 0) Dequeue(); }
					
					const String ToString() const { return "System::Collections::Generic::Queue"; }
					
					const Int32 Count;
					
					Array<ContentType> ToArray() const
					{
						Array<ContentType> result(Count);
						std::queue<ContentType> items(_items);
						for(int i = 0; i < Count; i++)
						{
							result[i] = items.front();
							items.pop();
						}
						return result;
					}
				private:
					std::queue<ContentType> _items;
			};
		}
	}
}
