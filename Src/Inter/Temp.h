//*****************************************************************************************
//
//	Filename: Temp.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef TEMP_H
#define TEMP_H

#include "Expr.h"
#include "../Symbols/Type.h"
#include "../Lexer/Word.h"

class Temp : public Expr
{
	public:
		static int count;
		int number;
		Temp(Type* p);	// constructor
		virtual std::string toString();
};

#endif
