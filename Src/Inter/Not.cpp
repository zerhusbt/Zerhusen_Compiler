//*****************************************************************************************
//
//	Filename: Not.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Not.h"

Not::Not(Token* tok, Expr* x2) : Logical(tok, x2, x2, "Not")
{
	//do nothing here
}

void Not::jumping(int t, int f)
{
	expr2->jumping(f,t);
}

std::string Not::toString()
{
	std::string returnString;
	returnString += op->toString();
	returnString += " ";
	returnString += expr2->toString();
	return returnString;
}
