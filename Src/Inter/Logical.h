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

#include <memory>
#include "Expr.h"
#include "Temp.h"
#include "../Symbols/Type.h"

class Logical : public Expr
{
	public:
		Expr* expr1;
		Expr* expr2;
		Logical(Token* tok, Expr* x1, Expr* x2, std::string objectType); //constructor
		Type* check(Type* p1, Type* p2, std::string objectType);
		virtual Expr* gen();
		virtual std::string toString();
};

#endif
