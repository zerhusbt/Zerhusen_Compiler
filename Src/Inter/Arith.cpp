//*****************************************************************************************
//
//	Filename: Arith.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Arith.h"

Arith::Arith(Token* tok, Expr* x1, Expr* x2)
{
	expr1 = x1;
	expr2 = x2;
	type = Type->max(expr1.type, expr2.type);
	if(type == NULL)
	{
		error("type error");
	}
}

Expr* Arith::gen()
{
	Arith* returnArith = new Arith(op, expr1->reduce(), expr2->reduce());
	return returnArith;
}

std::string Arith::toString()
{
	std::string returnString;
	returnString = expr1->toString();
	returnString += " ";
	returnString += op->toString();
	returnString += " ";
	returnString += expr2->toString();
	emit(returnString);
}
