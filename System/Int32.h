#pragma once
#include "Object.h"

namespace System
{
	class Int32 : public Object
	{
		public:
			static const Int32 MaxValue;
			static const Int32 MinValue;
			
			static Int32 Parse(const String&);
			
		
			Int32(int = 0);
			
			const String ToString() const;
			
			operator int() const;
			
			Int32 operator +(const int& val);
			Int32 operator -(const int& val);
			Int32 operator *(const int& val);
			Int32 operator /(const int& val);
			
			const Int32& operator +=(const int& val);
			const Int32& operator -=(const int& val);
			const Int32& operator *=(const int& val);
			const Int32& operator /=(const int& val);
			
			bool operator>(int val) const;
			bool operator<(int val) const;
			
			bool operator>=(int val) const;
			bool operator<=(int val) const;
			
			bool operator==(int val) const;
			bool operator!=(int val) const;
			
			const Int32& operator ++ ();
			const Int32& operator -- ();
			
			Int32 operator ++ (int);
			Int32 operator -- (int);
			
		private:
			int _value;
	};
}