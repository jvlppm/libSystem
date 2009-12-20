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
				~Object() { if(_temporary) delete _value; }
			
				operator const System::Object&() const { return *_value; }
			
				Object(const System::Object& value) : _temporary(false), _value(&value) { }
				Object(int value) : _temporary(true), _value(new Int32(value)) { }
				Object(float value) : _temporary(true), _value(new Float(value)) { }
				Object(bool value) : _temporary(true), _value(new Boolean(value)) { }
				Object(char value) : _temporary(true), _value(new Char(value)) { }
				Object(const char* value) : _temporary(true), _value(new String(value)) { }
				
				String ToString() const { return _value->ToString(); }
			private:
				bool _temporary;
				const System::Object* _value;
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
