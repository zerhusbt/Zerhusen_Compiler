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

Rel::Rel(Token* tok, Expr* x1, Expr* x2) : Logical(tok, x1, x2, "Rel")
{
	//do nothing here
}

// This check function has been moved to the Logical file due to a problem with using virtual 
// functions and the order in which object constructors are called
//Type* Rel::check(Type* p1, Type* p2)
//{
//	if((p1->tokenType()=="Array") || (p2->tokenType()=="Array")) //need to verify correct
//	{
//		return NULL;
//	}
//	else if(p1 == p2)
//	{
//		return Type::Bool;
//	}
//	else
//	{
//		return NULL;
//	}
//}

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
	emitjumps(test, t, f);
}
