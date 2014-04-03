//*****************************************************************************************
//
//	Filename: Or.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Or.h"

Or::Or(Token* tok, Expr* x1, Expr* x2) : Logical(tok, x1, x2)
{
	//do nothing here
}

void Or::jumping(int t, int f)
{
	int label = (t != 0) ? t : newlabel();
	expr1->jumping(label, 0);
	expr2->jumping(t,f);
	if(t == 0)
	{
		emitlabel(label);
	}
}
