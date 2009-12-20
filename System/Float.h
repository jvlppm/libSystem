#pragma once
#include "Object.h"
#include "Boolean.h"
#include "Int32.h"

namespace System
{
	class Float : public Object
	{
		public:
			static const Float MaxValue;
			static const Float MinValue;
			static const Float NaN;
			static const Float NegativeInfinity;
			static const Float PositiveInfinity;
			
			static Float Parse(const String& text);
			
			static Boolean IsNaN(Float value);
			static Boolean IsNegativeInfinity(Float value);
			static Boolean IsPositiveInfinity(Float value);
			
			Float(Int32 = 0);
			
			Float(double = 0);
			Float(float = 0);
			Float(int = 0);
			
			const String ToString() const;
			
			operator float() const;
			
			//Prefix
			const Float& operator ++ ();// Aumenta, depois verifica
			const Float& operator -- ();// Diminui, depois verifica
			
			//Postfix
			Float operator ++ (int);  // Faz verificacao, depois aumenta
			Float operator -- (int);  // Faz verificacao, depois diminui
			
		private:
			float _value;
	};
}