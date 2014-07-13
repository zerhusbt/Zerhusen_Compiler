//*****************************************************************************************
//
//	Filename: Constant.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef CONSTANT_H
#define CONSTANT_H

#include "../Symbols/Type.h"
#include "../Inter/Expr.h"
#include "../Inter/Temp.h"

class Constant : public Expr
{
	public:
		Constant(Token* tok, Type* p); //constructor
		Constant(int i); //constructor
		virtual void jumping(int t, int f);
		static Constant* True;
		static Constant* False;
};

#endif
