//*****************************************************************************************
//
//	Filename: Else.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#ifndef ELSE_H
#define ELSE_H

#include "Expr.h"
#include "Stmt.h"
#include "../Symbols/Type.h"

class Else : public Stmt
{
	public:
		Expr* expr;
		Stmt* stmt1;
		Stmt* stmt2;
		Else(Expr* x, Stmt* s1, Stmt* s2); //constructor
		virtual void gen(int b, int a);
};

#endif
