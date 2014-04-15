//*****************************************************************************************
//
//	Filename: Break.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#include "Break.h"

Break::Break()
{
	if(Stmt::Enclosing == NULL)
	{
		error("unenclosed break");
	}
	stmt = Stmt::Enclosing;
}

void Break::gen(int b, int a)
{
	std::string emitString;
	emitString += "goto L";
	emitString += stmt->after;
	emit(emitString);
}
