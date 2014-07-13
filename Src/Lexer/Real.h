//*****************************************************************************************
//
//	Filename: Real.h
//	Description: Header file for Real class used to extend Token class for floats
//	Author: Benjamin Zerhusen
//	Date Created: 8/25/2013
//	Last Modified: 11/15/2013
//
//*****************************************************************************************

#ifndef REAL_H
#define REAL_H

#include <string>
#include <sstream>
#include "Token.h"
#include "Tag.h"

class Real : public Token 
{
	public:
		float value;
		// Constructor
		Real(float v);
		// return value
		virtual std::string toString();
		virtual std::string tokenType();
};

#endif
