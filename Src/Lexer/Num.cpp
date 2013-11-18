//*****************************************************************************************
//
//	Filename: Num.cpp
//	Description: File for Num class used to extend Token class
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#include "Num.h"

Num::Num(int v) : Token(Tag::NUM)
{
	value = v;
}

std::string Num::toString() 
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

std::string Num::tokenType()
{
	return "Num";
}
