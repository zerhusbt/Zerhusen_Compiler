//*****************************************************************************************
//
//	Filename: Real.cpp
//	Description: File for Real class used to extend Token class for floats
//	Author: Benjamin Zerhusen
//	Date Created: 8/25/2013
//	Last Modified: 11/15/2013
//
//*****************************************************************************************

#include "Real.h"

Real::Real(float v) : Token(Tag::REAL)
{
	value = v;
}

std::string Real::toString()
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

std::string Real::tokenType()
{
	return "Real";
}
