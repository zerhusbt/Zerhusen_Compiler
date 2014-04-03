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

Temp::Temp(Type* p)
{
	number = ++count;
}

std::string Temp::toString()
{
	std::string returnString;
	returnString = "t";
	returnString += number;
	return returnString;
}
