//*****************************************************************************************
//
//	Filename: Access.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#include "Access.h"

Access::Access(Id* a, Expr* i, Type* p) : Op(new Word("[]", Tag::INDEX), p)
{
	// p is element type after flattening the array
	array = a;
	index = i;
}

Access::gen()
{
	return new Access(array, index->reduce(), type);
}

Access::jumping(int t, int f)
{
	emitjumps(//this is where I left off
}

Access::toString()
{
	
}
