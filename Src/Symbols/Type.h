//*****************************************************************************************
//
//	Filename: Type.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#ifndef TYPE_H
#define TYPE_H

#include "../Lexer/Word.h"
#include <iostream>

class Type : public Word
{
	public:
		int width;	// width is used for storage allocation
		// constructor
		Type(int tag, std::string s, int w);
		static bool numeric(Type* p);
		static bool isChar(Type* p);
		static bool isInt(Type* p);
		static bool isFloat(Type* p);
		static Type* max(Type* p1, Type* p2);
		virtual std::string tokenType() const;
		//objects for the basic types
		static Type* Int;
		static Type* Float;
		static Type* Char;
		static Type* Bool;
};

#endif
