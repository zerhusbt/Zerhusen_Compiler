//*****************************************************************************************
//
//	Filename: Token.h
//	Description: Header file for Token.cpp
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <sstream>

class Token 
{
	public:
		int tag;
		// Constructor
		Token(int t);
		// return value
		virtual std::string toString();
		virtual std::string tokenType();
};

#endif
