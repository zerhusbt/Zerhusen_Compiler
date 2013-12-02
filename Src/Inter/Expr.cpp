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
	emitjumps(toString(),t,f);
}

void Expr::emitjumps(std::string test, int t, int f)
{
	if (t != 0 && f != 0)
	{
		std::string returnString;
		returnString = "";
		returnString += "if ";
		returnString += test;
		returnString += " goto L";
		returnString += t;
		emit(returnString);
		returnString = "";
		returnString += "goto L";
		returnString += f;
		emit(returnString);
	}
	else if (t != 0)
	{
		std::string returnString;
		returnString = "";
		returnString += "if ";
		returnString += test;
		returnString += " goto L";
		returnString += t;
		emit(returnString);
	}
	else if (f != 0)
	{
		std::string returnString;
		returnString = "";
		returnString += "iffalse ";
		returnString += test;
		returnString += " goto L";
		returnString += f;
		emit(returnString);
	}
	else
	{
		// do nothing since both t and f fall through
	}
}

std::string Expr::toString()
{
	return op->toString();
}
