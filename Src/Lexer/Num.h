//*****************************************************************************************
//
//	Filename: Num.h
//	Description: Header file for Num class used to extend Token class
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#ifndef NUM_H
#define NUM_H

#include <string>
#include <sstream>
#include "Token.h"
#include "Tag.h"

class Num : public Token 
{
	public:
		int value;
		// Constructor
		Num(int v);
		// return value
		virtual std::string toString();
		virtual std::string tokenType();
};

#endif
