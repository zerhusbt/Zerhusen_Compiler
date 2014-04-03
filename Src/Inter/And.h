//*****************************************************************************************
//
//	Filename: And.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef AND_H
#define AND_H

#include "Expr.h"
#include "Logical.h"
#include "../Symbols/Type.h"

class And : public Logical
{
	public:
		And(Token* tok, Expr* x1, Expr* x2); //constructor
		void jumping(int t, int f);
};

#endif
