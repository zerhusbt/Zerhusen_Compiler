//*****************************************************************************************
//
//	Filename: Op.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/02/2014
//	Last Modified: 04/02/2014
//
//*****************************************************************************************

#include "Op.h"

Op::Op(Token* tok, Type* p) : Expr(tok,p)
{
	// do nothing else
}

Expr* Op::reduce()
{
	Expr* x = gen();
	Temp* t = new Temp(type);

	std::string returnString;
	returnString = t->toString();
	returnString += " = ";
	returnString += x->toString();
	emit(returnString);

	return t;
}
