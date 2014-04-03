//*****************************************************************************************
//
//	Filename: Unary.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Unary.h"

Unary::Unary(Token* tok, Expr* x) : Op(tok, NULL)
{
	expr = x;
	type = Type::max(Type::Int, expr->type);
	if(type == NULL)
	{
		error("type error");
	}
}

Expr* Unary::gen()
{
	Unary* returnUnary = new Unary(op, expr->reduce());
	return returnUnary;
}

std::string Unary::toString()
{
	std::string returnString;
	returnString += op->toString();
	returnString += " ";
	returnString += expr->toString();
	return returnString;
}
