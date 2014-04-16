//*****************************************************************************************
//
//	Filename: Array.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#include "Array.h"

Array::Array(int sz, Type* p) : Type(Tag::INDEX,"[]",(sz*(p->width)))
{
	size = sz;
	of = p;
}

std::string Array::tokenType()
{
	return "Array";
}

std::string Array::toString()
{
	std::string returnString = "";
	returnString += "[";
	returnString += size;
	returnString += "]";
	returnString += of->toString();	// the toString() method should be inherited from Word
	return returnString;
}
