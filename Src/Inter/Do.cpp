//*****************************************************************************************
//
//	Filename: Do.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#include "Do.h"

Do::Do()
{
	expr = NULL;
	stmt = NULL;
}

void Do::init(Stmt* s, Expr* x)
{
	expr = x;
	stmt = s;
	if(expr->type != Type::Bool)
	{
		expr->error("boolean required in do");
	}
}

void Do::gen(int b, int a)
{
	after = a;
	int label = newlabel();	// label for expr
	stmt->gen(b, label);
	emitlabel(label);
	expr->jumping(b, 0);
}
