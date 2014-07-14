//*****************************************************************************************
//
//	Filename: Temp.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Temp.h"

int Temp::count = 0;

Temp::Temp(Type* p) : Expr(Word::temp, p)
{
	number = ++count;
}

std::string Temp::toString()
{
	std::string returnString;
	returnString = "t";
	returnString += std::to_string(number);
	return returnString;
}
