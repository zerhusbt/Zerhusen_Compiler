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
		static Logical* create(Token* tok, Expr* x1, Expr* x2);
		Expr* expr1;
		Expr* expr2;
		Logical(Token* tok, Expr* x1, Expr* x2); //constructor
		virtual Type* check(Type* p1, Type* p2) const;
		void init(Token* tok, Expr* x1, Expr* x2);
		Expr* gen();
		std::string toString();
};

#endif
