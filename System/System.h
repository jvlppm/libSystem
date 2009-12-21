#pragma once
#include "String.h"
#include "Boolean.h"
#include "Int32.h"
#include "Float.h"
#include "Char.h"
#include "Console.h"
#include "Exception.h"
#include "DivideByZeroException.h"
#include "ArgumentOutOfRangeException.h"
#include "IndexOutOfRangeException.h"

#include "Collections/Generic/Array.h"
#include "Collections/Generic/Queue.h"
#include "Collections/Generic/Stack.h"

#include "IO/StreamWriter.h"

System::Int32 Main();

int main(int argc, char *argv[])
{
	return Main();
}

#ifndef UseCTypes
typedef bool cbool;
typedef char cchar;
typedef int cint;
typedef float cfloat;
typedef double cdouble;

#define bool System::Boolean
#define char System::Char
#define int System::Int32
#define float System::Float
#define double System::Float
typedef System::String string;
typedef System::Object object;
#endif
