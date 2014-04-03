//*****************************************************************************************
//
//	Filename: Logical.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef LOGICAL_H
#define LOGICAL_H

#include "../Symbols/Type.h"
#include "../Inter/Expr.h"
#include "../Inter/Temp.h"

class Logical : public Expr
{
	public:
		Expr* expr1;
		Expr* expr2;
		Logical(Token* tok, Expr* x1, Expr* x2); //constructor
		Type* check(Type* p1, Type* p2);
		Expr* gen();
		std::string toString();
};

#endif
