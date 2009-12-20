#pragma once
#include "Object.h"
#include "Boolean.h"
#include "Int32.h"
#include "Float.h"

namespace System
{
	class Double : public Object
	{
		public:
			static const Double MaxValue;
			static const Double MinValue;
			static const Double NaN;
			static const Double NegativeInfinity;
			static const Double PositiveInfinity;
			
			static Double Parse(const String& text);
			
			static Boolean IsNaN(Double value);
			static Boolean IsNegativeInfinity(Double value);
			static Boolean IsPositiveInfinity(Double value);
			
			Double(Int32 = 0);
			Double(Float = 0);
			
			Double(double = 0);
			Double(float = 0);
			Double(int = 0);
			
			const String ToString() const;
			
			operator double() const;
			
			//Prefix
			const Double& operator ++ ();// Aumenta, depois verifica
			const Double& operator -- ();// Diminui, depois verifica
			
			//Postfix
			Double operator ++ (int);  // Faz verificacao, depois aumenta
			Double operator -- (int);  // Faz verificacao, depois diminui
			
		private:
			double _value;
	};
}