//*****************************************************************************************
//
//	Filename: Rel.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Rel.h"

Rel::Rel(Token* tok, Expr* x1, Expr* x2) : Logical(tok, x1, x2)
{
	//do nothing here
}

Type* Rel::check(Type* p1, Type* p2)
{
	if((typeid(*p1)==typeid(Array)) || (typeid(*p2)==typeid(Array))) //need to verify correct
	{
		return NULL;
	}
	else if(p1 == p2)
	{
		return Type::Bool;
	}
	else
	{
		return NULL;
	}
}

void Rel::jumping(int t, int f)
{
	Expr* a = expr1->reduce();
	Expr* b = expr2->reduce();
	std::string test;
	test += a->toString();
	test += " ";
	test += op->toString();
	test += " ";
	test += b->toString();
	test += " ";
	emitjumps(test, t, f);
}