//*****************************************************************************************
//
//	Filename: SetElem.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#ifndef SETELEM_H
#define SETELEM_H

#include "Access.h"
#include "Expr.h"
#include "Id.h"
#include "Stmt.h"
#include "../Symbols/Array.h"
#include "../Symbols/Type.h"
#include <typeinfo>

class SetElem : public Stmt
{
	public:
		Id* array;
		Expr* index;
		Expr* expr;
		SetElem(Access* x, Expr* y); // constructor
		Type* check(Type* p1, Type* p2);
		virtual void gen(int b, int a);
};

#endif
