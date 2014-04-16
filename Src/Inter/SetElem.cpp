//*****************************************************************************************
//
//	Filename: SetElem.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#include "SetElem.h"

SetElem::SetElem(Access* x, Expr* y)
{
	array = x->array;
	index = x->index;
	expr = y;
	if(check(x->type, expr->type) == NULL)
	{
		error("type error");
	}
}

Type* SetElem::check(Type* p1, Type* p2)
{
	if((p1->typeId()=="Array") || (p2->typeId()=="Array")) // need to verify correct
	{
		return NULL;
	}
	else if(p1 == p2)
	{
		return p2;
	}
	else if(Type::numeric(p1) && Type::numeric(p2))
	{
		return p2;
	}
	else
	{
		return NULL;
	}
}

void SetElem::gen(int b, int a)
{
	std::string s1 = index->reduce()->toString();
	std::string s2 = expr->reduce()->toString();
	
	std::string emitString;
	emitString += array->toString();
	emitString += " [ ";
	emitString += s1;
	emitString += " ] = ";
	emitString += s2;
	emit(emitString);
}
