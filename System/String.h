#pragma once
#include "Boolean.h"
#include "Int32.h"
#include "Char.h"

namespace System
{
	namespace Collections { namespace Generic { template <class Type> class Array; } }
	class Boolean;
	class Int32;
	class Char;
	class String : public Object
	{
		friend class Object;
		
		public:
			static String Format(const String&, const Object&);
			static String Format(const String&, const Object&, const Object&);
			static String Format(const String&, const Object&, const Object&, const Object&);
			static String Format(const String&, const Object&, const Object&, const Object&, const Object&);
		
			String();
			String(const String&);
			String(const char*);
			
			operator const char* () const;
			
			Boolean Contains(const String&) const;
			String Replace(const String&, const String&) const;
			Boolean StartsWith(const String&) const;
			Boolean EndsWith(const String&) const;
			Int32 IndexOf(char) const;
			Int32 IndexOf(const String&) const;
			String Substring(Int32 startIndex) const;
			String Substring(Int32 startIndex, Int32 length) const;
			String ToUpper() const;
			String ToLower() const;
			String TrimStart(char) const;
			String TrimEnd(char) const;
			String Trim(char = ' ') const;
			Collections::Generic::Array<String> Split(char) const;
			
			const String ToString() const;
			const Int32 Length;
			
			const String& operator=(const String&);
			
			String operator+(const String&) const;
			const String& operator+=(const String&);
			
			String operator+(const Char&) const;
			const String& operator+=(const Char&);
			
			Boolean operator==(const String&) const;
			Boolean operator==(const char*) const;
			Boolean operator!=(const String&) const;
			Boolean operator!=(const char*) const;
			
			Char operator[](int i) const;
			Char operator[](Int32 i) const;
		private:
			const char* _text;
	};
}