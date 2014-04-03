//*****************************************************************************************
//
//	Filename: Or.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef OR_H
#define OR_H

#include "Expr.h"
#include "Logical.h"
#include "../Symbols/Type.h"

class Or : public Logical
{
	public:
		Or(Token* tok, Expr* x1, Expr* x2); //constructor
		void jumping(int t, int f);
};

#endif
