//*****************************************************************************************
//
//	Filename: Set.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#include "Set.h"

Set::Set(Id* i, Expr* x)
{
	id = i;
	expr = x;

	if(check(id->type, expr->type) == NULL)
	{
		error("type error");
	}
}

Type* Set::check(Type* p1, Type* p2)
{
	if(Type::numeric(p1) && Type::numeric(p2))
	{
		return p2;
	}
	else if((p1 == Type::Bool) && (p2 == Type::Bool))
	{
		return p2;
	}
	else
	{
		return NULL;
	}
}

void Set::gen(int b, int a)
{
	std::string emitString;
	emitString += id->toString();
	emitString += " = ";
	emitString += expr->gen()->toString();
	emit(emitString);
}
