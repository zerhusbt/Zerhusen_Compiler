//*****************************************************************************************
//
//	Filename: While.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#ifndef WHILE_H
#define WHILE_H

#include "Expr.h"
#include "Stmt.h"
#include "../Symbols/Type.h"

class While : public Stmt
{
	public:
		Expr* expr;
		Stmt* stmt;
		While(); //constructor
		void init(Expr* x, Stmt* s);
		virtual void gen(int b, int a);
};

#endif
