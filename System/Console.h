#pragma once
#include "String.h"
#include "Int32.h"
#include "Float.h"
#include "Char.h"
#include "Boolean.h"

namespace System
{
	class Console
	{
		class Object
		{
			public:
				operator const System::Object&() const { return _value; }
			
				Object(const System::Object& value) : _value(value) { }
				Object(int value) : _value(Int32(value)) { }
				Object(float value) : _value(Float(value)) { }
				Object(bool value) : _value(Boolean(value)) { }
				Object(char value) : _value(Char(value)) { }
				Object(const char* value) : _value(String(value)) { }
				
				String ToString() const { return _value.ToString(); }
			private:
				const System::Object& _value;
		};
		
		friend class String;
		public:
			
			static void Write(const Object& obj);
			static void Write(const String&, const Object&);
			static void Write(const String&, const Object&, const Object&);
			static void Write(const String&, const Object&, const Object&, const Object&);
			static void Write(const String&, const Object&, const Object&, const Object&, const Object&);
			
			static void WriteLine();
			static void WriteLine(const Object& obj);
			static void WriteLine(const String&, const Object&);
			static void WriteLine(const String&, const Object&, const Object&);
			static void WriteLine(const String&, const Object&, const Object&, const Object&);
			static void WriteLine(const String&, const Object&, const Object&, const Object&, const Object&);
	};
}
