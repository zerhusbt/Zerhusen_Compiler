//*****************************************************************************************
//
//	Filename: Set.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#ifndef SET_H
#define SET_H

#include "Expr.h"
#include "Id.h"
#include "Stmt.h"
#include "../Symbols/Type.h"

class Set : public Stmt
{
	public:
		Id* id;
		Expr* expr;
		Set(Id* i, Expr* x);	// constructor
		Type* check(Type* p1, Type* p2);
		void gen(int b, int a);
};

#endif
