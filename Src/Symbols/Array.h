//*****************************************************************************************
//
//	Filename: Array.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include "Type.h"

class Array : public Type
{
	public:
		Type* of;	// array *of* type
		int size = 1;	// number of elements
		// constructor
		Array(int sz, Type p);
		std::string toString();
}

#endif
