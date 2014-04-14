//*****************************************************************************************
//
//	Filename: While.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#include "While.h"

While::While()
{
	expr = NULL;
	stmt = NULL;
}

void While::init(Expr* x, Stmt* s)
{
	expr = x;
	stmt = s;
	if(expr->type != Type::Bool)
	{
		expr->error("boolean required in while");
	}
}

void While::gen(int b, int a)
{
	after = a;	// save label a
	expr->jumping(0,a);
	int label = newlabel();	// label for stmt
	emitlabel(label);
	stmt->gen(label, b);
	
	std::string emitString;
	emitString += "goto L";
	emitString += b;
	emit(emitString);
}
