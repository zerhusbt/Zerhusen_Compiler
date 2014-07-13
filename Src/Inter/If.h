//*****************************************************************************************
//
//	Filename: If.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#ifndef IF_H
#define IF_H

#include "Expr.h"
#include "Stmt.h"
#include "../Symbols/Type.h"

class If : public Stmt
{
	public:
		Expr* expr;
		Stmt* stmt;
		If(Expr* x, Stmt* s); //constructor
		virtual void gen(int b, int a);
};

#endif
