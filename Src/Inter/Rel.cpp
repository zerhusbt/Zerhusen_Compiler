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
	//need to figure out instanceof operator p.999 of pdf (976 of book)
}

void Rel::jumping(int t, int f)
{

}
