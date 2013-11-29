//*****************************************************************************************
//
//	Filename: Expr.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/27/2013
//	Last Modified: 11/27/2013
//
//*****************************************************************************************

#include "Expr.h"

Expr::Expr(Token* tok, Type* p)
{
	op = tok;
	type = p;
}

Expr* Expr::gen()
{
	return this;
}

Expr* Expr::reduce()
{
	return this;
}

void Expr::jumping(int t, int f)
{
	
}

void Expr::emitjumps(std::string test, int t, int f)
{
	
}

std::string Expr::toString()
{
	return op->toString();
}
