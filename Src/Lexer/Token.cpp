//*****************************************************************************************
//
//	Filename: Token.cpp
//	Description: File for Token Class
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#include "Token.h"

Token::Token(int t)
{
	tag = t;
}

std::string Token::toString() const
{
	std::stringstream ss;
	ss << tag;
	return ss.str();
}

std::string Token::tokenType() const
{
	return "Token";
}

