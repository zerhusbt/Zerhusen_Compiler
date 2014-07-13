//*****************************************************************************************
//
//	Filename: Do.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#ifndef DO_H
#define DO_H

#include "Expr.h"
#include "Stmt.h"
#include "../Symbols/Type.h"

class Do : public Stmt
{
	public:
		Expr* expr;
		Stmt* stmt;
		Do(); //constructor
		void init(Stmt* s, Expr* x);
		virtual void gen(int b, int a);
};

#endif
