//*****************************************************************************************
//
//	Filename: Rel.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef REL_H
#define REL_H

#include "Expr.h"
#include "Logical.h"
#include "../Symbols/Type.h"
#include "../Symbols/Array.h"
#include <typeinfo>

class Rel : public Logical
{
	public:
		Rel(Token* tok, Expr* x1, Expr* x2); //constructor
		Type* check(Type* p1, Type* p2);
		void jumping(int t, int f);
};

#endif
