//*****************************************************************************************
//
//	Filename: Else.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#include "Else.h"

Else::Else(Expr* x, Stmt* s1, Stmt* s2)
{
	expr = x;
	stmt1 = s1;
	stmt2 = s2;
	if(expr->type != Type::Bool)
	{
		expr->error("boolean required in if");
	}
}

void Else::gen(int b, int a)
{
	int label1 = newlabel(); // label1 for stmt1
	int label2 = newlabel(); // label2 for stmt2
	expr->jumping(0, label2); // fall through to stmt2 on true
	emitlabel(label1);
	stmt1->gen(label1, a);
	
	std::string emitString;
	emitString += "goto L";
	emitString += std::to_string(a);
	emit(emitString);

	emitlabel(label2);
	stmt2->gen(label2, a);
}
