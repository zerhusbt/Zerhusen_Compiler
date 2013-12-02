//*****************************************************************************************
//
//	Filename: Id.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#include "Id.h"

Id::Id(Word* id, Type* p, int b) : Expr(id,p)
{
	offset = b;
}
