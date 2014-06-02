//*****************************************************************************************
//
//	Filename: If.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#include "If.h"

If::If(Expr* x, Stmt* s)
{
	expr = x;
	stmt = s;
	std::cout<<"In If() the value of expr->type is: "<<expr->type<<" compared to: "<<Type::Bool<<std::endl;
	if(expr->type != Type::Bool)
	{
		expr->error("boolean required in if");
	}
}

void If::gen(int b, int a)
{
	int label = newlabel(); // label for the code for stmt
	expr->jumping(0, a); // fall through on true, goto a on false
	emitlabel(label);
	stmt->gen(label, a);
}
